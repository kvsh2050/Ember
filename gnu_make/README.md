# MAKEFILES

Makefile is used for automation of command line or command.
Example:
```
a.out : main.c
    gcc main.c

run : a.out 
    ./a.out 

-> make run 

STEPS MAKE FOLLOWS:
1. make looks at make run and looks at the dependencies of run 
2. Checks run is in the folder (you can avoid this by using PHONY), if yes says: make up to date 
3. if not, it checks the makefile with targets of the same name 
4. if it finds the target it executs that taret first, if not then error is thrown says : no target is matched  

```

## BASICS of MAKE 

1. makefile executes the shell commands automatically 
2. Name of the makefile can be Makefile or any name 
3. Makefile has Target and recipes
4. Target has recipes
5. Add Targets: (here the cmd as well as result of the cmd is shown). If you dont want the cmd to execute put @ at front of command/
    ```
    target_name:   (TARGET)
    <TAB>cmd 1     (RECIPE)
    <TAB>@cmd 2
    <TAB>cmd 3
    ```
6. Then Run make target_name
7. Make if we donot specify the target, executes the first target it finds
8. Make only executes only if dependencies files changes
    ```
    gcc: main.c
        gcc -c main.o main.c
    ```
9. Make executes everything at first, but only executes the recipe in subsequent "makes" only if the dependencies or code changes 
10. check this out !
    ```
    b.txt: main.c
	echo "HI" > main.txt

    #this above make syntax does not say up to date

    main.txt: main.c
	echo "HI" > main.txt

    #but this does when i rerun 

    main: main.c
	echo "HI" > main.txt
    # this type of syntax also does not say up-to-date information like that 
    ```

11.  The above confusion is solved by this, the above code, the target's name is important. because the make checks timestamps of target and dependencies 
12. if dependencies are not having any changes then the makefile does not run ( that means dependencies must be newer than the target)
13. the target name starts with main.txt the main.txt was created. and the main.txt has reference stmp to tell make to stop. at the main target, the main file or output is never created so the make repeats itself again and again 
14. main.txt is newer than dependencies then it wont execute 
15. MAKE SYNTAX :
    ```
    target: dependencies
    ---->Recipe 1
    ```
16. in this command:
    ```
    run: 
        ./a.out
    -> here a.out is delebrately deleted
    -> here it says makefile error

    
    run: a.out
        ./a.out

    -> but in here the make searches for make commad which would execute and give out the a.out file and executes that first and then it executes the run command if i do " amke run"


    a : main.c
	echo "HI"
	gcc -o main main.c 
	gcc main.c

    -> i get this error 
    gcc main.c
    cp a a.out
    cp: cannot stat 'a': No such file or directory
    make: *** [<builtin>: a.out] Error 1
    -> idk why this copy came from 

    abc : main.c
	echo "HI"
	gcc -o main main.c 
	gcc main.c
    ->. i get : make: *** No rule to make target 'a.out', needed by 'run'.  Stop.

    ```
17. Thus Makfile names are important else it will not execute it correctly as we assume 
18. dependencies can be targets of its own in make run cmd, we saw that a.out is a target which muct be excuted to obtain a.out and then execute make run. this a.out can be changed to abc target and make run point to the abc target to be first executed as well by lisitng it as dependencies in the make run target 
    ```
    abc : main.c
	echo "HI"
	gcc -o main main.c 
	gcc main.c

    run: abc
	    ./a.out
    -> this executes well too 

    a.out : main.c
        echo "HI"
        gcc -o main main.c 
        gcc main.c

    run: a.out
        ./a.out
    -> this executes well too

    ```
19. .PHONY actually says to the make, that things listed in the phony is the targets which are just names not a output file like a.out. As make consideres targets as output files or executables. For example, we have a file called clean is there, the clean target will not execute so to clear name resolutions of files and targets which are just name calls we use phony
    ```
    try to add a clean file first and execute, it wont work, it will say : up to date!
    .PHONY = clean 

    SRC = main.c 

    all: clean
        @

    a.out : $(SRC)
        echo "HI"
        gcc main.c

    run: a.out
        ./a.out

    clean: 
        rm main
        rm a.out 

    ```
20. Variables are names which is used to represent files, or other stuff in Makefiles
    ```
    SRC = main.c code.c 

    main.o : $(SRC)
        @gcc -c $(SRC)

    ```
21. Assignment operators to variables
    - ?= in GCC ?= gcc means gcc is default unless given other compiler on cmd line 
    - += means append to already exisitng variables 
    - VAR = <empty>
      and at cmd line, make VAR = 1 : this is how we give values to variables in makefile via cmd line 
    - := means the variable is expanded once or evaluated once at starting and not evaluted again and again whenever variable is called but = is evaluted again whenever variable is called

22. Internal variables used inside a target 
    - $^ : represents all dependencies 
        ```
        # Here we take all values of dependencies and make a executable 
        a.out : main.c code.c call.c
            gcc $^
        ```
    - $< : represents the 1st dependency of that particular target recipe it is used in 
        ```
        # Here we take 1st dependency main.c and make a.out 
        a.out : main.c code.c call.c
            gcc $<
        ```
    - All Files Representation (This is not restricted inside target)
        ```
        # Here %.o and %.c represents alll files with .o and .c at target (NOTE)
        %.o : %.c
	        gcc -c $^

        ```
    - $@: Represents Target 
        ```
        $The $@ represents the target name main 
        main : main.o 
	        gcc $^ -o $@
        ```
    - we can  write linux shell commands using $(shell echo "hi") like this (This is not restricted inside target)
23. Macros or small procedures can be written as :
    ```
    #MACROS 
    define echo_macro 
    echo "HI"
    echo "WELCOME TO ZOOTOPIA"
    endef
    ```
24. GIVES INFO ON THE FILES STATUS 
    ```
    $(info $(SRC) $(OBJ_FILE) $(HDR_FILES))
    ```
25. Makefile with different names 
    - make -f make_file <your_cmd>
26. Include 1 Makefile into another
    - include include_me.mk
27. $() : Executes whatever in the brackets and replaces inside makefiles 




