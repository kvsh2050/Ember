#include<stdio.h>

int init_var = 10;
int uninit_var;

int foo(int local){
    return local + 1;
}



//STARTUP CODE IN FIRMWARE AND STARTUP CODE IN LINUX FROM ROM TO RAM 

extern char _dst_start_data_ ;
extern char  _dst_end_data_ ;
extern char _src_start_addr_ ;   // but why char pointer or char variable ?
// can we do with a ptr instead of extern?

extern char _bss_start_;
extern char _bss_end_ ;

//  __attribute__((section("loadlink"))) : create new section for this code . this is a gcc attribute 
int __attribute__((section("vari"))) uniit_gloabl_var;

void __attribute__((section("loadlink"))) xyz(void) {
    char *src = &_src_start_addr_;   // use the linker script variable and is used in this function 
    char *dst_start = &_dst_start_data_;
    char *dst_end = &_dst_end_data_;
    char *bss_s = _bss_start_;
    char *bss_e = _bss_end_;

    while(dst_start != dst_end){
        *dst_start = *src;   // loading the dest(RAM location) with the ROM data 
        dst_start++;
        src ++;

    }
    while(bss_s != bss_e){
        *bss_s = 0;
        bss_s ++;
    }
}

// we can do the same for the BSS section and intialize it to zero 
// first the function xyz() in the begining of text so that it can be loaded at start of the program so that program executes correctly 
