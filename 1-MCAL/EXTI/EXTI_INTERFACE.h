/*****************************************************************************************
**************************AUTHOR: Mohamed Hesham Hassan*************************
**********************************DATE: 23.02.2024*************************************
****************************CONTACT: +201115581391********************************
************************EMAIL: mohamedhassan5401@outlook.com*******************
************************DRIVER: EXTI; External Interrupt Perepheral********************
***********************************VERSION: 0.0.1**************************************
*******************************FILE: EXTI_INTERFACE.C**********************************
******************************************************************************************/
#ifndef EXTI_INTERFACE_H
 // Header guard . (if file is not defined then define it)
#define EXTI_INTERFACE_H

void EXTI_vInit(void) ;

#if  EXTI_ENABLE_INT0 == TRUE

void EXTI_ENABLE_INT0_INTERRUPT(void);

void EXTI_DISABLE_INT0_INTERRUPT(void);

void EXTI_vASSIGN_SENSE_CTRL_INT0(u8 sense_ctrl_state);

u8 EXTI_u8GET_INT0_FLAG(void);

void EXTI_vCLEAR_INT0_FLAG(void);

void EXTI_CALLBACK0( void *( function ) (void) ); /*Function in case of intterrupt*/

void __vector_1(void) __attribute__( (signal) ) ;//vector function prototype and optimization prevention

#endif

#if  EXTI_ENABLE_INT1 == TRUE

void EXTI_ENABLE_INT1_INTERRUPT(void);

void EXTI_DISABLE_INT1_INTERRUPT(void);

void EXTI_vASSIGN_SENSE_CTRL_INT1(u8 sense_ctrl_state);

u8 EXTI_u8GET_INT1_FLAG(void);

void EXTI_vCLEAR_INT1_FLAG(void);

void EXTI_CALLBACK1( void *( function ) (void) ); /*Function in case of intterrupt*/

void __vector_2(void)  __attribute__( (signal) ) ;//vector function prototype and optimization prevention

#endif

#if EXTI_ENABLE_INT2 == TRUE

void EXTI_ENABLE_INT2_INTERRUPT(void);

void EXTI_DISABLE_INT2_INTERRUPT(void);

void EXTI_vASSIGN_SENSE_CTRL_INT2(u8 sense_ctrl_state);

u8 EXTI_u8GET_INT2_FLAG(void);

void EXTI_vCLEAR_INT2_FLAG(void);

void EXTI_CALLBACK2( void *( function ) (void) ); /*Function in case of intterrupt*/

void __vector_3(void)  __attribute__( (signal) ) ;//vector function prototype and optimization prevention

#endif


#endif 
/*END OF FILE*/