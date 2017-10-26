/**
 * @file conversion_test.c
 * @brief A file to perform unit tests on conversion functions. 
 *
 * Those functions are designed to be tested on the cmocka
 * unit test framework.
 * 
 * These cmocka test functions were all developed by Brian Kelly.  
 *
 * @author Brian Kelly 
 * @date October 25, 2017
 *
 */

#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include "conversion.h"

#define ZERO (0)

void test_big_to_little_invalid_pointers(void** state)
{
	uint32_t * data = NULL; 	
	uint32_t length = 10;
	/* pointer have not been allocated yet */

	big_to_little32(data, length);
	assert_non_null(data);
}

void test_big_to_little_valid_conversion(void **state)
{
	uint8_t retval;
	uint32_t * data = NULL;
	uint32_t length = 10;
	data = malloc(length * (sizeof(uint32_t))); 
	*data = 1234567890;
	retval = big_to_little32(data, length);
	free(data);
	assert_int_equal(retval, ZERO);
} 

void test_little_to_big_invalid_pointers(void** state)
{
	uint32_t * data = NULL; 	
	uint32_t length = 10;
	/* pointer have not been allocated yet */

	little_to_big32(data, length);
	assert_non_null(data);
}

void test_little_to_big_valid_conversion(void **state)
{
	uint8_t retval;
	uint32_t * data = NULL;
	uint32_t length = 10;
	data = malloc(length * (sizeof(uint32_t))); 
	*data = 1234567890;
	retval = little_to_big32(data, length);
	free(data);
	assert_int_equal(retval, ZERO);
} 

int main(void)
{
	const struct CMUnitTest tests[] = 
	{
		cmocka_unit_test(test_big_to_little_invalid_pointers),
		cmocka_unit_test(test_big_to_little_valid_conversion),
		cmocka_unit_test(test_little_to_big_invalid_pointers),
		cmocka_unit_test(test_little_to_big_valid_conversion)
	};

	return cmocka_run_group_tests(tests, NULL, NULL);
}



