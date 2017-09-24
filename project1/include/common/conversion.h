/**
 * @file conversion.h
 * @brief A header file to perform data conversion. 
 *
 * A header file containing functions to perform data conversion.
 *
 * @author Brian Kelly and Rhea Cooper
 * @date September 23, 2017
 *
 */

#ifndef __CONVERSION_H__
#define __CONVERSION_H__

#include <stdint.h>

#define NEGATIVE_NUM  (-1)
#define NEGATIVE_CHAR ('-')
#define NULL_TERM     ('\0')
#define ZERO_CHAR     ('0')
#define ONE_CHAR	  ('1')

/**
 * @brief A function to convert data from an integer data type into an ASCII string
 *
 * This function converts data from an integer data type into an ASCII string
 *
 * @param data - signed 32 bit integer data
 * @param ptr - converted character string as a pointer
 * @param base - integer value of the base for data conversion (bases 2 to 16)
 *
 * @return length of the converted data
 */
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base);

/**
 * @brief A function to covert data from an ASCII string into an integer data type
 *
 * This function converts data from an ASCII string into an integer data type
 *
 * @param ptr - the pointer to the character string
 * @param digits - the number of digits of the character set in the "ptr" variable
 * @param base - integer value of the base for data conversion (bases 2 to 16)
 *
 * @return converted 32-bit signed integer
 */
int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base);

/**
 * @brief A function to convert data from big endian to little endian 
 *
 * This function converts an array of data in memory from a big endian
 * representation to little endian.
 *
 * @param data - an array data in the memory location
 * @param length - length of the data array in the memory
 *
 * @return an error if the conversion fails for any reason
 */
int8_t big_to_little32(uint32_t * data, uint32_t length);

/**
 * @brief A function to convert data from little endian to big endian
 *
 * This function converts an array of data in memory from a little
 * endian representation to big endian.  
 *
 * @param data - an array data in the memory location
 * @param length - length of the data array in the memory
 *
 * @return an error if the conversion fails for any reason
 */
int8_t little_to_big32(uint32_t * data, uint32_t length);

#endif /* __CONVERSION_H__ */

