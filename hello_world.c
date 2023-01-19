#include <stdio.h>

int main(){
    int a = 588;
    int *pa;
    pa = &a;
    *pa = 71234567;
    printf("%d\n", sizeof(pa));

    int arr[5] = {1,2,3,4,5};
    printf("%d\n", *(arr));

    char arrb[4] = {'a','b','c','\0'};
    printf("%s\n" ,arrb);

    int *a = (int *)malloc(sizeof(int)*12);
    
}