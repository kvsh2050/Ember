//retain the function names or forward declaration here, no declaration no lib and put #include "sll.h"  -> "" local 
// add header guard: ifndef __H_SLL__ define __H_SLL__  -> any name
// donot make global variable visible, so use static in the global variables to hide variable 
// ship the code : no code visible to people outside, only use header 
// put all code in a lib dir 
// convert sll.c into lib or binary 
// use ar tool 
// gcc -c sll.c   -> give out .o file 
// ar -rc libsll.a sll.o  -> libsll.a is archive file + sll.h must be there for dev 
// gcc main.c libsll.a  // static lib