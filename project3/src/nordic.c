/**
 * @file uart.c 
 * @brief This file contains the functions for the Nordic RF device.  
 *
 * These functions were originally developed by Brian Kelly.
 *
 * @author Brian Kelly 
 * @date November 24, 2017
 *
 */

#ifdef KL25Z

#include "nordic.h"
#include "spi.h"

uint8_t nrf_read_register(uint8_t register)
{
	return 0;
}

void nrf_write_register(uint8_t register, uint8_t value)
{

}

uint8_t nrf_read_status()
{
	return 0;
}

void nrf_write_config(uint8_t config)
{

}

uint8_t nrf_read_config()
{
	return 0;
}

uint8_t nrf_read_rf_setup()
{
	return 0;
}

void nrf_write_rf_setup(uint8_t config)
{

}

uint8_t nrf_read_rf_ch()
{
	return 0;
}

void nrf_write_rf_ch(uint8_t channel)
{

}

void nrf_read_TX_ADDR(uint8_t * address)
{

}

void nrf_write_TX_ADDR(uint8_t * tx_addr)
{

}

uint8_t nrf_read_fifo_status()
{

}

void nrf_flush_tx_fifo()
{

}

void nrf_flush_rx_fifo()
{

}

#endif
