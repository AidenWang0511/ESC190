#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student1{
    char name;
    int id;
} student1;

typedef struct student2{
    char *name;
    int id;
} student2;

void change_name(student2 s2, char *name){
    printf("address of s2.name 2: %p\n", s2.name);
    //strcpy(s2.name, name);
    printf("check\n");
    strcpy(s2.name, name);
    printf("address of s2.name 3: %p\n", s2.name);
}

int main(){
    double a[] = {-3.1415, 0, 1.5, 2.7e14, 9999};
    double *p = a;
    while (*p++ != 9999) printf("%g, ", *p);
    printf("\n");
}
