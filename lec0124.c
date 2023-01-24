#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *my_strcpy(char *dest, char *src){
    /*
    //method 1
    int i=0;
    while(src[i] != '\0'){
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';

    //method 2
    for(int i=0; src[i] != '\0'; i++){
        dest[i] = src[i];
    }
    dest[i] = '\0';
    */
    //method 3
    int i = 0;
    do{
        dest[i] = src[i];
        i++;
    }while(src[i-1] != '\0');

    return dest;
}

// the expression x=y has a value and an effect
// the effect is put y into x
// the value is y
char *my_strcpy_fancy(char *dest, char *src){
    char *old_dest = dest;
    while(*dest++ = *src++);
    return old_dest;

}

void get_int_arr_from_input(int **p_arr, int *p_n){
    int n;
    printf("Number of elements that are coming: ");
    scanf("%d", &n);
    *p_n = n;
    *p_arr = (int *)malloc(n * sizeof(int));
    for(int i=0; i<n; i++){
        printf("Enter element %d: ", i);
        scanf("%d", &(*p_arr)[i]); // *(p_arr + i) is also the adress of (*p_arr)[i]
    }
    //get the number of integers n in the input
    //then get n integers from the input
}

int main(){
    int a = 0;
    scanf("%d", &a);
    printf("You just entered %d\n", a);

    float f = 3.14;
    scanf("%f", &f);

    char s[100];
    scanf("%s", s);
    //inputting 100 characters means need to set s[100] to NULL, and that would crash
    printf("You just entered %s\n", s);

    char *p_a = (char *)malloc(sizeof(1000));
    scanf("%s", p_a);
    
    int *p_int = (int *)malloc(sizeof(int));
    scanf("%d", p_int);

    int *my_arr;
    int n;
    get_int_arr_from_input(&my_arr, &n);
    for(int i=0; i<n; i++){
        printf("%d", my_arr[i]);
    }
    free(my_arr);



}

int main1(){
    char s1[100];
    char s2[] = "abc";
    my_strcpy_fancy(s1, s2);
    printf("%s\n", s1);
}