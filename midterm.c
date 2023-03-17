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

char *test(char *dest, const char *src){
    if(*dest != '\0'){
        return (test(dest+1, src)-1);
    }
    if(*src == '\0'){
        *dest = *src;
        return dest;
    }else{
        *dest = *src;
        return (test(dest+1, src+1)-1);
    }
}

void input_test(const char *filename){
    FILE *fp = fopen(filename, "r");
    char in = 'a';
    char *str = (char*)malloc(sizeof(char)*2000);
    int counter = 0;
    while(in != '\n'){
        fscanf(fp, "%c", &in);
        *(str+counter) = in;
        counter++;
    }
    *(str+counter) = '\0';
    printf("%s\n", str);
}

int main(){
    input_test("test.txt");
}
