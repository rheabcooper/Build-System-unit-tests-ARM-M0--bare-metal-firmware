# gdb start up script for KL25Z board on openOCD interface
#  Kinetis L Series supports Program Longword (32-bit) execution only

#openOCD: listen on port
target extended-remote :3333

#openOCD: set the breakpoints limit 
set remote hardware-breakpoint-limit 2
set remote hardware-watchpoint-limit 2

#openOCD: set any memory area not in the memory as accessible
set mem inaccessible-by-default off

#openOCD: enable ARM semihosting
monitor arm semihosting enable

#openOCD: reset device
monitor reset init

#openOCD: get symbols
#file /home/brian/repos/BMK-ecen5813-project1/project2/project2.elf

#openOCD: load/flash executable
load /home/brian/repos/BMK-ecen5813-project1/project2/project2.elf

#openOCD: reset device
monitor reset halt
monitor halt

#openOCD: view arm registers on the board
monitor reg

#openOCD: show the configured memory map on the target
info mem

#openOCD: set up main() as the first temporary breakpoint
tbreak main

#openOCD: start the execution until the main() function
continue
