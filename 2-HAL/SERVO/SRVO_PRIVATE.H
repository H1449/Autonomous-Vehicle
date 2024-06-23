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
#define SRVO_PRIVATE_H

#define SRVO_MIN_SERVE_DUTY_CYCLE  5
#define SRVO_HOME_POS_PWM_DUTY_CYCLE 7.5 
#define SRVO_RANGE_PWM_DUTY_CYCLE 2.5
#define SRVO_MAX_SERVE_DUTY_CYCLE 10
#define SRVO_ANGLE_STEP_PWM_DUTY_CYCLE (1/36)

#define SRVO_CONVERT_ANGLE_TO_DUTY_CYCLE(ANGLE) (SRVO_HOME_POS_PWM_DUTY_CYCLE +(SRVO_ANGLE_STEP_PWM_DUTY_CYCLE*ANGLE))

#define SRVO_NORMAL_DELAY_ms 10

#endif