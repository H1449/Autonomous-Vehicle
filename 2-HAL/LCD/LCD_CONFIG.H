//*****************************************************************************************/
//**************************AUTHOR: Mohamed Hesham Hassan***********************//
//**********************************DATE: 16.02.2024**********************************//
//****************************CONTACT: +201115581391*****************************//
//************************EMAIL: mohamedhassan5401@outlook.com****************//
//************************DRIVER: LCD; Liqiud Crystal Display Module ***************//
//***********************************VERSION: 0.0.1**********************************//
//*******************************FILE: LCD_CONFIG.H***************** **************//
//************************************************************************************/

#ifndef LCD_CONFIG_H 
// Header guard . (if file is not defined then define it)
#define LCD_CONFIG_H

#define LCD_SIG_DIR   GPIO_DDRB //control port
#define LCD_SIG_PORT GPIO_PORTB //control port

#define LCD_RS  1   //register select
#define LCD_RW 2 //readwrite select
#define LCD_E     3  //Operation (data read write) enable signal

#define LCD_DATA_DIR    GPIO_DDRA 
#define LCD_DATA_PORT GPIO_PORTA

//entry set mode - assign cursor moving direction and blinking of the entire display (39us)
#define LCD_I_D_INCREMENT_DECREMENT HIGH  
#define LCD_SH_SHIFT_DISPLAY HIGH 

//Display ON OFF Control
#define LCD_D_SCREEN_DISPLAY HIGH
#define LCD_C_CURSOR_DISPLAY LOW 
#define LCD_B_CURSOR_BLINK_DISPLAY HIGH 

#define LCD_SC LOW 
#define LCD_RL_RIGHT_LEFT_CURSOR HIGH

//Function SET
#define LCD_N_LINE_NUMBER LOW 
#define LCD_F_FONT_SIZE      LOW 
#define LCD_DL_INTERFACE_DATA_LENGTH LOW 
#define LCD_4_BUS_NIP HIGH 

#endif