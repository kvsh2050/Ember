.section .vector 
    .align 2
    vector_table:
        .word 0xABCD //stack top 
        .word reset_handler 
        .zero 128

.section .text 
    .align 2
    .type reset_handler, %function 
    reset_handler:
        mov r1, #10
        b .
    