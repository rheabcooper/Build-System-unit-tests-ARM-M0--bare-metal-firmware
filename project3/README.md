# Fall 2017 ECEN 5813 Project 3

Brian Kelly & Rhea Cooper's project 3 for the ECEN 5813 class at University of Colorado Boulder

Profiling Results
 
Standard Library Version for BBB

memmove Time - 10 bytes: 42 microseconds
memmove Time - 100 bytes: 4 microseconds
memmove Time - 1000 bytes: 12 microseconds
memmove Time - 5000 bytes: 73 microseconds

memset Time - 10 bytes: 19 microseconds
memset Time - 100 bytes: 4 microseconds
memset Time - 1000 bytes: 4 microseconds
memset Time - 5000 bytes: 9 microseconds

Non-DMA Version for BBB

memmove Time - 10 bytes: 6 microseconds
memmove Time - 100 bytes: 17 microseconds
memmove Time - 1000 bytes: 147 microseconds
memmove Time - 5000 bytes: 884 microseconds

memset Time - 10 bytes: 5 microseconds
memset Time - 100 bytes: 13 microseconds
memset Time - 1000 bytes: 100 microseconds
memset Time - 5000 bytes: 487 microseconds

Non-DMA Version using -O3 for BBB

memmove Time - 10 bytes: 4 microseconds
memmove Time - 100 bytes: 5 microseconds
memmove Time - 1000 bytes: 32 microseconds
memmove Time - 5000 bytes: 182 microseconds

memset Time - 10 bytes: 4 microseconds
memset Time - 100 bytes: 5 microseconds
memset Time - 1000 bytes: 23 microseconds
memset Time - 5000 bytes: 108 microseconds

