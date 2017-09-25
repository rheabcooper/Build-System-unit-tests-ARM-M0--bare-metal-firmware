/**
 * @file memory.c 
 * @brief This file contains the function implementations 
 *         for performing memory manipulation.
 *
 * @author Brian Kelly and Rhea Cooper
 * @date September 23, 2017
 *
 */

#include "memory.h"

uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length)
{
	/* TODO: check the memory & potential data corruption when memmove */	
	size_t element;
	uint8_t temp;

	uint8_t diff = abs(dst - src);
	printf("difference in address is %d, the length is %zu\n", diff, length);
	if(diff < length)
	{
		for (element = 0; element < length; element++)
		{
			temp = *(src + element);
			*(dst + element) = temp;
		}
	}
	else
	{
		for (element = 0; element < length; element++)
		{
			/* *(dst + element) = *(src + element); */
			temp = *(src + element);
			*(dst + element) = temp;
		}
	}
	return dst;
}	

uint8_t * my_memcpy(uint8_t * src, uint8_t * dst, size_t length)
{
	/* TODO: check the memory & potential data corruption when memcpy */
	size_t element;
	uint32_t diff = abs(dst - src);
	if (diff < length)
	{
		/* Error! Data corruption! */
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
	return src;
}

uint8_t * my_memzero(uint8_t * src, size_t length)
{
	size_t element;
	for(element = 0; element < length; element++)
	{
		*(src + element) = 0;
	}
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

