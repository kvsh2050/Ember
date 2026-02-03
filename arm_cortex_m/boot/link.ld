MEMORY
{
    FLASH  : ORIGIN = 0x00000000, LENGTH = 128K
}


SECTIONS {
    .text : {
        *(.vectors)
        *(.text)
    } > FLASH
}