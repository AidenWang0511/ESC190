#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "c_img.h"

int* q1b(int *d, int d_size, int target){
    int *ans = (int*) malloc(sizeof(int)*(target+1));
    ans[0] = 0;
    ans[1] = 1;
    for(int i=2; i<=target; i++) ans[i] = INT_MAX;

    for(int i=2; i<=target; i++){
        for(int j=0; j<d_size; j++){
            int a = d[j];
            if(a<=i && ans[i-a] != INT_MAX && ans[i-a] + 1 < ans[i]){
                ans[i] = ans[i-a] + 1;
            }
        }
    }

    return ans;
} 

int* q1c(int *d, int d_size, int target){
    int *ans = (int*) malloc(sizeof(int)*(target+1));
    ans[0] = 0;
    ans[1] = 1;
    for(int i=2; i<=target; i++) ans[i] = INT_MAX;

    int *coin = (int*) malloc(sizeof(int)*(target+1));
    for(int i=2; i<=target; i++){
        for(int j=0; j<d_size; j++){
            int a = d[j];
            if(a<=i && ans[i-a] != INT_MAX && ans[i-a] + 1 < ans[i]){
                ans[i] = ans[i-a] + 1;
                coin[i] = a;
            }
        }
    }

    int* res = (int*) malloc(sizeof(int)*(ans[target]));
    int i = 0;
    while(target > 0){
        res[i] = coin[target];
        target -= coin[target];
        i++;
    }

    free(coin);
    free(ans);

    return res;
}

uint8_t min(uint8_t a, uint8_t b){
    if(a<b) return a;
    return b;
}

void q2(struct rgb_img *im, struct rgb_img **new5_img){
    *new5_img = (struct rgb_img*)malloc(sizeof(struct rgb_img) * 5);
    for(int i=0; i<5; i++){
        create_img(&(new5_img[i]), im->height, im->width);
        for(int j=0; j<im->height; j++){
            for(int k=0; k<im->width; k++){
                set_pixel(new5_img[i], j, k, 
                    min(255, (int)(get_pixel(im, j, k, 0) * pow(1.1, i))), 
                    min(255, (int)(get_pixel(im, j, k, 1) * pow(1.1, i))), 
                    min(255, (int)(get_pixel(im, j, k, 2) * pow(1.1, i))));
            }
        }
    }
}

int main(){
    //question 1a: opt(n) = min{opt(n-d_i) + 1} for all d_i in D
    int d[] = {1, 4, 5};
    int d_size = sizeof(d)/sizeof(d[0]);
    int target = 18;
    //q1b
    printf("Question 1b:\n");
    int *ans = q1b(d, d_size, target);
    for(int i=0; i<=target; i++) printf("%d, ", ans[i]);
    printf("\n");

    //q1c
    printf("Question 1c:\n");
    int *ans2 = q1c(d, d_size, target);
    for(int i=0; i<ans[target]; i++) printf("%d, ", ans2[i]);
    printf("\n");
    free(ans);
    free(ans2);

    //q2
    printf("Question 2:\n");
    struct rgb_img *im;
    read_in_img(&im, "image.bin");
    struct rgb_img *new5_img;
    q2(im, &new5_img);
    for(int i=0; i<5; i++){
        char filename[50];
        sprintf(filename, "image%d.bin", i);
        write_img(&(new5_img[i]), filename);
    }
    free(new5_img);
    free(im);

    return 0;
}