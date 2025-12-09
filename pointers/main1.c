#include<stdio.h>

int main(){
    // Pointer declaration 
    char c = 'A';
    char *ptr = &c ;
    char **pptr = &ptr;

    printf("c = %c\n&c = %p\n", c , &c);
    printf("ptr = %p\ndef_ptr = %c\n&ptr = %p\npptr = %p\n", ptr , *ptr, &ptr, pptr);

    return 0;
}