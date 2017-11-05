/**
 * @file uart.c 
 * @brief This file contains the functions for UART interface
 *			of the Freedom Freescale board.  
 *
 * These functions were originally developed by Rhea Cooper
 *  and Brian Kelly modified and improved the code.  
 *
 * @author Brian Kelly and Rhea Cooper
 * @date October 24, 2017
 *
 */

#ifdef KL25Z

#include "uart.h"

void UART_configure()
{
	/* enabling clock to Port A */
	SIM->SCGC5 |= 0x0200;

	/* enabling clock to UART0 */
	SIM->SCGC4 |= 0x400;

	/* FLL/PLL source to select 40 Mhz clock */
	SIM->SOPT2 |= 0x04000000;

	UART0->C2 = 0;
	UART0->C4 = 0x0F;
	UART0->C1 = 0;

	UART0->BDH = 0x00;
	UART0->BDL = 0x17;

	/* set pins to uart0 RX/RX */
	PORTA->PCR[1] |= 0x0200;         
	PORTA->PCR[2] |= 0x0200;  

	/* enabling the transmitting, receiving, and receive/transmit interrupts */
	UART0_C2 = UART0_C2_TE_MASK | UART0_C2_RE_MASK | UART0_C2_RIE_MASK;

	/* Interrupt enabling */
	/* This is for loop should be replaced. */
	/* By default this loop allows single stepping */
	NVIC_ISER[0] |= 0x00001000;
}

void UART_send(uint8_t data)
{	
	while(!(UART0_S1 & UART0_S1_TDRE_MASK)){ }
	UART0_D = data;
}

uint8_t UART_receive()
{	
	uint8_t c;
	while(!(UART0_S1 & UART0_S1_RDRF_MASK)){ }
	c=UART0_D;
	return c;
}

void UART_send_n(uint8_t *data, uint8_t count)
{
	for(uint8_t i=0;i<=count;i++)
	{
		while(!(UART0_S1 & UART0_S1_TDRE_MASK)){ }
		UART0_D=*(data+i);
	}
	
}	

void UART_receive_n(uint8_t *data, uint8_t count)
{	
	for(uint8_t i=0;i<=count;i++)
	{
		while(!(UART0_S1 & UART0_S1_RDRF_MASK)){ }
		*(data+i)=UART0_D;
	}
}


#endif /* ifdef KL25Z */
