#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lab03.h"

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
/*
typedef struct student1{
    char name[200];
    char student_number[11];
    int year;
} student1;
*/

void print_student_info(student1 stu){
    printf("name: %s\n", stu.name);
    printf("student #: %s\n", stu.student_number);
    printf("Year: %d\n", stu.year);
}

//question 3a:
void set_default_name(student1 *p_s){
    strcpy((*p_s).name, "Default Student");
    strcpy((*p_s).student_number, "0");
    (*p_s).year = 0;
}
//question 3b:
void set_default_name_wrong(student1 s){
    strcpy(s.name, "Default Student");
    s.year = 0;
}

//question 4
void create_block1(student1 **p_p_s, int n_students){
    *p_p_s = (student1 *)malloc(n_students * sizeof(student1));
}

//question 5
void set_name(student1 *ps, char *str){
    if (strlen(str) > 199){
        for(int i=0; i<199; i++){
            (*ps).name[i] = str[i];
        }
    }else{
        strcpy(ps->name, str);
    }
    (*ps).name[199] = '\0';
}

//question 6
void destroy_block1(student1 *pps, int n_students){
    free(pps);
}

//quetions 7
typedef struct student2{
    char *name;
    char *student_number;
    int year;
} student2;

void create_block2(student2 **p_p_s, int n_students){
    *p_p_s = (student2 *)malloc(n_students * sizeof(student2));
    for(int i=0; i<n_students; i++){
        (*p_p_s)[i].name = 0;
        (*p_p_s)[i].student_number = 0;
    }
}

void print_student2_info(student2 stu){
    printf("name: %s\n", stu.name);
    printf("student #: %s\n", stu.student_number);
    printf("Year: %d\n", stu.year);
}

//question 8
void set_name2(student2 *ps, char *str){
    int l = strlen(str);
    (*ps).name = (char *)malloc(l*sizeof(char));
    strcpy(ps->name, str);
}

//question 9
void destroy_block2(student2 **pps, int n_students){
    for(int i=0; i<n_students; i++){
        if(((*pps)+i)->name != 0){
            free(((*pps)+i)->name);
        }
        if( ((*pps)+i)->student_number != 0){
            free(((*pps)+i)->student_number);
        }
    }
    free(*pps);
}

//question 10
/*
student2 will have an effect, but only on the variable name and student number. Since these 2 varaibles
are initiated as a pointer to char. When a local copy of student 2 is created when passing it into a function
a copy of the adress of these 2 variable is passed. Thus, any modification inside the function will also be
effective outside of the function.
*/

//question 13
void print_file_contents(char *fname){
    char line[200];
    FILE *fp = fopen(fname, "r");
    while(fgets(line, sizeof(line), fp) != NULL){
        printf("%s", line);
    }
    fclose(fp); 
    printf("\n");
}

//question 14
void get_file_avg(char *fname){
    char line[200];
    int sum = 0;
    int num_val = 0;
    FILE *fp = fopen(fname, "r");
    while(fgets(line, sizeof(line), fp) != NULL){
        num_val++;
        sum += atoi(line);
    }
    double ans = (double)sum / (double)num_val;
    printf("The avg is: %.2f\n", ans);
    fclose(fp); 
}

int main(){
    int num = 1;
    set_int1(num);
    printf("no effect: %d\n", num);
    set_int2(&num);
    printf("does change: %d\n", num);
    printf("\n");

    student1 stu1;
    strcpy(stu1.name, "Eugene Liu");
    strcpy(stu1.student_number, "349727487");
    stu1.year = 1;
    print_student_info(stu1);
    printf("\n");

    printf("Wrong: \n");
    set_default_name_wrong(stu1);
    print_student_info(stu1);

    printf("Correct: \n");
    set_default_name(&stu1);
    print_student_info(stu1);
    printf("\n");

    student1 *ps;
    int num_students = 3;
    create_block1(&ps, num_students);
    for(int i=0; i<num_students; i++){
        printf("Enter Student %d's name: \n", (i+1));
        scanf("%s", &( (*(ps+i)).name) );

        printf("Enter Student %d's #: \n", (i+1));
        scanf("%s", &( (*(ps+i)).student_number) );

        printf("Enter Student %d's year: \n", (i+1));
        scanf("%d", &( (*(ps+i)).year) );
    }
    printf("\n");
    for(int i=0; i<num_students; i++){
        print_student_info(*(ps+i));
    }
    printf("\n");
    
    print_student_info(stu1);
    set_name(&stu1, "abcdefghijklmn");
    print_student_info(stu1);
    printf("\n");

    destroy_block1(ps, num_students);
    printf("\n");
    

    student2 *st2;
    num_students = 3;
    create_block2(&st2, num_students);
    set_name2((st2+1), "James");
    set_name2((st2), "Aiden");
    for(int i=0; i<num_students; i++){
        print_student2_info(*(st2+i));
    }
    destroy_block2(&st2, num_students);
    printf("\n");

    print_file_contents("lab3_13.txt");
    printf("\n");

    get_file_avg("lab3_14.txt");
    printf("\n");
}