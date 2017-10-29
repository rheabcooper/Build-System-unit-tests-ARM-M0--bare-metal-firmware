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

uint8_t rec_data;
uint32_t rec_data_count = 0;
uint8_t analyse = 0;

/**
 * @brief function to run project2 materials
 * 
 * This function calls some various tests that we can run to test 
 * the circular buffer and uart code for the project 2. 
 *
 * @return void
 */

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



void transmit_integer(int32_t integer_value);
void transmit_string(uint8_t * data);
void transmit_char(uint8_t * data);
void transmit_char_host(uint8_t * data);
void transmit_string_host(uint8_t * data);
void transmit_integer_host(in32_t integer_value);
void data_analysis();

void project2(void);

#endif /* __PROJECT2_H__ */
