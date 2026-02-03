MEMORY
{
    FLASH        (rx) : ORIGIN = 0x80000000, LENGTH = 64K
    RAM          (rwx): ORIGIN = 0x20000000, LENGTH = 8K
    SYS_ROM      (rx) : ORIGIN = 0x1FFF000,  LENGTH = 2K
}


SECTIONS {
    .vector : {
        * (.vector)
        * (.text)
    } > FLASH

    .data : {
        * (.data)
    } > RAM

}