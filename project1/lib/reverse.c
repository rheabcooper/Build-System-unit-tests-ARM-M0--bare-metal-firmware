/**
 * @file reverse.c
 * @brief A function to perform a complete reverse 
 *          of all the elements in the array
 *
 * This function is derived from Homework #2 and #3.  
 *
 * @author Brian Kelly
 * @date September 24, 2017
 *
 */

#include "reverse.h"

void reverse(uint8_t * str, uint32_t length)
{
	uint32_t element;
	uint8_t temp;

	/* This is a more efficient method that
		uses less looping when performing the
		array reverse computation */
	for (element = 0; element < length/2; element++)
	{
		temp = *(str + element);
		*(str + element) = *(str + length - 1 - element);
		*(str + length - 1 - element) = temp;
	}	
}
