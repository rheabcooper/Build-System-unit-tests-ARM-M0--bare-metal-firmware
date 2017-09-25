/**
 * @file debug.c
 * @brief A file to implement the function for debug printing 
 *           if it is enabled by the compile time switch. 
 *
 * @author Brian Kelly
 * @date September 23, 2017
 *
 */

#include "debug.h"

void print_array(uint8_t * start, uint32_t length)
{
	uint32_t element;
	for(element = 0; element < length; element++)
	{
		printf("%d", *(start + element));
	}
	putchar('\n');
}
