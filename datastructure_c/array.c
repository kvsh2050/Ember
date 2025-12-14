#include<stdio.h>


int main(){

    //arrays: same type of data stored contiguously in memory 

    int array[10];  // memory array of 10 elements each with 1 byte   // declaration only 
    char a[10] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};  // declaration with initialization  

    //Accessing 
    printf("element accessing : %c\n", a[2]);
    printf("element accessing : %c\n", *(a+2));
    printf("array addressing 1: %p\n", a);
    printf("array addressing 2: %p\n", &a[0]);
    printf("array addressing : %p\n", a+2);
    printf("array addressing : %p\n", a+10);
    printf("out of array addressing : %c\n", *(a+9));  // put 10 or more for accessing memory out of array 
    printf("array size : %lu\n", sizeof(a));

    printf("-------------------------\n");


    //Multidimensional Array 
    //Array of 1D Arrays

    //Matrix - 2D Array 
    char aa[2][10] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};  // declaration with initialization  
    //array is just memory indexed intelligently : *(*(a+i)+j)
    printf("array addressing : %p\n", aa);

    //3D Array , or 2 - 2D Array 
    char aaa[2][2][10] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};  // declaration with initialization  
    printf("mul array size : %lu\n", sizeof(a));
    printf("-------------------------\n");

    printf("array addressing : %p\n", &aaa[0][0][0]);
    printf("array addressing : %p\n", &aaa[1][0][0]);
    printf("array addressing : %p\n", &aaa[2][0][0]);
    // 10 ele - 10 ele | 10 ele - 10 ele | 10 ele - 10 ele |

    //2D array is screen and pixel 3 channel is characterised by struct 

    return 0;
}