## Memory model 
    ```
    <----1 bit------>
    _________________
    |               |   0x0
    |               |   0x4
    |               |   0x8                 ---> 
    |               |   0xc
    |MEMORYMAPPEDI/O|
    |_______________|                                           ________________
    |               |   <--------- Data address                 |               |
    |               |   <--------> Data bus                     |               |
    |    MEMORY     |   <--------- Instruction address bus      |     CPU       |
    |               |   ---------> Instrution bus from memory   |               |
    |_______________|   <--------- ~rd/wr                       |_______________|
---

## POINTERS
    - We can access memory one byte or byte read/writeable 
    - Memory has instruction bus and databus for instruction address and data/instruction 
    - the memory is accessed by the CPU and DMA
    - DATA BUS is bidirectional  
    - Pointer is a number can be loaded into instruction address bus(function pointer) or databus (data pointer)which is used as address, to represent another memory location 
    - pointers manipulates/directly changes memory
    -  ptr may point to a memory address to directly write to memory mapped i/o
        example: say there is a video buffer , we must change it to change the pixel in screen.then we can point to that location using pointer varibles pointing and writing to that buffer directly knowing the buffer's address directly 
    - Pointer is like a index of a book 
    - Definition of ptr in c: char c = 'A'; 
                              char *c_ptr = &c;   --> here * means the varible after it is pointer - tell compiler
                              ans = *c_ptr        ---> here the * is dereference it, it means go to the memory saved in this c_ptr and put it in ans 
    - We can add, do arithmetric operations using pointers 
    - But the pointer & int or cha -> wont work 
    - But pointers can be typecasted to int/char to do  arithmetic : i = i **c_ptr; -> valid becaus 1st * -> multiply and 2nd * is derefernce and i && c  -> valid too. for clear one is put brackets in code 
    - Strings has \0 at end , while char array does not have \0 , but if i put \0 in char array, then it is inherently string, the variable for the array name and string are pointers. we can print the char array without \0 as a string.
    - sizeof() operator varies for array and pointer & Array cannot be reassigned (we cannot change the location of the array pointer to point to different memory location ) but the pointer can be reassigned (can modify the address stored in this variable ) or (we cannot change the address or content in the array variable like x[]; x-> content of x (which is a address to point to the location of array elements)cannot be changed)
    -  (&*i) = i   -> cancels out 

---
## POINTERS TO POINTERS:
        - int * ptr = & i;
         int **pptr = &ptr ;            pptr  --> ptr --> i 


---
# ESH GOOGLE repo 
# Free RTOS repo/ free rtos kernel 
# fs.h linux repo 
