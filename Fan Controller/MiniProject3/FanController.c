/*
 * FanController.c
 *
 *  Created on: Oct 14, 2023
 *      Author: Youssef Abuzeid
 */
#include "lm35_sensor.h"
#include "dcmotor.h"
#include "lcd.h"


/* Global Variables*/
DcMotor_State g_state=OFF;
uint8 g_temp=0;



/*
 * Description :
 * Function responsible for displaying the state of the fan on the LCD
 */
void APP_printFanState(DcMotor_State state){
	LCD_moveCursor(0,10);
	switch (state){
	case OFF:
		LCD_displayString("OFF");
		break;
	case CW:


	case A_CW:

		LCD_displayString("ON ");
	}
}
/*
 * Description :
 * Function responsible for displaying the temperature on the LCD
 */
void APP_printTemprature(void){
	LCD_moveCursor(1,10);
	if(g_temp<10){
		LCD_intgerToString(g_temp);
		LCD_displayString("  ");
	}else if(g_temp<100){
		LCD_intgerToString(g_temp);
		LCD_displayString(" ");
	}else{
		LCD_intgerToString(g_temp);
	}
}
/*
 * Description :
 * Function responsible for Controling the Fan Based on the temperature
 */
void APP_controlMotor(void){
	if(g_temp>=120){
		g_state=CW;
		DcMotor_Rotate(g_state,100);
	}else if(g_temp>=90){
		g_state=CW;
		DcMotor_Rotate(g_state,75);
	}else if(g_temp>=60){
		g_state=CW;
		DcMotor_Rotate(g_state,50);
	}else if(g_temp>=30){
		g_state=CW;
		DcMotor_Rotate(g_state,25);
	}else{
		g_state=OFF;
		DcMotor_Rotate(g_state,0);
	}
}
int main(void){

	/*
	 * init the LM35 sensor
	 */
	LM35_init();
	/*
	 * init the LCD
	 */
	LCD_init();
	/*
	 * init the Dc motor
	 */
	DcMotor_Init();
	/*
	 * move the cursor to the starting position
	 */
	LCD_moveCursor(0,3);
	LCD_displayString("FAN is  ");
	APP_printFanState(g_state);
	LCD_moveCursor(1,3);
	LCD_displayString("Temp =    C");

	while(1){
		/*
		 * Get the temperature from the sensor
		 */
		g_temp=LM35_getTemperature();
		/*
		 * print the state of the fan
		 */
		APP_printFanState(g_state);
		/*
		 * print the temperature
		 */
		APP_printTemprature();
		/*
		 * control the fan based on temperature
		 */
		APP_controlMotor();


	}
}
