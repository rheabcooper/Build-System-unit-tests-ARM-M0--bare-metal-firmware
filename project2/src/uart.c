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

#include "uart.h"

void UART_configure()
{
	SIM_SCGC4|=SIM_SCGC4_UART0_MASK;      /* enabling clock to UART0 */             
	SIM_SOPT2|=SIM_SCGC4_UART0_MASK & MCGFLLCLK;
	UART0_C2 = 0x00;
/*	UART0_BDH=BDH;
	UART0_BDL=BDL; */
	UART0_C4=UART0_C4_OSR_MASK & OSR;
	UART0_C1=0x00;
	UART0_C2=UART0_C2_TE_MASK|UART0_C2_RE_MASK|UART0_C2_RIE_MASK|UART0_C2_TIE_MASK;
	SIM_SCGC5|=SIM_SCGC5_PORTA_MASK;       /* enabling clock to Port A */ 
	PORTA_PCR1=0x02;         /* alternate function for PTA1 -UART0_RX */
	PORTA_PCR2=0x02;         /* alternate function for PTA1 -UART0_RX */
	NVIC->ISER[0] |= 0x00001000;
}

void UART_send(uint8_t *data)
{	
	while(!(UART0_S1 & UART0_S1_TDRE_MASK)){ }
	UART0_D = *data;
}

void UART_receive(uint8_t *data)
{	
	
	while(!(UART0_S1 & UART0_S1_RDRF_MASK)){ }
	*data=UART0_D;
}

void UART_send_n(uint32_t *data, uint32_t length)
{
	uint32_t i;

	for(i=0; i<=length; i++)
	{
		while(!(UART0_S1 & UART0_S1_TDRE_MASK)){ }
		UART0_D=*(data+i);
	}
	
}	

void UART_receive_n(uint32_t *data, uint32_t length)
{	
	uint32_t i;

	for(i=0; i<=length; i++)
	{
		while(!(UART0_S1 & UART0_S1_RDRF_MASK)){ }
		*(data+i)=UART0_D;
	}
}

void UART_IRQhandler()
{	
	__disable_irq(); /* global disable IRQs */
	if(0 != (UART0_C2 & UART0_C2_RIE_MASK))        
	{
		if(0 != (UART0_S1 & UART0_S1_RDRF_MASK))
		{
			/* UART_receive(); - will implement this later */  
		}
		UART0_C2 &= ~UART0_C2_RIE_MASK;	
	}
	//IF TDRE==1
	 else if(0 != (UART0_C2 & UART0_C2_TIE_MASK)) 
	{
		if(0 != (UART0_S1 & UART0_S1_TDRE_MASK))
		{
			/* UART_send(); - will implement this later */
		} 
		UART0_C2 &= ~UART0_C2_TIE_MASK;
	}	
	__enable_irq(); /* global disable IRQs */
	
}



	
