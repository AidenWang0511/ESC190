#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare_ints(const void  *pa, const void *pb){
    int *pai = (int *)pa;
    int *pbi = (int *)pb;
    return (*pai - *pbi);
    //return *((int *)pa) - *((int *)pb); one of these 2 would work, this one looks more complicated
}

void bubble_sort(void *arr, int num_items, int item_size, int (*compare)(const void *, const void *)){
    void *temp = malloc(item_size);
    for(int i=0; i<num_items-1; i++){
        int swapped = 0;
        for(int j=0; j< num_items-1-i; j++){
            void *pj = arr + j*item_size;
            void *pj1 = arr + (j+1) * item_size;
            if(compare(pj, pj1) > 0){
                memcpy(temp, pj, item_size);
                //memcpy(dest, src, num_bytes) copy num_bytes from src to dest
                memcpy(pj, pj1, item_size);
                memcpy(pj1, temp, item_size);
                swapped = 1;
            }
        }
        if(!swapped) break;
    }
    free(temp);
}

typedef struct student1{
    char name[2];
    int age;
} student1;

int compareStudent1(const void *p_a, const void *p_b){
    student1 *pai = (student1 *)p_a;
    student1 *pbi = (student1 *)p_b;
    int age_diff = pai->age - pbi->age;
    if(age_diff != 0){
        return age_diff;
    }
    return strcmp(pai->name, pbi->name);
}

int main(){
    int arr[] = {5,10,2,56,6,7};
    qsort(arr, 6, sizeof(int), compare_ints);
    for(int i=0; i<6; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}