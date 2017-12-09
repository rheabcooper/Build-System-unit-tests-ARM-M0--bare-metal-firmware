/*
 * profiling.c
 *
 *  Created on: Dec 1, 2017
 *      Author: rhco4796
 */

#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include "conversion.h"
#include "memory.h"
#include <time.h>
#include <sys/time.h>
#include "profiling.h"

#define MEMMOVE_BYTES_SIZE_A (20)
#define MEMMOVE_BYTES_SIZE_B (200)
#define MEMMOVE_BYTES_SIZE_C (2000)
#define MEMMOVE_BYTES_SIZE_D (10000)

#define MEMSET_BYTES_SIZE_A (10)
#define MEMSET_BYTES_SIZE_B (100)
#define MEMSET_BYTES_SIZE_C (1000)
#define MEMSET_BYTES_SIZE_D (5000)

struct timeval start;
struct timeval finish;

uint32_t time_delta;


#ifdef KL25Z
#include "dma.h"

#define RESET_VALUE (0x00)
#define PRESCALAR (0x04)
#define MCGFLLCLK_VAL (0x1)
#define LPTPM_INCREMENT (0x1)
#define LPTPM_DISABLE (0x0)
#define OVERFLOW (0xFFFF)


uint32_t count=0;


void Timer_init(){
SIM->SCGC6|=SIM_SCGC6_TPM0_MASK;


	SIM_SOPT2|=SIM_SOPT2_TPMSRC(MCGFLLCLK_VAL);


	TPM0_SC=0x00;


	TPM0_CNT=0x00;


	TPM0_MOD=OVERFLOW;


	TPM0_SC|=TPM_SC_TOF_MASK;


	TPM0_SC|=TPM_SC_TOIE_MASK;
}

void Timer_start(){


	TPM0_CNT=0x00;

	TPM0_SC|= TPM_SC_CMOD(LPTPM_INCREMENT);
}

void Timer_stop(){
	TPM0_SC |= TPM_SC_CMOD(LPTPM_DISABLE);
}

#endif


void memmove_stdlib_profile(void)
{
	uint8_t * a;
	uint8_t * b;
	uint8_t * space;

	space = (uint8_t*) reserve_words( MEMMOVE_BYTES_SIZE_A );
	a = &space[0];
	b = &space[10];

	for(uint32_t i = 0; i < MEMMOVE_BYTES_SIZE_A; i++)
	{
		space[i] = i;
	} 
 
	gettimeofday(&start, NULL);
	memmove(a, b, MEMMOVE_BYTES_SIZE_A);
	gettimeofday(&finish, NULL);
	
	time_delta = (finish.tv_sec - start.tv_sec) * 1000000;
	time_delta += (finish.tv_usec - start.tv_usec);

	printf("memmove Time - 10 bytes: %d microseconds\n", time_delta);

	free_words( (uint32_t*)space );
/* --------------------------------------------------------------- */
	space = (uint8_t*) reserve_words( MEMMOVE_BYTES_SIZE_B );
	a = &space[0];
	b = &space[100];

	for(uint32_t i = 0; i < MEMMOVE_BYTES_SIZE_B; i++)
	{
		space[i] = i;
	} 
 
	gettimeofday(&start, NULL);
	memmove(a, b, MEMMOVE_BYTES_SIZE_B);
	gettimeofday(&finish, NULL);
	
	time_delta = (finish.tv_sec - start.tv_sec) * 1000000;
	time_delta += (finish.tv_usec - start.tv_usec);

	printf("memmove Time - 100 bytes: %d microseconds\n", time_delta);

	free_words( (uint32_t*)space );
/* --------------------------------------------------------------- */
	space = (uint8_t*) reserve_words( MEMMOVE_BYTES_SIZE_C );
	a = &space[0];
	b = &space[1000];

	for(uint32_t i = 0; i < MEMMOVE_BYTES_SIZE_C; i++)
	{
		space[i] = i;
	} 
 
	gettimeofday(&start, NULL);
	memmove(a, b, MEMMOVE_BYTES_SIZE_C);
	gettimeofday(&finish, NULL);

	time_delta = (finish.tv_sec - start.tv_sec) * 1000000;
	time_delta += (finish.tv_usec - start.tv_usec);
	
	printf("memmove Time - 1000 bytes: %d microseconds\n", time_delta);
	
	free_words( (uint32_t*)space );
/* --------------------------------------------------------------- */
	space = (uint8_t*) reserve_words( MEMMOVE_BYTES_SIZE_D );
	a = &space[0];
	b = &space[5000];

	for(uint32_t i = 0; i < MEMMOVE_BYTES_SIZE_D; i++)
	{
		space[i] = i;
	} 
 
	gettimeofday(&start, NULL);
	memmove(a, b, MEMMOVE_BYTES_SIZE_D);
	gettimeofday(&finish, NULL);

	time_delta = (finish.tv_sec - start.tv_sec) * 1000000;
	time_delta += (finish.tv_usec - start.tv_usec);

	printf("memmove Time - 5000 bytes: %d microseconds\n", time_delta);

	free_words( (uint32_t*)space );

}


void memset_stdlib_profile(void)
{
	uint8_t * a;
	uint8_t * space;

	space = (uint8_t*) reserve_words( MEMSET_BYTES_SIZE_A );
	a = &space[0];

	for(uint32_t i = 0; i < MEMSET_BYTES_SIZE_A; i++)
	{
		space[i] = i;
	} 
 
	gettimeofday(&start, NULL);
	memset(a, 0xAF, MEMSET_BYTES_SIZE_A);
	gettimeofday(&finish, NULL);

	time_delta = (finish.tv_sec - start.tv_sec) * 1000000;
	time_delta += (finish.tv_usec - start.tv_usec);

	printf("\nmemset Time - 10 bytes: %d microseconds\n", time_delta);
	free_words( (uint32_t*)space );
/* -------------------------------------------------------------- */

	space = (uint8_t*) reserve_words( MEMSET_BYTES_SIZE_B );
	a = &space[0];

	for(uint32_t i = 0; i < MEMSET_BYTES_SIZE_B; i++)
	{
		space[i] = i;
	} 
 
	gettimeofday(&start, NULL);
	memset(a, 0xAF, MEMSET_BYTES_SIZE_B);
	gettimeofday(&finish, NULL);

	time_delta = (finish.tv_sec - start.tv_sec) * 1000000;
	time_delta += (finish.tv_usec - start.tv_usec);

	printf("memset Time - 100 bytes: %d microseconds\n", time_delta);
	free_words( (uint32_t*)space );
/* -------------------------------------------------------------- */

	space = (uint8_t*) reserve_words( MEMSET_BYTES_SIZE_C );
	a = &space[0];

	for(uint32_t i = 0; i < MEMSET_BYTES_SIZE_C; i++)
	{
		space[i] = i;
	} 
 
	gettimeofday(&start, NULL);
	memset(a, 0xAF, MEMSET_BYTES_SIZE_C);
	gettimeofday(&finish, NULL);
	
	time_delta = (finish.tv_sec - start.tv_sec) * 1000000;
	time_delta += (finish.tv_usec - start.tv_usec);

	printf("memset Time - 1000 bytes: %d microseconds\n", time_delta);
	free_words( (uint32_t*)space );
/* -------------------------------------------------------------- */

	space = (uint8_t*) reserve_words( MEMSET_BYTES_SIZE_D );
	a = &space[0];

	for(uint32_t i = 0; i < MEMSET_BYTES_SIZE_D; i++)
	{
		space[i] = i;
	} 
 
	gettimeofday(&start, NULL);
	memset(a, 0xAF, MEMSET_BYTES_SIZE_D);
	gettimeofday(&finish, NULL);

	time_delta = (finish.tv_sec - start.tv_sec) * 1000000;
	time_delta += (finish.tv_usec - start.tv_usec);

	printf("memset Time - 5000 bytes: %d microseconds\n", time_delta);
	free_words( (uint32_t*)space );
}



void memmove_profile(void)
{
	int8_t ret;
	uint8_t * a;
	uint8_t * b;
	uint8_t * space;

	space = (uint8_t*) reserve_words( MEMMOVE_BYTES_SIZE_A );
	a = &space[0];
	b = &space[10];

	for(uint32_t i = 0; i < MEMMOVE_BYTES_SIZE_A; i++)
	{
		space[i] = i;
	} 
 
	gettimeofday(&start, NULL);
	ret = my_memmove(a, b, MEMMOVE_BYTES_SIZE_A);
	gettimeofday(&finish, NULL);
	
	time_delta = (finish.tv_sec - start.tv_sec) * 1000000;
	time_delta += (finish.tv_usec - start.tv_usec);

	if (ret == SUCCESS)
	{
		printf("\nmemmove Time - 10 bytes: %d microseconds\n", time_delta);
	}
	else
	{
		printf("\nmemmove Time - 10 bytes:  memmove failed!\n");
	}
	free_words( (uint32_t*)space );
/* --------------------------------------------------------------- */
	space = (uint8_t*) reserve_words( MEMMOVE_BYTES_SIZE_B );
	a = &space[0];
	b = &space[100];

	for(uint32_t i = 0; i < MEMMOVE_BYTES_SIZE_B; i++)
	{
		space[i] = i;
	} 
 
	gettimeofday(&start, NULL);
	ret = my_memmove(a, b, MEMMOVE_BYTES_SIZE_B);
	gettimeofday(&finish, NULL);
	
	time_delta = (finish.tv_sec - start.tv_sec) * 1000000;
	time_delta += (finish.tv_usec - start.tv_usec);

	if (ret == SUCCESS)
	{
		printf("memmove Time - 100 bytes: %d microseconds\n", time_delta);
	}
	else
	{
		printf("memmove Time - 100 bytes:  memmove failed!\n");
	}

	free_words( (uint32_t*)space );
/* --------------------------------------------------------------- */
	space = (uint8_t*) reserve_words( MEMMOVE_BYTES_SIZE_C );
	a = &space[0];
	b = &space[1000];

	for(uint32_t i = 0; i < MEMMOVE_BYTES_SIZE_C; i++)
	{
		space[i] = i;
	} 
 
	gettimeofday(&start, NULL);
	ret = my_memmove(a, b, MEMMOVE_BYTES_SIZE_C);
	gettimeofday(&finish, NULL);

	time_delta = (finish.tv_sec - start.tv_sec) * 1000000;
	time_delta += (finish.tv_usec - start.tv_usec);
	
	if (ret == SUCCESS)
	{
		printf("memmove Time - 1000 bytes: %d microseconds\n", time_delta);
	}
	else
	{
		printf("memmove Time - 1000 bytes:  memmove failed!\n");
	}
	
	free_words( (uint32_t*)space );
/* --------------------------------------------------------------- */
	space = (uint8_t*) reserve_words( MEMMOVE_BYTES_SIZE_D );
	a = &space[0];
	b = &space[5000];

	for(uint32_t i = 0; i < MEMMOVE_BYTES_SIZE_D; i++)
	{
		space[i] = i;
	} 
 
	gettimeofday(&start, NULL);
	ret = my_memmove(a, b, MEMMOVE_BYTES_SIZE_D);
	gettimeofday(&finish, NULL);

	time_delta = (finish.tv_sec - start.tv_sec) * 1000000;
	time_delta += (finish.tv_usec - start.tv_usec);

	if (ret == SUCCESS)
	{
		printf("memmove Time - 5000 bytes: %d microseconds\n", time_delta);
	}
	else
	{
		printf("memmove Time - 5000 bytes:  memmove failed!\n");
	}

	free_words( (uint32_t*)space );

}


void memset_profile(void)
{
	uint8_t * a;
//	uint8_t * b;
	uint8_t * space;

	space = (uint8_t*) reserve_words( MEMSET_BYTES_SIZE_A );
	a = &space[0];
//	b = &space[10];

	for(uint32_t i = 0; i < MEMSET_BYTES_SIZE_A; i++)
	{
		space[i] = i;
	} 
 
	gettimeofday(&start, NULL);
	my_memset(a, MEMSET_BYTES_SIZE_A, 0xAF);
//	my_memzero(b, 10);
	gettimeofday(&finish, NULL);

	time_delta = (finish.tv_sec - start.tv_sec) * 1000000;
	time_delta += (finish.tv_usec - start.tv_usec);

	printf("\nmemset Time - 10 bytes: %d microseconds\n", time_delta);
	free_words( (uint32_t*)space );
/* -------------------------------------------------------------- */

	space = (uint8_t*) reserve_words( MEMSET_BYTES_SIZE_B );
	a = &space[0];
//	b = &space[100];

	for(uint32_t i = 0; i < MEMMOVE_BYTES_SIZE_B; i++)
	{
		space[i] = i;
	} 
 
	gettimeofday(&start, NULL);
	my_memset(a, MEMSET_BYTES_SIZE_B, 0xAF);
//	my_memzero(b, 100);
	gettimeofday(&finish, NULL);

	time_delta = (finish.tv_sec - start.tv_sec) * 1000000;
	time_delta += (finish.tv_usec - start.tv_usec);

	printf("memset Time - 100 bytes: %d microseconds\n", time_delta);
	free_words( (uint32_t*)space );
/* -------------------------------------------------------------- */

	space = (uint8_t*) reserve_words( MEMSET_BYTES_SIZE_C );
	a = &space[0];
//	b = &space[1000];

	for(uint32_t i = 0; i < MEMSET_BYTES_SIZE_C; i++)
	{
		space[i] = i;
	} 
 
	gettimeofday(&start, NULL);
	my_memset(a, MEMSET_BYTES_SIZE_C, 0xAF);
//	my_memzero(b, 1000);
	gettimeofday(&finish, NULL);
	
	time_delta = (finish.tv_sec - start.tv_sec) * 1000000;
	time_delta += (finish.tv_usec - start.tv_usec);

	printf("memset Time - 1000 bytes: %d microseconds\n", time_delta);
	free_words( (uint32_t*)space );
/* -------------------------------------------------------------- */

	space = (uint8_t*) reserve_words( MEMSET_BYTES_SIZE_D );
	a = &space[0];
//	b = &space[5000];

	for(uint32_t i = 0; i < MEMSET_BYTES_SIZE_D; i++)
	{
		space[i] = i;
	} 
 
	gettimeofday(&start, NULL);
	my_memset(a, MEMSET_BYTES_SIZE_D, 0xAF);
//	my_memzero(b, 5000);
	gettimeofday(&finish, NULL);

	time_delta = (finish.tv_sec - start.tv_sec) * 1000000;
	time_delta += (finish.tv_usec - start.tv_usec);

	printf("memset Time - 5000 bytes: %d microseconds\n", time_delta);
	free_words( (uint32_t*)space );
}




