//*****************************************************************************************/
//**************************AUTHOR: Mohamed Hesham Hassan***********************//
//**********************************DATE: 01.04.2024**********************************//
//****************************CONTACT: +201115581391*****************************//
//************************EMAIL: mohamedhassan5401@outlook.com****************//
//************************DRIVER: SRVO; 4x4 Keypad Module********** ***************//
//***********************************VERSION: 0.0.1**********************************//
//*******************************FILE: SRVO_PRIVATE.H*******************************//
//*************************************************************************************/

#ifndef SRVO_PRIVATE_H 
// Header guard . (if file is not defined then define it)
#define SRVO_PRIVATE_H

/* 1ms     1.5ms      2ms  */
/*  -90         0           90  */
/* pulse(x) = 1.5ms (+) [ x * (0.5ms/90) ] , where  -90 < x <  90*/

#define SRVO_HOME_POS_PWM_DS 7.5 
#define SRVO_RANGE_PWM_DS 2.5
#define SRVO_ANGLE_STEP_PWM_DS (1/36)
#define SRVO_MAX_SERVE (SRVO_HOME_POS_PWM_DS + SRVO_RANGE_PWM_DS )
#define SRVO_MIN_SERVE  (SRVO_HOME_POS_PWM_DS - SRVO_RANGE_PWM_DS )
#endif