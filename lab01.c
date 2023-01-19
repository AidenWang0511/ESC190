#include <stdio.h>
#include <stdlib.h>

void changeVal(int *num){
    *num = 10;
}

void changeChar(char *arr){
    *arr = 'A';
    *(arr+1) = 'B';
}

int main(){
    int a = 5;
    printf("Value before change: %d\n", a);
    changeVal(&a);
    printf("Value after change: %d\n", a);

    char *arr = (char*)malloc(sizeof(char)*10);
    
    printf("%s", arr);
    changeChar(arr);
    printf("%s", arr);


}