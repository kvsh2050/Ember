MEMORY {
    BANK1 : ORIGIN = 0xA000 , LENGTH = 4k
    bank2 : org = 0xB000 , len = 16k 
    bank3 : org = 0xC000 , l = 1M
}



# gcc attributes 



a = 10;

SECTIONS{
    b = 100;

    loadlink : {
        *(loadlink)
    }
    .text : {
        * (.loadlink)
        main.o (.text)
        main.o (.data)
        main.o (.bss)
        * (.text)
        c = a + b; // evauted and hown in the memory coloumn 
    } > BANK1   #put this .text section and put that in the memory bank 1 

    .data { 
        main.o (.data)
        globals.o (.data)
    } > RAM AT > ROM #prevesrve the init value from ROM ROM: LOAD ADDRESS, RAM : VMA
    #load at ram, but take value from rom 
    #or data lives in ROM but cpis over to the RAM. because the .text section uses RAM 




    .rodata : {
        *(vari)  // created via c 
        * (.rodata)
        _src_start_addr_ = .;
    } > ROM AT > ROM 

    .data {
        _dst_start_data_ = .; 
        main.o (.data)
        globals.o (.data)
        _dst_end_data_ = .;  // we know section from RAM ?
    } > RAM AT > ROM 


    .bss {
        main.o (.bss)
    } > RAM  AT > RAM    




    #discards all the sections from bar.o completely in the main.elf file 
    /DISCARD/ : {
        * (*)
    }

}