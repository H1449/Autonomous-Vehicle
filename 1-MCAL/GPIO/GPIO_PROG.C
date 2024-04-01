//*****************************************************************************************/
//**************************AUTHOR: Mohamed Hesham Hassan***********************//
//**********************************DATE: 11.02.2024**********************************//
//****************************CONTACT: +201115581391*****************************//
//************************EMAIL: mohamedhassan5401@outlook.com****************//
//************************DRIVER: GPIO; General purpose input output***************//
//***********************************VERSION: 0.0.1**********************************//
//*******************************FILE: GPIO_PROG.C*******************************//
//*************************************************************************************/

//include essential header files (BIT_MATH and STD_TYPES)
#include "BIT_MATH.H"
#include "STD_TYPES.H"
#include "AT_REG.H" //this file is written by me to include all essential uncategorized addresses

//include header files of the driver
#include "GPIO_CONFIG.H"
#include "GPIO_PRIVATE.H"
#include "GPIO_INTERFACE.H"


void GPIO_vSET_PORT_DIRECTION(u8 PORT,u8 DIR) // finction to set port direction
{
    switch (PORT)
    { //assign port direction
    case GPIO_PA: switch (DIR) {case HIGH: SET_REG(GPIO_DDRA); break; default:CLEAR_REG(GPIO_DDRA) ;break; } ;break;
    case GPIO_PB: switch (DIR) {case HIGH: SET_REG(GPIO_DDRB); break; default:CLEAR_REG(GPIO_DDRB) ;break; } ;break;
    case GPIO_PC: switch (DIR) {case HIGH: SET_REG(GPIO_DDRC); break; default:CLEAR_REG(GPIO_DDRC) ;break; } ;break;
    case GPIO_PD: switch (DIR) {case HIGH: SET_REG(GPIO_DDRD); break; default:CLEAR_REG(GPIO_DDRD) ;break; } ;break;
    default:   break;
    }
}

void GPIO_vSET_PIN_DIRECTION(u8 PORT, u8 PIN, u8 DIR) // finction to set pin direction in a port
{
    switch (PORT)
    { //assign pin direction
    case GPIO_PA:   switch (DIR) {case HIGH: SET_BIT(GPIO_DDRA,PIN); break; default:CLEAR_BIT(GPIO_DDRA,PIN) ;break; } ;break;
    case GPIO_PB:   switch (DIR) {case HIGH: SET_BIT(GPIO_DDRB,PIN); break; default:CLEAR_BIT(GPIO_DDRB,PIN) ;break; } ;break;
    case GPIO_PC:   switch (DIR) {case HIGH: SET_BIT(GPIO_DDRC,PIN); break; default:CLEAR_BIT(GPIO_DDRC,PIN) ;break; } ;break;
    case GPIO_PD:   switch (DIR) {case HIGH: SET_BIT(GPIO_DDRD,PIN); break; default:CLEAR_BIT(GPIO_DDRD,PIN) ;break; } ;break;
    default:   break;
    }
}

void GPIO_vASSIGN_PORT(u8 PORT, u8 LEV)  // function to assign level to entire hardware port (HIGH or LOW)
{
 switch (PORT)
    { //assign port direction
    case GPIO_PA: switch (LEV) {case HIGH: SET_REG(GPIO_PORTA); break; default:CLEAR_REG(GPIO_PORTA) ;break; } ;break;
    case GPIO_PB: switch (LEV) {case HIGH: SET_REG(GPIO_PORTB); break; default:CLEAR_REG(GPIO_PORTB) ;break; } ;break;
    case GPIO_PC: switch (LEV) {case HIGH: SET_REG(GPIO_PORTC); break; default:CLEAR_REG(GPIO_PORTC) ;break; } ;break;
    case GPIO_PD: switch (LEV) {case HIGH: SET_REG(GPIO_PORTD); break; default:CLEAR_REG(GPIO_PORTD) ;break; } ;break;
    default:   break;
    }
}

void GPIO_vASSIGN_PIN(u8 PORT,u8 PIN,u8 LEV)  // function to assign level to  hardware pin in a port (HIGH or LOW)
{
      switch (PORT)
    { //assign pin level
    case GPIO_PA:   switch (LEV) {case HIGH: SET_BIT(GPIO_PORTA,PIN); break; default:CLEAR_BIT(GPIO_PORTA,PIN) ;break; } ;break;
    case GPIO_PB:   switch (LEV) {case HIGH: SET_BIT(GPIO_PORTB,PIN); break; default:CLEAR_BIT(GPIO_PORTB,PIN) ;break; } ;break;
    case GPIO_PC:   switch (LEV) {case HIGH: SET_BIT(GPIO_PORTC,PIN); break; default:CLEAR_BIT(GPIO_PORTC,PIN) ;break; } ;break;
    case GPIO_PD:   switch (LEV) {case HIGH: SET_BIT(GPIO_PORTD,PIN); break; default:CLEAR_BIT(GPIO_PORTD,PIN) ;break; } ;break; 
    default:   break;
    }
}

void GPIO_TOGGLE_PIN(u8 PORT, u8 PIN) //function to toggle bit in a port
{
          switch (PORT)
    { //toggle pin level
    case GPIO_PA: TOGGLE_BIT(GPIO_PORTA,PIN);break;
    case GPIO_PB: TOGGLE_BIT(GPIO_PORTB,PIN);break;
    case GPIO_PC: TOGGLE_BIT(GPIO_PORTC,PIN);break;
    case GPIO_PD: TOGGLE_BIT(GPIO_PORTD,PIN);break;    
    default:   break;
    }
}

u8 GPIO_u8GET_PIN(u8 PORT, u8 PIN) // function to read current hardware pin in a port return True or False
{
       switch (PORT)
    { //get pin level
    case GPIO_PA: return GET_BIT(GPIO_PINA,PIN); 
    case GPIO_PB: return GET_BIT(GPIO_PINB,PIN); 
    case GPIO_PC: return GET_BIT(GPIO_PINC,PIN); 
    case GPIO_PD: return GET_BIT(GPIO_PIND,PIN);   
    default: 
    return ERROR; 
    } 
}

