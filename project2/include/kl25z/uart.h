/**
 * @file uart.h
 * @brief A header file to configure the UART interface
 * 			with the Freedom Freescale board. 
 *
 * A header file containing functions to configure UART interface
 *	on the Freedom Freescale board.  
 *
 * This header file was originally developed by Rhea Cooper.  
 * Brian Kelly modified the functions and code to improve the 
 * UART interface from the host machine.  
 *
 * @author Brian Kelly and Rhea Cooper
 * @date October 24, 2017
 *
 */

#ifndef __UART_H__
#define __UART_H__
#include <stdio.h>
#include <stdint.h>
#include "MKL25Z4.h"
#include "cirbuf.h"
//#include "project2.h"

#define CLOCK_SETUP (1)
#define BAUD (115200)
#define OSR (16)
#define CLOCK_FREQUENCY (48000000)
#define SBR (((CLOCK_FREQUENCY)/(OSR))/(BAUD))

#define PTA1_ISFR_MASK (0x00000001) 
#define PTA2_ISFR_MASK (0x00000002)
uint8_t analyse;
uint32_t rec_data_count;
uint8_t rec_data;


/**
 * @brief A function to set up the UART interface on the KL25Z 
 *
 * This function sets the baud rate to 115200 and initializes the 
 * required registers to certain values to enable transmit and receive.
 * Per the project2 requirements, transmit and receive characters should 
 * function without the use of printf. 
 * 
 * @return void
 */
void UART_configure();

/**
 * @brief A function to send a single byte data on a uart device 
 *
 * This function takes in a pointer to the data to be sent through the UART.
 *
 * @param data - unsigned 8-bit pointer data to be sent 
 *
 * @return void
 */
void UART_send(uint8_t data);

/**
 * @brief A function to receive a single byte data from an UART interface 
 *
 * This function takes in a pointer to the data to be received from the UART.
 *
 * @param data - unsigned 8-bit pointer data to be received
 *
 * @return void 
 */
uint8_t UART_receive();

/**
 * @brief A function to send a contiguous block of data over the UART interface
 *
 * This function takes in a pointer to the data to be sent and the length of data.
 *
 * @param data - unsigned 32-bit pointer data to be sent
 * @param count - length of the data 
 *
 * @return void 
*/
void UART_send_n(uint8_t *data, uint8_t count);

/**
 * @brief A function to receive a contiguous block of data from the UART interface
 *
 * This function takes in a pointer to the data to be received and the length of data.
 *
 * @param data - unsigned 32-bit pointer data to be received
 * @param count - length of the data
 *
 * @return void
 */
void UART_receive_n(uint8_t *data, uint8_t count);

/**
 * @brief A function to handle UART interrupts
 *
 * This function needs to handle both transmit and receive interrupts 
 * and each interrupt should clear their associated flag if set.
 * 
 * @return void
 */
void UART0_IRQHandler();


#endif /* __UART_H__ */
