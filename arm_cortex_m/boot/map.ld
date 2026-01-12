MEMORY {
    MEM : org = 0x00 , l = 16k
}

SECTIONS {
    .text : {
        * (.vector)
        * (.text)
    } > MEM
}