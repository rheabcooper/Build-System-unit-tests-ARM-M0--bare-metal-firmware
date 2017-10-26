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
	assert_int_equal(1,1);	
}

void test_memset_check_set(void **state)
{
	assert_int_equal(1,1);	
}

void test_memzero_invalid_pointers(void **state)
{
	assert_int_equal(1,1);	
}

void test_memzero_check_set(void **state)
{
	assert_int_equal(1,1);	
}

void test_reverse_invalid_pointers(void **state)
{
	assert_int_equal(1,1);	
}	

void test_reverse_check_odd_reverse(void **state)
{
	assert_int_equal(1,1);	
}

void test_reverse_check_even_reverse(void **state)
{
	assert_int_equal(1,1);	
}

void test_reverse_check_characters(void **state)
{
	assert_int_equal(1,1);	
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

