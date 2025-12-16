#include<stdio.h>


struct _abc{
    int member;
};

struct _xyz{
    int a;
    float m;

    struct _abc stru;
}__attribute__((packed));

int main(){

    struct member {
      int id;
      char *name;  
    };

    struct member variable;

    variable.id = 123;

    //Array of struct 
    struct member vari[10];  
    // goes like 0th struct , first struct 
    vari[6].id = 1;

    return 0;
}

// Struct helps us to create a new data type 

// address, memory, size of is really important - you must orecalculate before in pen and paper  