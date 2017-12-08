/*
 * rtc.c
 *
 *  Created on: Dec 1, 2017
 *      Author: rhco4796
 */
#include "cirbuf.h"


#include "MKL25Z4.h"
#include "rtc.h"
void rtc_init(void){
	SIM_SCGC6 |= SIM_SCGC6_RTC_MASK;
	//Enabling clock to Port D
	MCG_C1 |= MCG_C1_IRCLKEN_MASK;

		MCG_C2 &= ~(MCG_C2_IRCS_MASK);

		//Clock to port c
		SIM->SCGC5 |= SIM_SCGC5_PORTC_MASK;

		//Pin alternate 1
		PORTC_PCR1 |= PORT_PCR_MUX(1);

		//Set clock to RTC as RTC CLKIN
		SIM_SOPT1 |= SIM_SOPT1_OSC32KSEL(2);

		//Select clock for RTC CLKOUT as MCGIRCLK
		SIM_SOPT2 |= SIM_SOPT2_CLKOUTSEL(4);

		//Set up GPIO PTC pins for RTC
		PORTC_PCR3 |= PORT_PCR_MUX(5);

		//RTC Access


    //Enable software access and interrupts to the RTC module.


    //Clear all RTC registers.
    RTC_CR = RTC_CR_SWR_MASK;
    RTC_CR &= ~RTC_CR_SWR_MASK;

    //if (RTC_SR & RTC_SR_TIF_MASK){
   //      RTC_TSR = 0x00000000;
    //}
    //Set time compensation parameters. (These parameters can be different for each application)
    RTC_SR=~RTC_SR_TCE(1);
    RTC_TSR=1512686058;
    RTC_SR|=RTC_SR_TCE(1);

    //RTC_TCR = RTC_TCR_CIR(1) | RTC_TCR_TCR(0xFF);
    RTC_IER = 0;
    //Enable seconds interrupt
    RTC_IER |= RTC_IER_TSIE_MASK;

    //Enable time seconds interrupt for the module and enable its irq.
    NVIC_EnableIRQ(RTC_Seconds_IRQn);

    //Write to Time Seconds Register.

    //Enable time counter.
    //RTC_SR |= RTC_SR_TCE_MASK;


}



