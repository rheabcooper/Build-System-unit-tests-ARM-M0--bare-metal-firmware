/*
 * spi.h
 *
 *  Created on: Dec 5, 2017
 *      Author: rhco4796
 */
/*
 * spi.h
 *
 *  Created on: Dec 3, 2017
 *      Author: rhco4796
 */

#ifndef INCLUDES_SPI_H_
#define INCLUDES_SPI_H_


#include <stdint.h>
#include <stdio.h>
#include <MKL25Z4.h>
#define CE (1<<5)
#define nrf_transmit_enable()	(GPIOD_PSOR = CE)       //ce should be 1 to enable tx rx
#define nrf_transmit_disable() 	(GPIOD_PCOR = CE)

#define CSN (1<<0)
#define nrf_chip_enable() 		(GPIOD_PCOR = CSN)  // csn is active low
#define nrf_chip_disable()		(GPIOD_PSOR = CSN)

#define INTERRUPT (1<<0)

void SPI_init();

/************************************************************
* SPI_read_byte() - Function to read a single byte
* uint8_t * byte - Pointer to the location where returned
* 				   data is to be stored
*************************************************************/
void SPI_read_byte(uint8_t * byte);

/************************************************************
* SPI_write_byte() - Function to write a single byte
* uint8_t byte - Data byte to be written
* uint8_t (return) - Value returned after writing DUMMY byte
*************************************************************/
uint8_t SPI_write_byte(uint8_t byte);

/************************************************************
* SPI_send_packet() - Function to send an array of data
* uint8_t * p - Pointer to the data array that is to be sent
* size_t length - Length of the packet
*************************************************************/
void SPI_send_packet(uint8_t * p, size_t length);

/************************************************************
* SPI_flush() - Function to block until transmit buffer is
* 				empty
*************************************************************/
void SPI_flush();




#endif /* INCLUDES_SPI_H_ */


