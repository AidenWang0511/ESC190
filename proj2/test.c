#include <stdio.h>
#include "seamcarving.h"
#include "c_img.h"
#include <math.h>
#include <stdlib.h>
#include <string.h>

int main(){
    struct rgb_img *im;
    struct rgb_img *cur_im;
    struct rgb_img *grad;
    double *best;
    int *path;

    // read_in_img(&im, "6x5.bin");
    // calc_energy(im, &grad);
    // print_grad(grad);
    // printf("best array:\n");
    // dynamic_seam(grad, &best);
    // //print best
    // for(int i = 0; i < grad->height; i++){
    //     for(int j = 0; j < grad->width; j++){
    //         printf("%f ", best[i*grad->width + j]);
    //     }
    //     printf("\n");
    // }

    // recover_path(best, grad->height, grad->width, &path);
    // //print path
    // printf("path: ");
    // for(int i = 0; i < grad->height; i++){
    //     printf("%d ", path[i]);
    // }
    // printf("\n");

    read_in_img(&im, "HJoceanSmall.bin");
    
    for(int i = 0; i < 150; i++){
        printf("i = %d\n", i);
        calc_energy(im,  &grad);
        dynamic_seam(grad, &best);
        recover_path(best, grad->height, grad->width, &path);
        remove_seam(im, &cur_im, path);

        destroy_image(im);
        destroy_image(grad);
        free(best);
        free(path);
        im = cur_im;
    }
    char filename[200];
    sprintf(filename, "imgFinal.bin");
    write_img(cur_im, filename);
    destroy_image(cur_im);
    destroy_image(im);
}