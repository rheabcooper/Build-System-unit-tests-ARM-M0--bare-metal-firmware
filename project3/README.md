# Fall 2017 ECEN 5813 Project 3

Brian Kelly & Rhea Cooper's project 3 for the ECEN 5813 class at University of Colorado Boulder

Profiling Results
 
Standard Library Version for BBB

memmove Time - 10 bytes: 9 microseconds
memmove Time - 100 bytes: 19 microseconds
memmove Time - 1000 bytes: 151 microseconds
memmove Time - 5000 bytes: 1129 microseconds

memset Time - 10 bytes: 9 microseconds
memset Time - 100 bytes: 32 microseconds
memset Time - 1000 bytes: 290 microseconds
memset Time - 5000 bytes: 1577 microseconds

Non-DMA Version for BBB

memmove Time - 10 bytes: 9 microseconds
memmove Time - 100 bytes: 18 microseconds
memmove Time - 1000 bytes: 152 microseconds
memmove Time - 5000 bytes: 755 microseconds

memset Time - 10 bytes: 9 microseconds
memset Time - 100 bytes: 31 microseconds
memset Time - 1000 bytes: 292 microseconds
memset Time - 5000 bytes: 1695 microseconds

Non-DMA Version using -O3 for BBB

memmove Time - 10 bytes: 7 microseconds
memmove Time - 100 bytes: 6 microseconds
memmove Time - 1000 bytes: 37 microseconds
memmove Time - 5000 bytes: 185 microseconds

memset Time - 10 bytes: 18 microseconds
memset Time - 100 bytes: 9 microseconds
memset Time - 1000 bytes: 69 microseconds
memset Time - 5000 bytes: 322 microseconds



