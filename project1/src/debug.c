/**
 * @file debug.c
 * @brief A file to implement the function for debug printing 
 *           if it is enabled by the compile time switch. 
 *
 * These functions were originally developed by Rhea Cooper
 *  and Brian Kelly modified and improved the code.  
 *
 * @author Brian Kelly
 * @date September 23, 2017
 *
 */

#include "debug.h"

void print_array(uint8_t * start, uint32_t length)
{
	#ifdef VERBOSE
	uint32_t element;
	for(element = 0; element < length; element++)
	{
		printf("%d", *(start + element));
	}
	putchar('\n');
	#endif
}
