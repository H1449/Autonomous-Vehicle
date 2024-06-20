/**************************************************************************************
**************************AUTHOR: Mohamed Hesham Hassan**********************
**********************************DATE: 10.06.2024**********************************
****************************CONTACT: +201115581391*****************************
************************EMAIL: mohamedhassan5401@outlook.com****************
************************DRIVER: Ultrasonic Sensor***********************************
***********************************VERSION: 1.2.5***********************************
*******************************FILE: USS_PROGRAM.C*******************************
**************************************************************************************/
#include "_ATMEGA32_.h"
#include <util/delay.h>
#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include"GPIO_PRIVATE.h"

#include "USS_CONFIG.h"
#include "USS_PRIVATE.h"
#include "USS_INTERFACE.h"

void USS_vInit(void)
{

    TMR2_vInit(TMR_MODE_CTC, TMR_PRESCALE_8);
    TMR2_vReset_Prescaler();
    TMR2_vSET_CTC_CALLBACK(&uSS_vRead_Time);

    #if USS_TRIG_PORT == 'A'
        SET_BIT(GPIO_DDRA, USS_TRIG_PIN );
        TRIGGER_PORT=GPIO_PORTA;
    #elif USS_TRIG_PORT == 'B'
        SET_BIT(GPIO_DDRB, USS_TRIG_PIN );
        TRIGGER_PORT=GPIO_PORTB;
    #elif USS_TRIG_PORT == 'C'
        SET_BIT(GPIO_DDRC, USS_TRIG_PIN );
        TRIGGER_PORT=GPIO_PORTC;
    #elif USS_TRIG_PORT == 'D'
        SET_BIT(GPIO_DDRD, USS_TRIG_PIN );
        TRIGGER_PORT=GPIO_PORTD;
    #endif

    #if USS_ECHO_PORT == 'A'
        CLEAR_BIT(GPIO_DDRA, USS_ECHO_PIN );
        ECHO_PIN = GPIO_PINA;
    #elif USS_ECHO_PORT == 'B'
        CLEAR_BIT(GPIO_DDRB, USS_ECHO_PIN );
        ECHO_PIN = GPIO_PINB;
    #elif USS_ECHO_PORT == 'C'
        CLEAR_BIT(GPIO_DDRC, USS_ECHO_PIN );
        ECHO_PIN = GPIO_PINC;
    #elif USS_ECHO_PORT == 'D'
        CLEAR_BIT(GPIO_DDRD, USS_ECHO_PIN );
        ECHO_PIN = GPIO_PIND;
    #endif
}

static void uSS_vRead_Time(void)
{
    counter++;
    if( GET_BIt(ECHO_PIN, USS_TRIG_PIN) == LOW )
    {
        GlobalInterrupt_Disable();
        time_ms = (counter*USS_PERIOD_ms) + (TMR_TCNT2*USS_TIME_TICK_TIME_s*1000);
        counter = 0;
    }
    

}

static void USS_vPULL_THE_TRIGGER(void)
{/*Send 10us pulse to trigger measurement*/
    CLEAR_BIT(USS_TRIG_PORT , USS_TRIG_PIN);
    _delay_us(2);
    SET_BIT(USS_TRIG_PORT , USS_TRIG_PIN);
    _delay_us(10);
    CLEAR_BIT(USS_TRIG_PORT , USS_TRIG_PIN);
    _delay_us(2);
}

u32 USS_u32GET_DISTANCE_mm(void)
{
    USS_vPULL_THE_TRIGGER();
    TMR2_vENABLE_CTC_INTERRUPT();
    while( GET_BIt(ECHO_PIN, USS_TRIG_PIN) == LOW  );
    TMR2_vSet_Prescaler(TMR_PRESCALE_8);
    TMR2_vASSIGN_CTC_VALUE(USS_OCR_VALUE);
    GlobalInterrupt_Enable();
    while(time_ms == 0.0);
    TMR2_vReset_Prescaler();
    TMR2_vDISABLE_CTC_INTERRUPT();
    time_ms=0.0;
    return USS_MEASURE_DISTANCE_mm(time_ms);
}

