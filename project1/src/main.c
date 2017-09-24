/**
 * @file - main.c 
 * @brief - A main file for executing various function calls for project 1
 *
 * @author Brian Kelly and Rhea Cooper
 * @date September 23, 2017
 *
 */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "platform.h"
#include "project1.h"
#include "memory.h"
#include "conversion.h"
#include "debug.h"

#define PROJECT1
#define HOST

int main(void)
{
	#ifdef PROJECT1	
		project1();
	#endif

	return 0;
}
