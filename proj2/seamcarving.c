#include "seamcarving.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <float.h>

//helper fucntion for calc_energy to simplify code
int dxsq(struct rgb_img *im, int y, int x){
    int r1, g1, b1, r2, g2, b2;

    if(x == 0){
        r1 = get_pixel(im, y, im->width-1, 0);
        g1 = get_pixel(im, y, im->width-1, 1);
        b1 = get_pixel(im, y, im->width-1, 2);
    }else{
        r1 = get_pixel(im, y, x-1, 0);
        g1 = get_pixel(im, y, x-1, 1);
        b1 = get_pixel(im, y, x-1, 2);
    }

    if(x == im->width-1){
        r2 = get_pixel(im, y, 0, 0);
        g2 = get_pixel(im, y, 0, 1);
        b2 = get_pixel(im, y, 0, 2);
    }else{
        r2 = get_pixel(im, y, x+1, 0);
        g2 = get_pixel(im, y, x+1, 1);
        b2 = get_pixel(im, y, x+1, 2);
    }

    return (r1-r2)*(r1-r2) + (g1-g2)*(g1-g2) + (b1-b2)*(b1-b2);
}

//helper fucntion for calc_energy to simplify code
int dysq(struct rgb_img *im, int y, int x){
    int r1, g1, b1, r2, g2, b2;

    if(y == 0){
        r1 = get_pixel(im, im->height-1, x, 0);
        g1 = get_pixel(im, im->height-1, x, 1);
        b1 = get_pixel(im, im->height-1, x, 2);
    }else{
        r1 = get_pixel(im, y-1, x, 0);
        g1 = get_pixel(im, y-1, x, 1);
        b1 = get_pixel(im, y-1, x, 2);
    }

    if(y == im->height-1){
        r2 = get_pixel(im, 0, x, 0);
        g2 = get_pixel(im, 0, x, 1);
        b2 = get_pixel(im, 0, x, 2);
    }else{
        r2 = get_pixel(im, y+1, x, 0);
        g2 = get_pixel(im, y+1, x, 1);
        b2 = get_pixel(im, y+1, x, 2);
    }

    return (r1-r2)*(r1-r2) + (g1-g2)*(g1-g2) + (b1-b2)*(b1-b2);
}

void calc_energy(struct rgb_img *im, struct rgb_img **grad){
    create_img(grad, im->height, im->width);
    for(int y = 0; y < im->height; y++){
        for(int x = 0; x < im->width; x++){
            double energy = ( (double)(sqrt( (double)(dxsq(im, y, x)) + (double)(dysq(im, y, x)) )) )/10;
            int cast_energy = (uint8_t)(energy);
            set_pixel(*grad, y, x, cast_energy, cast_energy, cast_energy);
        }
    }
}

void dynamic_seam(struct rgb_img *grad, double **best_arr){
    *best_arr = (double *)malloc(sizeof(double) * grad->width * grad->height);
    for(int y = 0; y < grad->height; y++){
        for(int x = 0; x < grad->width; x++){
            if(y == 0){
                (*best_arr)[y*grad->width + x] = get_pixel(grad, y, x, 0);
            }else{
                double min = DBL_MAX;
                if(x == 0){
                    if((*best_arr)[(y-1)*grad->width + x] < min){
                        min = (*best_arr)[(y-1)*grad->width + x];
                    }
                    if((*best_arr)[(y-1)*grad->width + x+1] < min){
                        min = (*best_arr)[(y-1)*grad->width + x+1];
                    }
                }else if(x == grad->width-1){
                    if((*best_arr)[(y-1)*grad->width + x] < min){
                        min = (*best_arr)[(y-1)*grad->width + x];
                    }
                    if((*best_arr)[(y-1)*grad->width + x-1] < min){
                        min = (*best_arr)[(y-1)*grad->width + x-1];
                    }
                }else{
                    if((*best_arr)[(y-1)*grad->width + x] < min){
                        min = (*best_arr)[(y-1)*grad->width + x];
                    }
                    if((*best_arr)[(y-1)*grad->width + x+1] < min){
                        min = (*best_arr)[(y-1)*grad->width + x+1];
                    }
                    if((*best_arr)[(y-1)*grad->width + x-1] < min){
                        min = (*best_arr)[(y-1)*grad->width + x-1];
                    }
                }
                
                (*best_arr)[y*grad->width + x] = get_pixel(grad, y, x, 0) + min;
            }
        }
    }
}

void recover_path(double *best, int height, int width, int **path){
    *path = (int *)malloc(sizeof(int) * height);
    int x = 0, y = height-1;
    double min = DBL_MAX;
    for(int i = 0; i < width; i++){
        if(best[y*width + i] < min){
            min = best[y*width + i];
            x = i;
        }
    }
    (*path)[y] = x;
    y--;
    while(y >= 0){
        if(x == 0){
            if(best[y*width + x] < best[y*width + x+1]){
                (*path)[y] = x;
            }else{
                (*path)[y] = x+1;
                x++;
            }
        }else if(x == width-1){
            if(best[y*width + x] < best[y*width + x-1]){
                (*path)[y] = x;
            }else{
                (*path)[y] = x-1;
                x--;
            }
        }else{
            if(best[y*width + x] < best[y*width + x+1] && best[y*width + x] < best[y*width + x-1]){
                (*path)[y] = x;
            }else if(best[y*width + x+1] < best[y*width + x] && best[y*width + x+1] < best[y*width + x-1]){
                (*path)[y] = x+1;
                x++;
            }else{
                (*path)[y] = x-1;
                x--;
            }
        }
        y--;
    }
}

void remove_seam(struct rgb_img *src, struct rgb_img **dest, int *path){
    create_img(dest, src->height, src->width-1);
    for(int y = 0; y < src->height; y++){
        int x = 0;
        for(int i = 0; i < src->width; i++){
            if(i != path[y]){
                set_pixel(*dest, y, x, get_pixel(src, y, i, 0), get_pixel(src, y, i, 1), get_pixel(src, y, i, 2));
                x++;
            }
        }
    }
}

