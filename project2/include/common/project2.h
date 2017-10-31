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
#include "uart.h"
#include "MKL25Z4.h"

uint32_t CB_TX_length=576;
uint32_t CB_RX_length=16;
int32_t alphabets = 0;
int32_t numbers = 0;
int32_t punctuations = 0;
int32_t misc = 0;
uint8_t string_for_alp[]="Number of alphabets is : \n\r";
uint8_t string_for_num[]="Number of numbers is : \n\r";
uint8_t string_for_punc[]="Number of punctuations is : \n\r";
uint8_t string_for_misc[]="Number of miscellaneous characters is : \n\r";

/*Variable which states the length of buffer*/
uint32_t  buffer_length=16;

/*global variables that will be used in uart.c and project2.c */
uint32_t rec_data_count=0;
uint8_t rec_data;
uint8_t analyse=0;

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
