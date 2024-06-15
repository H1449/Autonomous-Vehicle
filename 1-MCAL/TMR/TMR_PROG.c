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
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "_ATMEGA32_.h"  //this file is written by me to include all essential uncategorized addresses
#include "GPIO_PRIVATE.h"
//include header files of the driver
#include "TMR_CONFIG.h"
#include "TMR_PRIVATE.h"
#include "TMR_INTERFACE.h"



#if  TMR_ENABLE_TMR0 == TRUE

/*GENERAL*/
void TMR0_vInit( u8 mode , u8 PRESCALER)
{
    TMR_TCNT0=0;
switch (mode)
{
case TMR_MODE_NORMAL:
        CLEAR_BIT( TMR_TCCR0 , TMR_TCCR0_WGM00 ) ;
        CLEAR_BIT( TMR_TCCR0 , TMR_TCCR0_WGM01 ) ;
        TMR0_MODE = mode;
    break;
    case TMR_MODE_CTC:
        CLEAR_BIT( TMR_TCCR0 , TMR_TCCR0_WGM00 ) ;
        SET_BIT( TMR_TCCR0 , TMR_TCCR0_WGM01 ) ;
        TMR0_MODE = mode;
    break;
    case TMR_MODE_PWM:
        SET_BIT(    TMR_TCCR0 , TMR_TCCR0_WGM00 ) ;
        CLEAR_BIT( TMR_TCCR0 , TMR_TCCR0_WGM01 ) ;
        CLEAR_BIT(TMR_TCCR0, TMR_TCCR0_FOC0);
        TMR0_MODE = mode;
    break;
    case TMR_MODE_FAST_PWM:
        SET_BIT( TMR_TCCR0 , TMR_TCCR0_WGM00 ) ;
        SET_BIT( TMR_TCCR0 , TMR_TCCR0_WGM01 ) ;
        CLEAR_BIT(TMR_TCCR0, TMR_TCCR0_FOC0);
        TMR0_MODE = mode;
    break;
}

 switch (PRESCALER)
    {
    case TMR_PRESCALE_1:
        SET_BIT( TMR_TCCR0 , TMR_TCCR0_CS00 );
        CLEAR_BIT( TMR_TCCR0 , TMR_TCCR0_CS01 );
        CLEAR_BIT( TMR_TCCR0 , TMR_TCCR0_CS02 );
        TMR0_PRESCALE = 1;
        break;
    case TMR_PRESCALE_8:
        CLEAR_BIT( TMR_TCCR0 , TMR_TCCR0_CS00 );
        SET_BIT( TMR_TCCR0 , TMR_TCCR0_CS01 );
        CLEAR_BIT( TMR_TCCR0 , TMR_TCCR0_CS02 );
        TMR0_PRESCALE = 8;
        break;
    case TMR_PRESCALE_64:
        SET_BIT( TMR_TCCR0 , TMR_TCCR0_CS00 );
        SET_BIT( TMR_TCCR0 , TMR_TCCR0_CS01 );
        CLEAR_BIT( TMR_TCCR0 , TMR_TCCR0_CS02 );
        TMR0_PRESCALE = 64;

        break;
    case TMR_PRESCALE_256:
        CLEAR_BIT( TMR_TCCR0 , TMR_TCCR0_CS00 );
        CLEAR_BIT( TMR_TCCR0 , TMR_TCCR0_CS01 );
        SET_BIT( TMR_TCCR0 , TMR_TCCR0_CS02 );
        TMR0_PRESCALE = 256;
        break;
    case TMR_PRESCALE_1024:
        SET_BIT( TMR_TCCR0 , TMR_TCCR0_CS00 );
        CLEAR_BIT( TMR_TCCR0 , TMR_TCCR0_CS01 );
        SET_BIT( TMR_TCCR0 , TMR_TCCR0_CS02 );
        TMR0_PRESCALE = 1024;
        break;
     case TMR_XCLK_FALLING:
        CLEAR_BIT( TMR_TCCR0 , TMR_TCCR0_CS00 );
        SET_BIT( TMR_TCCR0 , TMR_TCCR0_CS01 );
        SET_BIT( TMR_TCCR0 , TMR_TCCR0_CS02 );
        TMR0_PRESCALE = TMR_XCLK_FALLING;
        break;
    case TMR_XCLK_RISING:
        SET_BIT( TMR_TCCR0 , TMR_TCCR0_CS00 );
        SET_BIT( TMR_TCCR0 , TMR_TCCR0_CS01 );
        SET_BIT( TMR_TCCR0 , TMR_TCCR0_CS02 );
        TMR0_PRESCALE = TMR_XCLK_RISING;
        break;
    }


}

void TMR0_vDeInit(void)
{
    CLEAR_BIT( TMR_TCCR0 , TMR_TCCR0_CS00 );
    CLEAR_BIT( TMR_TCCR0 , TMR_TCCR0_CS01 );
    CLEAR_BIT( TMR_TCCR0 , TMR_TCCR0_CS02 );
}

void TMR0_vSet_Prescaler(u8 prescaler)
{

 switch (prescaler)
    {
    case TMR_PRESCALE_1:
        SET_BIT( TMR_TCCR0 , TMR_TCCR0_CS00 );
        CLEAR_BIT( TMR_TCCR0 , TMR_TCCR0_CS01 );
        CLEAR_BIT( TMR_TCCR0 , TMR_TCCR0_CS02 );
        TMR0_PRESCALE = 1;
        break;
    case TMR_PRESCALE_8:
        CLEAR_BIT( TMR_TCCR0 , TMR_TCCR0_CS00 );
        SET_BIT( TMR_TCCR0 , TMR_TCCR0_CS01 );
        CLEAR_BIT( TMR_TCCR0 , TMR_TCCR0_CS02 );
        TMR0_PRESCALE=8;
        break;
    case TMR_PRESCALE_64:
        SET_BIT( TMR_TCCR0 , TMR_TCCR0_CS00 );
        SET_BIT( TMR_TCCR0 , TMR_TCCR0_CS01 );
        CLEAR_BIT( TMR_TCCR0 , TMR_TCCR0_CS02 );
        TMR0_PRESCALE=64;
        break;
    case TMR_PRESCALE_256:
        CLEAR_BIT( TMR_TCCR0 , TMR_TCCR0_CS00 );
        CLEAR_BIT( TMR_TCCR0 , TMR_TCCR0_CS01 );
        SET_BIT( TMR_TCCR0 , TMR_TCCR0_CS02 );
        TMR0_PRESCALE=256;
        break;
    case TMR_PRESCALE_1024:
        SET_BIT( TMR_TCCR0 , TMR_TCCR0_CS00 );
        CLEAR_BIT( TMR_TCCR0 , TMR_TCCR0_CS01 );
        SET_BIT( TMR_TCCR0 , TMR_TCCR0_CS02 );
        TMR0_PRESCALE=1024;
        break;
     case TMR_XCLK_FALLING:
        CLEAR_BIT( TMR_TCCR0 , TMR_TCCR0_CS00 );
        SET_BIT( TMR_TCCR0 , TMR_TCCR0_CS01 );
        SET_BIT( TMR_TCCR0 , TMR_TCCR0_CS02 );
        TMR0_PRESCALE=TMR_XCLK_FALLING;
        break;
    case TMR_XCLK_RISING:
        SET_BIT( TMR_TCCR0 , TMR_TCCR0_CS00 );
        SET_BIT( TMR_TCCR0 , TMR_TCCR0_CS01 );
        SET_BIT( TMR_TCCR0 , TMR_TCCR0_CS02 );
        TMR0_PRESCALE = TMR_XCLK_FALLING;
        break;
    }

}

void TMR0_vSet_Mode(u8 mode)
{
    switch (mode)
{
case TMR_MODE_NORMAL:
        CLEAR_BIT( TMR_TCCR0 , TMR_TCCR0_WGM00 ) ;
        CLEAR_BIT( TMR_TCCR0 , TMR_TCCR0_WGM01 ) ;
        TMR0_MODE = mode;
    break;
    case TMR_MODE_CTC:
        CLEAR_BIT( TMR_TCCR0 , TMR_TCCR0_WGM00 ) ;
        SET_BIT( TMR_TCCR0 , TMR_TCCR0_WGM01 ) ;
        TMR0_MODE = mode;
    break;
    case TMR_MODE_PWM:
        SET_BIT(    TMR_TCCR0 , TMR_TCCR0_WGM00 ) ;
        CLEAR_BIT( TMR_TCCR0 , TMR_TCCR0_WGM01 ) ;
        TMR0_MODE = mode;
        CLEAR_BIT(TMR_TCCR0, TMR_TCCR0_FOC0);
    break;
    case TMR_MODE_FAST_PWM:
        SET_BIT( TMR_TCCR0 , TMR_TCCR0_WGM00 ) ;
        SET_BIT( TMR_TCCR0 , TMR_TCCR0_WGM01 ) ;
        TMR0_MODE = mode;
        CLEAR_BIT(TMR_TCCR0, TMR_TCCR0_FOC0);
    break;
}

}

u8 TMR0_u8GET_COUNTER_VALUE(void)
{
    return TMR_TCNT0;
}

/*NORMAL MODE*/
void TMR0_vENABLE_OVF_INTERRUPT(void)
{
     SET_BIT( TMR_TIMSK , TMR_TIMSK_TOIE0 ) ;
}

void TMR0_vDISABLE_OVF_INTERRUPT(void)
{
     CLEAR_BIT( TMR_TIMSK , TMR_TIMSK_TOIE0 ) ;
}

u8 TMR0_u8GET_OVF_INTERRUPT_FLAG(void)
{
     return GET_BIT( TMR_TIFR , TMR_TIFR_TOV0 ) ;
}

void TMR0_CALLBACK_OVERFLOW_vSET_CALLBACK( void *(pFunction) ( void ) )
{
    if (pFunction != NULL)
    {/*TMR0 CALLBACK OVERFLOW*/
       TMR_CALLBACK_OVERFLOW_PTR0 = pFunction;
    }
}

void __vector_11(void)
{
    TMR0_OVF_COUNTER++;
    if (TMR_CALLBACK_OVERFLOW_PTR0 != NULL)
    {
        TMR_CALLBACK_OVERFLOW_PTR0();
    }
}

/*CTC MODE*/
void TMR0_vASSIGN_CTC_VALUE(u8 OCR_VALUE)
{
    TMR_OCR0 = OCR_VALUE;
}

u8 TMR0_u8GET_CTC_VALUE(void)
{
    return TMR_OCR0;
}

void TMR0_vENABLE_CTC_INTERRUPT(void)
{
    SET_BIT( TMR_TIMSK , TMR_TIMSK_OCIE0 ) ;
}

void TMR0_vDISABLE_CTC_INTERRUPT(void)
{
    CLEAR_BIT( TMR_TIMSK , TMR_TIMSK_OCIE0 ) ;
}

u8 TMR0_u8GET_OUTPUT_COMPARE_INTERRUPT_FLAG(void)
{
     return GET_BIT( TMR_TIFR , TMR_TIFR_OCF0 ) ;
}

void TMR0_vCLEAR_OUTPUT_COMPARE_INTERRUPT_FLAG(void)
{
    SET_BIT(TMR_TIFR, TMR_TIFR_OCF0);
}

u32 TMR0_u32GET_CTC_FREQUENCY(void)
{

    return  (u32) ( F_CPU / ( 2*( 1+ TMR_OCR0 ) * TMR0_PRESCALE ) );
}

u8 TMR0_CTC_u8SET_FREQUENCY(u32 Target_Frequency)
{ // 30.5< target_frequency<F_CPU/2
    u8 STATE= ERROR;
    u8 N_1OCRn = (u8) ( ( F_CPU / ( 2* Target_Frequency* TMR0_PRESCALE ) ) -1 ) ;

    if (N_1OCRn <=255)
    {
         STATE = SUCCESS;
         TMR0_vASSIGN_CTC_VALUE(N_1OCRn);
    }
    else
    {
          STATE = ERROR;
    }
    
    

            if(  ( (  (u32) (0.90*(TMR0_u32GET_CTC_FREQUENCY())) <Target_Frequency) 
            && (  (u32)  (1.1*(TMR0_u32GET_CTC_FREQUENCY()))  >Target_Frequency) ) )
            {
                STATE = SUCCESS;
            }
            else
            {
                STATE = ERROR;
            }
            return STATE;

}

void TMR0_vSET_CTC_CALLBACK( void *(pFunction) ( void ) )
{
    if (pFunction != NULL)
    {
       TMR_CALLBACK_COMPARE_MATCH_PTR0 = pFunction;
    }
    
}

void __vector_10(void)
{
    TMR0_CTC_COUNTER++;
    if (TMR_CALLBACK_COMPARE_MATCH_PTR0 != NULL)
    {
        TMR_CALLBACK_COMPARE_MATCH_PTR0();
    }
        
}

/*NON-PWM*/
void TMR0_vENABLE_OC0_OF_OUTPUT_COMPARE(void)
{
SET_BIT(TMR_OC0_DDR,TMR_OC0_PIN);
}

void TMR0_vDISABLE_OC0_OF_OUTPUT_COMPARE(void)
{
CLEAR_BIT(TMR_OC0_DDR,TMR_OC0_PIN);
}

void TMR0_vDISCONNECT_OC0_ON_OUTPUT_COMPARE(void)
{
     CLEAR_BIT( TMR_TCCR0 , TMR_TCCR0_COM00 ) ;
     CLEAR_BIT( TMR_TCCR0 , TMR_TCCR0_COM01 ) ;
}

void TMR0_vSET_OC0_ON_OUTPUT_COMPARE(void)
{
     SET_BIT( TMR_TCCR0 , TMR_TCCR0_COM00 ) ;
     SET_BIT( TMR_TCCR0 , TMR_TCCR0_COM01 ) ;
}

void TMR0_vCLEAR_OC0_ON_OUTPUT_COMPARE(void)
{
    CLEAR_BIT( TMR_TCCR0 , TMR_TCCR0_COM00 ) ;
     SET_BIT( TMR_TCCR0 , TMR_TCCR0_COM01 ) ;
}

void TMR0_vTOGGLE_OC0_ON_OUTPUT_COMPARE(void)
{
     SET_BIT(      TMR_TCCR0 , TMR_TCCR0_COM00 ) ;
     CLEAR_BIT( TMR_TCCR0 , TMR_TCCR0_COM01 ) ;
}

void TMR0_vFORCE_OUTPUT_COMPARE(void)
{
    if(TMR0_MODE != TMR_MODE_FAST_PWM && TMR0_MODE != TMR_MODE_PWM)
    {
        SET_BIT(TMR_TCCR0, TMR_TCCR0_FOC0);
    }
}

/*PWM*/
void TMR0_PWM_vSET_DUTY_CYCLE_VALUE(u8 duty_cycle)
{
    if (TMR0_MODE == TMR_MODE_FAST_PWM 
    || TMR0_MODE == TMR_MODE_PWM )
    {
        if(duty_cycle <=100 && duty_cycle >=0)
            TMR_OCR0 =  (u8) ( (duty_cycle * 256)/100 )  ;
    }
}

void TMR0_PWM_vASSIGN_INVERSION(u8 is_inverted)
{
    switch (is_inverted)
    {
    case TRUE:
        SET_BIT( TMR_TCCR0 , TMR_TCCR0_COM00 ) ;
        CLEAR_BIT( TMR_TCCR0 , TMR_TCCR0_COM01 ) ;
        break;
    default: 
        SET_BIT( TMR_TCCR0 , TMR_TCCR0_COM00 ) ;
        SET_BIT( TMR_TCCR0 , TMR_TCCR0_COM01 ) ;
        break;
    }
}

u32 TMR0_u32GET_PWM_FREQUENCY(void)
{
    u32 frequency = 0;
    switch (TMR0_MODE)
    {
    case TMR_MODE_FAST_PWM: frequency = (u32) (F_CPU/TMR0_PRESCALE*256);
    break;
    
    case TMR_MODE_PWM: frequency = (u32) (F_CPU/TMR0_PRESCALE*510);
    break;
    }
    return frequency;
}

#endif

#if  TMR_ENABLE_TMR1 == TRUE
/*GENERAL*/
void TMR1_vInit( u8 MODE, u8 PRESCALER)
{

TMR_TCNT1H=0;
TMR_TCNT1L=0;
switch (MODE)
{
case TMR_MODE_NORMAL:
        CLEAR_BIT( TMR_TCCR1A , TMR_TCCR1A_WGM10 ) ;
        CLEAR_BIT( TMR_TCCR1A , TMR_TCCR1A_WGM11 ) ;
        CLEAR_BIT( TMR_TCCR1B , TMR_TCCR1B_WGM12 ) ;
        CLEAR_BIT( TMR_TCCR1B , TMR_TCCR1B_WGM13 ) ;
        TMR1_MODE = MODE;
    break;
    case TMR_MODE_CTC:
        CLEAR_BIT( TMR_TCCR1A , TMR_TCCR1A_WGM10 ) ;
        CLEAR_BIT( TMR_TCCR1A , TMR_TCCR1A_WGM11 ) ;
        SET_BIT( TMR_TCCR1B , TMR_TCCR1B_WGM12 ) ;
        CLEAR_BIT( TMR_TCCR1B , TMR_TCCR1B_WGM13 ) ;
        TMR1_MODE = MODE;
    break;
    case TMR_MODE_PWM:
        SET_BIT( TMR_TCCR1A , TMR_TCCR1A_WGM10 ) ;
        CLEAR_BIT( TMR_TCCR1A , TMR_TCCR1A_WGM11 ) ;
        CLEAR_BIT( TMR_TCCR1B , TMR_TCCR1B_WGM12 ) ;
        CLEAR_BIT( TMR_TCCR1B , TMR_TCCR1B_WGM13 ) ;
        TMR1_MODE = MODE;
    break;
    case TMR_MODE_FAST_PWM:
        SET_BIT( TMR_TCCR1A , TMR_TCCR1A_WGM10 ) ;
        CLEAR_BIT( TMR_TCCR1A , TMR_TCCR1A_WGM11 ) ;
        SET_BIT ( TMR_TCCR1B , TMR_TCCR1B_WGM12 ) ;
        CLEAR_BIT( TMR_TCCR1B , TMR_TCCR1B_WGM13 ) ;
        TMR1_MODE = MODE;
    break;
    case TMR_MODE_PWM_9_BITS:
        CLEAR_BIT( TMR_TCCR1A , TMR_TCCR1A_WGM10 ) ;
        SET_BIT( TMR_TCCR1A , TMR_TCCR1A_WGM11 ) ;
        CLEAR_BIT( TMR_TCCR1B , TMR_TCCR1B_WGM12 ) ;
        CLEAR_BIT( TMR_TCCR1B , TMR_TCCR1B_WGM13 ) ;
        TMR1_MODE = MODE;
    break;
    case TMR_MODE_PWM_10_BITS:
        SET_BIT( TMR_TCCR1A , TMR_TCCR1A_WGM10 ) ;
        SET_BIT( TMR_TCCR1A , TMR_TCCR1A_WGM11 ) ;
        CLEAR_BIT( TMR_TCCR1B , TMR_TCCR1B_WGM12 ) ;
        CLEAR_BIT( TMR_TCCR1B , TMR_TCCR1B_WGM13 ) ;
        TMR1_MODE = MODE;
    break;
        case TMR_MODE_PWM_INPUT_CAPTURE:
        CLEAR_BIT( TMR_TCCR1A , TMR_TCCR1A_WGM10 ) ;
        SET_BIT( TMR_TCCR1A , TMR_TCCR1A_WGM11 ) ;
        CLEAR_BIT( TMR_TCCR1B , TMR_TCCR1B_WGM12 ) ;
        SET_BIT( TMR_TCCR1B , TMR_TCCR1B_WGM13 ) ;
        TMR1_MODE = MODE;
    break;
        case TMR_MODE_PWM_OCR1A:
        SET_BIT( TMR_TCCR1A , TMR_TCCR1A_WGM10 ) ;
        CLEAR_BIT( TMR_TCCR1A , TMR_TCCR1A_WGM11 ) ;
        SET_BIT( TMR_TCCR1B , TMR_TCCR1B_WGM12 ) ;
        SET_BIT( TMR_TCCR1B , TMR_TCCR1B_WGM13 ) ;
        TMR1_MODE = MODE;
    break;
        case TMR_MODE_PWM_PHASE_AND_FREQUENCY_CORRECT:
        SET_BIT( TMR_TCCR1A , TMR_TCCR1A_WGM10 ) ;
        CLEAR_BIT( TMR_TCCR1A , TMR_TCCR1A_WGM11 ) ;
        CLEAR_BIT( TMR_TCCR1B , TMR_TCCR1B_WGM12 ) ;
        SET_BIT( TMR_TCCR1B , TMR_TCCR1B_WGM13 ) ;
        TMR1_MODE = MODE;
    break;
        case TMR_MODE_PWM_INPUT_CAPTURE_PHASE_AND_FREQUENCY_CORRECT:
        SET_BIT( TMR_TCCR1A , TMR_TCCR1A_WGM10 ) ;
        CLEAR_BIT( TMR_TCCR1A , TMR_TCCR1A_WGM11 ) ;
        CLEAR_BIT( TMR_TCCR1B , TMR_TCCR1B_WGM12 ) ;
        CLEAR_BIT( TMR_TCCR1B , TMR_TCCR1B_WGM13 ) ;
        TMR1_MODE = MODE;
    break;
            case TMR_MODE_FAST_PWM_9_BITS:
        CLEAR_BIT( TMR_TCCR1A , TMR_TCCR1A_WGM10 ) ;
        SET_BIT( TMR_TCCR1A , TMR_TCCR1A_WGM11 ) ;
        SET_BIT( TMR_TCCR1B , TMR_TCCR1B_WGM12 ) ;
        CLEAR_BIT( TMR_TCCR1B , TMR_TCCR1B_WGM13 ) ;
        TMR1_MODE = MODE;
    break;
            case TMR_MODE_FAST_PWM_10_BITS:
        SET_BIT( TMR_TCCR1A , TMR_TCCR1A_WGM10 ) ;
        SET_BIT( TMR_TCCR1A , TMR_TCCR1A_WGM11 ) ;
        SET_BIT( TMR_TCCR1B , TMR_TCCR1B_WGM12 ) ;
        CLEAR_BIT( TMR_TCCR1B , TMR_TCCR1B_WGM13 ) ;
        TMR1_MODE = MODE;
    break;
            case TMR_MODE_FAST_PWM_INPUT_CAPTURE:
        CLEAR_BIT( TMR_TCCR1A , TMR_TCCR1A_WGM10 ) ;
        SET_BIT( TMR_TCCR1A , TMR_TCCR1A_WGM11 ) ;
        SET_BIT( TMR_TCCR1B , TMR_TCCR1B_WGM12 ) ;
        SET_BIT( TMR_TCCR1B , TMR_TCCR1B_WGM13 ) ;
        TMR1_MODE = MODE;
    break;
            case TMR_MODE_FAST_PWM_OCR1A:
        SET_BIT( TMR_TCCR1A , TMR_TCCR1A_WGM10 ) ;
        SET_BIT( TMR_TCCR1A , TMR_TCCR1A_WGM11 ) ;
        SET_BIT( TMR_TCCR1B , TMR_TCCR1B_WGM12 ) ;
        SET_BIT( TMR_TCCR1B , TMR_TCCR1B_WGM13 ) ;
        TMR1_MODE = MODE;
    break;
            case TMR_MODE_CTC_INPUT_CAPTURE:
        CLEAR_BIT( TMR_TCCR1A , TMR_TCCR1A_WGM10 ) ;
        CLEAR_BIT( TMR_TCCR1A , TMR_TCCR1A_WGM11 ) ;
        SET_BIT( TMR_TCCR1B , TMR_TCCR1B_WGM12 ) ;
        SET_BIT ( TMR_TCCR1B , TMR_TCCR1B_WGM13 ) ;
        TMR1_MODE = MODE;
    break;
}
 
    switch (PRESCALER)
    {
    case TMR_PRESCALE_1:
        SET_BIT( TMR_TCCR1B , TMR_TCCR1B_CS10 );
        CLEAR_BIT( TMR_TCCR1B , TMR_TCCR1B_CS11 );
        CLEAR_BIT( TMR_TCCR1B , TMR_TCCR1B_CS12 );
        TMR1_PRESCALE = 1;
        break;
    case TMR_PRESCALE_8:
        CLEAR_BIT( TMR_TCCR1B , TMR_TCCR1B_CS10 );
        SET_BIT( TMR_TCCR1B , TMR_TCCR1B_CS11 );
        CLEAR_BIT( TMR_TCCR1B , TMR_TCCR1B_CS12 );
        TMR1_PRESCALE = 8;
        break;
    case TMR_PRESCALE_64:
        SET_BIT( TMR_TCCR1B , TMR_TCCR1B_CS10 );
        SET_BIT( TMR_TCCR1B , TMR_TCCR1B_CS11 );
        CLEAR_BIT( TMR_TCCR1B , TMR_TCCR1B_CS12 );
        TMR1_PRESCALE = 64;
        break;
    case TMR_PRESCALE_256:
        CLEAR_BIT( TMR_TCCR1B , TMR_TCCR1B_CS10 );
        CLEAR_BIT( TMR_TCCR1B , TMR_TCCR1B_CS11 );
        SET_BIT( TMR_TCCR1B , TMR_TCCR1B_CS12 );
       TMR1_PRESCALE = 256;
        break;
    case TMR_PRESCALE_1024:
        SET_BIT( TMR_TCCR1B , TMR_TCCR1B_CS10 );
        CLEAR_BIT( TMR_TCCR1B , TMR_TCCR1B_CS11 );
        SET_BIT( TMR_TCCR1B , TMR_TCCR1B_CS12 );
        TMR1_PRESCALE = 1024;
        break;
     case TMR_XCLK_FALLING:
        CLEAR_BIT( TMR_TCCR1B , TMR_TCCR1B_CS10 );
        SET_BIT( TMR_TCCR1B , TMR_TCCR1B_CS11 );
        SET_BIT( TMR_TCCR1B , TMR_TCCR1B_CS12 );
        TMR1_PRESCALE = TMR_XCLK_FALLING;
        break;
    case TMR_XCLK_RISING:
        SET_BIT( TMR_TCCR1B , TMR_TCCR1B_CS10 );
        SET_BIT( TMR_TCCR1B , TMR_TCCR1B_CS11 );
        SET_BIT( TMR_TCCR1B , TMR_TCCR1B_CS12 );
        TMR1_PRESCALE = TMR_XCLK_RISING;
        break;

    }


}

void TMR1_vDeInit(void)
{
    CLEAR_BIT( TMR_TCCR2 , TMR_TCCR2_CS20 );
    CLEAR_BIT( TMR_TCCR2 , TMR_TCCR2_CS21 );
    CLEAR_BIT( TMR_TCCR2 , TMR_TCCR2_CS22 );
}

void TMR1_vSet_Prescaler(u8 PRESCALER)
{
        switch (PRESCALER)
    {
    case TMR_PRESCALE_1:
        SET_BIT( TMR_TCCR1B , TMR_TCCR1B_CS10 );
        CLEAR_BIT( TMR_TCCR1B , TMR_TCCR1B_CS11 );
        CLEAR_BIT( TMR_TCCR1B , TMR_TCCR1B_CS12 );
        TMR1_PRESCALE = 1;
        break;
    case TMR_PRESCALE_8:
        CLEAR_BIT( TMR_TCCR1B , TMR_TCCR1B_CS10 );
        SET_BIT( TMR_TCCR1B , TMR_TCCR1B_CS11 );
        CLEAR_BIT( TMR_TCCR1B , TMR_TCCR1B_CS12 );
        TMR1_PRESCALE = 8;
        break;
    case TMR_PRESCALE_64:
        SET_BIT( TMR_TCCR1B , TMR_TCCR1B_CS10 );
        SET_BIT( TMR_TCCR1B , TMR_TCCR1B_CS11 );
        CLEAR_BIT( TMR_TCCR1B , TMR_TCCR1B_CS12 );
        TMR1_PRESCALE = 64;
        break;
    case TMR_PRESCALE_256:
        CLEAR_BIT( TMR_TCCR1B , TMR_TCCR1B_CS10 );
        CLEAR_BIT( TMR_TCCR1B , TMR_TCCR1B_CS11 );
        SET_BIT( TMR_TCCR1B , TMR_TCCR1B_CS12 );
       TMR1_PRESCALE = 256;
        break;
    case TMR_PRESCALE_1024:
        SET_BIT( TMR_TCCR1B , TMR_TCCR1B_CS10 );
        CLEAR_BIT( TMR_TCCR1B , TMR_TCCR1B_CS11 );
        SET_BIT( TMR_TCCR1B , TMR_TCCR1B_CS12 );
        TMR1_PRESCALE = 1024;
        break;
     case TMR_XCLK_FALLING:
        CLEAR_BIT( TMR_TCCR1B , TMR_TCCR1B_CS10 );
        SET_BIT( TMR_TCCR1B , TMR_TCCR1B_CS11 );
        SET_BIT( TMR_TCCR1B , TMR_TCCR1B_CS12 );
        TMR1_PRESCALE = TMR_XCLK_FALLING;
        break;
    case TMR_XCLK_RISING:
        SET_BIT( TMR_TCCR1B , TMR_TCCR1B_CS10 );
        SET_BIT( TMR_TCCR1B , TMR_TCCR1B_CS11 );
        SET_BIT( TMR_TCCR1B , TMR_TCCR1B_CS12 );
        TMR1_PRESCALE = TMR_XCLK_RISING;
        break;

    }

}

void TMR1_vSet_Mode(u8 MODE)
{
    switch (MODE)
{
case TMR_MODE_NORMAL:
        CLEAR_BIT( TMR_TCCR1A , TMR_TCCR1A_WGM10 ) ;
        CLEAR_BIT( TMR_TCCR1A , TMR_TCCR1A_WGM11 ) ;
        CLEAR_BIT( TMR_TCCR1B , TMR_TCCR1B_WGM12 ) ;
        CLEAR_BIT( TMR_TCCR1B , TMR_TCCR1B_WGM13 ) ;
        TMR1_MODE = MODE;
    break;
    case TMR_MODE_CTC:
        CLEAR_BIT( TMR_TCCR1A , TMR_TCCR1A_WGM10 ) ;
        CLEAR_BIT( TMR_TCCR1A , TMR_TCCR1A_WGM11 ) ;
        SET_BIT( TMR_TCCR1B , TMR_TCCR1B_WGM12 ) ;
        CLEAR_BIT( TMR_TCCR1B , TMR_TCCR1B_WGM13 ) ;
        TMR1_MODE = MODE;
    break;
    case TMR_MODE_PWM:
        SET_BIT( TMR_TCCR1A , TMR_TCCR1A_WGM10 ) ;
        CLEAR_BIT( TMR_TCCR1A , TMR_TCCR1A_WGM11 ) ;
        CLEAR_BIT( TMR_TCCR1B , TMR_TCCR1B_WGM12 ) ;
        CLEAR_BIT( TMR_TCCR1B , TMR_TCCR1B_WGM13 ) ;
        TMR1_MODE = MODE;
    break;
    case TMR_MODE_FAST_PWM:
        SET_BIT( TMR_TCCR1A , TMR_TCCR1A_WGM10 ) ;
        CLEAR_BIT( TMR_TCCR1A , TMR_TCCR1A_WGM11 ) ;
        SET_BIT ( TMR_TCCR1B , TMR_TCCR1B_WGM12 ) ;
        CLEAR_BIT( TMR_TCCR1B , TMR_TCCR1B_WGM13 ) ;
        TMR1_MODE = MODE;
    break;
    case TMR_MODE_PWM_9_BITS:
        CLEAR_BIT( TMR_TCCR1A , TMR_TCCR1A_WGM10 ) ;
        SET_BIT( TMR_TCCR1A , TMR_TCCR1A_WGM11 ) ;
        CLEAR_BIT( TMR_TCCR1B , TMR_TCCR1B_WGM12 ) ;
        CLEAR_BIT( TMR_TCCR1B , TMR_TCCR1B_WGM13 ) ;
        TMR1_MODE = MODE;
    break;
    case TMR_MODE_PWM_10_BITS:
        SET_BIT( TMR_TCCR1A , TMR_TCCR1A_WGM10 ) ;
        SET_BIT( TMR_TCCR1A , TMR_TCCR1A_WGM11 ) ;
        CLEAR_BIT( TMR_TCCR1B , TMR_TCCR1B_WGM12 ) ;
        CLEAR_BIT( TMR_TCCR1B , TMR_TCCR1B_WGM13 ) ;
        TMR1_MODE = MODE;
    break;
        case TMR_MODE_PWM_INPUT_CAPTURE:
        CLEAR_BIT( TMR_TCCR1A , TMR_TCCR1A_WGM10 ) ;
        SET_BIT( TMR_TCCR1A , TMR_TCCR1A_WGM11 ) ;
        CLEAR_BIT( TMR_TCCR1B , TMR_TCCR1B_WGM12 ) ;
        SET_BIT( TMR_TCCR1B , TMR_TCCR1B_WGM13 ) ;
        TMR1_MODE = MODE;
    break;
        case TMR_MODE_PWM_OCR1A:
        SET_BIT( TMR_TCCR1A , TMR_TCCR1A_WGM10 ) ;
        CLEAR_BIT( TMR_TCCR1A , TMR_TCCR1A_WGM11 ) ;
        SET_BIT( TMR_TCCR1B , TMR_TCCR1B_WGM12 ) ;
        SET_BIT( TMR_TCCR1B , TMR_TCCR1B_WGM13 ) ;
        TMR1_MODE = MODE;
    break;
        case TMR_MODE_PWM_PHASE_AND_FREQUENCY_CORRECT:
        SET_BIT( TMR_TCCR1A , TMR_TCCR1A_WGM10 ) ;
        CLEAR_BIT( TMR_TCCR1A , TMR_TCCR1A_WGM11 ) ;
        CLEAR_BIT( TMR_TCCR1B , TMR_TCCR1B_WGM12 ) ;
        SET_BIT( TMR_TCCR1B , TMR_TCCR1B_WGM13 ) ;
        TMR1_MODE = MODE;
    break;
        case TMR_MODE_PWM_INPUT_CAPTURE_PHASE_AND_FREQUENCY_CORRECT:
        SET_BIT( TMR_TCCR1A , TMR_TCCR1A_WGM10 ) ;
        CLEAR_BIT( TMR_TCCR1A , TMR_TCCR1A_WGM11 ) ;
        CLEAR_BIT( TMR_TCCR1B , TMR_TCCR1B_WGM12 ) ;
        CLEAR_BIT( TMR_TCCR1B , TMR_TCCR1B_WGM13 ) ;
        TMR1_MODE = MODE;
    break;
            case TMR_MODE_FAST_PWM_9_BITS:
        CLEAR_BIT( TMR_TCCR1A , TMR_TCCR1A_WGM10 ) ;
        SET_BIT( TMR_TCCR1A , TMR_TCCR1A_WGM11 ) ;
        SET_BIT( TMR_TCCR1B , TMR_TCCR1B_WGM12 ) ;
        CLEAR_BIT( TMR_TCCR1B , TMR_TCCR1B_WGM13 ) ;
        TMR1_MODE = MODE;
    break;
            case TMR_MODE_FAST_PWM_10_BITS:
        SET_BIT( TMR_TCCR1A , TMR_TCCR1A_WGM10 ) ;
        SET_BIT( TMR_TCCR1A , TMR_TCCR1A_WGM11 ) ;
        SET_BIT( TMR_TCCR1B , TMR_TCCR1B_WGM12 ) ;
        CLEAR_BIT( TMR_TCCR1B , TMR_TCCR1B_WGM13 ) ;
        TMR1_MODE = MODE;
    break;
            case TMR_MODE_FAST_PWM_INPUT_CAPTURE:
        CLEAR_BIT( TMR_TCCR1A , TMR_TCCR1A_WGM10 ) ;
        SET_BIT( TMR_TCCR1A , TMR_TCCR1A_WGM11 ) ;
        SET_BIT( TMR_TCCR1B , TMR_TCCR1B_WGM12 ) ;
        SET_BIT( TMR_TCCR1B , TMR_TCCR1B_WGM13 ) ;
        TMR1_MODE = MODE;
    break;
            case TMR_MODE_FAST_PWM_OCR1A:
        SET_BIT( TMR_TCCR1A , TMR_TCCR1A_WGM10 ) ;
        SET_BIT( TMR_TCCR1A , TMR_TCCR1A_WGM11 ) ;
        SET_BIT( TMR_TCCR1B , TMR_TCCR1B_WGM12 ) ;
        SET_BIT( TMR_TCCR1B , TMR_TCCR1B_WGM13 ) ;
        TMR1_MODE = MODE;
    break;
            case TMR_MODE_CTC_INPUT_CAPTURE:
        CLEAR_BIT( TMR_TCCR1A , TMR_TCCR1A_WGM10 ) ;
        CLEAR_BIT( TMR_TCCR1A , TMR_TCCR1A_WGM11 ) ;
        SET_BIT( TMR_TCCR1B , TMR_TCCR1B_WGM12 ) ;
        SET_BIT ( TMR_TCCR1B , TMR_TCCR1B_WGM13 ) ;
        TMR1_MODE = MODE;
    break;
}
}

u16 TMR1_u8GET_COUNTER_VALUE(void)
{
    u8 temp = TMR_TCNT1L;
    return ( (TMR_TCNT1H<<8) + TMR_TCNT1L );
}

void TMR1_vENABLE_OVF_INTERRUPT(void)
{
    SET_BIT(TMR_TIMSK, TMR_TIMSK_TOIE1);
}

void TMR1_vDISABLE_OVF_INTERRUPT(void)
{
    CLEAR_BIT(TMR_TIMSK, TMR_TIMSK_TOIE1);
}

u8 TMR1_u8GET_OVF_INTERRUPT_FLAG(void)
{
    return GET_BIT(TMR_TIFR, TMR_TIFR_TOV1);
}

void TMR1_vCLEAR_OVF_INTERRUPT_FLAG(void)
{
    SET_BIT(TMR_TIFR, TMR_TIFR_TOV1);
}

void TMR1_vSET_OVF_CALLBACK( void *(pFunction) ( void ) )
{
        if (pFunction != NULL)
    {
       TMR_CALLBACK_OVERFLOW_PTR1 = pFunction;
    }
}

void __vector_9 (void)
{
    TMR1_OVF_COUNTER++;
    if (TMR_CALLBACK_OVERFLOW_PTR1 != NULL)
    {
        TMR_CALLBACK_OVERFLOW_PTR1();
    }
}

/*OCR1A*/   
void TMR1_vASSIGN_CTCA_VALUE(u16 OCRA_VALUE)
{
    TMR_OCR1AH = ( OCRA_VALUE && 0xFF00);
    TMR_OCR1AL =  (OCRA_VALUE && 0x00FF) ;
}

u16 TMR1_u16GET_CTCA_VALUE(void)
{
    u8 temp = TMR_OCR1AL;
    return ( (TMR_OCR1AH<<8) + temp );
}

void TMR1_vENABLE_CTCA_INTERRUPT(void)
{
    SET_BIT(TMR_TIMSK, TMR_TIMSK_OCIE1A);
}

void TMR1_vDISABLE_CTCA_INTERRUPT(void)
{
    CLEAR_BIT(TMR_TIMSK, TMR_TIMSK_OCIE1A);
}

u8 TMR1_u8GET_CTCA_INTERRUPT_FLAG(void)
{
    return GET_BIT(TMR_TIFR, TMR_TIFR_OCF1A);
}

void TMR1_vCLEAR_CTCA_INTERRUPT_FLAG(void)
{
    SET_BIT(TMR_TIFR, TMR_TIFR_OCF1A);
}

void TMR1_vSET_CTCA_CALLBACK( void *(pFunction) ( void ) )
{
    if (pFunction != NULL)
    {
       TMR_CALLBACK_COMPARE_MATCH_A_PTR1 = pFunction;
    }
}

void __vector_7 (void)
{
    TMR1_CTCA_COUNTER++;
    if (TMR_CALLBACK_COMPARE_MATCH_A_PTR1 != NULL)
    {
        TMR_CALLBACK_COMPARE_MATCH_A_PTR1();
    }
}

void TMR1_vENABLE_OC1A_OF_OUTPUT_COMPARE(void)
{
    SET_BIT(TMR_OC1_DDR, TMR_OC1A_PIN);
}

void TMR1_vDISCONNECT_OC1A_ON_OUTPUT_COMPARE(void)
{
        CLEAR_BIT(TMR_TCCR1A, TMR_TCCR1A_COM1A0);
        CLEAR_BIT(TMR_TCCR1A, TMR_TCCR1A_COM1A1);
}

void TMR1_vSET_OC1A_ON_OUTPUT_COMPARE(void)
{
    SET_BIT(TMR_TCCR1A, TMR_TCCR1A_COM1A0);
    SET_BIT(TMR_TCCR1A, TMR_TCCR1A_COM1A1);
}

void TMR1_vCLEAR_OC1A_ON_OUTPUT_COMPARE(void)
{
    CLEAR_BIT(TMR_TCCR1A, TMR_TCCR1A_COM1A0);
    SET_BIT(TMR_TCCR1A, TMR_TCCR1A_COM1A1);
}

void TMR1_vTOGGLE_OC1A_ON_OUTPUT_COMPARE(void)
{
    SET_BIT(TMR_TCCR1A, TMR_TCCR1A_COM1A0);
    CLEAR_BIT(TMR_TCCR1A, TMR_TCCR1A_COM1A1);
}

void TMR1_vFORCE_OUTPUT_COMPARE_A(void) 
/*NON-PWM*/
{
    if(    TMR1_MODE == TMR_MODE_CTC_INPUT_CAPTURE 
    && TMR1_MODE == TMR_MODE_CTC 
    && TMR1_MODE == TMR_MODE_NORMAL  )
    {
        SET_BIT(TMR_TCCR1A, TMR_TCCR1A_FOC1A);
    }
}

/*OCR1B*/
void TMR1_vASSIGN_CTCB_VALUE(u16 OCRB_VALUE)
{
    TMR_OCR1BH = ( OCRB_VALUE && 0xFF00);
    TMR_OCR1BL =  (OCRB_VALUE && 0x00FF) ;
}

u16 TMR1_u16GET_CTCB_VALUE(void)
{
    u8 temp = TMR_OCR1BL;
    return ( (TMR_OCR1BH<<8) + temp );
}

void TMR1_vENABLE_CTCB_INTERRUPT(void)
{
    SET_BIT(TMR_TIMSK, TMR_TIMSK_OCIE1B);
}

void TMR1_vDISABLE_CTCB_INTERRUPT(void)
{
        CLEAR_BIT(TMR_TIMSK, TMR_TIMSK_OCIE1B);
}

u8 TMR1_u8GET_CTCB_INTERRUPT_FLAG(void)
{
    return GET_BIT(TMR_TIFR, TMR_TIFR_OCF1B);
}

void TMR1_vCLEAR_CTCB_INTERRUPT_FLAG(void)
{
    SET_BIT(TMR_TIFR, TMR_TIFR_OCF1B);
}

void TMR1_vSET_CTCB_CALLBACK( void *(pFunction) ( void ) )
{
    if (pFunction != NULL)
    {
       TMR_CALLBACK_COMPARE_MATCH_B_PTR1 = pFunction;
    }
}

void __vector_8 (void)
{
    TMR1_CTCB_COUNTER++;
    if (TMR_CALLBACK_COMPARE_MATCH_B_PTR1 != NULL)
    {
        TMR_CALLBACK_COMPARE_MATCH_B_PTR1();
    }
}

void TMR1_vENABLE_OC1B_OF_OUTPUT_COMPARE(void)
{
    SET_BIT(TMR_OC1_DDR, TMR_OC1B_PIN);
}

void TMR1_vDISCONNECT_OC1B_ON_OUTPUT_COMPARE(void)
{
        CLEAR_BIT(TMR_TCCR1A, TMR_TCCR1A_COM1B0);
        CLEAR_BIT(TMR_TCCR1A, TMR_TCCR1A_COM1B1);
}

void TMR1_vSET_OC1B_ON_OUTPUT_COMPARE(void)
{
    SET_BIT(TMR_TCCR1A, TMR_TCCR1A_COM1B0);
    SET_BIT(TMR_TCCR1A, TMR_TCCR1A_COM1B1);
}

void TMR1_vCLEAR_OC1B_ON_OUTPUT_COMPARE(void)
{
    CLEAR_BIT(TMR_TCCR1A, TMR_TCCR1A_COM1B0);
    SET_BIT(TMR_TCCR1A, TMR_TCCR1A_COM1B1);
}

void TMR1_vTOGGLE_OC1B_ON_OUTPUT_COMPARE(void)
{
    SET_BIT(TMR_TCCR1A, TMR_TCCR1A_COM1B0);
    CLEAR_BIT(TMR_TCCR1A, TMR_TCCR1A_COM1B1);
}

void TMR1_vFORCE_OUTPUT_COMPARE_B(void) /*NON-PWM*/
{
    if(    TMR1_MODE == TMR_MODE_CTC_INPUT_CAPTURE 
    && TMR1_MODE == TMR_MODE_CTC 
    && TMR1_MODE == TMR_MODE_NORMAL  )
    {
        SET_BIT(TMR_TCCR1A, TMR_TCCR1A_FOC1B);
    }
}

/*INPUT CAPTURE*/
void TMR1_vENABLE_ICR_INTERRUPT(void)
{
    SET_BIT(TMR_TIMSK, TMR_TIMSK_TICIE1);
}

void TMR1_vDISABLE_ICR_INTERRUPT(void)
{
    CLEAR_BIT(TMR_TIMSK, TMR_TIMSK_TICIE1);
}

u16  TMR1_u16GET_ICR_VALUE(void)
{
    u8 temp = TMR_ICR1L;
    return ( (TMR_ICR1H<<8) + temp ); 
} 

void TMR1_vENABLE_NOISE_CANCELER_ON_ICR(void)
{
    SET_BIT(TMR_TCCR1B , TMR_TCCR1B_ICNC1);
}

void TMR1_vDISABLE_NOISE_CANCELER_ON_ICR(void)
{
    CLEAR_BIT(TMR_TCCR1B , TMR_TCCR1B_ICNC1);
}

void TMR1_ICR_EDGE_SELECT(u8 edge)
{
        switch (edge)
    {
    case TMR_RISING_EDGE:
        SET_BIT(TMR_TCCR1B , TMR_TCCR1B_ICES);
        break;
    
    default:
    CLEAR_BIT(TMR_TCCR1B , TMR_TCCR1B_ICES);
        break;
    }
}

u8 TMR1_u8GET_ICR_INTERRUPT_FLAG(void)
{
    return GET_BIT(TMR_TIFR, TMR_TIFR_ICF1);
}

void TMR1_CLEAR_ICR_INTERRUPT_FLAG(void)
{
    SET_BIT(TMR_TIFR, TMR_TIFR_ICF1);
}

void TMR1_vSET_ICR_CALLBACK( void *(pFunction) ( void ) )
{
    if (pFunction != NULL)
    {
       TMR_CALLBACK_INPUT_CAPTURE_PTR1 = pFunction;
    }
}

void __vector_7 (void)
{
    TMR1_ICR_COUNTER++;
    if (TMR_CALLBACK_INPUT_CAPTURE_PTR1 != NULL)
    {
        TMR_CALLBACK_INPUT_CAPTURE_PTR1();
    }
}



#endif

#if  TMR_ENABLE_TMR2 == TRUE

/*GENERAL*/
void TMR2_vInit( u8 MODE , u8 PRESCALER)
{
    TMR_TCNT2 = 0;
    switch (MODE)
    {
    case TMR_MODE_NORMAL:
            CLEAR_BIT( TMR_TCCR2 , TMR_TCCR2_WGM20 ) ;
            CLEAR_BIT( TMR_TCCR2 , TMR_TCCR2_WGM21 ) ;
            TMR2_MODE = MODE;
            break;
        case TMR_MODE_CTC:
            CLEAR_BIT( TMR_TCCR2 , TMR_TCCR2_WGM20 ) ;
            SET_BIT( TMR_TCCR2 , TMR_TCCR2_WGM21 ) ;
            TMR2_MODE = MODE;
            break;
        case TMR_MODE_PWM:
            SET_BIT(    TMR_TCCR2 , TMR_TCCR2_WGM20 ) ;
            CLEAR_BIT( TMR_TCCR2 , TMR_TCCR2_WGM21 ) ;
            TMR2_MODE = MODE;
            break;
        case TMR_MODE_FAST_PWM:
            SET_BIT( TMR_TCCR2 , TMR_TCCR2_WGM20 ) ;
            SET_BIT( TMR_TCCR2 , TMR_TCCR2_WGM21 ) ;
            TMR2_MODE = MODE;
            break;
    }

     switch (PRESCALER)
    {
    case TMR_PRESCALE_1:
        SET_BIT( TMR_TCCR2 , TMR_TCCR2_CS20 );
        CLEAR_BIT( TMR_TCCR2 , TMR_TCCR2_CS21 );
        CLEAR_BIT( TMR_TCCR2 , TMR_TCCR2_CS22 );
        TMR2_PRESCALE = TMR_PRESCALE_1;
        break;
    case TMR_PRESCALE_8:
        CLEAR_BIT( TMR_TCCR2 , TMR_TCCR2_CS20 );
        SET_BIT( TMR_TCCR2 , TMR_TCCR2_CS21 );
        CLEAR_BIT( TMR_TCCR2 , TMR_TCCR2_CS22 );
        TMR2_PRESCALE = TMR_PRESCALE_8;
        break;
    case TMR_PRESCALE_64:
        SET_BIT( TMR_TCCR2 , TMR_TCCR2_CS20 );
        SET_BIT( TMR_TCCR2 , TMR_TCCR2_CS21 );
        CLEAR_BIT( TMR_TCCR2 , TMR_TCCR2_CS22 );
        TMR2_PRESCALE = TMR_PRESCALE_64;

        break;
    case TMR_PRESCALE_256:
        CLEAR_BIT( TMR_TCCR2 , TMR_TCCR2_CS20 );
        CLEAR_BIT( TMR_TCCR2 , TMR_TCCR2_CS21 );
        SET_BIT( TMR_TCCR2 , TMR_TCCR2_CS22 );
        TMR2_PRESCALE = TMR_PRESCALE_256;
        break;
    case TMR_PRESCALE_1024:
        SET_BIT( TMR_TCCR2 , TMR_TCCR2_CS20 );
        CLEAR_BIT( TMR_TCCR2 , TMR_TCCR2_CS21 );
        SET_BIT( TMR_TCCR2 , TMR_TCCR2_CS22 );
        TMR2_PRESCALE = TMR_PRESCALE_1024;
        break;
     case TMR_XCLK_FALLING:
        CLEAR_BIT( TMR_TCCR2 , TMR_TCCR2_CS20 );
        SET_BIT( TMR_TCCR2 , TMR_TCCR2_CS21 );
        SET_BIT( TMR_TCCR2 , TMR_TCCR2_CS22 );
        TMR2_PRESCALE = TMR_XCLK_FALLING;
        break;
    case TMR_XCLK_RISING:
        SET_BIT( TMR_TCCR2 , TMR_TCCR2_CS20 );
        SET_BIT( TMR_TCCR2 , TMR_TCCR2_CS21 );
        SET_BIT( TMR_TCCR2 , TMR_TCCR2_CS22 );
        TMR2_PRESCALE = TMR_XCLK_RISING;
        break;
    }


}

void TMR2_vDeInit(void)
{
    CLEAR_BIT( TMR_TCCR2 , TMR_TCCR2_CS20 );
    CLEAR_BIT( TMR_TCCR2 , TMR_TCCR2_CS22 );
    CLEAR_BIT( TMR_TCCR2 , TMR_TCCR2_CS21 );
}

void TMR2_vSet_Prescaler(u8 prescaler)
{

 switch (prescaler)
    {
    case TMR_PRESCALE_1:
        SET_BIT( TMR_TCCR2 , TMR_TCCR2_CS20 );
        CLEAR_BIT( TMR_TCCR2 , TMR_TCCR2_CS21 );
        CLEAR_BIT( TMR_TCCR2 , TMR_TCCR2_CS22 );
        TMR2_PRESCALE = TMR_PRESCALE_1;
        break;
    case TMR_PRESCALE_8:
        CLEAR_BIT( TMR_TCCR2 , TMR_TCCR2_CS20 );
        SET_BIT( TMR_TCCR2 , TMR_TCCR2_CS21 );
        CLEAR_BIT( TMR_TCCR2 , TMR_TCCR2_CS22 );
        TMR2_PRESCALE = TMR_PRESCALE_8;
        break;
    case TMR_PRESCALE_64:
        SET_BIT( TMR_TCCR2 , TMR_TCCR2_CS20 );
        SET_BIT( TMR_TCCR2 , TMR_TCCR2_CS21 );
        CLEAR_BIT( TMR_TCCR2 , TMR_TCCR2_CS22 );
        TMR2_PRESCALE = TMR_PRESCALE_64;

        break;
    case TMR_PRESCALE_256:
        CLEAR_BIT( TMR_TCCR2 , TMR_TCCR2_CS20 );
        CLEAR_BIT( TMR_TCCR2 , TMR_TCCR2_CS21 );
        SET_BIT( TMR_TCCR2 , TMR_TCCR2_CS22 );
        TMR2_PRESCALE = TMR_PRESCALE_256;
        break;
    case TMR_PRESCALE_1024:
        SET_BIT( TMR_TCCR2 , TMR_TCCR2_CS20 );
        CLEAR_BIT( TMR_TCCR2 , TMR_TCCR2_CS21 );
        SET_BIT( TMR_TCCR2 , TMR_TCCR2_CS22 );
        TMR2_PRESCALE = TMR_PRESCALE_1024;
        break;
     case TMR_XCLK_FALLING:
        CLEAR_BIT( TMR_TCCR2 , TMR_TCCR2_CS20 );
        SET_BIT( TMR_TCCR2 , TMR_TCCR2_CS21 );
        SET_BIT( TMR_TCCR2 , TMR_TCCR2_CS22 );
        TMR2_PRESCALE = TMR_XCLK_FALLING;
        break;
    case TMR_XCLK_RISING:
        SET_BIT( TMR_TCCR2 , TMR_TCCR2_CS20 );
        SET_BIT( TMR_TCCR2 , TMR_TCCR2_CS21 );
        SET_BIT( TMR_TCCR2 , TMR_TCCR2_CS22 );
        TMR2_PRESCALE = TMR_XCLK_RISING;
        break;
    }
}

void TMR2_vSet_Mode(u8 MODE)
{
      switch (MODE)
    {
    case TMR_MODE_NORMAL:
            CLEAR_BIT( TMR_TCCR2 , TMR_TCCR2_WGM20 ) ;
            CLEAR_BIT( TMR_TCCR2 , TMR_TCCR2_WGM21 ) ;
            TMR2_MODE = MODE;
            break;
        case TMR_MODE_CTC:
            CLEAR_BIT( TMR_TCCR2 , TMR_TCCR2_WGM20 ) ;
            SET_BIT( TMR_TCCR2 , TMR_TCCR2_WGM21 ) ;
            TMR2_MODE = MODE;
            break;
        case TMR_MODE_PWM:
            SET_BIT(    TMR_TCCR2 , TMR_TCCR2_WGM20 ) ;
            CLEAR_BIT( TMR_TCCR2 , TMR_TCCR2_WGM21 ) ;
            TMR2_MODE = MODE;
            break;
        case TMR_MODE_FAST_PWM:
            SET_BIT( TMR_TCCR2 , TMR_TCCR2_WGM20 ) ;
            SET_BIT( TMR_TCCR2 , TMR_TCCR2_WGM21 ) ;
            TMR2_MODE = MODE;
            break;
    }

}

u8 TMR2_u8GET_COUNTER_VALUE(void)
{
        return TMR_TCNT2;
}

 void TMR01_vReset_Prescaler(void)
{
    SET_BIT(TMR_SFIOR, TMR_SFIOR_PSR2);
}

/*NORMAL MODE*/
void TMR2_vENABLE_OVF_INTERRUPT(void)
{
     SET_BIT( TMR_TIMSK , TMR_TIMSK_TOIE2 ) ;
}

void TMR2_vDISABLE_OVF_INTERRUPT(void)
{
    CLEAR_BIT( TMR_TIMSK , TMR_TIMSK_TOIE2 ) ;
}

u8 TMR2_u8GET_OVF_INTERRUPT_FLAG(void)
{
    return GET_BIT( TMR_TIFR , TMR_TIFR_TOV2 ) ;
}

void TMR2_vSET_OVF_CALLBACK( void *(pFunction) ( void ) )
{
    if (pFunction != NULL)
    {
       TMR_CALLBACK_OVERFLOW_PTR2 = pFunction;
    }
}

void __vector_5(void)
{
    TMR2_OVF_COUNTER++;
    if (TMR_CALLBACK_OVERFLOW_PTR2 != NULL)
    {
        TMR_CALLBACK_OVERFLOW_PTR2();
    }
}

/*CTC MODE*/
void TMR2_vASSIGN_CTC_VALUE(u8 OCR_VALUE)
{
    TMR_OCR2 = OCR_VALUE;
}

u8 TMR2_u8GET_CTC_VALUE(void)
{
    return TMR_OCR2;
}

void TMR2_vENABLE_CTC_INTERRUPT(void)
{
    SET_BIT( TMR_TIMSK , TMR_TIMSK_OCIE2 ) ;
}

void TMR2_vDISABLE_CTC_INTERRUPT(void)
{
    CLEAR_BIT( TMR_TIMSK , TMR_TIMSK_OCIE2 ) ;
}

u8 TMR2_u8GET_OUTPUT_COMPARE_INTERRUPT_FLAG(void)
{
     return GET_BIT( TMR_TIFR , TMR_TIFR_OCF2 ) ;
}

void TMR2_vCLEAR_OUTPUT_COMPARE_INTERRUPT_FLAG(void)
{
    CLEAR_BIT( TMR_TIFR , TMR_TIFR_OCF2 ) ;
}

u32 TMR2_u32GET_CTC_FREQUENCY(void)
{
    return  (u32) ( F_CPU / ( 2*( 1+ TMR_OCR2 ) * TMR2_PRESCALE ) );
}

u8 TMR2_CTC_u8SET_FREQUENCY(u32 Target_Frequency)
{ // 30.5< target_frequency<F_CPU/2
    u8 STATE= ERROR;
    u8 N_1OCRn = (u8) ( ( F_CPU / ( 2* Target_Frequency* TMR2_PRESCALE ) ) -1 ) ;

    if (N_1OCRn <=255)
    {
         STATE = SUCCESS;
         TMR2_vASSIGN_CTC_VALUE(N_1OCRn);
    }
    else
    {
          STATE = ERROR;
    }
    
    

            if(  ( (  (u32) (0.90*(TMR2_u32GET_CTC_FREQUENCY())) <Target_Frequency) 
            && (  (u32)  (1.1*(TMR2_u32GET_CTC_FREQUENCY()))  >Target_Frequency) ) )
            {
                STATE = SUCCESS;
            }
            else
            {
                STATE = ERROR;
            }
            return STATE;

}

void TMR2_vSET_CTC_CALLBACK( void *(pFunction) ( void ) )
{
    if (pFunction != NULL)
    {
       TMR_CALLBACK_COMPARE_MATCH_PTR2 = pFunction;
    }
    
}

void __vector_4(void)
{
    TMR2_CTC_COUNTER++;
    if (TMR_CALLBACK_COMPARE_MATCH_PTR2 != NULL)
    {
        TMR_CALLBACK_COMPARE_MATCH_PTR2();
    }
        
}

/*NON-PWM*/
void TMR0_ENABLE_Pd7_OF_OUTPUT_COMPARE(void)
{
SET_BIT(TMR_OC2_DDR,TMR_OC2_PIN);
}

void TMR0_DISCONNECT_PD7_ON_OUTPUT_COMPARE(void)
{
     CLEAR_BIT( TMR_TCCR2 , TMR_TCCR2_COM20 ) ;
     CLEAR_BIT( TMR_TCCR2 , TMR_TCCR2_COM21 ) ;
}

void TMR0_vSET_PD7_ON_OUTPUT_COMPARE(void)
{
     SET_BIT( TMR_TCCR2 , TMR_TCCR2_COM20 ) ;
     SET_BIT( TMR_TCCR2 , TMR_TCCR2_COM21 ) ;
}

void TMR2_CLEAR_PD7_ON_OUTPUT_COMPARE(void)
{
    CLEAR_BIT( TMR_TCCR2 , TMR_TCCR2_COM20 ) ;
    SET_BIT( TMR_TCCR2 , TMR_TCCR2_COM21 ) ;
}

void TMR2_TOGGLE_PD7_ON_OUTPUT_COMPARE(void)
{
     SET_BIT(      TMR_TCCR2 , TMR_TCCR2_COM20 ) ;
     CLEAR_BIT( TMR_TCCR2 , TMR_TCCR2_COM21 ) ;
}

void TMR2_vFORCE_OUTPUT_COMPARE(void)
{
    SET_BIT(TMR_TCCR2, TMR_TCCR2_FOC2);
}

/*PWM*/
void TMR2_PWM_vSET_DUTY_CYCLE_VALUE(u8 duty_cycle)
{
    if (TMR2_MODE == TMR_MODE_FAST_PWM 
    || TMR2_MODE == TMR_MODE_PWM )
    {
        if(duty_cycle <=100 && duty_cycle >=0)
            TMR_OCR2 =  (u8) ( (duty_cycle * 256)/100 )  ;
    }
    }

void TMR2_PWM_ASSIGN_INVERSION(u8 is_inverted)
{
    switch (is_inverted)
    {
    case TRUE:
        SET_BIT( TMR_TCCR2 , TMR_TCCR2_COM20 ) ;
        CLEAR_BIT( TMR_TCCR2 , TMR_TCCR2_COM21 ) ;
        break;
    default: 
        SET_BIT( TMR_TCCR2 , TMR_TCCR2_COM20 ) ;
        SET_BIT( TMR_TCCR2 , TMR_TCCR2_COM21 ) ;
        break;
    }
}

u32 TMR2_u32GET_PWM_FREQUENCY(void)
{
    u32 frequency = 0;
    switch (TMR2_MODE)
    {
    case TMR_MODE_FAST_PWM: frequency = (u32) (F_CPU/TMR2_PRESCALE*256);
    break;
    
    case TMR_MODE_PWM: frequency = (u32) (F_CPU/TMR2_PRESCALE*510);
    break;
    }
    return frequency;
}


#endif

#if (TMR_ENABLE_TMR0 == TRUE) && (TMR_ENABLE_TMR1 == TRUE)
    void TMR01_vReset_Prescaler(void)
    {
        SET_BIT(TMR_SFIOR, TMR_SFIOR_PSR10);
    }
#endif

