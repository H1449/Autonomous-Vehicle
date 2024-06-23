//*****************************************************************************************/
//**************************AUTHOR: Mohamed Hesham Hassan***********************//
//**********************************DATE: 11.02.2024**********************************//
//****************************CONTACT: +201115581391*****************************//
//************************EMAIL: mohamedhassan5401@outlook.com****************//
//************************DRIVER: GPIO; General purpose input output***************//
//***********************************VERSION: 0.0.1**********************************//
//*******************************FILE: GPIO_PRIVATE.H*******************************//
//*************************************************************************************/

#ifndef GPIO_PRIVATE_H 
// Header guard . (if file is not defined then define it)
#define GPIO_PRIVATE_H

//include DDR addresses (for IO direction)
#define GPIO_DDRA      ( ( * (volatile u8 *) 0X3A ) )
#define GPIO_DDRB      ( ( * (volatile u8 *) 0X37 ) )
#define GPIO_DDRC      ( ( * (volatile u8 *) 0X34 ) )
#define GPIO_DDRD      ( ( * (volatile u8 *) 0X31 ) )

//include PORT addresses (for output)
#define GPIO_PORTA      ( ( * (volatile u8 *) 0X3B ) )
#define GPIO_PORTB      ( ( * (volatile u8 *) 0X38 ) )
#define GPIO_PORTC      ( ( * (volatile u8 *) 0X35 ) )
#define GPIO_PORTD      ( ( * (volatile u8 *) 0X32 ) )

//include PIN adddresses (for input)
#define GPIO_PINA      ( ( * (volatile u8 *) 0X39 ) )
#define GPIO_PINB      ( ( * (volatile u8 *) 0X36 ) )
#define GPIO_PINC      ( ( * (volatile u8 *) 0X33 ) )
#define GPIO_PIND      ( ( * (volatile u8 *) 0X30 ) )

//define ports names for reference
#define GPIO_PA 0
#define GPIO_PB 1
#define GPIO_PC 2
#define GPIO_PD 3


//define invdevidual hardware PINS
//later

/*END OF FILE*/
#endif