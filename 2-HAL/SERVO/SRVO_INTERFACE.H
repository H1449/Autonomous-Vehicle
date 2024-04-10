//*****************************************************************************************/
//**************************AUTHOR: Mohamed Hesham Hassan***********************//
//**********************************DATE: 01.04.2024**********************************//
//****************************CONTACT: +201115581391*****************************//
//************************EMAIL: mohamedhassan5401@outlook.com****************//
//************************DRIVER: SRVO; Liqiud Crystal Display Module ***************//
//***********************************VERSION: 0.0.1**********************************//
//*******************************FILE: SRVO_INTERFACE.H****************************//
//*************************************************************************************/

#ifndef SRVO_INTERFACE_H
 // Header guard . (if file is not defined then define it)
#define SRVO_INTERFACE_H

/*Servo needs PWM 50Hz (20ms) signal with duty cycle of 
~7.5% (1.5ms on time)  at 0*  
 5%  (1ms on time)     at -90* and
  10% (2ms on time)  at +90* 
 **/
/*   1Hz  <   Freq < 500Hz   typically Freq = ~50Hz. */
#define SRVO_SWEEP_TYPE_180
#define SRVO_SWEEP_TYPE_360

#define SRVO_DIRECTION_ANTICLKWISE 1
#define SRVO_DIRECTION_CLKWISE -1


void SRVO_vInit(); // initialize SERVO


void SRVO_SWEEP( u8 angle, u8 Direction );


   #if SRVO_USE_TMR0 == FALSE
    void  SRVO_vSend_PWM_IO_ANGLE0();
    void SRVO_vSend_PWM_IO_ANGLE90();
    void SRVO_vSend_PWM_IO_ANGLE_N90();
    void SRVO_vSend_PWM_IO_ANGLE_N45();
    void SRVO_vSend_PWM_IO_ANGLE_45();
   #endif


#endif //end of file