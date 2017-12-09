/**
 * @file cirbuf.h
 * @brief A header file to perform DMA operations. 
 *
 * A header file containing functions to perform memory manipulation.
 *
 * This header file was all developed by Rhea Cooper.
 *
 * @author Brian Kelly and Rhea Cooper
 * @date October 24, 2017
 *
 */
#ifndef INCLUDES_DMA_H_
#define INCLUDES_DMA_H_
#include <stdio.h>
#include <stdint.h>
#include "MKL25Z4.h"
#include "conversion.h"
#define DMA_DSR_BCR0_DONE (0x01000000)
#define DMA_CLOCK_DISABLE (0x7FFFFFFF)


/**
 * @brief A function to initialize the UART 
 *
 * This function initializes the dma for memmove and memset for 1,2,4 byte transfers. 
 *
 *
 */
void DMA_init();
/**
 * @brief A function for byte memmove transfer 
 *
 * This function uses DMA for memmove for byte transfers. 
 *
 * @param src: source
 * @param dst:destination
 * @param size :size
 * 
 */

void memmove_DMA_byte(uint8_t *src,uint8_t *dst, size_t length);
/**
 * @brief A function for byte memmove transfer 
 *
 * This function uses DMA for memmove for byte transfers. 
 *
 * @param src: source
 * @param dst:destination
 * @param size :size
 * 
 */
void memmove_DMA_halfword(uint16_t *src, uint16_t *dst, size_t length);
/**
 * @brief A function for byte memmove transfer 
 *
 * This function uses DMA for memmove for byte transfers. 
 *
 * @param src: source
 * @param dst:destination
 * @param size :size
 * 
 */
void memmove_DMA_word(uint32_t *src,uint32_t *dst, size_t length);
/**
 * @brief A function for byte memmove transfer 
 *
 * This function uses DMA for memmove for byte transfers. 
 *
 * @param src: source
 * @param dst:destination
 * @param size :size
 * 
 */-
void memzero_DMA_byte(uint8_t *src,uint32_t length);
/**
 * @brief A function for byte memmove transfer 
 *
 * This function uses DMA for memmove for byte transfers. 
 *
 * @param src: source
 * @param dst:destination
 * @param size :size
 * 
 */
void memzero_DMA_halfword(uint16_t *src,uint32_t length);
/**
 * @brief A function for byte memmove transfer 
 *
 * This function uses DMA for memmove for byte transfers. 
 *
 * @param src: source
 * @param dst:destination
 * @param size :size
 * 
 */

void memzero_DMA_word(uint32_t *src,uint32_t length);
/**
 * @brief A function for byte memmove transfer 
 *
 * This function uses DMA for memmove for byte transfers. 
 *
 * @param src: source
 * @param dst:destination
 * @param size :size
 * 
 */





#endif /* INCLUDES_DMA_H_ */
