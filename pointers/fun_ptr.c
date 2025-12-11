#include<stdio.h>

//typedef 
typedef int (*f)(int);  // now my f becomes a type, not a pointer variable. need to declare it in workspace


//function pointer 
void function1(){
    printf("function1\n");
}

void function2(int a){
    printf("function2: %d\n", a);
}

int function3(int a){
    printf("function3: %d\n", a);
    return 0;
}

int main(){

    //function ptr or callbacks 
    //points to mem location where a piece of code/instructions is/are present 
    //function ptr changes prgram counter to the fun ptr value -> put into the instruction bus 

    //ptr access RAM , wheras variables stored in the registers and stack/ram after operation (i guess we use stack
    // for pointer we can use ram any mem map or i/o maped)


    //function ptr;
    //deference the function ptr and dereference to execute the code 
    void (*f_ptr)(/*arguments if any */);   //-> declaring the function ptr and also the return type in front and put *before name to make it ptr
    void (*fptr)(int);  // void is return type 
    f func;

    f_ptr = function1;  // address, for function call only function1()
    f_ptr();   // derefernce 

    fptr = &function2;  //& also can be used 
    fptr(10);

    func = function3;
    func(10);

    return 0;
}