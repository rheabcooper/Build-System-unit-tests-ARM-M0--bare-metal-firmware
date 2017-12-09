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


FRDM:

10 BYTES:

Time in microseconds for STANDARD MEMMOVE is 7

Time in microseconds for STANDARD MEMSET is 7

Time in microseconds for DMA MEMMOVE is 23

Time in microseconds for DMA MEMSET is 21

Time in microseconds for NON-DMA MEMMOVE is 22

Time in microseconds for NONDMA MEMSET is 34

Time in microseconds for NONDMA MEMMOVE (-O3) is 24

Time in microseconds for NONDMA MEMZERO(-03) is 32


100 BYTES:

Time in microseconds for STANDARD MEMMOVE is 46

Time in microseconds for STANDARD MEMSET is 37

Time in microseconds for DMA MEMMOVE is 32

Time in microseconds for DMA MEMSET is 30

Time in microseconds for NON-DMA MEMMOVE is 164

Time in microseconds for NONDMA MEMSET is 236

Time in microseconds for NONDMA MEMMOVE (-O3) is 164

Time in microseconds for NONDMA MEMZERO(-03) is 236


1000 BYTES:

Time in microseconds for STANDARD MEMMOVE is 432

Time in microseconds for STANDARD MEMSET is 337

Time in microseconds for DMA MEMMOVE is 117

Time in microseconds for DMA MEMSET is 42

Time in microseconds for NON-DMA MEMMOVE is 1537

Time in microseconds for NONDMA MEMSET is 2253

Time in microseconds for NONDMA MEMMOVE (-O3) is 1535

Time in microseconds for NONDMA MEMZERO(-03) is 2252

5000 BYTES:

Time in microseconds for STANDARD MEMMOVE is 2150

Time in microseconds for STANDARD MEMSET is 1673

Time in microseconds for DMA MEMMOVE is 499 

Time in microseconds for DMA MEMSET is 42

Time in microseconds for NON-DMA MEMMOVE is 1389 

Time in microseconds for NONDMA MEMSET is 1842

Time in microseconds for NONDMA MEMMOVE (-O3) is 1389

Time in microseconds for NONDMA MEMZERO(-03) is 1842


CONCLUSIONS:

1. NON-DMA VERSION ON FRDM (i.e. the functions implemented by us) are the slowest. Especially memset since we are also checking in the function and returning a status flag.

2. -03 FLAG increases its efficiency a little especially on the BBB

3. DMA is faster than standard library versions as the size of data increases.

4. NON-DMA functions are faster on the BBB than on the FRDM.

5. Standard library functions are faster on the BBB than on the FRDM.
