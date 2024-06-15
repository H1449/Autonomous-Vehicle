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

#include "BIT_MATH.H"
#include "STD_TYPES.H"
#include "_ATMEGA32_.h"  //this file is written by me to include all essential uncategorized addresses
#include <util/delay.h>

//include header files of the driver
#include "TMR_CONFIG.H"
#include "TMR_PRIVATE.H"
#include "TMR_INTERFACE.H"
#include "SRVO_CONFIG.H"
#include "SRVO_PRIVATE.H"
#include "SRVO_INTERFACE.H"

void SRVO_vInit(u8 SRVO_PIN)
{
    GlobalInterrupt_Enable();
    switch (SRVO_PIN)
    {
        case SRVO_PIN_PB3:
            TMR0_vInit(TMR_MODE_FAST_PWM, TMR_PRESCALE_1024);
            TMR0_PWM_vASSIGN_INVERSION(TRUE);
            TMR0_vENABLE_CTC_INTERRUPT();
        break;

        case SRVO_PIN_PD7:
            TMR2_vInit(TMR_MODE_FAST_PWM, TMR_PRESCALE_1024);
            TMR2_PWM_vASSIGN_INVERSION(TRUE);
            TMR2_vENABLE_CTC_INTERRUPT();
        break;

        case SRVO_PIN_PD5:
            TMR1_vInit(TMR_MODE_FAST_PWM, TMR_PRESCALE_1024);
            TMR1_PWM_vASSIGN_INVERSION(TRUE);
            TMR1_vENABLE_CTCA_INTERRUPT();
        break;

        case SRVO_PIN_PD4:
            TMR1_vInit(TMR_MODE_FAST_PWM, TMR_PRESCALE_1024);
            TMR1_PWM_vASSIGN_INVERSION(TRUE);
            TMR1_vENABLE_CTCB_INTERRUPT();
        break;

    }


}

void SRVO_SWEEP( u8 angle, u8 Direction , u8 Angular_Speed )
{
    const u8 SRVO_delay = (u8) (Angular_Speed* SRVO_HOME_POS_PWM_DUTY_CYCLE);
    switch (Direction)
    {
    case SRVO_DIRECTION_ANTICLKWISE:
    for (f16 pwm= SRVO_HOME_POS_PWM_DUTY_CYCLE ;  
    pwm < SRVO_MAX_SERVE ; pwm+= SRVO_ANGLE_STEP_PWM_DUTY_CYCLE)
    {
        TMR_TMR0_PWM_SET_DUTY_CYCLE(pwm);
        _delay_ms( SRVO_delay );
    }
    break;
        case SRVO_DIRECTION_CLKWISE:
    for (f16 pwm= SRVO_HOME_POS_PWM_DUTY_CYCLE ; 
    pwm < SRVO_MAX_SERVE ; pwm+= SRVO_ANGLE_STEP_PWM_DUTY_CYCLE)
    {
        TMR_TMR0_PWM_SET_DUTY_CYCLE(pwm);
        _delay_ms( SRVO_delay );
    }
    break;

    }
}


