//linker does symbol resolution/addresss, merge section 
// which address goes into which memory location or placement of sections : linker scripts comes into play 
// .o has format like .text , .bss,  etc., 
// ld main.o -o main.elf or main.bin
//objdump -D main.o > c.txt  -> for disassembly 

//view internal inker script of the linux x86, ld --verbose also applicable for arm 
// all code's function goes to the .text section
//initialized global, static variables: global auto, initialized local goes into the .data section;
//uninitialized global, local, static unitinialized : .bss 
//local auto is allocated dynamically in stack. at function run time 
// .elf -> final binary : one has many header this is also a finaly binary format 
// .bin -> simple clear file that has no unecessary headers


TOOLS:
arm-none-eabi-gcc       -> compiler 
*-gcc -c generates obj files .o 
*-ld                    
*-as : assembler
*-objdump 
*-nm 
*-strip
*-readelf


HOW LINKER SCRIPT WORKS ?
MEMORY {
    BANK1 : ORIGIN = 0xA000 , LENGTH = 0x1000
    BANK2 : ORIGIN = 0xB000 , LENGTH = 0x1000
}

SECTIONS{
    .text : {
        main.o (.text)
        main.o (.data)
        main.o (.bss)
    } > BANK1   #put this .text section and put that in the memory bank 1 
}


.bss and .data -> globals and static (global and static)

- when const keyword is used, then it is under .rodata -> globals
- .text, .rodata -> ROM 
- .data, varibale -> RAM


```
MEMORY {
    ROM : ORIGIN = 0xA000 , LENGTH = 0x1000
    RAM : org = 0xB000 , len = 0x1000
}

SECTIONS{
    .text : {
        * (.text)
    } > ROM   #put this .text section and put that in the memory bank 1 

    .data { 
        main.o (.data)
        globals.o (.data)
    } > RAM   # but initialized values went off!

    .bss {
        main.o (.bss)
    } > RAM

    .rodata : {
        * (.rodata)
    } > ROM

    #discards all the sections from bar.o completely in the main.elf file 
    /DISCARD/ : {
        * (*)
    }

}





```
- copy of .data in ROM
- code use address from RAM 
- VMA, LMA 
- current location counter : represented by . a dot.
- CLC shows cuurent location in linker script 

# LINKER COMMAND LANGUAGE 

We can specify in the linker script all these and linker understands this  :
1. input files
2. file formats 
3. output file 
4. placement of common blocks : sections 
5. address of section 

input files of linker:
1. obj
2. archive
3. linker script 
4. else error

# LINKER SCRIPT?
linker is a collection of statements. it is used to
1. set a particular option
2. used to select soemthin
3. group input files 
4. name output files 

2 important statements are
1. section 
2. memory , default is assigned (starts at 00 till ff)

expressions:
1. can be assignement a = 5;
2. all are evaluted as integers
3. int - long or unsigned long 
4. all artihemtic operations are present 
5. can create , define, call/reference global variables 
6. can call special buit-in functions 
7. int can be negative (-), hex (0x), decimal, octal(0), k (10 ^3), M (10 ^ 6)

symbols:
1. start with : letter, underscore, point
2. if quoted, symbol name can be anything 
3. may include any letters, underscores, digits, points, and hypens 
4. keywords like MEMORY etc.,  must not be used in unquoted ones 

location counter:
1. always contains current output location 
2. it always appears in SECTIONS
3. appears in a expression instead of symbols or varibles in linker script
4. assignemnt has side effect :
    - moves location counter 
    - create holes in output section like skiping bytes (that is a hole)
    . = . + 10;
5. never be used to move backward 
    . = . - 10

evalution:
1. Lazy Evaluation: calc only when needed and is useful 
2. first evaluates the memory and stuff 

assignemnt:
1. =, &=,  etc., 
2. may put ; at end 
3. correct  a = a +  b ; not a + b = c; 

placement of assigments:
1. evalution of assignment expression  has 2 thing
    - absolute address
    - relative address
2. absolute address gen:
    - cmd in ld script not in SECTIONS
    - independent state in SECTION cmd 
3. relative addr:
    - definitions/like in contents of SECTIONS (example .text) will make a relative address with respect to the address of the content 

SYMBOLS when assiging a value to 
1. absolute symbol
    - value same as in output file 
2. relocatable symbols
    - offset value from base
3. similar to absolute address holding symbol in previous section 


wildcard is *  means it is placeholder of all things 
