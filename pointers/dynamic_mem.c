#include <stdio.h>
#include <stdlib.h>


int main (){

    //give me 4 bytes(int) from the heap and map the address/store the address into this pointer 
    int *p = (int *)malloc(4);
    printf("before : %d\n, address heap: %p\n", *p, p);
    *p = 4;
    printf("after  : %d\n", *p);
    free(p);

    //dangling pointer 
    /*
        1. if dynamically allocated pointer is used after free()
        2. not very good in embedded system  environment
    
    */
       //double free ()
    /*
        1. corrupts the 2 files 

        | size allocated : 4 bytes, total size of this is 4 bytes if size_t is 4 else other|  original mem allocation |
        (book keeping ) | (actuall memory allocation)
    */

    *p = 6;   //after free, we are allocating 
    printf("after free, dangling   : %d\n for address : %p\n", *p, p);  // but it works for me ? for linux os 

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


// WHAT IF WE WRITE MORE DATA THAN REQUIRED ?
// pointer arithmetic can access other regions in heap and can change it, unless guarded by os
// there is no checking on this : causes bugs 
