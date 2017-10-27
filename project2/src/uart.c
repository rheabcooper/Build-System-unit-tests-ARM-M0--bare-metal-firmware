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
#include "cirbuf.h"

void UART_configure()
{
	/* enabling clock to Port A */
	SIM_SCGC5 |= SIM_SCGC5_PORTA_MASK;

	/* enabling clock to UART0 */
	SIM_SCGC4 |= SIM_SCGC4_UART0_MASK;
	SIM_SOPT2 &= ~SIM_SOPT2_UART0SRC_MASK;

	/* FLL/PLL source to select 48 Mhz clock */
	SIM_SOPT2 |= SIM_SOPT2_UART0SRC((CLOCK_SETUP));

	UART0_C2 = 0x00;
	UART0_C1 = 0x00;
	UART0_C3 = 0x00;
	UART0_S2 = 0x00;

	UART0_BDH = (SBR >> 8) & UARTLP_BDH_SBR_MASK;
	UART0_BDL = (SBR & UARTLP_BDL_SBR_MASK);
	UART0_C4  = UARTLP_C4_OSR(OSR - 1);

	PORTA_PCR1 = PORT_PCR_MUX(2);         /* alternate function for PTA1 -UART0_RX */
	PORTA_PCR2 = PORT_PCR_MUX(2);         /* alternate function for PTA1 -UART0_RX */

	/* enabling the transmitting, receiving, and receive/transmit interrupts */
	UART0_C2 = UART0_C2_TE_MASK | UART0_C2_RE_MASK | UART0_C2_RIE_MASK | UART0_C2_TIE_MASK;

	/* Interrupt enabling */
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
			UART0_D = UART_receive_n(data, length);
		}
		UART0_C2 &= ~UART0_C2_RIE_MASK;	
	}
	//IF TDRE==1
	 else if(0 != (UART0_C2 & UART0_C2_TIE_MASK)) 
	{
		if(0 != (UART0_S1 & UART0_S1_TDRE_MASK))
		{
			UART_send_n(data, UART0_D);
		} 
		UART0_C2 &= ~UART0_C2_TIE_MASK;
	}	
	__enable_irq(); /* global disable IRQs */
	
}



	
