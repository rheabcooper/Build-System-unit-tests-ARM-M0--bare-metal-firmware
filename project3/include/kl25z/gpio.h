/**
 * @file gpio.h 
 * @brief This file contains the functions for initializng 
 *        the GPIO pins associated with the NRF and SPI devices.  
 *
 * These functions were originally developed by Brian Kelly 
 *
 * @author Brian Kelly 
 * @date November 26, 2017
 *
 */

#ifndef __GPIO_H__
#define __GPIO_H__

#ifdef KL25Z

/**
 * @brief A function to initialize the GPIO pins
 *
 * A function to initialize the GPIO pins associated
 *  with the NRF and SPI devices
 *
 * @return void
 */
void GPIO_nrf_init(void);

#endif

#endif /* __GPIO_H__ */
