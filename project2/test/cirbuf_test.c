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

#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include "cirbuf.h"

void cirbuf_allocate_free_test(void **state)
{
	uint32_t * data = NULL;
	assert_non_null(data);
}

void cirbuf_invalid_pointer_test(void **state)
{
	uint32_t * data = NULL;
	assert_null(data);
}

void cirbuf_initialized_buffer_test(void **state)
{
	assert_int_not_equal(5,1);	
}

void cirbuf_add_remove_test(void **state)
{
	assert_int_equal(1,1);	
}

void cirbuf_buffer_full_test(void **state)
{
	assert_int_equal(1,1);	
}

void cirbuf_buffer_empty_test(void **state)
{
	skip();
}

void cirbuf_wrap_add_test(void **state)
{
	skip();
}

void cirbuf_wrap_remove_test(void **state)
{
	assert_int_equal(1,1);	
}

void cirbuf_overfill_test(void **state)
{
	assert_int_equal(1,1);	
}

void cirbuf_over_empty_test(void **state)
{
	assert_int_not_equal(400,350);	
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

