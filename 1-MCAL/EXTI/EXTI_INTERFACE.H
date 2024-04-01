//*****************************************************************************************/
//**************************AUTHOR: Mohamed Hesham Hassan***********************//
//**********************************DATE: 23.02.2024**********************************//
//****************************CONTACT: +201115581391*****************************//
//************************EMAIL: mohamedhassan5401@outlook.com****************//
//************************DRIVER: EXTI; External Interrupt Perepheral****************//
//***********************************VERSION: 0.0.1**********************************//
//*******************************FILE: EXTI_INTERFACE.C*****************************//
//*************************************************************************************/
#ifndef EXTI_INTERFACE_H
 // Header guard . (if file is not defined then define it)
#define EXTI_INTERFACE_H

void EXTI_vInit () ;

void EXTI_EN(); // enable global interrupt

void EXTI_DIS();//disable global interrupt

void EXTI_INT0_EN();

void EXTI_INT0_DIS();

void EXTI_INT1_EN();

void EXTI_INT1_DIS();

void EXTI_INT2_EN();

void EXTI_INT2_DIS();

void __vector_1(void)  __attribute__( (signal) ) ;//vector function prototype and optimization prevention

void __vector_2(void)  __attribute__( (signal) ) ;//vector function prototype and optimization prevention

void __vector_3(void)  __attribute__( (signal) ) ;//vector function prototype and optimization prevention

void EXTI_CALLBACK( void *( function ) (void) );
#endif //end of file