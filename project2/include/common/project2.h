/**
 * @file project2.h 
 * @brief This file is to be used to execute project 2.
 *
 * @author Brian Kelly
 * @date October 15, 2017
 *
 */

#ifndef __PROJECT2_H__
#define __PROJECT2_H__

#include "common.h"
#include "cirbuf.h"
#include "conversion.h"

/* For KL25Z platform specific header files */
#ifdef KL25Z
#include "uart.h"
#include "MKL25Z4.h"
#endif

/**
 * @brief A function to transfer an integer from the FRDM to the terminal by converting to ascii
 *
 * This function takes the integer value as a parameter
 *
 * @param integer_value : the integer to be converted to a parameter value 
 *
 */
void transmit_integer(int32_t integer_value);
/**
 * @brief A function to transfer a string from the FRDM to the terminal
 *
 * This function takes a pointer to the string as a parameter
 *
 * @param *data : pointer to the string
 *
 */
void transmit_string(uint8_t * data);
/**
 * @brief A function to transfer a character from the FRDM to the terminal by converting to ascii
 *
 * This function takes the character value as a parameter
 *
 * @param integer_value : the char to be transmitted 
 *
 */
void transmit_char(uint8_t * data);
/**
 * @brief A function to transfer an integer from the FRDM to the terminal by converting to ascii
 *
 * This function takes the integer value as a parameter
 *
 * @param integer_value : the integer to be converted to a parameter value 
 *
 */

void transmit_char_host(uint8_t * data);
/**
 * @brief A function to transfer an integer from the FRDM to the terminal by converting to ascii
 *
 * This function takes the integer value as a parameter
 *
 * @param integer_value : the integer to be converted to a parameter value 
 *
 */

void transmit_string_host(uint8_t * data);
/**
 * @brief A function to transfer a sstring from the FRDM to the host or BBB
 *
 * This function takes a pointer to string
 *
 * @param integer_value : pointer to string
 *
 */
void transmit_integer_host(int32_t integer_value);
/**
 * @brief A function to categorize the received character into an alphabet,a number or a punctuation
 *
 */
void data_analysis();
/**
 * @brief A function to display the analysis on the terminal once the rx buffer is full
 *
 */
void dump_stats();

/**
 * @brief function to run project2 materials
 * 
 * This function calls some various tests that we can run to test 
 * the circular buffer and uart code for the project 2. 
 *
 * @return void
 */
void project2(void);

#endif /* __PROJECT2_H__ */
