/**
 * @file logger.c 
 * @brief This file contains the function implementations 
 *         for printing data to the terminal
 *
 * @author Brian Kelly and Rhea Cooper
 * @date December 5, 2017
 *
 */

#include "logger.h"
/*
 * logger.c
 *
 *  Created on: Dec 3, 2017
 *      Author: rhco4796
 */



#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "cirbuf.h"
#include "logger_queue.h"
#include "logger.h"
#include "conversion.h"
#include "uart.h"
#include <time.h>
#include <sys/time.h>







void log_integer(uint32_t integer_value,uint8_t length)
{
uint8_t a[length];
uint8_t *strptr=a;

length=my_itoa(integer_value,strptr,BASE_10);

	while(*strptr!='\0')
	{
			CB_AddItem(CB_TX,strptr);
			strptr++;
	}
	uint8_t xyz;
		while(CB_TX->count!=0){
				CB_RemoveItem(CB_TX,&xyz);
				UART0_D=xyz;
	       		for (int i=200;i>0;i--);  //wait for it to get sent
				}

	/*To enable transmit interrupt*/
	//UART0_C2|=UART_C2_TIE_MASK;
}

/*to transmit a string from the UART of FRDM */
void log_string(uint8_t * data)
{
	while(*data!='\0')
	{
		CB_AddItem(CB_TX,data);
		data++;
	}
	/*To enable transmitter interrupt*/
	uint8_t xyz;
		while(CB_TX->count!=0){
				CB_RemoveItem(CB_TX,&xyz);
				UART0_D=xyz;
	       		for (int i=200;i>0;i--);  //wait for it to get sent
				}
}

void log_data(uint8_t * data,uint8_t length)
{
	while(*data!='\0')
	{
		CB_AddItem(CB_TX,data);
		data++;
	}
	/*Enable the transmit interrupt*/
	uint8_t xyz;
	while(CB_TX->count!=0){
			CB_RemoveItem(CB_TX,&xyz);
			UART0_D=xyz;
       		for (int i=200;i>0;i--);  //wait for it to get sent
			}
}


void log_data_host(uint8_t * data,uint8_t length)
{
		CB_AddItem(CB_TX,data);
		uint8_t data_rec;

		CB_RemoveItem(CB_TX,&data_rec);
		printf("%c", data_rec);

}

void log_string_host(uint8_t * data)
{
	while(*data!='\0')
	{
		CB_AddItem(CB_TX,data);
		data++;
	}

	uint8_t *print_value=NULL;
	while(CB_TX->count){
		CB_RemoveItem(CB_TX,print_value);
		printf("%u", *print_value);
		print_value++;
	}
}

void log_integer_host(int32_t integer_value,uint8_t length)
{
	uint8_t *char_value=NULL;
	/*Function to convert integer to ascii*/
	my_itoa(integer_value,char_value,BASE_10);
	CB_AddItem(CB_TX,char_value);  //add to circular buffer
	uint8_t *print_value=NULL;
	while(CB_TX->count){
		CB_RemoveItem(CB_TX,print_value);
		printf("%u", *print_value);
		print_value++;
	}

}

void flush()
{
	while(CB_TX->count)
	{
		/*Binary logger for system halted*/
		main_log->logid= SYSTEM_HALTED;
		main_log->loglength=0;
		log_item(main_log);
	}


}



