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

#include "TMR_CONFIG.h"
#include "TMR_INTERFACE.h"
#include "TMR_PRIVATE.h"

#include "USS_CONFIG.h"
#include "USS_PRIVATE.h"
#include "USS_INTERFACE.h"

  

static void uSS_vRead_Time(void)
{
    u8 Is_Echoed =LOW;

    switch (USS_ECHO_PORT)
        {
        case 'A' : Is_Echoed = GET_BIT(GPIO_PINA, USS_ECHO_PIN );break;

        case 'B' : Is_Echoed = GET_BIT(GPIO_PINB, USS_ECHO_PIN );break;

        case 'C' : Is_Echoed = GET_BIT(GPIO_PINC, USS_ECHO_PIN );break;

        case 'D' : Is_Echoed = GET_BIT(GPIO_PIND, USS_ECHO_PIN );break;
        }

    if( Is_Echoed == LOW && counter!=0 )
    {
        TMR2_vDISABLE_CTC_INTERRUPT();

        counter = 0;
    }
    counter++;
}

void USS_vInit(void)
{
    
    GlobalInterrupt_Enable();
    TMR2_vDISABLE_CTC_INTERRUPT();
    TMR2_vInit(TMR_MODE_CTC, TMR_PRESCALE_8);
    TMR2_vASSIGN_CTC_VALUE(USS_OCR_VALUE);
    TMR2_vSET_CTC_CALLBACK(&uSS_vRead_Time);

    #if USS_TRIG_PORT == 'A'
        SET_BIT(GPIO_DDRA, USS_TRIG_PIN );

    #elif USS_TRIG_PORT == 'B'
        SET_BIT(GPIO_DDRB, USS_TRIG_PIN );

    #elif USS_TRIG_PORT == 'C'
        SET_BIT(GPIO_DDRC, USS_TRIG_PIN );

    #elif USS_TRIG_PORT == 'D'
        SET_BIT(GPIO_DDRD, USS_TRIG_PIN );

    #endif

    #if USS_ECHO_PORT == 'A'
        CLEAR_BIT(GPIO_DDRA, USS_ECHO_PIN );

    #elif USS_ECHO_PORT == 'B'
        CLEAR_BIT(GPIO_DDRB, USS_ECHO_PIN );

    #elif USS_ECHO_PORT == 'C'
        CLEAR_BIT(GPIO_DDRC, USS_ECHO_PIN );

    #elif USS_ECHO_PORT == 'D'
        CLEAR_BIT(GPIO_DDRD, USS_ECHO_PIN );

    #endif
}

static void USS_vPULL_THE_TRIGGER(void)
{/*Send 10us pulse to trigger measurement*/
    switch (USS_TRIG_PORT)
    {
    case 'A' :
        CLEAR_BIT(GPIO_PORTA , USS_TRIG_PIN);_delay_us(20);
        SET_BIT(GPIO_PORTA, USS_TRIG_PIN );     _delay_us(25);
        CLEAR_BIT(GPIO_PORTA , USS_TRIG_PIN); _delay_us(20);
        break;
    case 'B' :
        CLEAR_BIT(GPIO_PORTB , USS_TRIG_PIN); _delay_us(20);
        SET_BIT(GPIO_PORTB, USS_TRIG_PIN );     _delay_us(25);
        CLEAR_BIT(GPIO_PORTB , USS_TRIG_PIN); _delay_us(20);
        break;
    case 'C' :
        CLEAR_BIT(GPIO_PORTC , USS_TRIG_PIN); _delay_us(20);
        SET_BIT(GPIO_PORTC, USS_TRIG_PIN );     _delay_us(25);
        CLEAR_BIT(GPIO_PORTC , USS_TRIG_PIN); _delay_us(20);
        break;
    case 'D' :
        CLEAR_BIT(GPIO_PORTD , USS_TRIG_PIN); _delay_us(20);
        SET_BIT(GPIO_PORTD, USS_TRIG_PIN );     _delay_us(25);
        CLEAR_BIT(GPIO_PORTD , USS_TRIG_PIN); _delay_us(20);
        break;
    }
}

u32 USS_u32GET_DISTANCE_mm(void)
{
    u8 Is_Echoed =FALSE;
    
    USS_vPULL_THE_TRIGGER();
    
    TMR2_vENABLE_CTC_INTERRUPT();

    f32 time_ms = (counter*USS_PERIOD_ms) + (TMR_TCNT2*USS_TIME_TICK_TIME_s*1000);


    return USS_MEASURE_DISTANCE_mm(time_ms);
}

