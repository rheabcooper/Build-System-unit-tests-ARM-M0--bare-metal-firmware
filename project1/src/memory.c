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

uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length)
{
	size_t element;
	uint8_t * temp;
	uint8_t buffer[length];
	temp = &buffer[0];
	uint8_t diff = abs(dst - src);

	if(diff < length)
	{
		for (element = 0; element < length; element++)
		{
			*(temp + element) = *(src + element);
		}
		for (element = 0; element < length; element++)
		{
			*(dst + element) = *(temp + element);
		}
	}
	else
	{
		for (element = 0; element < length; element++)
		{
			*(dst + element) = *(src + element);
		}
	}
	return dst;
}	

uint8_t * my_memcpy(uint8_t * src, uint8_t * dst, size_t length)
{
	size_t element;
	uint32_t diff = abs(dst - src);
	if (diff < length)
	{
		#ifdef VERBOSE
		printf("Data Corruption Error!\n");
		#endif		
	}
	for(element = 0; element < length; element++)
	{
		*(dst + element) = *(src + element);
	}
	return dst;
}

uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value)
{
	size_t element;
	for(element = 0; element < length; element++)
	{
		*(src + element) = value;
	}	
	src = (uint8_t *)src;
	return src;
}

uint8_t * my_memzero(uint8_t * src, size_t length)
{
	size_t element;
	for(element = 0; element < length; element++)
	{
		*(src + element) = 0;
	}
	src = (uint8_t *)src;
	return src;	
}

uint8_t * my_reverse(uint8_t * src, size_t length)
{
	uint32_t element;
	uint8_t temp;
	for (element = 0; element < length/2; element++)
	{
		temp = *(src + element);
		*(src + element) = *(src + length - 1 - element);
		*(src + length - 1 - element) = temp;
	}	
	return src;
}

int32_t * reserve_words(size_t length)
{
	int32_t * ptr = NULL;
	ptr = (int32_t *)malloc(length * sizeof(int32_t *));
	if (NULL != ptr)
	{
		return ptr;
	}
	else
	{
		ptr = NULL;
		return ptr;
	}
}

void free_words(uint32_t * src)
{
	free(src);	
}

