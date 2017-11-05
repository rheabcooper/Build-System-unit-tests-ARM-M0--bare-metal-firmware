/**
 * @file memory_test.c
 * @brief A file to perform unit tests on the memory functions. 
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

#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include "memory.h"
#define ZERO (0)
#define ODD_LENGTH (5)
#define EVEN_LENGTH (6)
#define VALUE (1)
#define TEST_MEMMOVE_LENGTH (16)
#define LENGTH (32)

uint8_t array[LENGTH];

void test_memmove_invalid_pointers(void **state)
{
	uint8_t *src=NULL;
	uint8_t *dst=NULL;
	memory_status status=my_memmove(src, dst, TEST_MEMMOVE_LENGTH);
	assert_int_equal(status,NULL_POINTER);	
}
	
void test_memmove_no_overlap(void **state)
{
	uint8_t *src = &array[0];
	uint8_t *dst = &array[16];
	uint8_t i;
	uint8_t flag=ZERO;

    /* Initialize the set to test values */
  	for( i = 0; i < LENGTH; i++)
  	{
    		array[i] = i;
  	}

  
  	my_memmove(src, dst, TEST_MEMMOVE_LENGTH);
 
  	for (i = 0; i < TEST_MEMMOVE_LENGTH; i++)
  	{
    		if (array[i + 16] != i)
    		{
      			flag++;
			break;
    		}
  	}
	assert_int_equal(flag,ZERO);
}

void test_memmove_src_in_dst_overlap(void **state)
{
	uint8_t *src = &array[8];
	uint8_t *dst = &array[0];
    uint8_t i;
	uint8_t flag=ZERO;

    /* Initialize the set to test values */
  	for( i = 0; i < LENGTH; i++)
  	{
    		array[i] = i;
  	}
  
  	my_memmove(src, dst, TEST_MEMMOVE_LENGTH);
 
  	for (i = 0; i < TEST_MEMMOVE_LENGTH; i++)
  	{
    		if (array[i] != (i+8))
    		{
      			flag++;
				break;
    		}
  	}

	assert_int_equal(flag,ZERO);		
}

void test_memmove_dst_in_src_overlap(void **state)
{
	uint8_t *src = &array[0];
	uint8_t *dst = &array[8];
	uint8_t i;
	uint8_t flag=ZERO;

    /* Initialize the set to test values */
  	for( i = 0; i < LENGTH; i++)
  	{
    		array[i] = i;
  	}

  	my_memmove(src, dst, TEST_MEMMOVE_LENGTH);
 
  	for (i = 0; i < TEST_MEMMOVE_LENGTH; i++)
  	{
    		if (array[i + 8] != i)
    		{
      			flag++;
				break;
    		}
  	}
	assert_int_equal(flag,ZERO);	
}

void test_memset_invalid_pointers(void **state)
{
	uint8_t *src=NULL;
	memory_status status = my_memset(src,ODD_LENGTH,VALUE);
	assert_int_equal(status,NULL_POINTER);	
}

void test_memset_check_set(void **state)
{	
	uint8_t i;
	uint8_t *src=&array[0];

	for( i = 0; i < LENGTH; i++)
  	{
    		array[i] = i;
  	}

	memory_status status = my_memset(src,ODD_LENGTH,VALUE);
	assert_int_equal(status,SUCCESS);	
}

void test_memzero_invalid_pointers(void **state)
{
	
	uint8_t *src=NULL;
	memory_status status = my_memzero(src,ODD_LENGTH);
	assert_int_equal(status,NULL_POINTER);
}

void test_memzero_check_set(void **state)
{	
	uint8_t i;
	uint8_t *src=&array[0];

	for( i = 0; i < LENGTH; i++)
  	{
    		array[i] = i;
  	}

	memory_status status = my_memzero(src,ODD_LENGTH);
	assert_int_equal(status,SUCCESS);		
}

void test_reverse_invalid_pointers(void **state)
{	
	uint8_t *src=NULL;
	memory_status status = my_reverse(src,ODD_LENGTH);
	assert_int_equal(status,NULL_POINTER);
}	

void test_reverse_check_odd_reverse(void **state)
{
	uint8_t i;
	uint8_t flag=ZERO;
	uint8_t copy[LENGTH];
	uint8_t *src=&array[0];

	for( i = 0; i < LENGTH; i++)
  	{
    	array[i] = i;
		copy[i] = i;
  	}

	my_reverse(src, ODD_LENGTH);

	for( i = 0; i < ODD_LENGTH; i++)
	{
		if(array[i] != copy[ODD_LENGTH-1-i])
		{
			flag++;
		}
	}
	
	assert_int_equal(flag,ZERO);
}

void test_reverse_check_even_reverse(void **state)
{
	uint8_t i;
	uint8_t flag=ZERO;
	uint8_t copy[LENGTH];
	uint8_t *src=&array[0];

	for( i = 0; i < LENGTH; i++)
  	{
    		array[i] = i;
		copy[i]=i;
  	}

	my_reverse(src,EVEN_LENGTH);

	for(i=0;i<EVEN_LENGTH;i++)
	{
		if(array[i]!=copy[EVEN_LENGTH-1-i])
		{
			flag++;
		}
	}

	assert_int_equal(flag,ZERO);	
}

void test_reverse_check_characters(void **state)
{
	uint16_t i;
	uint8_t flag=ZERO;
	uint8_t copy[256];
	uint8_t *src=&array[0];

	for(i = 0; i < 256; i++)
	{
		array[i]=i;
		copy[i]=i;
	}

	my_reverse(src,256);

	for(i=0;i<256;i++)
	{
		if(array[i] != copy[256-1-i])
		{
			flag++;
		}
	}

	assert_int_equal(flag,ZERO);	
}

int main(void)
{
	const struct CMUnitTest tests[] = 
	{
		cmocka_unit_test(test_memmove_invalid_pointers),
		cmocka_unit_test(test_memmove_no_overlap),
		cmocka_unit_test(test_memmove_src_in_dst_overlap),
		cmocka_unit_test(test_memmove_dst_in_src_overlap),
		cmocka_unit_test(test_memset_invalid_pointers),
		cmocka_unit_test(test_memset_check_set),
		cmocka_unit_test(test_memzero_invalid_pointers),
		cmocka_unit_test(test_memzero_check_set),
		cmocka_unit_test(test_reverse_invalid_pointers),
		cmocka_unit_test(test_reverse_check_odd_reverse),
		cmocka_unit_test(test_reverse_check_even_reverse),
		cmocka_unit_test(test_reverse_check_characters)
	};

	return cmocka_run_group_tests(tests, NULL, NULL);
}

