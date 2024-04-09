//*****************************************************************************************/
//**************************AUTHOR: Mohamed Hesham Hassan***********************//
//**********************************DATE: 01.04.2024**********************************//
//****************************CONTACT: +201115581391*****************************//
//************************EMAIL: mohamedhassan5401@outlook.com****************//
//************************DRIVER: SRVO; Liqiud Crystal Display Module ***************//
//***********************************VERSION: 0.0.1**********************************//
//*******************************FILE: SRVO_PROG.C*******************************//
//*************************************************************************************/

//include essential header files (BIT_MATH and STD_TYPES)
#include <util/delay.h>
#include "BIT_MATH.H"
#include "STD_TYPES.H"
#include "AT_REG.H" //this file is written by me to include all essential uncategorized addresses

//include header files of the driver
#include "TMR_CONFIG.H"
#include "TMR_PRIVATE.H"
#include "TMR_INTERFACE.H"
#include "SRVO_CONFIG.H"
#include "SRVO_PRIVATE.H"
#include "SRVO_INTERFACE.H"

 f16 pwm = SRVO_HOME_POS_PWM_DS;
 
void SRVO_vInit()
{
    TMR_TMR0_PWM_vInit(TMR_PRESCALE_64,FALSE);
   
}

void SRVO_SWEEP( u8 angle, u8 Direction , u8 Angular_Speed )
{
    switch (Direction)
    {
    case SRVO_DIRECTION_ANTICLKWISE:
    for (pwm= SRVO_HOME_POS_PWM_DS ;  pwm < SRVO_MAX_SERVE ; pwm+= SRVO_ANGLE_STEP_PWM_DS)
    {
        TMR_TMR0_PWM_SET_DUTY_CYCLE(pwm);
        _delay_ms( Angular_Speed *  SRVO_HOME_POS_PWM_DS );
    }
    break;
        case SRVO_DIRECTION_CLKWISE:
    for (pwm= SRVO_HOME_POS_PWM_DS ;  pwm > SRVO_MIN_SERVE ; pwm-= SRVO_ANGLE_STEP_PWM_DS)
    {
            TMR_TMR0_PWM_SET_DUTY_CYCLE(pwm);
        _delay_ms( Angular_Speed *  SRVO_HOME_POS_PWM_DS );
    }
    break;

    default: break;
    }
}


