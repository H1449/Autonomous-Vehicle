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

#include "TMR_CONFIG.h"
#include "TMR_PRIVATE.h"
#include "TMR_INTERFACE.h"
#include "SRVO_CONFIG.h"
#include "SRVO_PRIVATE.h"
#include "SRVO_INTERFACE.h"

u8 SRVO_vInit(void)
{
    u8 state = ERROR;
    #if SRVO_PIN == SRVO_PIN_PD5
        SET_BIT(TMR_OC1_DDR, TMR_OC1A_PIN);
    #else
        SET_BIT(TMR_OC1_DDR, TMR_OC2A_PIN);
    #endif
    if (TMR1_MODE == TMR_MODE_PWM_INPUT_CAPTURE && TMR1_PRESCALE >=8)
    {
        state = SUCCESS;

        u16 temp16 = 0; 
        switch (TMR1_PRESCALE)
        {
            case  8:  temp16 =  (u16)  ( (F_CPU/(400) )-1 );break;

            case  64:  temp16 =  (u16)  ( (F_CPU/(3200) )-1 );break;

            case  256:  temp16 =  (u16)  ( (F_CPU/(12800) )-1 );break;

            case  1024:  temp16 =  (u16)  ( (F_CPU/(51200) )-1 );break;
        }
        
        u8 temp =(u8) (temp16 >>8 );
        TMR_ICR1H = temp;
        TMR_ICR1L= (u8) (temp16 && 0x00FF);
    }
    return state;
}
void SRVO_SWEEP(s16 angle)
{
        static f32 pwm =0;
            if( angle>=0 && angle <=90)
    {
        TMR1_vSET_OC1A_ON_OUTPUT_COMPARE();
        TMR_OCR1AL = 10;
        for ( pwm = 7.5; pwm <= 10; pwm+= 0.1)
        {

         _delay_ms( 10 );
        }
    }
}
void SRVO_SWEEP2( s16 angle )
{ //, const u8 Angular_Speed 
   // #define SRVO_DELAY_DEG_PER_ms (u8) (SRVO_NORMAL_DELAY_ms*2/Angular_Speed);
   // #define SRVO_DELAY_ms (u8) (angle/Angular_Speed);

    static f32 pwm =0;
    if( angle>=0 && angle <=90)
    {
        //#define SRVO_DELAY_ms (u8) (angle/Angular_Speed);
        for (
            pwm = (SRVO_HOME_POS_PWM_DUTY_CYCLE);
            pwm <= (f32) SRVO_CONVERT_ANGLE_TO_DUTY_CYCLE(angle);
            pwm+= SRVO_ANGLE_STEP_PWM_DUTY_CYCLE 
            )
        {

        #if SRVO_PIN == SRVO_PIN_PD5
        TMR1_vSET_OC1A_ON_OUTPUT_COMPARE();
        u8 temp = TMR_ICR1L;
        TMR1_vASSIGN_CTCA_VALUE( (pwm* (temp +( TMR_ICR1H<<8) )) );
        #else
        TMR1_vSET_OC1B_ON_OUTPUT_COMPARE();
        u8 temp = TMR_ICR1L;
        TMR1_vASSIGN_CTCB_VALUE( (pwm* (temp +( TMR_ICR1H<<8) )) );
        #endif
            _delay_ms( SRVO_NORMAL_DELAY_ms );
        }
    }
   else
        if( angle>=-90 && angle <0)
        {
          //  #define SRVO_DELAY_ms (u8) (-1*angle/Angular_Speed);
            for ( ; pwm > SRVO_CONVERT_ANGLE_TO_DUTY_CYCLE(angle);
                     pwm-= SRVO_ANGLE_STEP_PWM_DUTY_CYCLE )
            {
                #if SRVO_PIN == SRVO_PIN_PD5
                    u8 temp = TMR_ICR1L;
                    TMR1_vASSIGN_CTCA_VALUE( (pwm* (temp +( TMR_ICR1H<<8) )) );
                #else
                    u8 temp = TMR_ICR1L;
                    TMR1_vASSIGN_CTCB_VALUE( (pwm* (temp +( TMR_ICR1H<<8) )) );
                #endif
                _delay_ms( SRVO_NORMAL_DELAY_ms );
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