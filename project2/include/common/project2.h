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
void project2(void);

#endif /* __PROJECT2_H__ */
