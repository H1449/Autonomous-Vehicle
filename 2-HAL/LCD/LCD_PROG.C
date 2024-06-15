//*****************************************************************************************/
//**************************AUTHOR: Mohamed Hesham Hassan***********************//
//**********************************DATE: 11.02.2024**********************************//
//****************************CONTACT: +201115581391*****************************//
//************************EMAIL: mohamedhassan5401@outlook.com****************//
//************************DRIVER: LCD; Liqiud Crystal Display Module ***************//
//***********************************VERSION: 0.0.1**********************************//
//*******************************FILE: LCD_PROG.C*******************************//
//*************************************************************************************/


//include essential header files (BIT_MATH and STD_TYPES)

#include "_ATMEGA32_.h"  //this file is written by me to include all essential uncategorized addresses
#include <util/delay.h>
#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "GPIO_PRIVATE.h"

#include "LCD_CONFIG.h"
#include "LCD_PRIVATE.h"
#include "LCD_INTERFACE.h"


void LCD_vInit(void) // set all pins of all ports OUTPUT and HIGH
{
	/*Delay more than 30 ms*/
	_delay_ms(70);
	/*SET SIGNAL PINS OUTPUT*/
	SET_BIT(LCD_SIG_DIR,LCD_E );
	SET_BIT(LCD_SIG_DIR,LCD_RS);
	SET_BIT(LCD_SIG_DIR,LCD_RW);
	_delay_ms(2);

	SET_BIT(LCD_DATA_DIR, LCD_DB4);
	SET_BIT(LCD_DATA_DIR, LCD_DB5);
	SET_BIT(LCD_DATA_DIR, LCD_DB6);
	SET_BIT(LCD_DATA_DIR, LCD_DB7);
	_delay_ms(5);
	LCD_vSend_Command(0x33);
	_delay_ms(2);
	LCD_vSend_Command(0x32);
	_delay_ms(2);
	LCD_vSend_Command(0x28); 
	_delay_ms(2);
	LCD_vSend_Command(0x0E); 
	_delay_ms(2);
	LCD_vSend_Command(0x01);
	_delay_ms(2);
	LCD_vSend_Command(0x02);
	_delay_ms(2);
}


void LCD_vSend_Command(u8 Command)
{

	CLEAR_BIT(LCD_SIG_PORT,LCD_RS); 
	_delay_ms(2);
	CLEAR_BIT(LCD_SIG_PORT,LCD_RW);  
	_delay_ms(2);

	LCD_DATA_PORT &= 0x0F ; 
	LCD_DATA_PORT |= (Command & 0xF0) ;

	SET_BIT(LCD_SIG_PORT,LCD_E); 
	_delay_ms(2);
	CLEAR_BIT(LCD_SIG_PORT,LCD_E); 
	_delay_ms(2);

	LCD_DATA_PORT &= 0x0F ; 
	LCD_DATA_PORT |= (Command <<4); 

	SET_BIT(LCD_SIG_PORT,LCD_E);  
	_delay_ms(2);
	CLEAR_BIT(LCD_SIG_PORT,LCD_E);  
	_delay_ms(2);
}


void LCD_vSend_Data(u8 Data)
{

	SET_BIT(LCD_SIG_PORT,LCD_RS); 
	_delay_ms(2); 
	CLEAR_BIT(LCD_SIG_PORT,LCD_RW);
	_delay_ms(2); 

	LCD_DATA_PORT &= 0x0F ; 
	LCD_DATA_PORT |= (Data & 0xF0) ; 

	SET_BIT(LCD_SIG_PORT,LCD_E);
	_delay_ms(2); 
	CLEAR_BIT(LCD_SIG_PORT,LCD_E);
	_delay_ms(2); 

	LCD_DATA_PORT &= 0x0F; 
	LCD_DATA_PORT |= Data <<4;

    SET_BIT(LCD_SIG_PORT,LCD_E); 
    _delay_ms(2); 
    CLEAR_BIT(LCD_SIG_PORT,LCD_E); 
    _delay_ms(2); 

}

void LCD_vSend_String(u8* String)
{

    while ( (*String) != '\0')
    {
        LCD_vSend_Data(*String);
        String++;
    }

}
