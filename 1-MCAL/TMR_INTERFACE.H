//*****************************************************************************************/
//**************************AUTHOR: Mohamed Hesham Hassan***********************//
//**********************************DATE: 01.04.2024**********************************//
//****************************CONTACT: +201115581391*****************************//
//************************EMAIL: mohamedhassan5401@outlook.com****************//
//************************DRIVER: TMR; External Interrupt Perepheral****************//
//***********************************VERSION: 0.0.1**********************************//
//*******************************FILE: TMR_INTERFACE.C*****************************//
//*************************************************************************************/
#ifndef TMR_INTERFACE_H
 // Header guard . (if file is not defined then define it)
#define TMR_INTERFACE_H

/*The simplest mode of operation is the normal mode (WGM01:0 = 0). In this mode the counting
direction is always up (incrementing), and no counter clear is performed. The counter simply
overruns when it passes its maximum 8-bit value (TOP = 0xFF) and then restarts from the bottom
(0x00). In normal operation the Timer/Counter Overflow Flag (TOV0) will be set in the same 
timer clock cycle as the TCNT0 becomes zero. The TOV0 Flag in this case behaves like a ninth
bit, except that it is only set, not cleared. However, combined with the timer overflow interrupt
that automatically clears the TOV0 Flag, the timer resolution can be increased by software.
There are no special cases to consider in the normal mode, a new counter value can be written
anytime. The output compare unit can be used to generate interrupts at some given time. Using the output
compare to generate waveforms in Normal mode is not recommended, since this will occupy
too much of the CPU time.*/


#if  TMR_TMR0_EN == TRUE

void TMR_TMR0_vInit( u8 MODE, u8 TMR_PRESCALER);

void TMR_TMR0_ASSIGN_TCNT0(u8 TCNT_VALUE);

u8 TMR_TMR0_GET_TCNT0();

void TMR_TMR0_vSET_COMPARE_MATCH(u8 OCR_VALUE);

void TMR_TMR0_SET_CALLBACK( void ( *pFunction ) ( void ) );

void __vector_11()   __attribute__( ( signal ) );

u8 TMR_TMR0_GET_OCR0();

void TMR_TMR0_OCI_EN_COMPARE_MATCH();

u8 TMR_TMR0_GET_OCIE_COMPARE_MATCH();

void TMR_TMR0_TOI_EN_OVERFLOW();

u8 TMR_TMR0_GET_TOIE_OVERFLOW();

u8 TMR_TMR0_GET_OCF_COMPARE_MATCH();

u8 TMR_TMR0_GET_TOV_OVERFLOW();

void TMR_TMR0_PWM_SET_DUTY_CYCLE(u8 duty_cycle);

void TMR_TMR0_PWM_vInit(u8 PRESCALER, u8 is_inverted);



void TMR_TMR0_DISCONNECT_OC0();

void TMR_TMR0_SET_OC0();

void TMR_TMR0_CLEAR_OC0();

void TMR_TMR0_TOGGLE_OC0();


void TMR_TMR0_PWM_DISCONNECT_OC0();

void TMR_TMR0_PWM_SET_OC0();

void TMR_TMR0_PWM_CLEAR_OC0();


void TMR_TMR0_FASTPWM_DISCONNECT_OC0();

void TMR_TMR0_FASTPWM_SET_OC0();

void TMR_TMR0_FASTPWM_CLEAR_OC0();
#endif





    #define TMR_MODE_NORMAL 0
    #define TMR_MODE_PWM 1
    #define TMR_MODE_FAST_PWM 2
    #define TMR_MODE_CTC 3

    #define TMR_PRESCALE_1 1
    #define TMR_PRESCALE_8 8
    #define TMR_PRESCALE_64 64
    #define TMR_PRESCALE_256 256
    #define TMR_PRESCALE_1024 1024
    #define TMR_XCLK_FALLING 2
    #define TMR_XCLK_RISING 3
/*Timer/Counter0 is a general purpose, single compare unit, 8-bit Timer/Counter module. The
main features are:
• Single Compare Unit Counter
• Clear Timer on Compare Match (Auto Reload)
• Glitch-free, Phase Correct Pulse Width Modulator (PWM)
• Frequency Generator
• External Event Counter
• 10-bit Clock Prescaler
• Overflow and Compare Match Interrupt Sources (TOV0 and OCF0)*/

#endif //end of file