# Project for the ECEN 5813 class at University of Colorado Boulder
Platform Independent Build System and Unit Testing

•	Implemented unit tests for circular buffer operations, memory manipulations using the Cmocka Framework 

•	Implemented a profiler system to profile memory operations using DMA, standard and custom libraries

•	Developed a platform independent Makefile with support for native and cross compilation on three target platforms (Desktop Linux, Beagle Bone Black, FRDMKL25Z) for the above version-controlled source files 


Bare-metal Firmware for ARM Cortex M0+ on FRDMKL25Z

•	Developed SPI and Nordic module nRF24L01 libraries for communication, UART drivers for logging 

•	Developed DMA libraries for block memory transfers, performed timer profiling, used them for UART transfers

•	Implemented blocking, non-blocking loggers using circular buffers for system updates across a UART channel

•	Configured the Real-Time Clock for time-stamping in the log

