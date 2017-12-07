/*
 * nordic.h
 *
 *  Created on: Dec 5, 2017
 *      Author: rhco4796
 */

/*
 * nordic.h
 *
 *  Created on: Dec 3, 2017
 *      Author: rhco4796
 */

#ifndef INCLUDES_NORDIC_H_
#define INCLUDES_NORDIC_H_




#define DUMMY 					(0xFF)
#define RF_CHANNEL_VALUE 		(0x12) //RF channel frequency
#define RF_SETUP_VALUE 			(0x07) // 0 dBm RF Tx output, 1 Mbps data rate,LNA gain


#define R_REGISTER				(0x00)
#define W_REGISTER				(0x20)
#define R_RX_PAYLOAD			(0x61)
#define W_TX_PAYLOAD			(0xA0)
#define FLUSH_TX				(0xE1)
#define FLUSH_RX				(0xE2)
#define REUSE_TX_PL				(0xE3)
#define ACTIVATE				(0x50)
#define R_RX_PL_WID				(0x60)
#define W_ACK_PAYLOAD			(0xA8)
#define WR__TX_PAYLOAD_NOACK	(0xB0)
#define NOP						(0xFF)

/*NRF2401 Register map*/
#define CONFIG					(0x00)
#define EN_AA					(0x01)
#define EN_RXADDR				(0x02)
#define SETUP_AW				(0x03)
#define SETUP_RETR				(0x04)
#define RF_CH					(0x05)
#define RF_SETUP				(0x06)
#define STATUS1					(0x07)
#define OBSERVE_TX				(0x08)
#define CD						(0x09)
#define RX_ADDR_P0				(0x0A)
#define RX_ADDR_P1				(0x0B)
#define RX_ADDR_P2				(0x0C)
#define RX_ADDR_P3				(0x0D)
#define RX_ADDR_P4				(0x0E)
#define RX_ADDR_P5				(0x0F)
#define TX_ADDR					(0x10)
#define RX_PW_P0				(0x11)
#define RX_PW_P1				(0x12)
#define RX_PW_P2				(0x13)
#define RX_PW_P3				(0x14)
#define RX_PW_P4				(0x15)
#define RX_PW_P5				(0x16)
#define FIFO_STATUS				(0x17)
#define DYNPD					(0x1C)
#define FEATURE					(0x1D)


#define CONFIG_RESERVED			(0x80)
#define	CONFIG_MASK_RX_DR		(0x40)
#define	CONFIG_MASK_TX_DS		(0x20)
#define	CONFIG_MASK_MAX_RT		(0x10)
#define	CONFIG_EN_CRC			(0x08)
#define	CONFIG_CRCO				(0x04)
#define	CONFIG_PWR_UP			(0x02)
#define	CONFIG_PRIM_RX			(0x01)


uint8_t txval[5];


void nrf_write_register(uint8_t Register, uint8_t value);


void nrf_read_register(uint8_t Register);

uint8_t nrf_read_status();
uint8_t nrf_read_config();
uint8_t nrf_read_rf_setup();
void nrf_write_rf_setup(uint8_t value);
void nrf_write_config(uint8_t value);
uint8_t nrf_read_rf_setup();

uint8_t nrf_read_rf_ch();
void nrf_write_rf_ch(uint8_t channel);
uint8_t * nrf_read_TX_ADDR();
void nrf_write_TX_ADDR(uint8_t * tx_addr) ;
uint8_t nrf_read_fifo_status();





#endif /* INCLUDES_NORDIC_H_ */
