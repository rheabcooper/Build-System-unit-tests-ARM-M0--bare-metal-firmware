/**
 * @file memory.h
 * @brief A header file to perform memory maniuplation. 
 *
 * A header file containing functions to perform memory manipulation.
 *
 * @author Brian Kelly and Rhea Cooper
 * @date September 23, 2017
 *
 */

#ifndef __MEMORY_H__
#define __MEMORY_H__

#include "common.h"

/**
 * @brief A function to move data from one memory location to another memory location
 *
 * This function takes two byte pointers (one source and one destination)
 * and a length of bytes to move from the source location to the destination.
 *
 * @param src - pointer data in the source location
 * @param dst - pointer data in the destination location
 * @param length - length of the data in the memory
 *
 * @return a pointer to the destination memory location
 */
uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length);

/**
 * @brief A function to copy data from one memory location to another memory location
 *
 * This function takes two byte pointers (one source and one destination)
 * and a length of bytes to copy from the source location to the destination.
 *
 * @param src - pointer data in the source location
 * @param dst - pointer data in the destination location
 * @param length - length of the data in the memory
 *
 * @return a pointer to the destination memory location
 */
uint8_t * my_memcpy(uint8_t * src, uint8_t * dst, size_t length);

/**
 * @brief A function to set a given value to the memory
 *
 * This function sets a given value to the memory through 
 * a pointer to the source location with a length in bytes 
 *
 * @param src - pointer data in the source location
 * @param length - length of the data in the memory
 * @param value - value to set for the memory location
 *
 * @return a pointer to the source memory location
 */
uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value);

/**
 * @brief A function to zero out all of the memory
 *
 * This function takes a pointer to the memory location and a length in bytes
 * and then zero out all of the memory.  
 *
 * @param src - pointer data in the source location
 * @param length - length of the data in the memory
 *
 * @return a pointer to the source memory location
 */
uint8_t * my_memzero(uint8_t * src, size_t length);

/**
 * @brief A function to reverse the order of all of the bytes in the memory
 *
 * This function takes a pointer to a memory location and a length in bytes
 * and then reverse the order of all of the bytes.
 *
 * @param src - pointer data in the source location
 * @param length - length of the bytes in the memory
 *
 * @return a pointer to the source in the memory
 */
uint8_t * my_reverse(uint8_t * src, size_t length);

/**
 * @brief A function to allocate the length of words in dynamic memory 
 *
 * This function takes the length of the words to allocate 
 * in dynamic memory. 
 *
 * @param length - length of the words in the memory
 *
 * @return a pointer to the memory allocation if successful or 
 *         a NULL pointer if not successful
 */
int32_t * reserve_words(size_t length);

/**
 * @brief A function to free a dynamic memory allocation 
 *
 * This function frees up a dynamic memory allocation by
 * providing the pointer src to the free memory function.
 *
 * @param src - pointer data in the source location 
 *
 * @return void
 */
void free_words(uint32_t * src);

#endif /* __MEMORY_H__ */
