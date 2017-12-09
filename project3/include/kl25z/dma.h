/*
 * dma.h
 *
 *  Created on: Nov 16, 2017
 *      Author: rhco4796
 */

#ifndef INCLUDES_DMA_H_
#define INCLUDES_DMA_H_
#include <stdio.h>
#include <stdint.h>
#include "MKL25Z4.h"
#include "conversion.h"
#define DMA_DSR_BCR0_DONE (0x01000000)
#define DMA_CLOCK_DISABLE (0x7FFFFFFF)

void DMA_init();
void memmove_DMA_byte(uint8_t *src,uint8_t *dst, size_t length);
void memmove_DMA_halfword(uint16_t *src, uint16_t *dst, size_t length);
void memmove_DMA_word(uint32_t *src,uint32_t *dst, size_t length);
void memzero_DMA_byte(uint8_t *src,uint32_t length);
void memzero_DMA_halfword(uint16_t *src,uint32_t length);
void memzero_DMA_word(uint32_t *src,uint32_t length);






#endif /* INCLUDES_DMA_H_ */
