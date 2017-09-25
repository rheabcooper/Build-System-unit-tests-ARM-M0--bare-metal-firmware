/**
 * @file conversion.c
 * @brief A file to implement the functions for performing 
 *          data conversion. 
 *
 * @author Brian Kelly and Rhea Cooper
 * @date September 23, 2017
 *
 */

#include "conversion.h"
#include "reverse.h"

uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base)
{
	uint8_t length = 0;  /* first element in the array */
	int8_t sign;         /* sign representation */
	uint8_t rem; 	     /* remainder variable for the base */
	char hex;		     /* hexadecimal value for base 16 */
	uint8_t element;     /* defined element in the array */

	/* For negative integer, it becomes a positive integer */
	if (0 > data)
	{
		sign = NEGATIVE_NUM;
		data *= -1;
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
			/* TODO: Figure out the base 16 value for negative integer */
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
		else if (BASE_2 == base)
		{
			while (0 != data)
			{
				rem = data % base;
				*(ptr + length) = rem + ZERO_CHAR;
				data /= base;
				length++;
			}		    
            reverse(ptr, length);
			if (NEGATIVE_NUM == sign)
			{
				for (element = 0; element <= length; element++)
				{
					if (*(ptr + element) == ZERO_CHAR)
					{
						*(ptr + element) = ONE_CHAR;
					}
					else
					{
						*(ptr + element) = ZERO_CHAR;
					}
				}
				/* TODO: Add the "add one to the char array" code
						  as the second part of two's complement for 
						   the negative integer. */	
			}
		}
		else if (BASE_10 == base) 
		{
			while (0 != data)
			{
				rem = data % base;
				*(ptr + length) = rem + ZERO_CHAR;
				data /= base;
				length++;
			}
			if (NEGATIVE_NUM == sign)
			{
				*(ptr + length) = NEGATIVE_CHAR;
				length++; 
			}
			reverse(ptr, length);
		}
		else
		{
			/* ERROR! Missing the base number! */
			/* TODO: Do we need to printf the error here? */
		}
	}
	
	/* adding the null terminator to the array */
	*(ptr + length) = NULL_TERM;
	length++;

	/* returning the length of the converted data */
	return length;
}

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base)
{
	/* TODO: This is easily done with positve char values and 
			  negative base 10 values, but we still need to figure
              out the negative base 2 and 16 with 2's complement */
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
	/* TODO:  Need to clean up and improve the conversion formula */
	int32_t element;
	if (NULL != data)
	{
		for(element = 0; element < length; element++)
		{
			/* int32_t b0 =  0x000000FF & *(data + element);
			int32_t b1 = (0x0000FF00 & *(data + element)) >> 8;
			int32_t b2 = (0x00FF0000 & *(data + element)) >> 16;
			int32_t b3 = (0xFF000000 & *(data + element)) >> 24;
			int32_t a0 = b0 << 24;
			int32_t a1 = b1 << 16;
			int32_t a2 = b2 << 8;
			int32_t a3 = b3;
		    int32_t  a = a0 | a1 | a2 | a3; */
		}
		return 0;
	}
	else
	{
		return -1;
	}
}

int8_t little_to_big32(uint32_t * data, uint32_t length)
{
	/* TODO:  Need to clean up and improve the conversion formula */
	int32_t element;
	if (NULL != data)
	{
		for(element = 0; element < length; element++)
		{
			/* int32_t b0 =  0x000000FF & *(data + element);
			int32_t b1 = (0x0000FF00 & *(data + element)) >> 8;
			int32_t b2 = (0x00FF0000 & *(data + element)) >> 16;
			int32_t b3 = (0xFF000000 & *(data + element)) >> 24;
			int32_t a0 = b0 << 24;
			int32_t a1 = b1 << 16;
			int32_t a2 = b2 << 8;
			int32_t a3 = b3;
			int32_t  a = a0 | a1 | a2 | a3; */
		}
		return 0;
	}
	else
	{
		return -1;
	}		
}
