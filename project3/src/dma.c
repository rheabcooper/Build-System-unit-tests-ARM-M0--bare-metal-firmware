
#include "dma.h"

#define DMA_ENABLE_TRANSFER (0x80)
#define DMA_START_BIT_ENABLE (0x10000)
#define DMA_DISABLE (0x00)
#define DMA_CHANNEL0 (0x3C)
#define DMAMUX_CLOCK_ENABLE (0x00000002)
#define DMA_CLOCK_ENABLE (0x00000100)
#define DMA_DCR0_UART (0xE09A0000)
#define DMA_DCR0_8BIT_SINC (0x805A0000)
#define DMA_DCR0_8BIT (0x801A0000)
#define DMA_DCR0_16BIT_SINC (0x806C0000)
#define DMA_DCR0_16BIT (0x802C0000)
#define DMA_DCR0_32BIT_SINC (0x80480000)
#define DMA_DCR0_32BIT (0x80080000)

#define DMA_CHANNEL_ENABLE (0x80)
#define DMA_INTERRUPT_ENABLE (0x80000000)
#define DMA_START_ENABLE (0x10000)
#define DMA_SSIZE_BYTE (0x100000)
#define DMA_SSIZE_HALFWORD (0x200000)
#define DMA_SSIZE_WORD (0x000000)
#define DMA_DSIZE_BYTE (0x20000)
#define DMA_DSIZE_HALFWORD (0x40000)
#define DMA_DSIZE_WORD (0x000000)

#define DMA_SINC (0x00400000)
#define DMA_DINC (0x80000)
#define DMA_SOURCE (0x3C)  //Page 66 of manual
//#define DMAMUX_CLOCK_ENABLE (0x00000002)
//#define DMA_CLOCK_ENABLE (0x00000100)
//#define DMA_DSR_BCR0_DONE (0x01000000)
#define DMA_CLOCK_DISABLE (0x7FFFFFFF)

void DMA_init(){
SIM_SCGC6=DMAMUX_CLOCK_ENABLE;

/*enable clock for DMA clock gate control*/
SIM_SCGC7=DMA_CLOCK_ENABLE;

DMAMUX0_CHCFG0=0x00;


}





void memmove_DMA_byte(uint8_t *src,uint8_t *dst, size_t length){
	if((src<dst) && (dst-length)<src)
		{
			uint8_t temp_dest[length];
			DMA_SAR0= (uint32_t)src;
			DMA_DAR0= (uint32_t)&temp_dest;
			DMA_DCR0|=DMA_INTERRUPT_ENABLE;
			DMA_DCR0|=DMA_SSIZE_BYTE;
			DMA_DCR0|=DMA_DSIZE_BYTE;
			DMA_DCR0|=DMA_SINC;
			DMA_DCR0|=DMA_DINC;
			DMA_DSR_BCR0=length;
			DMAMUX0_CHCFG0|=DMA_SOURCE;
			DMAMUX0_CHCFG0|=DMA_CHANNEL_ENABLE;
			DMA_DCR0|=DMA_START_ENABLE;
			DMA_SAR0= (uint32_t)&temp_dest;
			DMA_DAR0= (uint32_t)dst;
			DMA_DCR0|=DMA_INTERRUPT_ENABLE;
			DMA_DCR0|=DMA_SSIZE_BYTE;
			DMA_DCR0|=DMA_DSIZE_BYTE;
			DMA_DCR0|=DMA_SINC;
			DMA_DCR0|=DMA_DINC;
			DMA_DSR_BCR0=length;
			DMAMUX0_CHCFG0|=DMA_SOURCE;
			DMAMUX0_CHCFG0|=DMA_CHANNEL_ENABLE;
			DMA_DCR0|=DMA_START_ENABLE;

			NVIC_EnableIRQ(DMA0_IRQn);
		}
		else
		{
			DMA_SAR0= (uint32_t)src;
			DMA_DAR0= (uint32_t)dst;
			DMA_DCR0|=DMA_INTERRUPT_ENABLE;
			DMA_DCR0|=DMA_SSIZE_BYTE;
			DMA_DCR0|=DMA_DSIZE_BYTE;
			DMA_DCR0|=DMA_SINC;
			DMA_DCR0|=DMA_DINC;
			DMA_DSR_BCR0=length;
			DMAMUX0_CHCFG0|=DMA_SOURCE;
			DMAMUX0_CHCFG0|=DMA_CHANNEL_ENABLE;
			DMA_DCR0|=DMA_START_ENABLE;

			NVIC_EnableIRQ(DMA0_IRQn);
		}

}
void memmove_DMA_halfword(uint16_t *src, uint16_t *dst, size_t length){
	    uint8_t remainder=0;

		remainder=length % 2;

		length=length-remainder;

		/*check overlapping condition*/
		if((src<dst) && (dst-length)<src)
				{
					uint8_t temp_dest[length];
					DMA_SAR0= (uint32_t)src;
					DMA_DAR0= (uint32_t)&temp_dest;
					DMA_DCR0|=DMA_INTERRUPT_ENABLE;
					DMA_DCR0|=DMA_SSIZE_HALFWORD;
					DMA_DCR0|=DMA_DSIZE_HALFWORD;
					DMA_DCR0|=DMA_SINC;
					DMA_DCR0|=DMA_DINC;
					DMA_DSR_BCR0=length;
					DMAMUX0_CHCFG0|=DMA_SOURCE;
					DMAMUX0_CHCFG0|=DMA_CHANNEL_ENABLE;
					DMA_DCR0|=DMA_START_ENABLE;
					DMA_SAR0= (uint32_t)&temp_dest;
					DMA_DAR0= (uint32_t)dst;
					DMA_DCR0|=DMA_INTERRUPT_ENABLE;
					DMA_DCR0|=DMA_SSIZE_BYTE;
					DMA_DCR0|=DMA_DSIZE_BYTE;
					DMA_DCR0|=DMA_SINC;
					DMA_DCR0|=DMA_DINC;
					DMA_DSR_BCR0=length;
					DMAMUX0_CHCFG0|=DMA_SOURCE;
					DMAMUX0_CHCFG0|=DMA_CHANNEL_ENABLE;
					DMA_DCR0|=DMA_START_ENABLE;


				}
				else
				{
					DMA_SAR0= (uint32_t)src;
					DMA_DAR0= (uint32_t)dst;
					DMA_DCR0|=DMA_INTERRUPT_ENABLE;
					DMA_DCR0|=DMA_SSIZE_BYTE;
					DMA_DCR0|=DMA_DSIZE_BYTE;
					DMA_DCR0|=DMA_SINC;
					DMA_DCR0|=DMA_DINC;
					DMA_DSR_BCR0=length;
					DMAMUX0_CHCFG0|=DMA_SOURCE;
					DMAMUX0_CHCFG0|=DMA_CHANNEL_ENABLE;
					DMA_DCR0|=DMA_START_ENABLE;


				}

		/*remaining transfer by my_memmove*/
		if (remainder > 0){
				uint8_t * src1= (uint8_t *)src + length;
				uint8_t * dst1= (uint8_t *)dst + length;
				my_memmove(src1,dst1,(uint32_t)remainder);
			}
		NVIC_EnableIRQ(DMA0_IRQn);
}

void memmove_DMA_word(uint32_t *src,uint32_t *dst, size_t length){
	uint8_t remainder=0;
		remainder=length % 4;
		length=length-remainder;

		/*Check overlapping condition*/
		if((src<dst) && (dst-length)<src)
						{
							uint8_t temp_dest[length];
							DMA_SAR0= (uint32_t)src;
							DMA_DAR0= (uint32_t)&temp_dest;
							DMA_DCR0|=DMA_INTERRUPT_ENABLE;
							DMA_DCR0|=DMA_SSIZE_HALFWORD;
							DMA_DCR0|=DMA_DSIZE_HALFWORD;
							DMA_DCR0|=DMA_SINC;
							DMA_DCR0|=DMA_DINC;
							DMA_DSR_BCR0=length;
							DMAMUX0_CHCFG0|=DMA_SOURCE;
							DMAMUX0_CHCFG0|=DMA_CHANNEL_ENABLE;
							DMA_DCR0|=DMA_START_ENABLE;
							DMA_SAR0= (uint32_t)&temp_dest;
							DMA_DAR0= (uint32_t)dst;
							DMA_DCR0|=DMA_INTERRUPT_ENABLE;
							DMA_DCR0|=DMA_SSIZE_WORD;
							DMA_DCR0|=DMA_DSIZE_WORD;
							DMA_DCR0|=DMA_SINC;
							DMA_DCR0|=DMA_DINC;
							DMA_DSR_BCR0=length;
							DMAMUX0_CHCFG0|=DMA_SOURCE;
							DMAMUX0_CHCFG0|=DMA_CHANNEL_ENABLE;
							DMA_DCR0|=DMA_START_ENABLE;


						}
						else
						{
							DMA_SAR0= (uint32_t)src;
							DMA_DAR0= (uint32_t)dst;
							DMA_DCR0|=DMA_INTERRUPT_ENABLE;
							DMA_DCR0|=DMA_SSIZE_WORD;
							DMA_DCR0|=DMA_DSIZE_WORD;
							DMA_DCR0|=DMA_SINC;
							DMA_DCR0|=DMA_DINC;
							DMA_DSR_BCR0=length;
							DMAMUX0_CHCFG0|=DMA_SOURCE;
							DMAMUX0_CHCFG0|=DMA_CHANNEL_ENABLE;
							DMA_DCR0|=DMA_START_ENABLE;


						}
		/*remaining bytes transferred by my_memmoove*/
		if (remainder > 0){
			uint8_t * src1= (uint8_t *)src + length;
			uint8_t * dst1= (uint8_t *)dst + length;
			my_memmove(src1,dst1,(uint32_t)remainder);
		}
		NVIC_EnableIRQ(DMA0_IRQn);
}

void memzero_DMA_byte(uint8_t *src,uint32_t length){
	   /* DMA_DAR0=(uint32_t)src;

		uint8_t value=0;


		DMA_SAR0=(uint32_t)&value;


		DMA_DCR0=DMA_DCR0_8BIT;


		DMA_DSR_BCR0=length;

		DMAMUX0_CHCFG0|=DMA_CHANNEL0;

		DMAMUX0_CHCFG0|=DMA_ENABLE_TRANSFER;


		DMA_DCR0|=DMA_START_BIT_ENABLE;

		NVIC_EnableIRQ(DMA0_IRQn);
*/
        DMA_DAR0=(uint32_t)src;
		uint8_t value=0;
	    /*assign the value of source address to address of 0*/
		DMA_SAR0=(uint32_t)&value;
		DMA_DCR0|=DMA_INTERRUPT_ENABLE;
		DMA_DCR0|=DMA_SSIZE_BYTE;
		DMA_DCR0|=DMA_DSIZE_BYTE;
		DMA_DCR0|=DMA_DINC;
		DMA_DSR_BCR0=length;
		DMAMUX0_CHCFG0|=DMA_SOURCE;
		DMAMUX0_CHCFG0|=DMA_CHANNEL_ENABLE;
		DMA_DCR0|=DMA_START_ENABLE;
		NVIC_EnableIRQ(DMA0_IRQn);
}

void memzero_DMA_halfword(uint16_t *src,uint32_t length){
	uint8_t remainder=0;
		remainder=length % 2;
		length=length-remainder;

		uint16_t value=0;


					    /*assign the value of source address to address of 0*/
						DMA_SAR0=(uint32_t)&value;
						DMA_DAR0=(uint32_t)src;
				DMA_DCR0|=DMA_INTERRUPT_ENABLE;
				DMA_DCR0|=DMA_SSIZE_HALFWORD;
				DMA_DCR0|=DMA_DSIZE_HALFWORD;
				DMA_DCR0|=DMA_DINC;
				DMA_DSR_BCR0=length;
				DMAMUX0_CHCFG0|=DMA_SOURCE;
				DMAMUX0_CHCFG0|=DMA_CHANNEL_ENABLE;
				DMA_DCR0|=DMA_START_ENABLE;
				NVIC_EnableIRQ(DMA0_IRQn);

		/*remaining transfer by my_memset*/
		if (remainder > 0){
			uint8_t * src1= (uint8_t *)src + length;
			my_memset(src1,(uint32_t)remainder,(uint8_t) 0);

		}

}

void memzero_DMA_word(uint32_t *src,uint32_t length){
	uint8_t remainder=0;
		remainder=length % 4;
		length=length-remainder;
		uint32_t value=0;


			    /*assign the value of source address to address of 0*/
				DMA_SAR0=(uint32_t)&value;
				DMA_DAR0=(uint32_t)src;
				DMA_DCR0|=DMA_INTERRUPT_ENABLE;
				DMA_DCR0|=DMA_SSIZE_WORD;
				DMA_DCR0|=DMA_DSIZE_WORD;
				DMA_DCR0|=DMA_DINC;
				DMA_DSR_BCR0=length;
				DMAMUX0_CHCFG0|=DMA_SOURCE;
				DMAMUX0_CHCFG0|=DMA_CHANNEL_ENABLE;
				DMA_DCR0|=DMA_START_ENABLE;
				NVIC_EnableIRQ(DMA0_IRQn);

		/*remaining transfer by my_memset*/
		if (remainder > 0){
			uint8_t * src1= (uint8_t *)src + length;
			my_memset(src1,(uint32_t)remainder,(uint8_t) 0);

		}

}

