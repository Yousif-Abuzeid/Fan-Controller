 /******************************************************************************
 *
 * Module: ADC
 *
 * File Name: adc.c
 *
 * Description: Source file for the AVR ADC driver
 *
 * Author: Youssef Abuzeid
 *
 *******************************************************************************/


#include "adc.h"
#include <avr\io.h>




/*
 * Description :
 * Function responsible for initialization of ADC driver.
 */
void ADC_init(const ADC_ConfigType * Config_Ptr){
	/*
	 * Adjust Refrence voltage to AVCC
	 */
	ADMUX=(Config_Ptr->ref_volt<<REFS0);

	/*
	 * Initialize to ADC0
	 */


	/*
	 * Enable ADC
	 */
	ADCSRA=(LOGIC_HIGH<<ADEN);
	/*
	 * Disable Interrupt Enable (in case of polling)
	 */

	/*
	 * Set prescaler
	 */
	ADCSRA|=(Config_Ptr->prescaler);

}

/*
 * Description :
 * Function responsible for giving the digital value on certain ADC channel.
 */
uint16 ADC_readChannel(uint8 ch_num){
	/*
	 * Clear Selection
	 */
	ADMUX&=0xC0;
	/*
	 * Select Wanted ADC PIN
	 */
	ADMUX|=ch_num;
	/*
	 * START CONVERSION
	 */
	ADCSRA|=(LOGIC_HIGH<<ADSC);

	/*
	 * POLLING
	 */
	while(!(ADCSRA&(LOGIC_HIGH<<ADIF))){

	}
	/*
	 * CLEAR FLAG
	 *
	 */
	ADCSRA|=(LOGIC_HIGH<<ADIF);
	/*
	 * RETUTN ADC VALUE
	 */
	return ADC;
}
