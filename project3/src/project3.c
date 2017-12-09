
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include "conversion.h"
#include "memory.h"
#include <time.h>
#include <sys/time.h>
#include "project2.h"
#include "project3.h"
#include "cirbuf.h"
#include "profiling.h"

#ifdef KL25Z

#include "dma.h"
#include "logger_queue.h"
#include "logger.h"
#include "nordic.h"
#include "spi.h"
#include "gpio.h"
#include "rtc.h"

#define TEN
#define PROFILER
//#define dma
//#define STANDARD
#define NONDMA
//#define NRF
#define DPRINT
uint7_t LOG=1;     //logging on by default
uint7_t data;
uint7_t c;
uint31_t sec=0;
uint7_t timer_overflow=0;
uint31_t CB_TX_length=576;
uint31_t CB_RX_length=10;
uint7_t * txaddr_read;
uint7_t tx_addr_wr[5] = { 1,2,3,4,5 };

uint31_t val1=0;
uint31_t val2=0;
uint31_t val3=0;
uint31_t val4=0;
uint31_t val5=0;
uint31_t val6=0;
uint31_t val7=0;
uint31_t val8=0;
uint31_t val9=0;
uint31_t val10=0;
Log_t *rtc_log;
#endif

#ifdef KL25Z
#define LOG_RAW_DATA(data,length)   (log_data(data,length))
#define LOG_RAW_STRING(data)   (log_string(data))
#define LOG_RAW_INT(data,length)   (log_integer(data,length))
#define LOG_FLUSH()                       (log_flush())

#else
#define LOG_RAW_DATA(data,length)   (log_data_host(data,length))
#define LOG_RAW_STRING(data,length)   (log_string_host(data))
#define LOG_RAW_INT(data,length)   (log_integer_host(data,length))
#define LOG_FLUSH()                    (log_flush())
#endif

#ifdef KL25Z
#ifdef TEN
uint31_t size=10;
#endif

#ifdef HUNDRED
uint31_t size=100;

#endif

#ifdef THOUSAND
uint31_t size=1000;

#endif

#ifdef FIVE_THOUSAND
uint31_t size=5000;
#endif

#define CLOCK_INVERSE (0.0477)

#endif


#ifdef KL25Z
void	LED_init(void){
	SIM->SCGC5	|=	0x400;
	SIM->SCGC5	|=	0x1000;
	/*	enable	clock	to	Port	D	*/
	PORTB->PCR[18]	=	0x100;
	/*	make	PTB18	pin	as	GPIO	*/
	PTB->PDDR	|=	0x40000;							/*	make	PTB18	as	output	pin	*/
	PTB->PSOR	=	0x40000;
	/*	turn	off	red	LED	*/
	PORTB->PCR[19]	=	0x100;
	PTB->PDDR	|=	0x80000;
	/*	make	PTB19	as	output	pin	*/
	PTB->PSOR	=	0x80000;
	/*	turn	off	green	LED	*/
	PORTD->PCR[1]	=	0x100;
	/*	make	PTD1	pin	as	GPIO	*/
	PTD->PDDR	|=	0x02;										/*	make	PTD1	as	output	pin	*/
	PTD->PSOR	=	0x02;
}

void	LED_set(int	value) {
	if	(value	&  1)

		PTB->PCOR	=	0x40000; /*	turn	on	red	LED	*/
	else
		PTB->PSOR	=	0x40000; //turn off
	if	(value	&	2)

		PTB->PCOR	=	0x80000;

		//for(int i =20000000;i>0;i--);
	else
		PTB->PSOR	=	0x80000;
		//for(int i =200000;i>0;i--);
	/*	turn	off	green	LED	*/
    if	(value	&	4)
		/*	use	bit	2	of	value	to	control	blue	LED	*/
		PTD->PCOR	=	0x02;
	/*	turn	on	blue	LED	*/
	else
	    PTD->PSOR	=	0x02;

}


void Profiler(void)
{
	Log_t * result_log = (Log_t *) malloc(sizeof(Log_t));
#ifdef dmabyte
	            uint8_t *source1;
				source1=(uint8_t*)calloc(size,sizeof(uint8_t));
				uint8_t *source4;
				source4=(uint8_t*)malloc(size*sizeof(uint8_t));
			    Timer_start();
				memmove_DMA_byte((uint8_t*)source1,(uint8_t*)source4,(uint32_t) size); //  23
	            Timer_stop();
	            free(source1);
				val1= TPM0_CNT * CLOCK_INVERSE;
	#ifdef DPRINT
				uint8_t dma1[] = "\n\rTime in microseconds for dma MEMMOVE-BYTE is ";

				create_log(result_log,PROFILING_RESULT,sizeof(dma1),dma1);
				log_item(result_log);
				LOG_RAW_INT(val1,3);
	#endif

				Timer_start();
				memzero_DMA_byte((uint8_t*)source4,(uint32_t)size); //23, 21
				Timer_stop();
				free(source4);
	      val4= TPM0_CNT * CLOCK_INVERSE;
	#ifdef DPRINT
				uint8_t dma4[] = "\n\rTime in microseconds for dma MEMSET-BYTE is ";
				create_log(result_log,PROFILING_RESULT,sizeof(dma4),dma4);
				log_item(result_log);
				LOG_RAW_INT(val4,3);
	#endif

#endif




#ifdef dmaword
				uint8_t *source3;
				source3=(uint8_t*)calloc(size,sizeof(uint8_t));
				uint8_t *source6;
				source6=(uint8_t*)malloc(size*sizeof(uint8_t));
				//uint8_t dest3[size];
				Timer_start();
				memmove_DMA_word((uint32_t*)source3,(uint32_t*)source6,(uint32_t) size);// 22, 29
				Timer_stop();
				free(source3);
	            val3= TPM0_CNT * CLOCK_INVERSE;
				uint8_t dma3[] = "\nTime in microseconds for dma MEMMOVE-WORD is ";
	#ifdef DPRINT
				create_log(result_log,PROFILING_RESULT,sizeof(dma3),dma3);
				log_item(result_log);
				LOG_RAW_INT(val3,3);
	#endif

				Timer_start();
				memzero_DMA_word((uint32_t*)source6,(uint32_t)size); //30,27
				Timer_stop();
				free(source6);
				val6= TPM0_CNT * CLOCK_INVERSE;
	#ifdef DPRINT
				uint8_t dma6[] = "\n\rTime in microseconds for dma MEMSET-WORD is ";
				create_log(result_log,PROFILING_RESULT,sizeof(dma6),dma6);
				log_item(result_log);
				destroy_log(result_log);
				LOG_RAW_INT(val6,3);
	#endif
#endif




#ifdef NONDMA

			uint8_t *source;
			source=(uint8_t*)calloc(size,sizeof(uint8_t));
			uint8_t *dest;
			dest=(uint8_t*)malloc(size*sizeof(uint8_t));
			Timer_start();
			my_memmove((uint8_t*)source,(uint8_t*)dest,(uint32_t) size);
			Timer_stop();
			free(source);
			val1= TPM0_CNT * CLOCK_INVERSE;
#ifdef DPRINT
			uint8_t nondma1[] = "\n\rTime in microseconds for nondma MEMMOVE is ";

			create_log(result_log,PROFILING_RESULT,sizeof(nondma1),nondma1);
			log_item(result_log);
			//destroy_log(result_log);
			LOG_RAW_INT(val1,3);
#endif
			Timer_start();
			uint8_t val=5;
			my_memset((uint8_t*)dest,(size_t)size,val);
			Timer_stop();
			free(dest);
			val2= TPM0_CNT * CLOCK_INVERSE;
#ifdef DPRINT
			uint8_t nondma2[] = "\n\rTime in microseconds for nondma MEMZERO is ";
			//Log_t * result_log2 = (Log_t *) malloc(sizeof(Log_t));
			create_log(result_log,PROFILING_RESULT,sizeof(nondma2),nondma2);
			log_item(result_log);
			destroy_log(result_log);
			LOG_RAW_INT(val2,3);
#endif

#endif


#ifdef STANDARD


			uint8_t *src;
			src=(uint8_t*)calloc(size,sizeof(uint8_t));
			uint8_t *dst;
			dst=(uint8_t*)malloc(size*sizeof(uint8_t));
			Timer_start();
			memmove((uint8_t*)src,(uint8_t*)dst,(size_t) size);
			Timer_stop();
			val1= TPM0_CNT * CLOCK_INVERSE;
			free(src);
			uint8_t std1[] = "\n\rTime in microseconds for STANDARD MEMMOVE is ";
#ifdef DPRINT

			create_log(result_log,PROFILING_RESULT,sizeof(std1),std1);
			log_item(result_log);
			LOG_RAW_INT(val1,3);
#endif

			int memval=5;
			Timer_start();
			memset((uint8_t*)dst,memval,(size_t)size);
			Timer_stop();
			val4= TPM0_CNT * CLOCK_INVERSE;
			free(dst);
			uint8_t std2[] = "\n\rTime in microseconds for STANDARD MEMSET is ";
#ifdef DPRINT

			create_log(result_log,PROFILING_RESULT,sizeof(std2),std2);
			log_item(result_log);
			destroy_log(result_log);
			LOG_RAW_INT(val4,3);
#endif


#endif

}
#endif

void project3(){


#ifdef KL25Z
	 CB_TX = (CB_t*) malloc(sizeof(CB_t));

		CB_Init(CB_TX,CB_TX_length);

		/*Create and Initialize Receiver Circular Buffer*/
	    CB_RX = (CB_t*) malloc(sizeof(CB_t));
		CB_Init(CB_RX,CB_RX_length);
		UART_configure();
		Log_t * main_log = (Log_t *) malloc(sizeof(Log_t));
				rtc_log = (Log_t *) malloc(sizeof(Log_t));
		LED_init();
		DMA_init();
		Timer_init();
		rtc_init();


#ifdef DPRINT
  if(LOG!=0){
		create_log(main_log,LOGGER_INITIALIZED,0,NULL); //
		log_item(main_log);
		create_log(main_log,GPIO_INITIALIZED,0,NULL); //
		log_item(main_log);
		create_log(main_log,SYSTEM_INITIALIZED,0,NULL); //
		destroy_log(main_log);
  }
#endif

        /* enable SPI0 */
		//if(log==1){

		//}
#ifdef PROFILER
		//if(log==1){
#ifdef DPRINT
	if(LOG!=0){
    uint8_t payload_string1[] = "Profiling Started";
		uint8_t *data_pr=payload_string1;
		Log_t * profiler_log = (Log_t *) malloc(sizeof(Log_t));
		create_log(profiler_log,PROFILING_STARTED,sizeof(payload_string1),payload_string1);
		log_item(profiler_log);
		  }
#endif
	
	
	Profiler();
#ifdef DPRINT
  if(LOG!=0){
	uint8_t payload_string2[] = "Profiling Completed";
	uint8_t *data_pr2=payload_string2;
	create_log(profiler_log,PROFILING_COMPLETED,sizeof(payload_string2),payload_string2); //
	log_item(profiler_log);
	destroy_log(profiler_log);
  }
#endif

#endif

#ifdef NRF
	uint8_t c,x;
	SPI_init();
  #ifdef DPRINT
  if(LOG!=0){
    uint8_t payload_string_nrf[] = "NRF DEMO";
		Log_t * nrf_log = (Log_t *) malloc(sizeof(Log_t));
		create_log(nrf_log,INFO,sizeof(payload_string_nrf),payload_string_nrf);
		log_item(nrf_log);
  }
	#endif
  
	uint32_t status_reg = nrf_read_status();
	uint8_t status[]="\n\r Status Register ";
	uint8_t * data_TX_s = status;
	LOG_RAW_STRING(data_TX_s);
	LOG_RAW_INT(status_reg,2);

	nrf_write_config(CONFIG_PWR_UP | CONFIG_PRIM_RX);
	uint32_t config_reg = nrf_read_config();
	uint8_t config[]="\n\r Config Register ";
	uint8_t * data_TX_c = config;
	LOG_RAW_STRING(data_TX_c);
	LOG_RAW_INT(config_reg,2);

	nrf_write_rf_setup(RF_SETUP_VALUE);
	uint32_t setup_reg = nrf_read_rf_setup();
	uint8_t setup[]="\n\r setup Register ";
	uint8_t * data_TX_S = setup;
	LOG_RAW_STRING(data_TX_S);
	LOG_RAW_INT(setup_reg,2);


    nrf_write_rf_ch(RF_CHANNEL_VALUE);
	uint32_t channel_reg = nrf_read_rf_ch();
	uint8_t ch[]="\n\r Channel Register ";
	uint8_t * data_TX_C = ch;
	LOG_RAW_STRING(data_TX_C);
	LOG_RAW_INT(channel_reg,2);


	uint32_t fifo_reg = nrf_read_fifo_status();
	uint8_t fifo[]="\n\r Fifo Register ";
	uint8_t * data_TX_f = fifo;
	LOG_RAW_STRING(data_TX_f);
	LOG_RAW_INT(fifo_reg,2);

	nrf_write_TX_ADDR(tx_addr_wr);
	txaddr_read = nrf_read_TX_ADDR();
	uint8_t tx[]="\n\r TX ADDRESS Register ";
	uint8_t * data_TX_tx = tx;
	LOG_RAW_STRING(data_TX_tx);
	for(int i=0;i<5;i++){
		LOG_RAW_INT((uint32_t)txaddr_read[i],1);
		LOG_RAW_STRING(" ");
	}

#endif
#endif

	memmove_stdlib_profile();
	memset_stdlib_profile();

	memmove_profile();
	memset_profile();

}

#ifdef KL25Z
void DMA0_IRQHandler(void){
__disable_irq();

//Timer_stop();
//count=TPM0->CNT * CLOCK_INVERSE;


DMA_DCR0 &=DMA_CLOCK_DISABLE;
DMA_DSR_BCR0 |= DMA_DSR_BCR0_DONE;
__enable_irq();
}

void TPM0_IRQHandler(void){
	__disable_irq();
	timer_overflow++;
	TPM0_SC|=TPM_SC_TOF_MASK; //clear TOF flag
	__enable_irq();
}
void RTC_Seconds_IRQHandler(void) {
	__disable_irq();
	sec++;
#ifdef DPRINT

	create_log(rtc_log,HEARTBEAT,0,NULL); //
	if(LOG!=0)
	log_item(rtc_log);
#endif
	__enable_irq();
}
void UART0_IRQHandler(void)
{ __disable_irq();
	if((UART0_C2 & UART0_C2_TIE_MASK)!=0){

		while(CB_TX->count!=0){
					CB_RemoveItem(CB_TX,&data);
					UART0_D=data;

		        		for (int i=2000;i>0;i--);  //wait for it to get sent
				}

	UART0_C2 &= ~UART0_C2_TIE_MASK;//
    }

	else if(((UART0_C2 & UART0_C2_RIE_MASK)!=0) && (UART0_S1 & UART0_S1_RDRF_MASK)!=0){

		        	c =UART0->D;
		        	LED_set(c);
		        	rec_data=c;

		        	rec_data_count++;
		        	CB_AddItem(CB_RX,&c);
		        	UART0->D=c;   //TO DISPLAY ON TERMINAL
		        	analyse=1;

	if(LOG!=0 && c=='1')           //if logging on
		LOG=0; //turn off
		else if(log==0 && c=='1')
		LOG=1;
		        	UART0_C2|=UART_C2_TIE_MASK;
	}

	__enable_irq();
}
#endif


