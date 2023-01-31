#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
struct uoft_student{
    char st_number_str[11]; //10 digits + NULL
    int faculty_num; //0 for Engingeering, 1 for art&sci, 2 for kinesiology, 3 for Music
};*/

typedef struct uoft_student{
    char st_number_str[11]; //10 digits + NULL
    int faculty_num; //0 for Engingeering, 1 for art&sci, 2 for kinesiology, 3 for Music
} uoft_student;
//OR
//typedef struct uoft_student uoft_student;

typedef struct waterloo_student{
    char *st_number_str;
} waterlooser;

void change_w_id(waterlooser w){
    w.st_number_str = (char *)malloc(5*sizeof(char));//no effec toutside the fn
    strcpy(w.st_number_str, "666");//no effect outside the fn
}

void change_w_id2(waterlooser w){
    strcpy(w.st_number_str, "666");//does have an effect, becasue a pointer is used
    //address is passed in this case
}

void create_waterlooser(waterlooser **ppw){
    *ppw = (waterlooser *)malloc(sizeof(waterlooser));
    (*ppw)->st_number_str = (char *)malloc(11 * sizeof(char));
    //(*(*ppw)).st_number_str = (char *)malloc(11*sizeof(char)); same as above
}

void destroy_waterlooser(waterlooser *pw){
    free(pw->st_number_str);
    free(pw);
    //order of free matters
}

void destroy_waterlooser2(waterlooser **pw){//also valid
    free((*pw)->st_number_str);
    free(*pw);
    //order of free matters
}

void print_uoft_student(uoft_student s){ 
    //calling this functions creates a local copy of the struct passed in, not the memory address
    //Thus, the original won't be modified
    printf("Faculty: %d\n", s.faculty_num);
    printf("Student #: %s\n", s.st_number_str);

    //(*s) gives an error since s is not a pointer
    //modifying s in his function has no effect since its a local copy
}

void switch_faculty(uoft_student *ps){
    (*ps).faculty_num = 1;
    
}

//can use typedf to define new custom types
typedef int BOOL;

int main(){
    //struct uoft_student s;
    uoft_student s;
    s.faculty_num = 0;
    strcpy(s.st_number_str, "1008880169");

    print_uoft_student(s);
    // printf("Faculty: %d\n", s.faculty_num);
    // printf("Student #: %s\n", s.st_number_str);

    switch_faculty(&s);
    print_uoft_student(s);

    waterlooser *pw;
    create_waterlooser(&pw);
    strcpy(pw -> st_number_str, "1234567890");


    BOOL t = 0; // same as int t = 0

    //char abc[2];
    //strcpy(abc, "1238");//give error, goes out of bounds
    

}