#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void q1(int *pn, char **parr){
    int n;
    printf("How many character are you entering?\n");
    scanf("%d", &n);
    *pn = n;
    printf("n: %d\n", n);
    *parr = (char *)malloc(sizeof(char)*(n+1));
    printf("size check: %d\n", sizeof(parr));
    for(int i=0; i<n; i++){
        printf("enter char %d: \n", i);
        scanf(" %c", &((*parr)[i]));
    }
    (*parr)[n] = '\0';
}

void q2a(char *a, char *b){
    int i, j;
    for(i=0; a[i] != '\0'; i++){}
    for(j=0; b[i] != '\0'; j++){
        a[i+j] = b[j];
    }
    a[i+j] = '\0';
}

int main(){
    char *arr;
    int n;
    q1(&n, &arr);
    printf("%s", arr);
    free(arr);
}