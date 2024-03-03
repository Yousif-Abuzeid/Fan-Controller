 /******************************************************************************
 *
 * Module: LCD
 *
 * File Name: lcd.h
 *
 * Description: Header file for the LCD driver
 *
 * Author: Youssef Abuzeid
 * ******************************************************************************
 */
#ifndef LCD_H_
#define LCD_H_


/************************************************************************************************************************************
 * 												Includes
 ************************************************************************************************************************************/
#include "std_types.h"



/************************************************************************************************************************************
 * 												Port and pins Definitions
 ************************************************************************************************************************************/

#define NUMBER_OF_BITS			8
#define LCD_DATA_PIN_1			PIN4_ID
#define LCD_DATA_PIN_2			PIN5_ID
#define LCD_DATA_PIN_3			PIN6_ID
#define LCD_DATA_PIN_4			PIN7_ID
#define LCD_PORT_DATA			PORTC_ID
#define LCD_PORT_CONTROL		PORTD_ID
#define LCD_RS					PIN0_ID
#define LCD_EN					PIN2_ID

#if(NUMBER_OF_BITS!=8 && NUMBER_OF_BITS!=4)
#error("NUMBER OF BITS SHOULD BE 8 OR 4")
#endif
/************************************************************************************************************************************
 * 												Commands Definitions
 ************************************************************************************************************************************/
#define LCD_COMMAND_ONE_LINE_8_BIT		0x30
#define LCD_COMMAND_TWO_LINE_8_BIT		0x38
#define LCD_COMMAND_4_BIT_INIT_1		0x33
#define LCD_COMMAND_4_BIT_INIT_2		0x32
#define LCD_COMMAND_ONE_LINE_4_BIT		0x20
#define LCD_COMMAND_TWO_LINE_4_BIT		0x28
#define LCD_COMMAND_CURSOR_BLINK		0x0f
#define	LCD_COMMAND_CURSOR_OFF			0x0c
#define LCD_COMMAND_SHIFT_DISPLAY_LEFT	0x18
#define LCD_COMMAND_SHIFT_DISPLAY_RIGHT	0x1c
#define LCD_COMMAND_CLEAR_SCREEN		0x01


/************************************************************************************************************************************
 * 												Function Prototypes
 ************************************************************************************************************************************/
/*
 * Description :
 * Function responsible for sending a command for the LCD
 */
void LCD_sendCommand(uint8 a_Command);
/*
 * Description :
 * Function responsible for displaying a character on the LCD
 */
void LCD_displayCharacter(uint8 a_Char);
/*
 * Description :
 * Function responsible for initialization of the LCD
 */
void LCD_init(void);
/*
 * Description :
 * Function responsible for displaying a String on the LCD
 */
void LCD_displayString(uint8 * a_str);
/*
 * Description :
 * Function responsible for moving the cursor to a certain position
 */
void LCD_moveCursor(uint8 a_row,uint8 a_col);
/*
 * Description :
 * Function responsible for displaying a String on the LCD in a certain position
 */
void LCD_displayStringRowCol(uint8 * a_str,uint8 a_row,uint8 a_col);
/*
 * Description :
 * Function responsible for clearing the LCD
 */
void LCD_clearScreen(void);
/*
 * Description :
 * Function responsible for displaying an integer on the LCD
 */
void LCD_intgerToString(uint16 a_num);
/*
 * Description :
 * Function responsible for creating a custom character on the LCD
 */
void LCD_CreateCustomCharacter(uint8 *pucPattern,const uint8 cLocation);
#endif /* LCD_H_ */
