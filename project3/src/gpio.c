/*
 * gpio.c
 *
 *  Created on: Dec 5, 2017
 *      Author: rhco4796
 */
/*
 * gpio.c
 *
 *  Created on: Dec 3, 2017
 *      Author: rhco4796
 */
#include <stdio.h>
#include <stdint.h>
#include "nordic.h"
#include "spi.h"
#include "gpio.h"

#include "logger_queue.h"

void GPIO_nrf_init(){
SIM->SCGC5	|=	0x1000;
SIM->SCGC5 |= 0x2000;//clock to port D
SIM->SCGC4  |= SIM_SCGC4_SPI0_MASK;


PORTD->PCR[5]	=	0x100;                   //CE is low by default

GPIOD_PDDR |= CE;					// Set the pins direction to output
GPIOD_PCOR |= CE;

PORTD_PCR0	=	0x100;                  //CS is high by default

GPIOD_PDDR |= CSN;					//Set the pins direction to output
GPIOD_PSOR |= CSN;

PORTE_PCR0	=	0x100;                  //interrupt

GPIOE_PDDR |= INTERRUPT;

PORTD->PCR[1]= 0x200;

	//Set as SPI0_MOSI
PORTD->PCR[2]= 0x200;

	//Set as SPI0_MISO
PORTD->PCR[3]= 0x200;



}

void GPIO_led_init(){
	SIM->SCGC5	|=	0x400;

	/*	enable	clock	to	Port	D	*/
	PORTB->PCR[18]	=	0x100;
	/*	make	PTB18	pin	as	GPIO	*/
	PTB->PDDR	|=	0x40000;							/*	make	PTB18	as	output	pin	*/
	PTB->PSOR	=	0x40000;
	/*	turn	off	red	LED	*/
	PORTB->PCR[19]	=	0x100;
	PTB->PDDR	|=	0x80000;
	/*	make	PTB19	as	output	pin	*/
	PTB->PSOR	=	0x80000;
	/*	turn	off	green	LED	*/


}





