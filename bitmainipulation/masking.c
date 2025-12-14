#include<stdio.h>

int main(){

    //set and clear bits 
    // OR - set : 1
    // AND - clear : 0 
    // to isolate targtes : bit mask : use shift and 1 bit 

    int num = 0xabcdef23;   // we need to target ef byte 
    int mask = 0xff << 8;
    
    int isolated_reg = num & mask ;   // this is masking register 
    printf("0x%x\n", mask ); 
    printf("0x%x\n", ~mask ); 

    // or else 
    //set 
    printf("0x%x\n", num | (mask) ); 

    //clear
    printf("0x%x\n", num & ~(mask) ); 


    // multiple bits setting 
    mask = mask | (mask << 16);

    //set 
    printf("0x%x\n", num | (mask) ); 

    //clear
    printf("0x%x\n", num & ~(mask) ); 

    return 0;
}