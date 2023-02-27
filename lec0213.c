#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//valgrind
//gcc -g -o lec0213 lec0213.c

//how does valgrind work?
//1. compile with -g
//2. run valgrind ./lec0213
//3. valgrind will run the program and check for memory errors
//4. valgrind will print out the errors


int main(){
    char a[5] = "EngSci";
    printf("%c", a[1000]);

    char *p = malloc(100000);

    return 0;
}