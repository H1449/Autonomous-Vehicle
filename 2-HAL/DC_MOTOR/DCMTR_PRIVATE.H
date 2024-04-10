//*****************************************************************************************/
//**************************AUTHOR: Mohamed Hesham Hassan***********************//
//**********************************DATE: 01.04.2024**********************************//
//****************************CONTACT: +201115581391*****************************//
//************************EMAIL: mohamedhassan5401@outlook.com****************//
//************************DRIVER: DC Motor Driver ******** *************************//
//***********************************VERSION: 0.0.1**********************************//
//*******************************FILE: DCMTR_PRIVATE_H.H*************************//
//************************************************************************************/

#ifndef DCMTR_PRIVATE_H 
// Header guard . (if file is not defined then define it)
#define DCMTR_PRIVATE_H

#define DCMTR_CAR_4WD 1
#define DCMTR_CAR_2WD 0

#define DELAY_MODE 1
#define TMR_MODE 0

#define DCMTR_MAX_PWM_DELAY (20*  ( DCMTR_MAX_VEL_PWM_DC/100) )

#define DCMTR_MIN_PWM_DELAY ( 20 * ( DCMTR_MIN_VEL_PWM_DC/100) )

#define DCMTR_SEND_PWM(PORT , PIN ) SET_BIT(PORT , PIN ); \
_delay_ms(15); \
 CLEAR_BIT(PORT , PIN ); \
    _delay_ms(5);

#endif