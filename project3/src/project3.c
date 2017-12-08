/**
 * @file project2.c 
 * @brief This file is to be used for project 2.
 *
 * @author Brian Kelly
 * @date November 26, 2017
 *
 */

#include "project3.h"
#include "memory.h"

#include <sys/time.h>
#include <stdint.h>
#include <stdlib.h>

#define BYTES_SIZE_A (20)
#define BYTES_SIZE_B (200)
#define BYTES_SIZE_C (2000)
#define BYTES_SIZE_D (10000)

struct timeval start;
struct timeval finish;
//struct timeval {
//	time_t tv_sec;
//	suseconds_t tv_usec;
//}

uint32_t time_delta;

void project3(void)
{
	memmove_profile();
	memset_profile();
}

void memmove_profile(void)
{
	int8_t ret;
	uint8_t * a;
	uint8_t * b;
	uint8_t * space;

	space = (uint8_t*) reserve_words( BYTES_SIZE_A );
	a = &space[0];
	b = &space[10];

	for(uint32_t i = 0; i < BYTES_SIZE_A; i++)
	{
		space[i] = i;
	} 
 
	gettimeofday(&start, NULL);
	ret = my_memmove(a, b, BYTES_SIZE_A);
	gettimeofday(&finish, NULL);
	
	time_delta = (finish.tv_sec - start.tv_sec) * 1000000;
	time_delta += (finish.tv_usec - start.tv_usec);

	if (ret == SUCCESS)
	{
		printf("memmove Time - 10 bytes: %d microseconds\n", time_delta);
	}
	else
	{
		printf("memmove Time - 10 bytes:  memmove failed!\n");
	}
	free_words( (uint32_t*)space );
/* --------------------------------------------------------------- */
	space = (uint8_t*) reserve_words( BYTES_SIZE_B );
	a = &space[0];
	b = &space[100];

	for(uint32_t i = 0; i < BYTES_SIZE_B; i++)
	{
		space[i] = i;
	} 
 
	gettimeofday(&start, NULL);
	ret = my_memmove(a, b, BYTES_SIZE_B);
	gettimeofday(&finish, NULL);
	
//	msec = finish.tv_sec * 1000 + finish.tv_usec / 1000;
//	msec -= start.tv_sec * 1000 + start.tv_usec / 1000;

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
	space = (uint8_t*) reserve_words( BYTES_SIZE_C );
	a = &space[0];
	b = &space[1000];

	for(uint32_t i = 0; i < BYTES_SIZE_C; i++)
	{
		space[i] = i;
	} 
 
	gettimeofday(&start, NULL);
	ret = my_memmove(a, b, BYTES_SIZE_C);
	gettimeofday(&finish, NULL);
	
//	msec = finish.tv_sec * 1000 + finish.tv_usec / 1000;
//	msec -= start.tv_sec * 1000 + start.tv_usec / 1000;

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
	space = (uint8_t*) reserve_words( BYTES_SIZE_D );
	a = &space[0];
	b = &space[5000];

	for(uint32_t i = 0; i < BYTES_SIZE_D; i++)
	{
		space[i] = i;
	} 
 
	gettimeofday(&start, NULL);
	ret = my_memmove(a, b, BYTES_SIZE_D);
	gettimeofday(&finish, NULL);
	
//	msec = finish.tv_sec * 1000 + finish.tv_usec / 1000;
//	msec -= start.tv_sec * 1000 + start.tv_usec / 1000;

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
	uint8_t * b;
	uint8_t * space;

	space = (uint8_t*) reserve_words( BYTES_SIZE_A );
	a = &space[0];
	b = &space[10];

	for(uint32_t i = 0; i < BYTES_SIZE_A; i++)
	{
		space[i] = i;
	} 
 
	gettimeofday(&start, NULL);
	my_memset(a, BYTES_SIZE_A, 0xAF);
	my_memzero(b, 10);
	gettimeofday(&finish, NULL);
	
//	msec = finish.tv_sec * 1000 + finish.tv_usec / 1000;
//	msec -= start.tv_sec * 1000 + start.tv_usec / 1000;

	time_delta = (finish.tv_sec - start.tv_sec) * 1000000;
	time_delta += (finish.tv_usec - start.tv_usec);

	printf("\nmemset Time - 10 bytes: %d microseconds\n", time_delta);
	free_words( (uint32_t*)space );
/* -------------------------------------------------------------- */

	space = (uint8_t*) reserve_words( BYTES_SIZE_B );
	a = &space[0];
	b = &space[100];

	for(uint32_t i = 0; i < BYTES_SIZE_B; i++)
	{
		space[i] = i;
	} 
 
	gettimeofday(&start, NULL);
	my_memset(a, BYTES_SIZE_B, 0xAF);
	my_memzero(b, 100);
	gettimeofday(&finish, NULL);
	
//	msec = finish.tv_sec * 1000 + finish.tv_usec / 1000;
//	msec -= start.tv_sec * 1000 + start.tv_usec / 1000;

	time_delta = (finish.tv_sec - start.tv_sec) * 1000000;
	time_delta += (finish.tv_usec - start.tv_usec);

	printf("memset Time - 100 bytes: %d microseconds\n", time_delta);
	free_words( (uint32_t*)space );
/* -------------------------------------------------------------- */

	space = (uint8_t*) reserve_words( BYTES_SIZE_C );
	a = &space[0];
	b = &space[1000];

	for(uint32_t i = 0; i < BYTES_SIZE_C; i++)
	{
		space[i] = i;
	} 
 
	gettimeofday(&start, NULL);
	my_memset(a, BYTES_SIZE_C, 0xAF);
	my_memzero(b, 1000);
	gettimeofday(&finish, NULL);
	
//	msec = finish.tv_sec * 1000 + finish.tv_usec / 1000;
//	msec -= start.tv_sec * 1000 + start.tv_usec / 1000;

	time_delta = (finish.tv_sec - start.tv_sec) * 1000000;
	time_delta += (finish.tv_usec - start.tv_usec);

	printf("memset Time - 1000 bytes: %d microseconds\n", time_delta);
	free_words( (uint32_t*)space );
/* -------------------------------------------------------------- */

	space = (uint8_t*) reserve_words( BYTES_SIZE_D );
	a = &space[0];
	b = &space[5000];

	for(uint32_t i = 0; i < BYTES_SIZE_D; i++)
	{
		space[i] = i;
	} 
 
	gettimeofday(&start, NULL);
	my_memset(a, BYTES_SIZE_D, 0xAF);
	my_memzero(b, 5000);
	gettimeofday(&finish, NULL);
	
//	msec = finish.tv_sec * 1000 + finish.tv_usec / 1000;
//	msec -= start.tv_sec * 1000 + start.tv_usec / 1000;

	time_delta = (finish.tv_sec - start.tv_sec) * 1000000;
	time_delta += (finish.tv_usec - start.tv_usec);

	printf("memset Time - 5000 bytes: %d microseconds\n", time_delta);
	free_words( (uint32_t*)space );

}
