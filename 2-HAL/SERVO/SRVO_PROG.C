//*****************************************************************************************/
//**************************AUTHOR: Mohamed Hesham Hassan***********************//
//**********************************DATE: 01.04.2024**********************************//
//****************************CONTACT: +201115581391*****************************//
//************************EMAIL: mohamedhassan5401@outlook.com****************//
//************************DRIVER: SRVO; Liqiud Crystal Display Module ***************//
//***********************************VERSION: 0.0.1**********************************//
//*******************************FILE: SRVO_PROG.C*******************************//
//*************************************************************************************/

#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "_ATMEGA32_.h"  //this file is written by me to include all essential uncategorized addresses
#include <util/delay.h>

#include "TMR_PRIVATE.h"
#include "TMR_INTERFACE.h"
#include "SRVO_CONFIG.h"
#include "SRVO_PRIVATE.h"
#include "SRVO_INTERFACE.h"

void SRVO_vInit(void)
{
    #if SRVO_PIN == SRVO_PIN_PD5
        SET_BIT(TMR_OC1_DDR, TMR_OC1A_PIN);
    #else
        SET_BIT(TMR_OC_DDR, TMR_OC2A_PIN);
    #endif
    if (TMR1_MODE == TMR_MODE_PWM_INPUT_CAPTURE && TMR1_PRESCALE >=8)
    {
        TMR_ICR1 = (u16)  ( (F_CPU/(50*TMR1_PRESCALE) )-1 )
    }
}

void SRVO_SWEEP( s16 angle , u8 Angular_Speed )
{
    const u8 SRVO_DELAY_DEG_PER_ms = (u8) (SRVO_NORMAL_DELAY_ms*2/Angular_Speed);
    static u16 pwm = (u16) (SRVO_HOME_POS_PWM_DUTY_CYCLE);
    (if angle>=0 && angle <=90)
    {
        for ( ; pwm <= SRVO_CONVERT_ANGLE_TO_DUTY_CYCLE(angle);
                  pwm+= SRVO_ANGLE_STEP_PWM_DUTY_CYCLE )
        {
        #if SRVO_PIN == SRVO_PIN_PD5
        TMR1_vASSIGN_CTCA_VALUE((pwm* TMR_ICR1));
        #else
        TMR1_vASSIGN_CTCB_VALUE((pwm* TMR_ICR1));
        #endif
            _delay_ms( SRVO_DELAY_DEG_PER_ms );
        }
    }
   else
        (if angle>=-90 && angle <0)
        {
            for ( ; pwm > SRVO_CONVERT_ANGLE_TO_DUTY_CYCLE(angle);
                     pwm-= SRVO_ANGLE_STEP_PWM_DUTY_CYCLE )
            {
                #if SRVO_PIN == SRVO_PIN_PD5
                TMR1_vASSIGN_CTCA_VALUE((pwm* TMR_ICR1));
                #else
                TMR1_vASSIGN_CTCB_VALUE((pwm* TMR_ICR1));
                #endif
                _delay_ms( SRVO_delay );
            }
        }

}

/* 1ms     1.5ms      2ms  
  -90         0             90  
   5%       7.5%      10%*/
/* pulse(x) = 1.5ms (+) [ x * (0.5ms/90) ] , where  -90 < x <  90*/
/*Servo needs PWM 50Hz (20ms) signal with duty cycle of 
~7.5% (1.5ms on time)  at 0*  
 5%  (1ms on time)     at -90* and
  10% (2ms on time)  at +90* 
 **/

/*END*/