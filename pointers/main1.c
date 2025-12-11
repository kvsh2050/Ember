#include<stdio.h>
#include<stdlib.h>

int main(){
    // Pointer declaration 
    char c = 'A';
    char *ptr = &c ;
    char **pptr = &ptr;
    void *av;  //-> we cannot dereference 

    printf("c = %c\n&c = %p\n", c , &c);
    printf("ptr = %p\ndef_ptr = %c\n&ptr = %p\npptr = %p\n", ptr , *ptr, &ptr, pptr);

    //array of pointers 
    char *p[10];   //pointer array 

    printf("pointer start address in normal memory : %p\n", &p);
    for (int i = 0 ; i < sizeof(p)/8; i ++){
        //p[i]= (char *)malloc(1);   // we are casting this to char pointer, the malloc return void * ususally, we are typecasting it to char *
        p[i]= malloc(1);
        printf("pointers in nrml mem points to heap address, pointers assigned the address of other dyanmic allocated array: %p\n", p[i]);

    }
    for (int j = 0 ; j < 10 ; j++){
        *p[j] = 10 - j;
        printf("info in heap : %d\n", *p[j]);
        printf("info in nrml loc : %p\n", p[j]);
    }

    for (int i = 0; i < 10; i++){
        free(p[i]);
        printf("free in heap : %p\n", p[i]);
    }
    return 0;
}