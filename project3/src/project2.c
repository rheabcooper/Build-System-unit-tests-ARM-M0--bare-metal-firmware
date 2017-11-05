/**
 * @file project2.c 
 * @brief This file is to be used for project 2.
 *
 * @author Brian Kelly
 * @date October 15, 2017
 *
 */

#include "project2.h"
#include "uart.h"

uint32_t CB_TX_length=576;
uint32_t CB_RX_length=5;
int32_t alphabets = 0;
int32_t numbers = 0;
int32_t punctuations = 0;
int32_t misc = 0;
uint8_t string_for_alp[]="Number of alphabets is : \n\r";
uint8_t string_for_num[]="Number of numbers is : \n\r";
uint8_t string_for_punc[]="Number of punctuations is : \n\r";
uint8_t string_for_misc[]="Number of miscellaneous characters is : \n\r";

uint8_t data;
uint8_t c;

#ifdef KL25Z
/*to transmit an integer from the UART of FRDM */
void transmit_integer(int32_t integer_value)
{	
	uint8_t length;
	uint8_t *char_value = NULL;
	/*Function to convert integer to ascii*/
	length = my_itoa(integer_value, char_value, BASE_10);
	for(int i = 0; i < length; i++)
	{
		CB_AddItem(CB_TX,char_value);
		char_value++;
	}
	
	/*To enable transmit interrupt*/
	UART0_C2|=UART_C2_TIE_MASK;
}

/*to transmit a string from the UART of FRDM */
void transmit_string(uint8_t * data)
{	
	while(*data != '\0')
	{
		CB_AddItem(CB_TX, data);
		data++;
	}

	/*To enable transmitter interrupt*/
	UART0_C2|=UART_C2_TIE_MASK;
}

void transmit_char(uint8_t * data)
{
	CB_AddItem(CB_TX,data);
	 
	/*Enable the transmit interrupt*/
	UART0_C2 |= UART_C2_TIE_MASK;
}
#endif

void transmit_char_host(uint8_t * data)
{
		CB_AddItem(CB_TX,data);
		uint8_t data_rec;
		
		CB_RemoveItem(CB_TX,&data_rec);
		printf("%c", data_rec);
	
}

void transmit_string_host(uint8_t * data)
{
	while(*data!='\0')
	{
		CB_AddItem(CB_TX,data);
		data++;	
	}
	
	uint8_t *print_value=NULL;
	while(CB_TX->count)
	{
		CB_RemoveItem(CB_TX,print_value);
		printf("%u", *print_value);
		print_value++;
	}
}

void transmit_integer_host(int32_t integer_value)
{	
	uint8_t *char_value=NULL;
	/*Function to convert integer to ascii*/
	my_itoa(integer_value,char_value,BASE_10);
	CB_AddItem(CB_TX,char_value);  //add to circular buffer
	uint8_t *print_value=NULL;
	while(CB_TX->count)
	{
		CB_RemoveItem(CB_TX,print_value);
		printf("%u", *print_value);
		print_value++;
	}

}

void data_analysis()
{
	uint8_t c = rec_data;
	/* Check if data is an alphabet, number,
	 * punctuation or a miscellaneous character*/
	if(((c>='a') && (c<='z')) || ((c>='A') && (c<='Z')))
	    alphabets++;
	else if (c == '.' || c == ',')
	    punctuations++;
	else if ((c>='0') && (c<= '9'))	
		numbers++;  	
	else
		misc++;
	analyze=0;
	if(rec_data_count==CB_RX_length)
	{
		if(alphabets == 5)
		{
			dump_stats(); 
		}
	}
}

void dump_stats()
{
	#ifdef KL25Z
	transmit_string(string_for_alp);  
	transmit_integer(alphabets);  
	transmit_string(string_for_num);
	transmit_integer(numbers);
	transmit_string(string_for_punc);
	transmit_integer(punctuations);
	transmit_string(string_for_misc);
	transmit_integer(misc);
	#endif
	
	#ifdef HOST
	transmit_string_host(string_for_alp);  
	transmit_integer_host(alphabets);  
	transmit_string_host(string_for_num);
	transmit_integer_host(numbers);
	transmit_string_host(string_for_punc);
	transmit_integer_host(punctuations);
	transmit_string_host(string_for_misc);
	transmit_integer_host(misc);
	#endif
}

void project2()
{
	printf("Starting project2\n");
	
	/*Create and Initialize Transmit Circular Buffer*/
	CB_TX = (CB_t*) malloc(sizeof(CB_t));
	CB_Init(CB_TX,CB_TX_length);
	
	/*Create and Initialize Receiver Circular Buffer*/
    	CB_RX = (CB_t*) malloc(sizeof(CB_t));
	CB_Init(CB_RX,CB_RX_length);
	
	#ifdef HOST
	/*testing of sending characters from FRDM to terminal using the above functions*/
	uint8_t test[4]={'1','2','3','4'};
	uint8_t * data_TX = test;

	/* Welcome Banner */
	printf("\r\n\r\n======= Linux VM HOST ========\r\n");

	transmit_char_host(data_TX);
	//enable & disable transmit interrupt here
	UART0_C2|=UART_C2_TIE_MASK;
	/*wait for interrupt*/
	while(1){
	/*When UART receives data the variable is set to analyze data*/
		if(analyse == 1){
			data_analysis();
		}
	}
	#endif

	#ifdef KL25Z
	/* 	__disable_irq();  */
	/* Welcome Banner */
	printf("\r\n\r\n======= Freescale Freedom FRDM-KL25Z ========\r\n");

	UART_configure();

/*	__enable_irq(); */
	/*testing of sending characters from FRDM to terminal using the above functions*/
	uint8_t test[4]={'1','2','3','4'};
	uint8_t * data_TX = test;

	transmit_char(data_TX);
	//enable & disable transmit interrupt here
	UART0_C2|=UART_C2_TIE_MASK;
	/*wait for interrupt*/
	while(1)
	{
	/*When UART receives data the variable is set to analyze data*/
		if(analyse == 1)
		{
			data_analysis();
		}
	}
	#endif
}

void UART0_IRQHandler()
{	
       	__disable_irq();  // global disable IRQs
	/* Check if interrupt is for TX or RX and handle accordingly
	 * For TX interrupt we take the data from TX buffer and
	 * sent it to UART to transmit*/
        if((UART0_C2 & UART0_C2_TIE_MASK) != 0)
		{
			while(CB_TX->count!=0)
			{
				CB_RemoveItem(CB_TX,&data);
				UART0->D=data;
            	for (int i=2000; i > 0; i--);  //wait for it to get sent
			}
		
			/*Disabling TX interrupt bit*/
			UART0_C2 &= ~UART0_C2_TIE_MASK;
   		}

    /* For RX interrupt check add data to the RX buffer and
     * analyse the data to check if it is an alphabet, number,
     * punctuation or a miscellaneous characters*/
		else if(((UART0_C2 & UART0_C2_RIE_MASK) != 0) &&
				((UART0_S1 & UART0_S1_RDRF_MASK) != 0) )
		{
				c= UART0->D;
				LED_Set(c);   
				rec_data = c;        //updating the global variable
    			rec_data_count++;
    			CB_AddItem(CB_RX,&c);
				/*analyse is a global variable in the project2.h file*/
    			analyze = 1;     //only setting a flag instead of calling the function as ISR should be as short as possible
    			UART0_C2|=UART_C2_TIE_MASK;
		}

	__enable_irq();  // global disable IRQs
	
}

void LED_Init()
{
	SIM->SCGC5 |= 0x400;
	SIM->SCGC5 |= 0x1000;
	/*  enable clock to Port D */
	PORTB->PCR[18] = 0x100;
	/* make PTB18 pin as GPIO */
	PTB->PDDR |= 0x40000;	/* make	PTB18 as output	pin	*/
	PTB->PSOR = 0x40000;
	/* turn off red LED */
	PORTB->PCR[19] = 0x100;
	PTB->PDDR |= 0x80000;
	/*  make PTB19 as output pin */
	PTB->PSOR = 0x80000;
	/* turn off green LED */
	PORTD->PCR[1] = 0x100;
	/* make PTD1 pin as GPIO */
	PTD->PDDR |= 0x02;	/* make PTD1 as output pin */
	PTD->PSOR = 0x02;
}

void LED_Set(uint8_t val) 
{
	if (val && 1)
	{
		/* use bit 0 of value to control red LED */
		PTB->PCOR = 0x40000;
	}
	/* turn on red LED */ 
	else
	{
		PTB->PSOR =	0x40000;
	}

	if (val && 2)
	{
		/*	use	bit	1	of	value	to	control	green	LED	*/
		PTB->PCOR =	0x80000;
	}
	/*	turn	on	green	LED	*/
	else
	{
		PTB->PSOR =	0x80000;
	}
	/*	turn	off	green	LED	*/
	if (val && 4)
	{
		/*	use	bit	2	of	value	to	control	blue	LED	*/
		PTD->PCOR =	0x02;
	}
	/*	turn	on	blue	LED	*/
	else
	{
		PTD->PSOR =	0x02;
	}
}
