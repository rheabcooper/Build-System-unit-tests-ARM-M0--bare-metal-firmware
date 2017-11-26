/**
 * @file spi.h
 * @brief This file contains the functions for SPI interface
 *			of the Freedom Freescale board.  
 *
 * These functions were originally developed by Brian Kelly.
 *
 * @author Brian Kelly 
 * @date November 24, 2017
 *
 */

#ifndef __SPI_H__
#define __SPI_H__

#ifdef KL25Z

#include <stdint.h>


void SPI_init();

void SPI_read_byte(uint8_t byte);

void SPI_write_byte(uint8_t byte);

void SPI_send_packet(uint8_t * p, size_t length);

void SPI_flush();

#endif

#endif /* __SPI_H__ */
