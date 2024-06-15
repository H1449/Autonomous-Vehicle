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

#define SRVO_PIN_PB3    0
#define SRVO_PIN_PD5    1
#define SRVO_PIN_PD4    2
#define SRVO_PIN_PD7    3

void SRVO_vInit(u8 SRVO_PIN); // initialize SERVO

void SRVO_SWEEP( u8 angle, u8 Direction , u8 Angular_Speed );

/*Servo needs PWM 50Hz (20ms) signal with duty cycle of 
~7.5% (1.5ms on time)  at 0*  
 5%  (1ms on time)     at -90* and
  10% (2ms on time)  at +90* 
 **/
/*   1Hz  <   Freq < 500Hz   typically Freq = ~50Hz. */

#endif //end of file