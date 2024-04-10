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
#include "AT_REG.H" //this file is written by me to include all essential uncategorized addresses
#include <util/delay.h>
//include header files of the driver

#include "GPIO_CONFIG.H"
#include "GPIO_PRIVATE.H"
#include "GPIO_INTERFACE.H"


#include "SRVO_CONFIG.H"
#include "SRVO_PRIVATE.H"
#include "SRVO_INTERFACE.H"

 f16 pwm = SRVO_HOME_POS_PWM_DS;

void SRVO_vInit()
{
    #if SRVO_USE_TMR0 == TRUE
    TMR_TMR0_PWM_vInit(TMR_PRESCALE_256,FALSE);
    #else
    SET_BIT(GPIO_DDRD,7);
    #endif
   
}

void SRVO_SWEEP( u8 angle, u8 Direction)
{
#if SRVO_USE_TMR0 == TRUE
#include "TMR_CONFIG.H"
#include "TMR_PRIVATE.H"
#include "TMR_INTERFACE.H"

if (Direction == SRVO_DIRECTION_ANTICLKWISE)
    {
 
    for (pwm= SRVO_HOME_POS_PWM_DS ;  pwm <= (SRVO_HOME_POS_PWM_DS+ (SRVO_ANGLE_STEP_PWM_DS*angle) ) ; pwm+= SRVO_ANGLE_STEP_PWM_DS)
    {
        TMR_TMR0_PWM_SET_DUTY_CYCLE(pwm);
        _delay_ms(15);
    }
	
	}
	else
  {
    for (pwm= SRVO_HOME_POS_PWM_DS ;  pwm >= (SRVO_HOME_POS_PWM_DS - (SRVO_ANGLE_STEP_PWM_DS*angle) ) ; pwm-= SRVO_ANGLE_STEP_PWM_DS)
    {
        TMR_TMR0_PWM_SET_DUTY_CYCLE(pwm);
        _delay_ms( 15 );
    }
  } 
  #else
  if (Direction == SRVO_DIRECTION_ANTICLKWISE)
    {
          SRVO_vSend_PWM_IO_ANGLE_N90();
        _delay_ms(10);
        SRVO_vSend_PWM_IO_ANGLE_N45();
        _delay_ms(10);

         SRVO_vSend_PWM_IO_ANGLE0();
        _delay_ms(10);
        SRVO_vSend_PWM_IO_ANGLE_45();
        _delay_ms(10);
        SRVO_vSend_PWM_IO_ANGLE90();
        _delay_ms(10);


	
	}
	else
  {

      
        SRVO_vSend_PWM_IO_ANGLE90();
        _delay_ms(10);
        SRVO_vSend_PWM_IO_ANGLE_45();
        _delay_ms(10);
        SRVO_vSend_PWM_IO_ANGLE0();
          _delay_ms(10);
        SRVO_vSend_PWM_IO_ANGLE_N45();
          _delay_ms(10);
        SRVO_vSend_PWM_IO_ANGLE_N90();
  } 

  #endif

}

    #if SRVO_USE_TMR0 == FALSE
    #include "GPIO_CONFIG.H"
    #include "GPIO_INTERFACE.H"
    #include "GPIO_PRIVATE.H"
    void SRVO_vSend_PWM_IO_ANGLE0()
    {
        SET_BIT(GPIO_PORTD,7);
        _delay_us(1400);
        CLEAR_BIT(GPIO_PORTD,7);
        _delay_us(18600);
    }
        void SRVO_vSend_PWM_IO_ANGLE90()
    {
        SET_BIT(GPIO_PORTD,7);
        _delay_us(520);
        CLEAR_BIT(GPIO_PORTD,7);
        _delay_us(19480);
    }
            void SRVO_vSend_PWM_IO_ANGLE_N90()
    {
        SET_BIT(GPIO_PORTD,7);
        _delay_us(2400);
        CLEAR_BIT(GPIO_PORTD,7);
        _delay_us(19600);
    }
                void SRVO_vSend_PWM_IO_ANGLE_N45()
    {
        SET_BIT(GPIO_PORTD,7);
        _delay_us(1250);
        CLEAR_BIT(GPIO_PORTD,7);
        _delay_us(18750);
    }
    void SRVO_vSend_PWM_IO_ANGLE_45()
    {
        SET_BIT(GPIO_PORTD,7);
        _delay_us(1750);
        CLEAR_BIT(GPIO_PORTD,7);
        _delay_us(18250);
    }
    #endif
