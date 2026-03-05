# Stack Overflow Lab

## Overview

This project demonstrates a basic stack-based buffer overflow vulnerability in C.

The goal of this lab is to understand:

- stack frame structure
- buffer overflow vulnerabilities
- return address corruption
- stack inspection using gdb



## Vulnerable Code

The vulnerability exists due to the use of the unsafe function:

gets()
Example:
char buffer[32];
gets(buffer);

#compilation
The program was compiled with disabled protections to observe stack behavior 
gcc -g -fno-stack-protector -z execstack vuln.c -o vuln

explaination :
    Flag      	                      Purpose
-g	                            include debugging symbols
-fno-stack-protector           	disable stack canaries
-z execstack	                  allow executable stack

#running the program 
normal execution :
./vuln 

exaample input :
hello 

output :
input : hello
you entered : hello

Interupting the flow :
AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA 

### The program crashes with segmentation fault 

# Debugging with GDB

Start debugger :
gdb ./vuln

Set Breakpoint :
break vuln

Run program :
run 

Inspect stack memory :
x/40x $rsp 

# Observed a crash 
after entering the output out of range ( char buffer[16] )

Program received signal SIGSEGV
0x0000550041414141 in ?? ()

The value :
0x41414141

corresponds to the ASCII character :
'A'
This represents the return address was overwritten with user input.

#Root cause :

stack layout :
Higher Address
---------------------
Return Address
Saved RBP
Buffer[32]
---------------------
Lower Address

Overflow input overwrites memory upward:
Buffer → Saved RBP → Return Address

Once the return address is corrupted, the CPU attempts to jump to an invalid location, causing a crash.


Tools Used :
C (GCC)
Linux
GDB debugger
