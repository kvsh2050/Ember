//GDB debugs target(cpu)
#include<stdio.h>
char *message = "hi";

int foo(int a){
    return a*a;
}

int main(){
    int  a = 10;
    printf("Hello World! from %d\n", a);
    int result = foo(a);
    printf("The square is %d\n", result);
    return 0;
}
