#include <stdio.h>

struct my_struct{
    long long int a;
    float b;
    int c;
};

int main(){

    int a = 10;
    int *ptr = &a;   //int here says read 4 bytes when deref, it says that you are pointing to the int data type
    struct my_struct var;
    struct my_struct *s_ptr = &var;
    //deref struct
    (*s_ptr).c = 4;   //or 
    s_ptr -> c = 4;   //struct, or datatypes with the members 
    printf("the c : %d\n", s_ptr -> c);
    printf("the c : %d\n", (*s_ptr).c);

    //cannot do mul, div on pointers : pointer arithmetic 
    *ptr = *ptr + 1;  // 1*sizeof(int) -> datatype of the pointer or data which the pointer points to 
    //cannot go to unallocated or no info memory -> segmentation fault / garbage/hangs 
    //*(ptr + 1)  === ptr[1]

    return 0;
}