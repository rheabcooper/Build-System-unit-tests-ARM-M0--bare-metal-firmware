/**
 * @file uart.h
 * @brief A header file to configure the UART interface
 * 			with the Freedom Freescale board. 
 *
 * A header file containing functions to configure UART interface
 *	on the Freedom Freescale board.  
 *
 * This header file was all developed by Brian Kelly.
 *
 * @author Brian Kelly and Rhea Cooper
 * @date October 15, 2017
 *
 */

#ifndef __UART_H__
#define __UART_H__
#define MCGFLLCLK (0x04000000)
#define PTA1_ISFR_MASK (0x00000001) 
#define PTA2_ISFR_MASK (0x00000002)
#define OSR (15)
#define BAUD (115200)
#define CLOCK_FREQUENCY (41940000)
#define SBR  ((CLOCK_FREQUENCY/(OSR+1))/BAUD)
#define BDH (0x00)
#define BDL ((uint8_t)SBR)

/**
 * @brief A function to set up the UART interface on the KL25Z as per the project requirements to transmit and receive characters without the use of printf
 *
 * This function sets the baud rate to 115200 and initializes the required registers to certain values to enable transmit and receive.
 
 * 
 */

void UART_configure();

/**
 * @brief A function to send a single byte data down a uart device 
 *
 * This function takes in a pointer to the data to be sent through the UART.
 *
 * @param data-pointer to byte to be sent
 
 *
 * 
 */
void UART_send(uint8_t *data);
/**
 * @brief A function to send a single byte data down a uart device 
 *
 * This function takes in a pointer to the data to be received from the UART.
 *
 * @param data-pointer to byte to be received
 
 *
 * 
 */
void UART_receive(uint8_t *data);
/**
 * @brief A function to send a contiguous block of data down a uart
 *
 * This function takes in a pointer to the data to be sent and the number of bytes.
 *
 * @param data-pointer to data to be sent
 * @param count-number of bytes
 *
 * 
*/

void UART_send_n(uint32_t *data,uint32_t count);
/**
 * @brief A function to send a contiguous block of data down a uart
 *
 * This function takes in a pointer to the data to be received and the number of bytes.
 *
 * @param data-pointer to data to be received
 * @param count-number of bytes
 *
 * 
*/

void UART_receive_n(uint32_t *data,uint32_t count);
/**
 * @brief A function to handle UART interrupts
 *
 * This function needs to handle both transmit and receive interrupts and each interrupt should clear their associated flag if set.
 * 
 *
 * 
*/

void UART_IRQhandler();




#endif /* __UART_H__ */
