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
#include "dma.h"
#include "memory.h"
#include <time.h>
#include <sys/time.h>
#include "profiling.h"

#define KL25Z
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





