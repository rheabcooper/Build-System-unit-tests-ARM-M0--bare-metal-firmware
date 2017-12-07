/*
 * spi.c
 *
 *  Created on: Dec 5, 2017
 *      Author: rhco4796
 */
/*
 * spi.c
 *
 *  Created on: Dec 3, 2017
 *      Author: rhco4796
 */
#include <stdio.h>
#include <stdint.h>
#include "nordic.h"
#include "spi.h"
#include "gpio.h"



void SPI_init(){

	GPIO_nrf_init();
	SPI0_C1 = SPI_C1_MSTR_MASK;

	//Make Master SS pin to select slave output
	SPI0_C2 = SPI_C2_MODFEN_MASK;
	SPI0_BR = (SPI_BR_SPPR(0x02) | SPI_BR_SPR(0x01)); //Set Bitrate to 1Mbps

	//Enable SPI0
	SPI0_C1 |= SPI_C1_SPE_MASK;
}
void SPI_read_byte(uint8_t * byte){
	while(!(SPI0->S & SPI_S_SPRF_MASK)){}
	*byte = SPI0->D;
}

uint8_t SPI_write_byte(uint8_t byte) {
	uint8_t dummy;
	while(!(SPI0->S & SPI_S_SPTEF_MASK)) { } /* wait until tx ready */
	SPI0->D = byte; /* send data byte */
	while(!(SPI0->S & SPI_S_SPRF_MASK)) { } /* wait until tx complete */
	dummy = SPI0->D; /* clear SPRF */
	return dummy;
}

void SPI_send_packet(uint8_t * p, size_t length){

	for(int i=0;i<length;i++){
		SPI_write_byte(*(p+i));
	}
}

/*Function to block till SPI transmit buffer is empty*/
void SPI_flush(){
	while(!(SPI0->S & SPI_S_SPTEF_MASK)){}
}



