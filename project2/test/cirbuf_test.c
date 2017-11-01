/**
 * @file cirbuf_test.c
 * @brief A file to perform unit tests on the circular buffer functions. 
 *
 * Those functions are designed to be tested on the cmocka
 * unit test framework.
 *
 * The cmocka test functions/framework were all developed by Brian Kelly.  
 * Rhea Cooper developed unit tests under all of the cmocka functions.
 *
 * @author Brian Kelly and Rhea Cooper
 * @date October 25, 2017
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include "cirbuf.h"
#define BUFFER_LENGTH (16)
#define ZERO (0)

uint32_t buffer_length=BUFFER_LENGTH;

void cirbuf_allocate_free_test(void **state)
{
	CB_t *cbufptr=(CB_t*)malloc(sizeof(CB_t));
	CB_status status1=CB_Init(cbufptr,buffer_length);
	assert_int_equal(status1, NO_ERROR);
	CB_status status2=CB_Destroy(cbufptr);
	assert_int_equal(status2, NO_ERROR);
}

void cirbuf_invalid_pointer_test(void **state)
{	
	CB_t *cbufptr=(CB_t*)malloc(sizeof(CB_t));
	
	CB_status status=CB_IsEmpty(NULL);
	CB_Destroy(cbufptr);
	
	assert_int_equal(status,NULL_POINTER);
}

void cirbuf_initialized_buffer_test(void **state)
{	
	uint8_t check;
	CB_t *cbufptr=(CB_t*)malloc(sizeof(CB_t));
	CB_Init(cbufptr,buffer_length);

	if( ((cbufptr->head) == (cbufptr->buffer_pointer)) && 
		((cbufptr->tail) == (cbufptr->buffer_pointer)) && 
		((cbufptr->aptr) == (cbufptr->buffer_pointer)) )
	{
		check = ZERO;
	}
	
	CB_Destroy(cbufptr);
	assert_int_equal(check, ZERO);
}

void cirbuf_add_remove_test(void **state)
{	
	uint8_t data_add[buffer_length];
	uint8_t i;
	uint8_t data_rec_array[buffer_length];
	int check = 0;

	CB_t *cbufptr=(CB_t*)malloc(sizeof(CB_t));
	CB_Init(cbufptr, buffer_length);
	
	for(i = 0; i < buffer_length; i++)
	{
    	data_add[i]=i;
		CB_AddItem(cbufptr, &data_add[i]);
	}

	for(i = 0; i < buffer_length; i++)
	{
    	CB_RemoveItem(cbufptr,&data_rec_array[i]);
	}
    for(i = 0; i < buffer_length; i++)
	{
    	if(data_add[i] != data_rec_array[i])
		{
	    	check++;	
		}
	}
	
	CB_Destroy(cbufptr);
	assert_int_equal(check,ZERO);
}

void cirbuf_buffer_full_test(void **state)
{
	uint32_t iterations=0;
	uint8_t data = 1;

 	CB_t *cbufptr = (CB_t*)malloc(sizeof(CB_t));
	CB_Init(cbufptr,buffer_length);

	while(iterations != buffer_length + 1)
	{
		CB_AddItem(cbufptr,&data);
		iterations++;
    }

	CB_status status=CB_IsFull(cbufptr);
	CB_Destroy(cbufptr);
	assert_int_equal(status, BUFFER_FULL);
}

void cirbuf_buffer_empty_test(void **state)
{
	CB_t *cbufptr = (CB_t*)malloc(sizeof(CB_t));
	CB_Init(cbufptr, buffer_length);	
	CB_status status = CB_IsEmpty(cbufptr);
	CB_Destroy(cbufptr);	
	assert_int_equal(status, BUFFER_EMPTY);
}

void cirbuf_wrap_add_test(void **state)
{
	uint32_t iterations = 0;
	uint8_t data = 1;
 	uint8_t check;

	CB_t *cbufptr = (CB_t*)malloc(sizeof(CB_t));
	CB_Init(cbufptr, buffer_length);

    while(iterations != buffer_length + 1)
	{
		CB_AddItem(cbufptr,&data);
		iterations++;
    }

	if(cbufptr->head == cbufptr->buffer_pointer)
	{
		check = ZERO;
	}
	
	CB_Destroy(cbufptr);
	assert_int_equal(check, ZERO);
}

void cirbuf_wrap_remove_test(void **state)
{	
	uint8_t *data_rec_ptr;
	uint8_t data_rec[buffer_length];
    uint32_t iterations=0;
	uint8_t data = 1;
	uint8_t check;

	CB_t *cbufptr = (CB_t*)malloc(sizeof(CB_t));
	CB_Init(cbufptr, buffer_length);
	data_rec_ptr = data_rec;

	while(iterations <= buffer_length)
    {
    	CB_AddItem(cbufptr, &data);
        iterations++;
	}

	for(int i = 0; i <= buffer_length; i++)
	{    		
		CB_RemoveItem(cbufptr,data_rec_ptr);
		data_rec_ptr++;
    }
 
	if(cbufptr->tail == cbufptr->buffer_pointer) 
	{ 
		check = ZERO;		
	}

	CB_Destroy(cbufptr);	
	assert_int_equal(check, ZERO);
}

void cirbuf_overfill_test(void **state)
{
	uint32_t iterations=0;
	uint8_t data = 1;

	CB_t *cbufptr = (CB_t*)malloc(sizeof(CB_t));
	CB_Init(cbufptr, buffer_length);

	while(iterations <= buffer_length)
    {
    	CB_AddItem(cbufptr, &data);
		iterations++;
    }

	CB_status status = CB_AddItem(cbufptr,&data);	
	assert_int_equal(status, BUFFER_FULL);
}

void cirbuf_over_empty_test(void **state)
{
	CB_t *cbufptr = (CB_t*)malloc(sizeof(CB_t));
	CB_Init(cbufptr, buffer_length);
	uint8_t data_rec;
	CB_status status = CB_RemoveItem(cbufptr, &data_rec);
	CB_Destroy(cbufptr);
	assert_int_equal(status, BUFFER_EMPTY);
}

int main (void)
{
	const struct CMUnitTest tests[] = 
	{
		cmocka_unit_test(cirbuf_allocate_free_test),
		cmocka_unit_test(cirbuf_invalid_pointer_test),
		cmocka_unit_test(cirbuf_initialized_buffer_test),
		cmocka_unit_test(cirbuf_add_remove_test),
		cmocka_unit_test(cirbuf_buffer_full_test),
		cmocka_unit_test(cirbuf_buffer_empty_test),
		cmocka_unit_test(cirbuf_wrap_add_test),
		cmocka_unit_test(cirbuf_wrap_remove_test),
		cmocka_unit_test(cirbuf_overfill_test),
		cmocka_unit_test(cirbuf_over_empty_test)
	};

	return cmocka_run_group_tests(tests, NULL, NULL);
}

