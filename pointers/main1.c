#include<stdio.h>

int main(){
    // Pointer declaration 
    char c = 'A';
    char *ptr = &c ;

    printf("c = %c\n&c = %p\n", c , &c);
    printf("ptr = %p\ndef_ptr = %c\n&ptr = %p\n", ptr , *ptr, &ptr);

    return 0;
}