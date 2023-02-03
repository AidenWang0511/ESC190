#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if !defined(STUDENT_H)
#define STUDENT_H
typedef struct student1{
    char name[200];
    char student_number[11];
    int year;
} student1;
#endif