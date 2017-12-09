#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "cirbuf.h"
#include "logger_queue.h"
#include "logger.h"
#include "conversion.h"
#include <time.h>
#include <sys/time.h>
#include "MKL25Z4.h"
#define KL25Z





uint8_t logidstring[] = " Log ID:";
uint8_t payloadstring[]= " Payload:";
uint8_t timestampstring[] = " Timestamp:";


void create_log(Log_t * logger_ptr, log_id ID, uint8_t length, uint8_t *pl)
{
	logger_ptr->logid=ID;
	logger_ptr->loglength=length;
	logger_ptr->checksum=logger_ptr->logid ^ logger_ptr->loglength ;
#ifdef KL25Z
	logger_ptr->timestamp=RTC_TSR;
#endif
#ifdef BBB
	time_t seconds;
    seconds = time(NULL);
	logger_ptr->timestamp=seconds;
#endif
	logger_ptr->payload=(uint8_t*)malloc(length);
	for(int i=0;i<length;i++)
	{
		*(logger_ptr->payload+i)=*(pl+i);
		logger_ptr->checksum^=*(logger_ptr->payload);


	}



}

void destroy_log(Log_t *logger_ptr)
{
	free((void*)logger_ptr->payload);
	logger_ptr->payload=NULL;
	free((void*)logger_ptr);
	logger_ptr=NULL;
}

void log_item(Log_t * logger_ptr){
		uint8_t length1;
		uint8_t a1[length1];
		uint8_t *strptr1=a1;
		uint8_t space[]= "\n\r";
		log_data(space,sizeof(space));
		log_integer(logger_ptr->timestamp,11);

		log_data(logidstring,sizeof(logidstring));


		length1=my_itoa(logger_ptr->logid,strptr1,BASE_10);

			while(*strptr1!='\0')
			{
					CB_AddItem(CB_TX,strptr1);
					strptr1++;
			}
			/*To enable transmit interrupt*/
				UART0_C2|=UART_C2_TIE_MASK;

	if(logger_ptr->loglength!=0){
		log_data(logger_ptr->payload,logger_ptr->loglength);  // or use log_data
	}
}







