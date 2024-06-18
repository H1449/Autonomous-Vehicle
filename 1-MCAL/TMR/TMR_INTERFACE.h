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

    #define TMR_RISING_EDGE 1
    #define TMR_FALLING_EDGE 0
    
    #define TMR_MODE_NORMAL 4
    #define TMR_MODE_PWM 1
    #define TMR_MODE_FAST_PWM 2
    #define TMR_MODE_CTC 3


    #define TMR_PRESCALE_1 1
    #define TMR_PRESCALE_8 8
    #define TMR_PRESCALE_64 64
    #define TMR_PRESCALE_256 128
    #define TMR_PRESCALE_1024 10
    #define TMR_XCLK_FALLING 2
    #define TMR_XCLK_RISING 3

#if  TMR_ENABLE_TMR0 == TRUE

/*GENERAL*/
void TMR0_vInit( u8 MODE, u8 TMR_PRESCALER); 

void TMR0_vDeInit(void);

void TMR0_vSet_Prescaler(u8 prescaler);

void TMR0_vSet_Mode(u8 mode);

u8 TMR0_u8GET_COUNTER_VALUE(void); 

/*NORMAL MODE*/
void TMR0_vENABLE_OVF_INTERRUPT(void);

void TMR0_vDISABLE_OVF_INTERRUPT(void);

u8 TMR0_u8GET_OVF_INTERRUPT_FLAG(void);

void TMR0_vSET_OVF_CALLBACK( void (*pFunction) ( void ) );

void __vector_11(void) __attribute__( ( signal ) );

/*CTC MODE*/
void TMR0_vASSIGN_CTC_VALUE(u8 OCR_VALUE); 

u8 TMR0_u8GET_CTC_VALUE(void);

void TMR0_vENABLE_CTC_INTERRUPT(void);

void TMR0_vDISABLE_CTC_INTERRUPT(void);

u8 TMR0_u8GET_OUTPUT_COMPARE_INTERRUPT_FLAG(void);

void TMR0_vCLEAR_OUTPUT_COMPARE_INTERRUPT_FLAG(void);

u32 TMR0_u32GET_CTC_FREQUENCY(void);

u8 TMR0_CTC_u8SET_FREQUENCY(u32 Target_Frequency);

void TMR0_vSET_CTC_CALLBACK( void (*pFunction) ( void ) );

void __vector_10(void) __attribute__( ( signal ) );

/*NON-PWM*/
void TMR0_vENABLE_OC0_OF_OUTPUT_COMPARE(void);

void TMR0_vDISCONNECT_OC0_ON_OUTPUT_COMPARE(void);

void TMR0_vSET_OC0_ON_OUTPUT_COMPARE(void);

void TMR0_vCLEAR_OC0_ON_OUTPUT_COMPARE(void);

void TMR0_vTOGGLE_OC0_ON_OUTPUT_COMPARE(void);

void TMR0_vFORCE_OUTPUT_COMPARE(void);

/*PWM*/
void TMR0_PWM_vSET_DUTY_CYCLE_VALUE(u8 duty_cycle);

void TMR0_PWM_vASSIGN_INVERSION(u8 is_inverted);

u32 TMR0_u32GET_PWM_FREQUENCY(void);

#endif

#if  TMR_ENABLE_TMR1 == TRUE

    #define TMR_MODE_PWM_9_BITS 9 
    #define TMR_MODE_PWM_10_BITS 10 
    #define TMR_MODE_PWM_INPUT_CAPTURE 12
    #define TMR_MODE_PWM_OCR1A 13

    #define TMR_MODE_PWM_PHASE_AND_FREQUENCY_CORRECT 5
    #define TMR_MODE_PWM_INPUT_CAPTURE_PHASE_AND_FREQUENCY_CORRECT 6
    
    #define TMR_MODE_FAST_PWM_9_BITS 18
    #define TMR_MODE_FAST_PWM_10_BITS 20
    #define TMR_MODE_FAST_PWM_INPUT_CAPTURE 7
    #define TMR_MODE_FAST_PWM_OCR1A 8


    #define TMR_MODE_CTC_INPUT_CAPTURE 11


/*GENERAL*/
void TMR1_vInit( u8 MODE, u8 PRESCALER);

void TMR1_vDeInit(void);

void TMR1_vSet_Prescaler(u8 PRESCALER);

void TMR1_vSet_Mode(u8 MODE);

u16 TMR1_u8GET_COUNTER_VALUE(void);

void TMR1_vENABLE_OVF_INTERRUPT(void);

void TMR1_vDISABLE_OVF_INTERRUPT(void);

u8 TMR1_u8GET_OVF_INTERRUPT_FLAG(void);

void TMR1_vCLEAR_OVF_INTERRUPT_FLAG(void);

void TMR1_vSET_OVF_CALLBACK( void *(pFunction) ( void ) );

void __vector_9(void) __attribute__( ( signal ) );

/*OCR1A*/
void TMR1_vASSIGN_CTCA_VALUE(u16 OCRA_VALUE);

u16 TMR1_u16GET_CTCA_VALUE(void);

void TMR1_vENABLE_CTCA_INTERRUPT(void);

void TMR1_vDISABLE_CTCA_INTERRUPT(void);

u8 TMR1_u8GET_CTCA_INTERRUPT_FLAG(void);

void TMR1_vCLEAR_CTCA_INTERRUPT_FLAG(void);

void TMR1_vSET_CTCA_CALLBACK( void (*pFunction) ( void ) );

void __vector_7(void) __attribute__( ( signal ) );

void TMR1_vENABLE_OC1A_OF_OUTPUT_COMPARE(void);

void TMR1_vDISCONNECT_OC1A_ON_OUTPUT_COMPARE(void);

void TMR1_vSET_OC1A_ON_OUTPUT_COMPARE(void);

void TMR1_vCLEAR_OC1A_ON_OUTPUT_COMPARE(void);

void TMR1_vTOGGLE_OC1A_ON_OUTPUT_COMPARE(void);

void TMR1_vFORCE_OUTPUT_COMPARE_A(void);

/*OCR1B*/
void TMR1_vASSIGN_CTCB_VALUE(u16 OCRB_VALUE);

u16 TMR1_u16GET_CTCB_VALUE(void);

void TMR1_vENABLE_CTCB_INTERRUPT(void);

void TMR1_vDISABLE_CTCB_INTERRUPT(void);

u8 TMR1_u8GET_CTCB_INTERRUPT_FLAG(void);

void TMR1_vCLEAR_CTCB_INTERRUPT_FLAG(void);

void TMR1_vSET_CTCB_CALLBACK( void (*pFunction) ( void ));

void __vector_8(void) __attribute__( ( signal ) );

void TMR1_vENABLE_OC1B_OF_OUTPUT_COMPARE(void);

void TMR1_vDISCONNECT_OC1B_ON_OUTPUT_COMPARE(void);

void TMR1_vSET_OC1B_ON_OUTPUT_COMPARE(void);

void TMR1_vCLEAR_OC1B_ON_OUTPUT_COMPARE(void);

void TMR1_vTOGGLE_OC1B_ON_OUTPUT_COMPARE(void);

void TMR1_vFORCE_OUTPUT_COMPARE_B(void);

/*INPUT CAPTURE*/
void TMR1_vENABLE_ICR_INTERRUPT(void);

void TMR1_vDISABLE_ICR_INTERRUPT(void);

void  TMR1_PWM_vSET_ICR_VALUE(u16 ICR_value);

u16  TMR1_u16GET_ICR_VALUE(void);

void TMR1_vENABLE_NOISE_CANCELER_ON_ICR(void);

void TMR1_vDISABLE_NOISE_CANCELER_ON_ICR(void);

void TMR1_ICR_EDGE_SELECT(u8 edge);

u8 TMR1_u8GET_ICR_INTERRUPT_FLAG(void);

void TMR1_CLEAR_ICR_INTERRUPT_FLAG(void);

void TMR1_vSET_ICR_CALLBACK( void (*pFunction) ( void ) );

void __vector_6(void) __attribute__( ( signal ) );

#endif

#if  TMR_ENABLE_TMR2 == TRUE

/*GENERAL*/
void TMR2_vInit( u8 MODE, u8 TMR_PRESCALER); 

void TMR2_vDeInit(void);

void TMR2_vSet_Prescaler(u8 prescaler);

void TMR2_vSet_Mode(u8 mode);

u8 TMR2_u8GET_COUNTER_VALUE(void); 

void TMR2_vReset_Prescaler(void);

/*NORMAL MODE*/
void TMR2_vENABLE_OVF_INTERRUPT(void);

void TMR2_vDISABLE_OVF_INTERRUPT(void);

u8 TMR2_u8GET_OVF_INTERRUPT_FLAG(void);

void TMR2_vSET_OVF_CALLBACK( void (*pFunction) ( void ) );

void __vector_5(void) __attribute__( ( signal ) );

/*CTC MODE*/
void TMR2_vASSIGN_CTC_VALUE(u8 OCR_VALUE); 

u8 TMR2_u8GET_CTC_VALUE(void);

void TMR2_vENABLE_CTC_INTERRUPT(void);

void TMR2_vDISABLE_CTC_INTERRUPT(void);

u8 TMR2_u8GET_OUTPUT_COMPARE_INTERRUPT_FLAG(void);

void TMR2_vCLEAR_OUTPUT_COMPARE_INTERRUPT_FLAG(void);

u32 TMR2_u32GET_CTC_FREQUENCY(void);

u8 TMR2_CTC_u8SET_FREQUENCY(u32 Target_Frequency);

void TMR2_vSET_CTC_CALLBACK( void (*pFunction) ( void ) ); /*Interrupt finction of tmr0 on compare match*/

void __vector_4(void) __attribute__( ( signal ) );

/*NON-PWM*/
void TMR2_vENABLE_OC2_OF_OUTPUT_COMPARE(void);

void TMR2_vDISCONNECT_OC2_ON_OUTPUT_COMPARE(void);

void TMR2_vSET_OC2_ON_OUTPUT_COMPARE(void);

void TMR2_vCLEAR_OC2_ON_OUTPUT_COMPARE(void);

void TMR2_vTOGGLE_OC2_ON_OUTPUT_COMPARE(void);

void TMR2_vFORCE_OUTPUT_COMPARE(void);

/*PWM*/
void TMR2_PWM_SET_DUTY_CYCLE_VALUE(u8 duty_cycle);

void TMR2_PWM_vASSIGN_INVERSION(u8 is_inverted);

u32 TMR2_u32GET_PWM_FREQUENCY(void);


#endif

#if TMR_ENABLE_TMR0 == TRUE && TMR_ENABLE_TMR1 == TRUE
    void TMR01_vReset_Prescaler(void);
#endif

#endif //end of file