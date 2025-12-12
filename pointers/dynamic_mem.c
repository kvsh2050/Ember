#include <stdio.h>
#include <stdlib.h>


int main (){

    //give me 4 bytes(int) from the heap and map the address/store the address into this pointer 
    int *p = (int *)malloc(4);
    printf("before : %d\n", *p);
    *p = 4;
    printf("after  : %d\n", *p);

    free(p);
    return 0;
}

//HEAP 
// 1. in os systems , linux, etc., or rtos implements heap 
// 2. a pool of memory, we can use during runtime 
// 3. can request this memory for the program 
// malloc, free : malloc(no.of bytes)  -> malloc api and it returns a void pointer back 
// free api and provide the pointer that must be freed
// the memory can be reused 
// memory management api can be imported from stdlib
// if malloc fails ? 
// calloc is *calloc(size_t nmemb, size_t size)
// realloc (void *nullable ptr, siz_t size) 
// reallocarray (void *nullable ptr, size_t nmemb, siz_t size) 

// if malloc fails : 1. if we are requesting more memory than a heap has 
// 2. if we do have some big number in the malloc(), then there is range of values which can be used in that. that is a constraint 
// 3. if free() is not used after the allocation, and we lost the pointer, then memory leak occurs, and heap does not hae memory left 
// 4. malloc returns NULL Pointer, if memory leak happens in heap
