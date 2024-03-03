 /******************************************************************************
 *
 * Module: Temperature Sensor
 *
 * File Name: lm35_sensor.h
 *
 * Description: source file for the LM35 Temperature Sensor driver
 *
 * Author: Youssef Abuzeid
 *
 *******************************************************************************/

#include "lm35_sensor.h"
#include "adc.h"

/*
 * Configurations for LM35 sensor
 */
ADC_ConfigType ADC_Configurations={INTERNAL,F_CPU_8};


/*
 * Description :
 * Function responsible for initialization of ADC for LM35 sensor configurations.
 */
void  LM35_init(void){

	ADC_init(&ADC_Configurations);
}


/*
 * Description :
 * Function responsible for calculate the temperature from the ADC digital value.
 */
uint8 LM35_getTemperature(void)
{
	uint8 temp_value = 0;

	uint16 adc_value = 0;

	/* Read ADC channel where the temperature sensor is connected */
	adc_value = ADC_readChannel(SENSOR_CHANNEL_ID);

	/* Calculate the temperature from the ADC value*/
	temp_value = (uint8)(((uint32)adc_value*SENSOR_MAX_TEMPERATURE*ADC_INTERNAL_REF_VOLT)/(ADC_MAXIMUM_VALUE*SENSOR_MAX_VOLT_VALUE));

	return temp_value;
}

