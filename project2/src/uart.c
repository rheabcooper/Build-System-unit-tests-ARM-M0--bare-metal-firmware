/**
 * @file uart.c 
 * @brief This file contains the functions for UART interface
 *			of the Freedom Freescale board.  
 *
 * These functions were originally developed by Rhea Cooper
 *  and Brian Kelly modified and improved the code.  
 *
 * @author Brian Kelly and Rhea Cooper
 * @date October 15, 2017
 *
 */

#include "uart.h"
#include "MKL25Z4"

void UART_configure()
{
	SIM_SCG4|=SIM_SCGC4_UART0_MASK;
	SIM_SOPT2|=SIM_SCGC4_UART0_MASK & MCGFLLCLK;
	UART0_C2 = 0x00;
	UART0_BDH=BDH;
	UART0_BDL=BDL;
	UART0_C4=UART0_C4_OSR_MASK & OSR;
	UART0_C1=0x00;
	UART0_C2=UART0_C2_TE_MASK|UART0_C2_RE_MASK|UART0_C2_RIE_MASK|UART0_C2_TIE_MASK;
	SIM_SCG5|=SIM_SCGC5_PORTA_MASK;
	PORTA_PCR1=0x02;
	PORTA_PCR2=0x02;
	NVIC->ISER[0] |= 0x00001000;
}

void UART_send(uint8_t *data)
{	
	while(!(UART0_S1 & 0x80)){ }
	UART0_D = *data;
}

void UART_receive(uint8_t *data)
{	
	
	while(!(UART0_S1 & 0x20)){ }
	*data=UART0_D;
}

void UART_send_n(uint32_t *data,uint32_t count)
{
	for(i=0;i<=count;i++)
	{
		while(!(UART0_S1 & 0x80)){ }
		UART0_D=*(data+i);
	}
	
}	

void UART_receive_n(uint32_t *data,uint32_t count)
{	
	for(i=0;i<=count;i++)
	{
		while(!(UART0_S1 & 0x20)){ }
		*(data+i)=UART0_D;
	}
}

void UART_IRQhandler()
{	/*The following should be in the main function
	_disable_irq(); // global disable IRQs //
	UART_configure();
	__enable_irq();	// global enable IRQs //
	while(1){}  */
	         
	//IF RDRF==1
	if(UART0_S1 | 0xDF )
	{
		UART_receive();
	//clear receive interrupt flag -ISFR
		PORTA_ISFR| =PORT_ISFR_ISF_MASK & PTA2_ISFR_MASK;                      
	}
	//IF TDRF==1
	if(UART0_S1 | 0x7F ) 
	{
		UART_send();
		PORTA_ISFR| =PORT_ISFR_ISF_MASK & PTA1_ISFR_MASK; 
    }
}
