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
    // student2 s2;

    // s2.name = (char*)malloc(sizeof(char)*10);
    // s2.id = 2;
    // printf("address of s2.name 1: %p\n", s2.name);

    // change_name(s2, "test");
    // printf("%s\n", s2.name);

    // int *a;
    // a = (int*)malloc(sizeof(int));
    // *a = 1;
    // int **pa = &a;
    // printf("%d\n", **pa);
    // printf("%p\n", *pa);
    // free(a);
//     const char *pc;
//     char *pc2 = (char *)malloc(sizeof(char)*10);
//     pc = pc2;
//     strcpy(pc2, "test");
//     printf("%s\n", pc);
//     *(pc2+1) = 'a';
//     printf("%s\n", pc);
// }
    char *pc2 = (char *)malloc(sizeof(char)*10);
    char * const pc = pc2;
    *(pc2+1) = 'b';
    printf("%s\n", pc);
}
