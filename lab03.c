#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//question 1:
void set_int1(int num){
    //a local copy is created and modified, no effect on original variable
    num = 3;
}
void set_int2(int *num){
    //an address copy is passed to this function,
    //dereferrencing the address and modifying it is the same as changing
    //value in the address o the orginal variable
    *num = 4;
}

//question 2:
typedef struct student1{
    char name[200];
    char student_number[11];
    int year;
} student1;

void print_student_info(student1 stu){
    printf("name: %s\n", stu.name);
    printf("student #: %s\n", stu.student_number);
}

int main(){
    int num = 1;
    set_int1(num);
    printf("no effect: %d\n", num);
    set_int2(&num);
    printf("does change: %d\n", num);

    student1 stu1;
    strcpy(stu1.name, "Eugene Liu");
    strcpy(stu1.student_number, "349727487");
    print_student_info(stu1);


}