## GDB 

1. gnu debugger : helps debug programs in C/C++
2. GDB is a utility or program that can run on linux , partof gnu compiler 

sudo apt install gdb-multiarch 

3. gdb controls execution of another program 
4. gdb can debug program in same machine or a development board 

gcc -g main.c
gdb -q a.out

5. checks the cpu registers, and memory , cpu registers 
6. can also control hardware- resets 

7. gdb sends commands to the OS (in form of interrupts) to controls hardware / programs
8. ptrace is used by gdb 

9. remote targets with os : send over to the network and to the gdb server in remote machine and port numbers 
10. dev board : firmware: we need a hardware debugger (a exta piece of hardware that serves like gdb server)
11. takes in cmds from the host machine, where host machine has debugger set up and it passes commands to the hardware debugger
12. the hardware debugger then cotrols cpu based on commands 

gcc -g main.c
gdb 
gdb -q 
file a.out 
list : shows the source code  or l
run : runs the code until it exits or hits break point 
break 3 : break at line 3  or break function_name 
continue  or c 
quit or q
info breakpoints : list of all break points  -> disable 3 (disable breakpoints) -> enable 3 (enable breakpoints)
or i b 
next or n : goes step by step 
step : step by step + but goes into called functions  or s
layout asm -> assembly of src code  
layout src -> shows src code
ni -> next instruction in asm :next
si -> next instruction in asm :step
info source
info registers 
info var 
go to break points , inside that you can see the local var: info locals 
print var_name / print a 
p /x a -> prints a in hex 
p /d a -> print in int 
set a 10 : sets the varibles in the code forcefully
info args : args of function 
p /x (unsigned int)x  : typecast 
p *(pointer)
x : prints memory address
p  x : pritns values in address x 

help _commads_ or help set 
break main.c:28 : 28 is line 
break main.c:28 if i == 5
delete 1 or d 1 : delete breakpoints/watchpoints 

watch i : watchpoint 
info watchpoints : gives old and new values , notices chnage in values or variables 

print &a : &a address of a print it 
watch *0xaddress : watches memory location
rwatch *0xaddress : reads watchpoint 

p *0xaddress or p ptr_variable
p *0xaddress@5 : print 5 values from the address : prints in words
p /d *(char *)0xaddress@5  -> prints in 1 bytes 
x /nfu 0xaddress : examine /nfu => /10db or /10xb  or /10xw /<count><format><unit>


backtree tracing and stack cmds

backtrace / bt: gives line and parent functions or caller functions
up : goes back to caller 
down : goes to next caller 

##  GDB SCRIPTS, TIPS
automation
gdb -q -x myscript.gdb a.out

dump memory from file 
dump memory mydata.txt &a
dump memory mydata.txt message message+10

can use define name_
    /*
    */
    end 

call: name_

## GDB Dashboard 
go to gdb-dashboard: cyrus 


## Hardware debug 
 host :
 1. gdb -> gdb server (st_util, trace 32, openocd)  
 2. usb 

 remote machine :
 1. h/w debugger -> jtag 
 2. CPU/controller

(gdb) target remote localhost:1234



