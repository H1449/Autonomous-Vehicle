//*****************************************************************************************/
//**************************AUTHOR: Mohamed Hesham Hassan***********************//
//**********************************DATE: 16.02.2024**********************************//
//****************************CONTACT: +201115581391*****************************//
//************************EMAIL: mohamedhassan5401@outlook.com****************//
//************************DRIVER: LCD; Liqiud Crystal Display Module ***************//
//***********************************VERSION: 0.0.1**********************************//
//*******************************FILE: LCD_INTERFACE.H****************************//
//*************************************************************************************/

#ifndef LCD_INTERFACE_H
 // Header guard . (if file is not defined then define it)
#define LCD_INTERFACE_H

void LCD_vInit(void); //initialize module 
void LCD_vSend_Command(u8 Command);
void LCD_vSend_Data(u8 Data);
void LCD_vSend_String(u8* String);

/*LIST OF COMMANDS*/
#define LCD_COMM_CLEAR_SCREEN 0x01
#define LCD_COMM_RETURN_HOME 0x02
#define LCD_COMM_ENTRY_SET        ( (0x1<<2) + (LCD_I_D_INCREMENT_DECREMENT<<1) +  LCD_SH_SHIFT_DISPLAY)  //  Entry mode set
#define LCD_COMM_DISPLAY_ON_OFF_CTRL ( (0x01<<3) + (LCD_D_SCREEN_DISPLAY<<2) + (LCD_C_CURSOR_DISPLAY<<1) +  LCD_B_CURSOR_BLINK_DISPLAY) //  Display ON/OFF Control
#define LCD_COMM_SET_CURSOR_DISPLAY   ( (0x01<<4) + (LCD_SC<<3) + (LCD_RL_RIGHT_LEFT_CURSOR<<2) ) // Cursor Display SET
#define LCD_COMM_DISPLAY_ON_OFF           ( (0x01<<5) + (LCD_DL_INTERFACE_DATA_LENGTH<<4) + (LCD_N_LINE_NUMBER<<3) +  (LCD_F_FONT_SIZE<<2) ) //  Display ON/OFF Control

#endif //end of file