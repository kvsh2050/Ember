.section .vector 
    .align 2
    vector_table:
        .word 0xABCD //stack top 
        .word reset_handler 
        .zero 4
    //access systick exception
    .org 0x3C
        .word systick_handler
        .zero 4 
    //We Append zeros until text section 

.section .text 
    .align 2
    .type reset_handler, %function 
    .type task1, %function
    .type task2, %function
    .type task3, %function 
    .type task4, %function
    .type systick_handler, %function

    reset_handler:
        mov r1, #10
        b .

    systick_handler:
        mov r2, #10
        b .

    task1:
        b .

    task2:
        b .

    task3: 
        b .

    task4:
        b .


.section stack
    .align 2 
    stack1:
        b .

    stack2:
        b .

    stack3:
        b .
            
    stack4:
        b .
        