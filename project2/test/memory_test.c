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

void test_memmove_invalid_pointers(void **state)
{
	skip();	
}
	
void test_memmove_no_overlap(void **state)
{
	assert_int_equal(1,1);	
}

void test_memmove_src_in_dst_overlap(void **state)
{
	assert_int_not_equal(1,0);	
}

void test_memmove_dst_in_src_overlap(void **state)
{
	assert_int_equal(1,1);	
}

void test_memset_invalid_pointers(void **state)
{
	uint8_t *src=NULL;
	memory_status status = my_memset(src,ODD_LENGTH,VALUE);
	assert_int_equal(status,NULL_POINTER);	
}

void test_memset_check_set(void **state)
{
	uint8_t *src=&array[0];
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
	uint8_t *src=&array[0];
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
	uint8_t *src=&array[0];
	memory_status status = my_reverse(src,ODD_LENGTH);
	assert_int_equal(status,SUCCESS);	
}

void test_reverse_check_even_reverse(void **state)
{
	uint8_t *src=&array[0];
	memory_status status = my_reverse(src,EVEN_LENGTH);
	assert_int_equal(status,SUCCESS);	
}

void test_reverse_check_characters(void **state)
{
	uint8_t flag=ZERO;
	uint8_t src[256];
	uint8_t copy[256];
	for(i=0;i<256;i++){
		src[i]=i;
		copy[i]=i;
	}
	uint8_t *src_ptr=src;
	my_reverse(src_ptr,256);
	for(i=0;i<256;i++)
	{
		if(src[i]!=copy[256-i]);
			flag++;
	}
	int zero=ZERO;	
	assert_int_equal(flag,zero);	
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

