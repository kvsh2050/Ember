MEMORY {
    ROM : org = 0x00 , l = 4k
}

SECTIONS {
    .text : {
        * (.vector)
        * (.text)
    } > ROM

}