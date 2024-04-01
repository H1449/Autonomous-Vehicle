//*****************************************************************************************/
//**************************AUTHOR: Mohamed Hesham Hassan***********************//
//**********************************DATE: 23.02.2024**********************************//
//****************************CONTACT: +201115581391*****************************//
//************************EMAIL: mohamedhassan5401@outlook.com****************//
//************************DRIVER: EXTI; External Interrupt Perepheral****************//
//***********************************VERSION: 0.1.5**********************************//
//*******************************FILE: EXTI_CONFIG.C*******************************//
//*************************************************************************************/


#ifndef EXTI_CONFIG_H 
// Header guard . (if file is not defined then define it)
#define EXTI_CONFIG_H

/*OPTIONS
    Command             Discription

-> EXTI_RISING          Rising Edge
-> EXTI_FALLING        Falling Edge
-> EXTI_LOW_LEVEL    Low Level
-> EXTI_ANY                Any logical change
*/

#define EXTI_INT0_SENSE_CONTROL EXTI_RISING 

#define EXTI_INT1_SENSE_CONTROL EXTI_RISING 

#define EXTI_INT2_SENSE_CONTROL EXTI_RISING 


#endif