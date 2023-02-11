#include <stdio.h>
#include<sys/mman.h>
#include<unistd.h>

int f(int a, int b, int c){
    return a+b;
}

int g(int a, int b, int c){
    return a+c;
}

//Hexadecimal: base 16
//0x1F = 16 + 15 = 32, 0x is used to represent hexadecimal, format use
void patch(int (*h)(int, int, int)){
    *(int *)((void*)h + 20) = 33047947;
}
int main(){
    int page_size = sysconf(_SC_PAGE_SIZE);
    void *page_start = (void *)(((unsigned long)f) & ~(page_size - 1));
    mprotect(page_start, page_size, PROT_READ | PROT_WRITE | PROT_EXEC);

    patch(g);
    printf("%d\n", g(1,2,3));
    return 0;
}