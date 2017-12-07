/*
 * nordic.c
 *
 *  Created on: Dec 5, 2017
 *      Author: rhco4796
 */

/*
 * nordic.c
 *
 *  Created on: Dec 3, 2017
 *      Author: rhco4796
 */

#include <stdio.h>
#include <stdint.h>
#include "nordic.h"
#include "spi.h"
#include "gpio.h"
//#include "MKL25Z4.h"
void nrf_read_register(uint8_t Register) {
	SPI_write_byte(R_REGISTER | Register);
}

void nrf_write_register(uint8_t Register, uint8_t value) {
	nrf_chip_enable();
	SPI_write_byte(W_REGISTER | Register);
	SPI_write_byte(value);
	nrf_chip_disable();
}

uint8_t nrf_read_status() {
	nrf_chip_enable();
	uint8_t value;
	nrf_read_register(STATUS1);
	value = SPI_write_byte(DUMMY);
	nrf_chip_disable();
	return value;
}


void nrf_write_config(uint8_t value) {

	nrf_chip_enable();
	uint8_t Register = CONFIG;
	nrf_write_register(Register, value);
	nrf_chip_disable();
}

/*Function to read from NRF CONFIG registerister*/
uint8_t nrf_read_config() {
	nrf_chip_enable();
	uint8_t value;
	nrf_read_register(CONFIG);
	value = SPI_write_byte(DUMMY);
	nrf_chip_disable();
	return value;
}
uint8_t nrf_read_rf_setup() {

	uint8_t value;
	nrf_chip_enable();
	nrf_read_register(RF_SETUP);
	value = SPI_write_byte(DUMMY);
	nrf_chip_disable();
	return value;
}


void nrf_write_rf_setup(uint8_t value){

	uint8_t Register = RF_SETUP;
	nrf_chip_enable();
	nrf_write_register(Register, value);
	nrf_chip_disable();
}

uint8_t nrf_read_rf_ch() {
	nrf_chip_enable();
	uint8_t value;
	nrf_read_register(RF_CH);
	value = SPI_write_byte(DUMMY);
	nrf_chip_disable();
	return value;
}


void nrf_write_rf_ch(uint8_t channel) {

	uint8_t Register = RF_CH;
	nrf_write_register(Register, channel);
}


uint8_t * nrf_read_TX_ADDR() {
	nrf_chip_enable();
	uint8_t i;
	nrf_read_register(TX_ADDR);
	for(i=0;i<5;i++)
	{
		txval[i] = SPI_write_byte(DUMMY);
	}
	nrf_chip_disable();
	return txval;
}


void nrf_write_TX_ADDR(uint8_t * tx_addr) {

	uint8_t Register = TX_ADDR;
	nrf_chip_enable();
	SPI_write_byte(W_REGISTER | Register);
	SPI_send_packet(tx_addr,5);
	nrf_chip_disable();
}


uint8_t nrf_read_fifo_status() {
	nrf_chip_enable();
	uint8_t value;
	nrf_read_register(FIFO_STATUS);
	value = SPI_write_byte(DUMMY);
	nrf_chip_disable();
	return value;
}


void nrf_flush_tx_fifo() {
	nrf_chip_enable();
	SPI_write_byte(FLUSH_TX);
	nrf_chip_disable();
}


void nrf_flush_rx_fifo() {
	nrf_chip_enable();
	SPI_write_byte(FLUSH_RX);
	nrf_chip_disable();
}


