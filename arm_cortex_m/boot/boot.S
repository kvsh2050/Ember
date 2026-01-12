.section .vector
vector_section:
    .word 0xABCD
    .word reset_exception_handler_address
    .word 400 
.section .text 
    //directives 
reset_exception_handler_address:
    bl . 



