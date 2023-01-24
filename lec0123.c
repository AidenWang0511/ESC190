#include<stdio.h>
#include<stdlib.h>

int main(){
    int *p_a = 0;
    *p_a = 1; //will crash
    p_a = (int *)malloc(sizeof(int));
    printf("%d\n", *p_a); //could be anything but won't crash
    *p_a = 1; //this is fine, same as p_a[0] = 1, p_a[i] gets converted to *(p_a + i)
    free(p_a); // if done after p_a = &b, will crash, and won't help the memory leak
    p_a[0]; //undefined behaviour, could crash, could output whatever is in memory

    int b = 2;
    p_a = &b;
    *p_a = 3; // *p_a is now 3, b is now 3
    b = 42; //*p_a is now 42
    printf("%d\n", *p_a);

    int c[] = {5,8,10};
    p_a = c; // p_a is now the address of the first element of c aka &c[0]
    p_a[0]; // 5
    p_a[1]; //8

    p_a++;//p_a = p_a + 1
    p_a[0]; //8
    *(p_a - 1);//5
    p_a[-1];//5

    *p_a = 0;
    &(*p_a); // same as p_a, will potentially crash if p_a is not a valid address
    *(&p_a); // same as p_a, will not crash

    int n = 5;
    *(&n); //same as n
    &(*n); //an error, *n means go to the adress n, but n is an int not an address

    int** p_p_a = 0;// a variable of type address of address of int
    p_p_a = (int*)malloc(sizeof(int *)); // p_p_a is now a valid address
    // **p_p_a = 1; //will crash
    *p_p_a = (int*)malloc(sizeof(int)); //p_p_a is now a valid address
    **p_p_a = 1; //same as p_p_a[0][0] = 1;
    free(*p_p_a); // free this first
    free(p_p_a); // free this nxt
    


}