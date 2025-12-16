#include<stdio.h>

struct name{
    int id;
    float m;
};

int main(){
    struct name n[10];

    int *ppptr;
    //or
    int* pptr;   // size of this pointer variable can be 4bytes/8bytes so that it can store any address addressible by the computer 

    int a = 9;
    pptr = & a;


    int h = 90;
    *pptr =  h;

    //struct 
    struct name *ptr;
    ptr = &n[5];


    // write value to struct using ptr;
    ptr -> id = 1;  /// struct ptr pointer can go to the 5th element of struct n and modify the id 
    (*ptr).m = 3.0;

    printf("num 5 id %d\n", ptr -> id );
    printf("num 5 m %f\n", ptr -> m );

    printf("%lu\n", sizeof(pptr));








    return 0;
}