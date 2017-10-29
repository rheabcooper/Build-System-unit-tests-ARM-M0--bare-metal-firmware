/**
 * @file memory.c 
 * @brief This file contains the function implementations 
 *         for performing memory manipulation.
 *
 * These functions were originally developed by Rhea Cooper
 *  and Brian Kelly modified and improved the code.  
 *
 * @author Brian Kelly and Rhea Cooper
 * @date September 23, 2017
 *
 */

#include "memory.h"
#define ZERO (0)
int8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length)
{
	if(src == NULL || dst == NULL)
    {
        	return INVALID_MEMORY_POINTER;
    }
	size_t element;
	if(src < dst)
	{
		for (element = 1; element <= length; element++)
		{
			*(dst + length - element) = *(src + length - element); 
		}
		return SUCCESS;
	}
	else
	{
		for (element = 0; element < length; element++)
		{
			*(dst + element) = *(src + element);
		}
		return SUCCESS;
	}
	 
}	



int8_t * my_memset(uint8_t * src, size_t length, uint8_t value)
{
	size_t element;
	uint8_t flag=ZERO;
	if(src == NULL)
    {
        return NULL_POINTER;
    }
	for(element = 0; element < length; element++)
	{
		*(src + element) = value;
	}
	for(element = 0; element < length; element++)
	{
		if(*(src + element) != value)
			flag++;
	}
	if(flag==ZERO)
		return SUCCESS;
	else
		return FAILED;
}

int8_t * my_memzero(uint8_t * src, size_t length)
{
	size_t element;
	if(src == NULL)
    {
        	return NULL_POINTER;
    }
	for(element = 0; element < length; element++)
	{
		*(src + element) = 0;
	}
	for(element = 0; element < length; element++)
	{
		if(*(src + element) != value)
			flag++;
	}
	if(flag==ZERO)
		return SUCCESS;
	else
		return FAILED;
}

int8_t * my_reverse(uint8_t * src, size_t length)
{
	if(src == NULL)
    {
        return NULL_POINTER;
    }
	uint32_t element;
	uint8_t temp;
	for (element = 0; element < length/2; element++)
	{
		temp = *(src + element);
		*(src + element) = *(src + length - 1 - element);
		*(src + length - 1 - element) = temp;
	}	
	return SUCCESS;
}



