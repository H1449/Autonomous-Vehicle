//*****************************************************************************************/
//**************************AUTHOR: Mohamed Hesham Hassan***********************//
//**********************************DATE: 01.04.2024**********************************//
//****************************CONTACT: +201115581391*****************************//
//************************EMAIL: mohamedhassan5401@outlook.com****************//
//************************DRIVER: DC Motor Driver ******** *************************//
//***********************************VERSION: 0.0.1**********************************//
//*******************************FILE: DCMTR_CONFIG.H*****************************//
//************************************************************************************/

#ifndef DCMTR_CONFIG_H 
// Header guard . (if file is not defined then define it)
#define DCMTR_CONFIG_H

#define DCMTR_WD_TYPE DCMTR_CAR_4WD
/*DCMTR_CAR_2WD
    DCMTR_CAR_4WD*/

#define DCMTR_PWM_MODE DELAY_MODE
/*DE:AY_MODE
TMR_MODE*/


#define DCMTR_MAX_VEL_PWM_DC 50
#define DCMTR_MIN_VEL_PWM_DC 10

/*************************************************************/

#define DCMTR_FRONT_LEFT_EN_DDR GPIO_DDRD
#define DCMTR_FRONT_LEFT_EN_PORT GPIO_PORTD
#define DCMTR_FRONT_LEFT_EN_PIN 0

#define DCMTR_FRONT_LEFT_A_DDR GPIO_DDRD
#define DCMTR_FRONT_LEFT_A_PORT GPIO_PORTD
#define DCMTR_FRONT_LEFT_A_PIN 2

#define DCMTR_FRONT_LEFT_B_DDR GPIO_DDRD
#define DCMTR_FRONT_LEFT_B_PORT GPIO_PORTD
#define DCMTR_FRONT_LEFT_B_PIN 1
/******************************************************************/

#define DCMTR_FRONT_RIGHT_EN_DDR GPIO_DDRD
#define DCMTR_FRONT_RIGHT_EN_PORT GPIO_PORTD
#define DCMTR_FRONT_RIGHT_EN_PIN 5

#define DCMTR_FRONT_RIGHT_A_DDR GPIO_DDRD
#define DCMTR_FRONT_RIGHT_A_PORT GPIO_PORTD
#define DCMTR_FRONT_RIGHT_A_PIN 4

#define DCMTR_FRONT_RIGHT_B_DDR GPIO_DDRD
#define DCMTR_FRONT_RIGHT_B_PORT GPIO_PORTD
#define DCMTR_FRONT_RIGHT_B_PIN 3
/***************************************************************/

#define DCMTR_BACK_LEFT_EN_DDR GPIO_DDRC
#define DCMTR_BACK_LEFT_EN_PORT GPIO_PORTC
#define DCMTR_BACK_LEFT_EN_PIN 0

#define DCMTR_BACK_LEFT_A_DDR GPIO_DDRC
#define DCMTR_BACK_LEFT_A_PORT GPIO_PORTC
#define DCMTR_BACK_LEFT_A_PIN 2

#define DCMTR_BACK_LEFT_B_DDR GPIO_DDRC
#define DCMTR_BACK_LEFT_B_PORT GPIO_PORTC
#define DCMTR_BACK_LEFT_B_PIN 1
/********************************************************/

#define DCMTR_BACK_RIGHT_EN_DDR GPIO_DDRC
#define DCMTR_BACK_RIGHT_EN_PORT GPIO_PORTC
#define DCMTR_BACK_RIGHT_EN_PIN 5


#define DCMTR_BACK_RIGHT_A_DDR GPIO_DDRC
#define DCMTR_BACK_RIGHT_A_PORT GPIO_PORTC
#define DCMTR_BACK_RIGHT_A_PIN 4

#define DCMTR_BACK_RIGHT_B_DDR GPIO_DDRC
#define DCMTR_BACK_RIGHT_B_PORT GPIO_PORTC
#define DCMTR_BACK_RIGHT_B_PIN 3

#endif