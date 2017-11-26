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

void GPIO_nrf_init();

#endif

#endif /* __GPIO_H__ */
