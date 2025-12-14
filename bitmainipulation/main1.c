#include<stdio.h>

int main(){

    int a = 2;              // 10
    int b = - 3;              //11    // c=  10
    int d = 0x0f;           //in registers loaded from the memory 
    int e = 0x0f;

    int c = d & e;
    printf("%x(hex)\n", c);

    int f = a & b;  //2 pos  
    printf("f: %x(hex)\n", f);
    printf("shift: %x(hex)\n",  f>>1);

    //bit manipulation : shift for signed  : right shift the neg num, you get ffff at MSB 
    int b1 = 1;
    printf("%x(hex)\n %d(hex)\n", (b1<< 31)>>30, (b1<<31)>>30);  //retains negative number MSB = 1 and MSB is preserved
    unsigned int b2 = 1;
    printf("0x%x(hex)\n %d(hex)\n", (b2<<31)>>30, (b2<<31)>>30);

    return 0;
}

//bit manipulation :
// each byte has an address, but it does not address to each bit in memory 
// cpu registers can be 4/8 bytes, cpu operates on resgisters : what if all registers used? 
// &, |, ~, ^, >>, <, -> operators
// for neg last bits in msb is 1 else 0 

//  >> -> divide by 2
// << -> multiply by 2 
// logical : fill vacated spots as 0 and arithmetic bit shifting : preseerves sign bit , mul and divide by 2
// note for logical and arithmetic in verilog is << and <<<
// left shift is same for all arithmetic and logical operators
