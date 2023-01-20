#include <stdio.h>
#include <stdlib.h>

void changeVal(int *num){
    *num = 10;
}

void changeChar(char *arr, int index, char c){
    *(arr+index) = 'a';
}

int strlength(char *str){
    int len = 0;
    while(*(str+len) != '\0'){
        len++;
    }
    return len;
}

void insertionSort(int arr[], int size){
    int i = 1;
    while(i < size){
        int j = i;
        while(j > 0 && arr[j-1] > arr[j]){
            int temp = arr[j-1];
            arr[j-1] = arr[j];
            arr[j] = temp;
            j--;
        }
        i++;
    }
}

void seq_replace(int *arr1, unsigned long arr1_sz, int *arr2, unsigned long arr2_sz){
    for(int i=0; i<arr1_sz; i++){
        for(int j=0; j<arr2_sz; j++){
            if(*(arr1+i) == *(arr2+j)){
                *(arr1+i) = 0;
            }
        }
    }
}

int main(){
    int a = 5;
    printf("Value before change: %d\n", a);
    changeVal(&a);
    printf("Value after change: %d\n\n", a);

    
    char *arr = (char*)malloc(sizeof(char)*7);
    printf("size of arr: %d\n", sizeof(arr)/sizeof(arr[0]));
    *arr = 'A';
    *(arr+1) = 'B';
    printf("%s\n", arr);
    changeChar(arr, 1, 'a');
    printf("%s\n", arr);
    printf("size of arr: %d\n\n", sizeof(arr)/sizeof(arr[0]));
    free(arr);

    int arrNum[10] = {10,9,8,7,6,5,4,3,2,1};
    int sizeNum = sizeof(arrNum)/sizeof(arrNum[0]);
    printf("before sorting:\n");
    for(int i=0; i<sizeNum; i++){
        printf("%d ", arrNum[i]);
    }
    printf("\n");
    insertionSort(arrNum, sizeNum);
    printf("after sorting:\n");
    for(int i=0; i<sizeNum; i++){
        printf("%d ", arrNum[i]);
    }
    printf("\n\n");

    char str[] = "abcdefg";
    printf("size of str is: %d\n\n", strlength(str)); //O(n)

    int arr1[] = {5, 6, 7, 8, 6, 7};
    int arr2[] = {6, 7};
    seq_replace(arr1, sizeof(arr1)/sizeof(arr1[0]), arr2, sizeof(arr2)/sizeof(arr2[0]));
    for(int i=0; i<sizeof(arr1)/sizeof(arr1[0]); i++){
        printf("%d ", arr1[i]);
    }
    printf("\n");
}
