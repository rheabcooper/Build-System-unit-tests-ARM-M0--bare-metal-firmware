/*
 * profiling.h
 *
 *  Created on: Dec 1, 2017
 *      Author: rhco4796
 */

#ifndef INCLUDES_PROFILING_H_
#define INCLUDES_PROFILING_H_

#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdio.h>
#include "conversion.h"
#include "memory.h"
#include <time.h>
#include <sys/time.h>

#ifdef KL25Z
#include "dma.h"

void Timer_init();

void Timer_start();

void Timer_stop();
#endif

void memmove_stdlib_profile(void);

void memset_stdlib_profile(void);

void memmove_profile(void);

void memset_profile(void);


#endif /* INCLUDES_PROFILING_H_ */
