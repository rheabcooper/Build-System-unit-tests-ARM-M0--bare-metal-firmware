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

/**
 * @brief A function to initialize the SPI controller
 *
 * A function to initialize the SPI controller
 *
 * @return void
 */
void SPI_init(void);

/**
 * @brief A function to read a single byte data from the SPI bus
 *
 * @param byte - unsigned 8-bit byte data to be read 
 *
 * @return void
 */
void SPI_read_byte(uint8_t byte);

/**
 * @brief A function to send a single byte data on the SPI bus
 *
 * @param byte - unsigned 8-bit byte data to be sent 
 *
 * @return void
 */
void SPI_write_byte(uint8_t byte);

/**
 * @brief A function to send numerous bytes on the SPI bus
 *
 * @param byte - unsigned 8-bit pointer to a byte array 
 * @param length - a length of how many bytes to send 
 *
 * @return void
 */
void SPI_send_packet(uint8_t * p, size_t length);

/**
 * @brief A function to block until SPI transmit buffer has completed transmitting
 *
 * @return void
 */
void SPI_flush();

#endif

#endif /* __SPI_H__ */
