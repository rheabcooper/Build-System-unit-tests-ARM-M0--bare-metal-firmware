/**
 * @file conversion.c
 * @brief A file to implement the functions for performing 
 *          data conversion. 
 *
 * These functions were originally developed by Rhea Cooper
 *  and Brian Kelly modified and improved the code.  
 *
 * @author Brian Kelly and Rhea Cooper
 * @date September 23, 2017
 *
 */

#include "common.h"
#include "conversion.h"
#include "reverse.h"

uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base)
{
	uint32_t length = 0;  /* first element in the array */
	int8_t sign;         /* sign representation */
	uint8_t rem; 	     /* remainder variable for the base */
	char hex;		     /* hexadecimal value for base 16 */

	/* For negative integer, it becomes a positive integer */
	if (0 > data)
	{
		sign = NEGATIVE_NUM; 
		data *= NEGATIVE_NUM;
	}

	/* for zero integer, assign '0' char to the array */
	if (0 == data)
	{
		*(ptr + length) = ZERO_CHAR;
		length++;     /* adding 1 to the length of the array */ 
	}
	else
	{
		if (BASE_16 == base)
		{
			while (0 < data)
			{
				rem = data % base;
				switch(rem)
				{
					case 10: hex = 'A';
						break;
					case 11: hex = 'B';
						break;
					case 12: hex = 'C';
						break;
					case 13: hex = 'D';
						break;
					case 14: hex = 'E';
						break;
					case 15: hex = 'F';
						break;
					default: hex = rem + ZERO_CHAR;
						break;	
				}
				
				*(ptr + length) = hex;
				data /= base;
				length++;
			}
		}
		else if (BASE_10 == base || BASE_2 == base) 
		{
			while (0 != data)
			{
				rem = data % base;
				*(ptr + length) = rem + ZERO_CHAR;
				data /= base;
				length++;
			}
		}
		else
		{
			#ifdef VERBOSE
			printf("Error! Incorrect Base number!\n");
			#endif
		}
		if (NEGATIVE_NUM == sign)
		{
			*(ptr + length) = NEGATIVE_CHAR;
			length++; 
		}
		reverse(ptr, length);

	}
	
	/* adding the null terminator to the array */
	*(ptr + length) = NULL_TERM;
	length++;

	/* returning the length of the converted data */
	return length;
}

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base)
{
	int32_t result = 0;
	uint8_t element = 0;
	int8_t sign = 1;

	if( *ptr == NEGATIVE_CHAR)
	{
		sign = NEGATIVE_NUM;
		element++;
	}
	
	while(NULL_TERM != *(ptr + element)) 
	{
		result = result * base + *(ptr + element) - ZERO_CHAR;
		element++;
	}	
	
	result *= sign;

	return result;
}

int8_t big_to_little32(uint32_t * data, uint32_t length)
{	
	uint32_t b0, b1, b2, b3, x0, x1, x2, x3;
	int32_t element;
	if(data!=NULL){	
	for(element = 0; element < length; element++)
	{
		/* extracting the bytes before conversion */
		b0 = BYTE4 & *(data + element);
		b1 = (BYTE3 & *(data + element)) >> 8;
		b2 = (BYTE2 & *(data + element)) >> 16;
		b3 = (BYTE1 & *(data + element)) >> 24;

		/* shifting the bytes for conversion */
		*(data + element)=(BYTE4 & *(data + element))<<24|
                         ((BYTE3 & *(data + element))>>8)<<16|
                         ((BYTE2 & *(data + element))>>16)<<8|
                         ((BYTE1 & *(data + element))>>24);
	}
	for (uint32_t element = 0; element < length; element++)
	{
		/* extracting the bytes after conversion */
		x0 = BYTE4 & *(data + element);
		x1 = (BYTE3 & *(data + element)) >> 8;
		x2 = (BYTE2 & *(data + element)) >> 16;
		x3 = (BYTE3 & *(data + element)) >> 24;
	}
	if (x0 == b3 && x1 == b2 && x2 == b1 && x3 == b0)
	{
		return 0;
	}
	else
	{
		#ifdef VERBOSE
		printf("Error!  Cannot convert from big endian to little endian!\n");
		#endif
		return -1;
	}
	}
	else 
		return 1;
}

int8_t little_to_big32(uint32_t * data, uint32_t length)
{
	uint32_t b0, b1, b2, b3, x0, x1, x2, x3;
	int32_t element;
	if(data!=NULL)
	{	
	for(element = 0; element < length; element++)
	{
		/* extracting the bytes before conversion */
		b0 = BYTE4 & *(data + element);
		b1 = (BYTE3 & *(data + element)) >> 8;
		b2 = (BYTE2 & *(data + element)) >> 16;
		b3 = (BYTE1 & *(data + element)) >> 24;

		/* shifting the bytes for conversion */
		*(data + element)=(BYTE4 & *(data + element))<<24|
                         ((BYTE3 & *(data + element))>>8)<<16|
                         ((BYTE2 & *(data + element))>>16)<<8|
                         ((BYTE1 & *(data + element))>>24);
	}
	for (uint32_t element = 0; element < length; element++)
	{
		/* extracting the bytes after conversion */
		x0 = BYTE4 & *(data + element);
		x1 = (BYTE3 & *(data + element)) >> 8;
		x2 = (BYTE2 & *(data + element)) >> 16;
		x3 = (BYTE3 & *(data + element)) >> 24;
	}
	if (x0 == b3 && x1 == b2 && x2 == b1 && x3 == b0)
	{
		return 0;
	}
	else
	{
		#ifdef VERBOSE
 		printf("Error!  Cannot convert from big endian to little endian!\n");
		#endif
		return -1;
	}
	}
	else 
		return 1;

} 
