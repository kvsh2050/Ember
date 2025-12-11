#include<stdio.h>

//#define NULL (void *)0x0    // void pointer for memory location 0 in memory -> 0x0 typecasted to void * and 
//0x0 is a address as it is casted as void *
//0x is hex , 0 is decimal -> this is already defined in stdio.h -> NULL keyword is point to mem loc 0 in C
//null pointer is just 0 

int main(){

    //void pointer declaration is same of data ptr 
    int i = 10;
    void *p = &i ;
    //cannot derefercne void pointer !!
    // used in typecast, updating and extracting a memory loc 
    printf("p value : %p, i address: %p \n", p, &i);

    int *pp = NULL;  // points to 0 ? and deref is not done usually here 
    printf("pp value : %d, deref *pp value: %p \n", *pp, pp);


    return 0;
}