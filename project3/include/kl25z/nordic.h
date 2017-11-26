/**
 * @file nordic.h
 * @brief This file contains the functions for the Nordic RF device.  
 *
 * These functions were originally developed by Brian Kelly.
 *
 * @author Brian Kelly 
 * @date November 24, 2017
 *
 */

#ifndef __NORDIC_H__
#define __NORDIC_H__

#ifdef KL25Z

#include <stdint.h> 

/**
 * @brief A function to read the register and return the value
 *
 * @param register - unsigned 8-bit register type 
 *
 * @return value of the register
 */
uint8_t nrf_read_register(uint8_t register);

/**
 * @brief A function to write to the given register with the data
 *
 * @param register - unsigned 8-bit register type
 * @param value - unsigned 8-bit value to be written to the register
 *
 * @return void
 */
void nrf_write_register(uint8_t register, uint8_t value);

/**
 * @brief A function to read the STATUS register and return the value
 *
 * @return value of the STATUS register
 */
uint8_t nrf_read_status();

/**
 * @brief A function to write the value to the CONFIG register
 *
 * @param config - unsigned 8-bit config value 
 *
 * @return void
 */
void nrf_write_config(uint8_t config);

/**
 * @brief A function to read the CONFIG register
 *
 * @return value of the CONFIG register
 */
uint8_t nrf_read_config();

/**
 * @brief A function to read the SETUP register
 *
 * @return value of the SETUP register
 */
uint8_t nrf_read_rf_setup();

/**
 * @brief A function to write the value to the SETUP register
 *
 * @param config - unsigned 8-bit config value 
 *
 * @return void
 */
void nrf_write_rf_setup(uint8_t config);

/**
 * @brief A function to read the RF_CH register memory
 *
 * @return unsigned 8 bit integer value of the RF_CH register
 */
uint8_t nrf_read_rf_ch();

/**
 * @brief A function to write the value to the RF_CH register memory
 *
 * @param config - unsigned 8-bit channel value 
 *
 * @return void
 */
void nrf_write_rf_ch(uint8_t channel);

/**
 * @brief A function to read the 5 byte data from the TX_ADDR register memory
 *
 * @param address - unsigned 8-bit integer pointer to the memory address
 *
 * @return void
 */
void nrf_read_TX_ADDR(uint8_t * address);

/**
 * @brief A function to write 5 byte data to the TX_ADDR register memory
 *
 * @param address - unsigned 8-bit integer pointer TX memory address to be written
 *
 * @return void
 */
void nrf_write_TX_ADDR(uint8_t * tx_addr);

/**
 * @brief A function to read the FIFO_STATUS register memory
 *
 * @return unsigned 8 bit integer value of the FIFO_STATUS register memory
 */
uint8_t nrf_read_fifo_status();

/**
 * @brief A function to send the command FLUSH_TX
 *
 * @return void
 */
void nrf_flush_tx_fifo();

/**
 * @brief A function to send the command FLUSH_RX
 *
 * @return void
 */
void nrf_flush_rx_fifo();

#endif

#endif /* __NORDIC_H__ */
