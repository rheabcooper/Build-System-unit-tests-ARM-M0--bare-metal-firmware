/**
 * @file debug.h
 * @brief A header file to enable or disable debug printing. 
 *
 * A header file containing functions to perform debug printing.  This can be
 * enabled or disabled with a compile time switch.  This compile time switch
 * should be enabled with a VERBOSE flag in the Makefile.   
 *
 * This header file was all developed by Brian Kelly. 
 *
 * @author Brian Kelly and Rhea Cooper
 * @date September 23, 2017
 *
 */

#ifndef __DEBUG_H__
#define __DEBUG_H__

#include "common.h"

/**
 * @brief A function to print the hex output of bytes 
 *
 * This function prints the hex output of bytes based on the
 * pointer to a memory location and a length of bytes to print.
 * This function is enabled or disabled with a compile time switch.
 * 
 * If enabled, the print_memory function should print as normal.
 * If not defined or disabled, nothing should print.  
 *
 * @param start - a pointer to a memory location
 * @param length - a length of bytes in the memory
 *
 * @return void
 */
void print_array(uint8_t * start, uint32_t length);

#endif /* __DEBUG_H__ */
