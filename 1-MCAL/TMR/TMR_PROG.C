//*****************************************************************************************/
//**************************AUTHOR: Mohamed Hesham Hassan***********************//
//**********************************DATE: 23.02.2024**********************************//
//****************************CONTACT: +201115581391*****************************//
//************************EMAIL: mohamedhassan5401@outlook.com****************//
//************************DRIVER: TMR; External Interrupt Perepheral****************//
//***********************************VERSION: 0.0.1**********************************//
//*******************************FILE: TMR_PROG.C*******************************//
//*************************************************************************************/

//include essential header files (BIT_MATH and STD_TYPES)
#include "BIT_MATH.H"
#include "STD_TYPES.H"
#include "AT_REG.H"  //this file is written by me to include all essential uncategorized addresses

#include "GPIO_CONFIG.H"
#include "GPIO_INTERFACE.H"
#include "GPIO_PRIVATE.H"
//include header files of the driver
#include "TMR_CONFIG.H"
#include "TMR_PRIVATE.H"
#include "TMR_INTERFACE.H"

#if  TMR_TMR0_EN == TRUE
void TMR_TMR0_vInit( u8 MODE , u8 PRESCALER)
{

    /*Set mode of Operation*/
    if (MODE == TMR_MODE_NORMAL )
    {
        TMR_TMR0_ASSIGN_TCNT0(0);
        CLEAR_BIT( TMR_TCCR0 , TMR_TCCR0_WGM00 ) ;
        CLEAR_BIT( TMR_TCCR0 , TMR_TCCR0_WGM01 ) ;
    }
    else
    {
        if (  MODE == TMR_MODE_CTC )
        {
            CLEAR_BIT( TMR_TCCR0 , TMR_TCCR0_WGM00 ) ;
            SET_BIT(       TMR_TCCR0 , TMR_TCCR0_WGM01 ) ;
        }
        else
        {
            if (   MODE == TMR_MODE_PWM )
            {
                SET_BIT(    TMR_TCCR0 , TMR_TCCR0_WGM00 ) ;
                CLEAR_BIT( TMR_TCCR0 , TMR_TCCR0_WGM01 ) ;
            }
            else 
            {       // TMR_MODE_FAST_PWM
                 SET_BIT( TMR_TCCR0 , TMR_TCCR0_WGM00 ) ;
                SET_BIT( TMR_TCCR0 , TMR_TCCR0_WGM01 ) ;
            }   
        }
    }
 
    /*Set Prescaler Value*/
    switch (PRESCALER)
    {
    case TMR_PRESCALE_1:
        SET_BIT( TMR_TCCR0 , TMR_TCCR0_CS00 );
        CLEAR_BIT( TMR_TCCR0 , TMR_TCCR0_CS01 );
        CLEAR_BIT( TMR_TCCR0 , TMR_TCCR0_CS02 );
        break;
    case TMR_PRESCALE_8:
        CLEAR_BIT( TMR_TCCR0 , TMR_TCCR0_CS00 );
        SET_BIT( TMR_TCCR0 , TMR_TCCR0_CS01 );
        CLEAR_BIT( TMR_TCCR0 , TMR_TCCR0_CS02 );
        break;
    case TMR_PRESCALE_64:
        SET_BIT( TMR_TCCR0 , TMR_TCCR0_CS00 );
        SET_BIT( TMR_TCCR0 , TMR_TCCR0_CS01 );
        CLEAR_BIT( TMR_TCCR0 , TMR_TCCR0_CS02 );
        break;
    case TMR_PRESCALE_256:
        CLEAR_BIT( TMR_TCCR0 , TMR_TCCR0_CS00 );
        CLEAR_BIT( TMR_TCCR0 , TMR_TCCR0_CS01 );
        SET_BIT( TMR_TCCR0 , TMR_TCCR0_CS02 );
        break;
    case TMR_PRESCALE_1024:
        SET_BIT( TMR_TCCR0 , TMR_TCCR0_CS00 );
        CLEAR_BIT( TMR_TCCR0 , TMR_TCCR0_CS01 );
        SET_BIT( TMR_TCCR0 , TMR_TCCR0_CS02 );
        break;
     case TMR_XCLK_FALLING:
        CLEAR_BIT( TMR_TCCR0 , TMR_TCCR0_CS00 );
        SET_BIT( TMR_TCCR0 , TMR_TCCR0_CS01 );
        SET_BIT( TMR_TCCR0 , TMR_TCCR0_CS02 );
        break;
    case TMR_XCLK_RISING:
        SET_BIT( TMR_TCCR0 , TMR_TCCR0_CS00 );
        SET_BIT( TMR_TCCR0 , TMR_TCCR0_CS01 );
        SET_BIT( TMR_TCCR0 , TMR_TCCR0_CS02 );
        break;

    default:
        CLEAR_BIT( TMR_TCCR0 , TMR_TCCR0_CS00 );
        CLEAR_BIT( TMR_TCCR0 , TMR_TCCR0_CS01 );
        CLEAR_BIT( TMR_TCCR0 , TMR_TCCR0_CS02 );
        break;
    }

}

void TMR_TMR0_DISCONNECT_OC0()
{
     CLEAR_BIT( TMR_TCCR0 , TMR_TCCR0_COM00 ) ;
     CLEAR_BIT( TMR_TCCR0 , TMR_TCCR0_COM01 ) ;
}

void TMR_TMR0_SET_OC0()
{
     SET_BIT( TMR_TCCR0 , TMR_TCCR0_COM00 ) ;
     SET_BIT( TMR_TCCR0 , TMR_TCCR0_COM01 ) ;
}

void TMR_TMR0_CLEAR_OC0()
{
    CLEAR_BIT( TMR_TCCR0 , TMR_TCCR0_COM00 ) ;
     SET_BIT( TMR_TCCR0 , TMR_TCCR0_COM01 ) ;
}

void TMR_TMR0_TOGGLE_OC0()
{
     SET_BIT(      TMR_TCCR0 , TMR_TCCR0_COM00 ) ;
     CLEAR_BIT( TMR_TCCR0 , TMR_TCCR0_COM01 ) ;
}

void TMR_TMR0_PWM_DISCONNECT_OC0()
{
     CLEAR_BIT( TMR_TCCR0 , TMR_TCCR0_COM00 ) ;
     CLEAR_BIT( TMR_TCCR0 , TMR_TCCR0_COM01 ) ;
}

void TMR_TMR0_PWM_SET_OC0()
{
     SET_BIT( TMR_TCCR0 , TMR_TCCR0_COM00 ) ;
     SET_BIT( TMR_TCCR0 , TMR_TCCR0_COM01 ) ;
}

void TMR_TMR0_PWM_CLEAR_OC0()
{
    CLEAR_BIT( TMR_TCCR0 , TMR_TCCR0_COM00 ) ;
     SET_BIT( TMR_TCCR0 , TMR_TCCR0_COM01 ) ;
}

void TMR_TMR0_FASTPWM_DISCONNECT_OC0()
{
     CLEAR_BIT( TMR_TCCR0 , TMR_TCCR0_COM00 ) ;
     CLEAR_BIT( TMR_TCCR0 , TMR_TCCR0_COM01 ) ;
}

void TMR_TMR0_FASTPWM_SET_OC0()
{
     SET_BIT( TMR_TCCR0 , TMR_TCCR0_COM00 ) ;
     SET_BIT( TMR_TCCR0 , TMR_TCCR0_COM01 ) ;
}

void TMR_TMR0_FASTPWM_CLEAR_OC0()
{
    CLEAR_BIT( TMR_TCCR0 , TMR_TCCR0_COM00 ) ;
     SET_BIT( TMR_TCCR0 , TMR_TCCR0_COM01 ) ;
}

/*void TMR_TMR0_DELAY_ms(u8 time_in_ms)
{
    u8 prescaler = TMR_PRESCALE_1024;
    f16 period = 1/F_CPU;
    u8 tick = period * prescaler;
    u8 compare_value = time_in_ms / tick;
    while (compare_value == 0 &&  prescaler >= TMR_PRESCALE_64)
    {
        prescaler/=4;
       tick = period * prescaler;
       compare_value = time_in_ms / tick;
    }*/
    
void TMR_TMR0_ASSIGN_TCNT0(u8 TCNT_VALUE)
{
    TMR_TCNT0 = TCNT_VALUE;
}

u8 TMR_TMR0_GET_TCNT0()
{
    return TMR_TCNT0;
}

void TMR_TMR0_vSET_COMPARE_MATCH(u8 OCR_VALUE)
{
    TMR_OCR0 = OCR_VALUE;
}

void TMR_TMR0_SET_CALLBACK( void ( *pFunction ) ( void ) )
{
    if (pFunction != NULL)
    {
       TMR_pOVF = pFunction;
    }
    
}

void __vector_11()
{
    /* To be Written*/
}

u8 TMR_TMR0_u8GET_COMPARE_MATCH()
{
    return TMR_OCR0;
}

void TMR_TMR0_OCI_EN_COMPARE_MATCH()
{
     SET_BIT( TMR_TIMSK , TMR_TIMSK_OCIE0 ) ;
}

u8 TMR_TMR0_GET_OCIE_COMPARE_MATCH()
{
     return GET_BIT( TMR_TIMSK , TMR_TIMSK_OCIE0 ) ;
}

void TMR_TMR0_TOI_EN_OVERFLOW()
{
     SET_BIT( TMR_TIMSK , TMR_TIMSK_TOIE ) ;
}

u8 TMR_TMR0_GET_TOIE_OVERFLOW()
{
     return GET_BIT( TMR_TIMSK , TMR_TIMSK_TOIE ) ;
}


u8 TMR_TMR0_GET_OCF_COMPARE_MATCH()
{
     return GET_BIT( TMR_TIFR , TMR_TIFR_OCF0 ) ;
}

u8 TMR_TMR0_GET_TOV_OVERFLOW()
{
     return GET_BIT( TMR_TIFR , TMR_TIFR_TOV0 ) ;
}

void TMR_TMR0_PWM_vInit(u8 PRESCALER, u8 is_inverted)
{
    SET_BIT(GPIO_DDRB , 3 ); //OC0 as output
 TMR_TMR0_vInit(TMR_MODE_FAST_PWM , PRESCALER);


    if ( is_inverted )
        TMR_TMR0_FASTPWM_SET_OC0();
    else
        TMR_TMR0_FASTPWM_CLEAR_OC0();

}

void TMR_TMR0_PWM_SET_DUTY_CYCLE(f16 duty_cycle)
{
if(duty_cycle <100 && duty_cycle >0)
TMR_TMR0_vSET_COMPARE_MATCH( (u8) ( (duty_cycle * 255)/100 )  );

}

#endif


#if  TMR_TMR1_EN == TRUE

void TMR_TMR1_vInit( u8 TMR_MODE, u8 TMR_PRESCALER)
{
      /*Set mode of Operation*/
    if (MODE == TMR_MODE_NORMAL )
    {
        CLEAR_BIT( TMR_TCCR1B , TMR_TCCR1B_WGM13 ) ;
        CLEAR_BIT( TMR_TCCR1B , TMR_TCCR1B_WGM12 ) ;
    }
    else /*need modification*/
    {
        if (  MODE == TMR_MODE_CTC )
        {
            CLEAR_BIT( TMR_TCCR0 , TMR_TCCR0_WGM00 ) ;
            SET_BIT(       TMR_TCCR0 , TMR_TCCR0_WGM01 ) ;
        }
        else
        {
            if (   MODE == TMR_MODE_PWM )
            {
                SET_BIT(    TMR_TCCR0 , TMR_TCCR0_WGM00 ) ;
                CLEAR_BIT( TMR_TCCR0 , TMR_TCCR0_WGM01 ) ;
            }
            else 
            {       // TMR_MODE_FAST_PWM
                 SET_BIT( TMR_TCCR0 , TMR_TCCR0_WGM00 ) ;
                SET_BIT( TMR_TCCR0 , TMR_TCCR0_WGM01 ) ;
            }   
        }
    }
 
    /*Set Prescaler Value*/
    switch (PRESCALER)
    {
    case TMR_PRESCALE_1:
        SET_BIT( TMR_TCCR1B , TMR_TCCR1B_CS10 );
        CLEAR_BIT( TMR_TCCR1B , TMR_TCCR1B_CS11 );
        CLEAR_BIT( TMR_TCCR1B , TMR_TCCR1B_CS12 );
        break;
    case TMR_PRESCALE_8:
        CLEAR_BIT( TMR_TCCR1B , TMR_TCCR1B_CS10 );
        SET_BIT( TMR_TCCR1B , TMR_TCCR1B_CS11 );
        CLEAR_BIT( TMR_TCCR1B , TMR_TCCR1B_CS12 );
        break;
    case TMR_PRESCALE_64:
        SET_BIT( TMR_TCCR1B , TMR_TCCR1B_CS10 );
        SET_BIT( TMR_TCCR1B , TMR_TCCR1B_CS11 );
        CLEAR_BIT( TMR_TCCR1B , TMR_TCCR1B_CS12 );
        break;
    case TMR_PRESCALE_256:
        CLEAR_BIT( TMR_TCCR1B , TMR_TCCR1B_CS10 );
        CLEAR_BIT( TMR_TCCR1B , TMR_TCCR1B_CS11 );
        SET_BIT( TMR_TCCR1B , TMR_TCCR1B_CS12 );
        break;
    case TMR_PRESCALE_1024:
        SET_BIT( TMR_TCCR1B , TMR_TCCR1B_CS10 );
        CLEAR_BIT( TMR_TCCR1B , TMR_TCCR1B_CS11 );
        SET_BIT( TMR_TCCR1B , TMR_TCCR1B_CS12 );
        break;
     case TMR_XCLK_FALLING:
        CLEAR_BIT( TMR_TCCR1B , TMR_TCCR1B_CS10 );
        SET_BIT( TMR_TCCR1B , TMR_TCCR1B_CS11 );
        SET_BIT( TMR_TCCR1B , TMR_TCCR1B_CS12 );
        break;
    case TMR_XCLK_RISING:
        SET_BIT( TMR_TCCR1B , TMR_TCCR1B_CS10 );
        SET_BIT( TMR_TCCR1B , TMR_TCCR1B_CS11 );
        SET_BIT( TMR_TCCR1B , TMR_TCCR1B_CS12 );
        break;

    default:
        CLEAR_BIT( TMR_TCCR1B , TMR_TCCR1B_CS10 );
        CLEAR_BIT( TMR_TCCR1B , TMR_TCCR1B_CS11 );
        CLEAR_BIT( TMR_TCCR1B , TMR_TCCR1B_CS12 );
        break;
    }

}

void TMR_TMR1_INPUT_CAPTURE_EDGE_SELECT(u8 edge)
{
    switch (edge)
    {
    case TMR_RISING_EDGE:
        SET_BIT(TMR_TCCR1B , TMR_TCCR1B_ICES,);
        break;
    
    default:
    CLEAR_BIT(TMR_TCCR1B , TMR_TCCR1B_ICES,);
        break;
    }
}

void TMR_TMR1_CLEAR_INPUT_CAPTURE_FLAG()
{
    CLEAR_BIT(TMR_TIFR , TMR_TIFR_ICF1);
}

void TMR_TMR1_IS_INPUT_CAPTURED()
{
    return (GET_BIT(TMR_TIFR , TMR_TIFR_ICF1 ) );
}

void TMR_TMR1_CLEAR_TMR_COUNTER()
{
    TMR_TCNT1H = 0x00;
    TMR_TCNT1L = 0x00;

}

void TMR_TMR1_CLEAR_TMR_OVF_FLAG()
{
    CLEAR_BIT(TMR_TIFR , TMR_TIFR_TOV1);

}


#endif

/*
#if  TMR_TMR2_EN == TRUE
void TMR_TMR2_vInit( u8 TMR_MODE, u8 TMR_PRESCALER)
{

}
#endif
*/
