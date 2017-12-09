/**
 * @file project3.h 
 * @brief This file is to be used to execute project 3.
 *
 * @author Brian Kelly
 * @date November 26, 2017
 *
 */

#ifndef __PROJECT3_H__
#define __PROJECT3_H__

/**
 * @brief function to run project3 materials
 * 
 * This function calls some various tests that we can run the profiling 
 * code and SPI demo sequence of commands to show this program can
 * read and write to the nRF device for the project 3. 
 *
 * @return void
 */
void project3(void);

#ifdef KL25Z
void LED_init(void);

void LED_set(int value);

void Profiler(void);
#endif



#endif /* __PROJECT3_H__ */
