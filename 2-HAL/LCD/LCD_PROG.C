//*****************************************************************************************/
//**************************AUTHOR: Mohamed Hesham Hassan***********************//
//**********************************DATE: 11.02.2024**********************************//
//****************************CONTACT: +201115581391*****************************//
//************************EMAIL: mohamedhassan5401@outlook.com****************//
//************************DRIVER: LCD; Liqiud Crystal Display Module ***************//
//***********************************VERSION: 0.0.1**********************************//
//*******************************FILE: LCD_PROG.C*******************************//
//*************************************************************************************/
/*1. check if lcd is busy
    2. enable e
    3. set r/w
    4. set rs switch for data/command
    5. send or do whatever
    6. disable e*/

//include essential header files (BIT_MATH and STD_TYPES)
#include <util/delay.h>
//#define F_CPU 16000000UL
#include "BIT_MATH.H"
#include "STD_TYPES.H"
#include "AT_REG.H" //this file is written by me to include all essential uncategorized addresses

//include header files of the driver
#include "GPIO_CONFIG.H"
#include "GPIO_INTERFACE.H"
#include "GPIO_PRIVATE.H"

#include "LCD_CONFIG.H"
#include "LCD_PRIVATE.H"
#include "LCD_INTERFACE.H"


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


void LCD_vSend_Command(u8 Command) // send command to LCD
{

	CLEAR_BIT(LCD_SIG_PORT,LCD_RS); // SET RS  to LOW : LOW for sending command and HIGH for data
	_delay_ms(2);
	CLEAR_BIT(LCD_SIG_PORT,LCD_RW);   // SET RW  to HIGH:  HIGH for READ and LOW for WRITE
	_delay_ms(2);

	LCD_DATA_PORT &= 0x0F ; //getting port ready //having data space cleared for rfeceiving new data
	LCD_DATA_PORT |= Command & 0xF0 ; // sending high nipple

	//enabling E bit for sending data
	SET_BIT(LCD_SIG_PORT,LCD_E);   // SET E  to HIGH
	_delay_ms(2);
	CLEAR_BIT(LCD_SIG_PORT,LCD_E);   // SET E  to LOW
	_delay_ms(2);
	//high nipple sent by now


	//to send low nipple
	LCD_DATA_PORT &= 0x0F ; //getting port ready //having data space cleared for rfeceiving new data
	LCD_DATA_PORT |= Command <<4; // sending low nipple

	//enabling E bit for sending data
	SET_BIT(LCD_SIG_PORT,LCD_E);   // SET E  to HIGH
	_delay_ms(2);
	//disabling E bit for sending data
	//LCD_DATA_PORT &= 0X0F ;
	CLEAR_BIT(LCD_SIG_PORT,LCD_E);   // SET E  to LOW
	_delay_ms(2);
}


void LCD_vSend_Data(u8 Data)
{

        //RS is set to HIGH and  R/W is set to LOW to send DATA
        SET_BIT(LCD_SIG_PORT,LCD_RS); // SET RS  to LOW : LOW for sending command and HIGH for data
        _delay_ms(2); 
        CLEAR_BIT(LCD_SIG_PORT,LCD_RW);   // SET RW  to HIGH:  HIGH for READ and LOW for WRITE
         _delay_ms(2); 

    //send command bit by bit 
    // to send high nipple
            LCD_DATA_PORT &= 0x0F ; //getting port ready //having data space cleared for rfeceiving new data
            LCD_DATA_PORT |= Data & 0xF0 ; // sending high nipple

        //enabling E bit for sending data   
        SET_BIT(LCD_SIG_PORT,LCD_E);   // SET E  to HIGH
        _delay_ms(2); 
        CLEAR_BIT(LCD_SIG_PORT,LCD_E);   // SET E  to LOW
        _delay_ms(2); 

        //to send low nipple
        LCD_DATA_PORT &= 0x0F ; //getting port ready //having data space cleared for rfeceiving new data
           LCD_DATA_PORT |= Data <<4;  // sending low nipple
     
        //enabling E bit for sending data
    SET_BIT(LCD_SIG_PORT,LCD_E);   // SET E  to HIGH
    _delay_ms(2); 
    CLEAR_BIT(LCD_SIG_PORT,LCD_E);   // SET E  to LOW
    _delay_ms(2); 

}

void LCD_vSend_String(u8* String)
{
  u8 index=0;
    while ( (*String) != '\0')
    {
        LCD_vSend_Data(String);
        String++;
    }
    
    
}
