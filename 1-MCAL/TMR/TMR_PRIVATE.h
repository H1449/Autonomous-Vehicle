/*****************************************************************************************/
//**************************AUTHOR: Mohamed Hesham Hassan***********************//
//**********************************DATE: 01.04.2024**********************************//
//****************************CONTACT: +201115581391*****************************//
//************************EMAIL: mohamedhassan5401@outlook.com****************//
//************************DRIVER: TMR; External Interrupt Perepheral****************//
//***********************************VERSION: 0.0.1**********************************//
//*******************************FILE: TMR_PRIVATE.C*******************************//
//*************************************************************************************/

/*TCNTn -->Timer / Counter register (from 0 to 255)*/
/*TOV    -->   bit which is Flag that is set HIGH when Timer overflows*/
/**/


#ifndef TMR_PRIVATE_H 

// Header guard . (if file is not defined then define it)
#define TMR_PRIVATE_H



//static void ( *TMR_pOVF ) ( void ) = NULL;
#define TMR_TIMSK            (*(volatile u8*)(0x59)) /*INTERRUPT MASK REGISTER (SECIOND KEY INTERRUPT)*/
#define TMR_TIFR               (*(volatile u8*)(0x58))
#define TMR_SFIOR        (*(volatile u8*)(0x50))

#if (TMR_ENABLE_TMR0 == TRUE) && (TMR_ENABLE_TMR1 == TRUE)
    
    #define TMR_SFIOR_PSR10 0
#endif

#if TMR_ENABLE_TMR0 == TRUE

    static void  ( *TMR_CALLBACK_COMPARE_MATCH_PTR0 ) (void) = NULL;
    static  void  ( *TMR_CALLBACK_OVERFLOW_PTR0 ) (void) = NULL;
    static u16 TMR0_PRESCALE=FALSE;
    static u8 TMR0_MODE = FALSE;
    static u32 TMR0_CTC_COUNTER = 0, TMR0_OVF_COUNTER = 0;

    #define TMR_OC0_DDR  (*(volatile u8*)(0x37))
    #define TMR_OC0_PORT (*(volatile u8*)(0x38))
    #define TMR_OC0_PIN     3

    #define TMR_TCCR0            (*(volatile u8*)(0x53))
    #define TMR_TCCR0_FOC0 7
    /*The FOC0 bit is only active when the WGM00 bit specifies a non-PWM mode. However, for
    ensuring compatibility with future devices, this bit must be set to zero when TCCR0 is written
    when operating in PWM mode. When writing a logical one to the FOC0 bit, an immediate compare
    match is forced on the Waveform Generation unit. The OC0 output is changed according to
    its COM01:0 bits setting. Note that the FOC0 bit is implemented as a strobe. Therefore it is the
    value present in the COM01:0 bits that determines the effect of the forced compare.
    A FOC0 strobe will not generate any interrupt, nor will it clear the timer in CTC mode using
    OCR0 as TOP.
    The FOC0 bit is always read as zero.*/
    #define TMR_TCCR0_WGM00 6
    #define TMR_TCCR0_COM01  5
    #define TMR_TCCR0_COM00  4
    #define TMR_TCCR0_WGM01 3
    /*These bits control the counting sequence of the counter, the source for the maximum (TOP)
    counter value, and what type of Waveform Generation to be used. Modes of operation supported
    by the Timer/Counter unit are: Normal mode, Clear Timer on Compare Match (CTC)
    mode, and two types of Pulse Width Modulation (PWM) modes. See Table 38 and “Modes of
    Operation” on page 73.
    These bits control the Output Compare pin (OC0) behavior. If one or both of the COM01:0 bits
    are set, the OC0 output overrides the normal port functionality of the I/O pin it is connected to.
    However, note that the Data Direction Register (DDR) bit corresponding to the OC0 pin must be
    set in order to enable the output driver.
    When OC0 is connected to the pin, the function of the COM01:0 bits depends on the WGM01:0
    bit setting. Table 39 shows the COM01:0 bit functionality when the WGM01:0 bits are set to a
    normal or CTC mode (non-PWM).*/

    #define TMR_TCCR0_CS02  2
    #define TMR_TCCR0_CS01  1
    #define TMR_TCCR0_CS00  0
    /*The three Clock Select bits select the clock source to be used by the Timer/Counter.*/

    

    #define TMR_TCNT0            (*(volatile u8*)(0x52)) /*TMR0 COUNTER REGISTER*/
    /*Writing to the TCNT0 Register blocks (removes) the compare
    match on the following timer clock. Modifying the counter (TCNT0) while the counter is running,
    introduces a risk of missing a compare match between TCNT0 and the OCR0 Register.*/

    #define TMR_OCR0             (*(volatile u8*)(0x5C)) /*OUTPUT COMPARE REGISTER *(YOU Write value in this register)*/
    /*The Output Compare Register contains an 8-bit value that is continuously compared with the
    counter value (TCNT0). A match can be used to generate an output compare interrupt, or to
    generate a waveform output on the OC0 pin.*/


    #define TMR_TIMSK_TOIE0   0 
    #define TMR_TIMSK_OCIE0 1 

    #define TMR_TIFR_TOV0 0
    #define TMR_TIFR_OCF0 1

    /*When the TOIE0 bit is written to one, and the I-bit in the Status Register is set (one), the
    Timer/Counter0 Overflow interrupt is enabled. The corresponding interrupt is executed if an
    overflow in Timer/Counter0 occurs, that is, when the TOV0 bit is set in the Timer/Counter Interrupt
    Flag Register – TIFR.
    When the OCIE0 bit is written to one, and the I-bit in the Status Register is set (one), the
    Timer/Counter0 Compare Match interrupt is enabled. The corresponding interrupt is executed if
    a compare match in Timer/Counter0 occurs, that is, when the OCF0 bit is set in the Timer/Counter
    Interrupt Flag Register – TIFR.*/

#endif

#if TMR_ENABLE_TMR1 == TRUE

    static void  ( *TMR_CALLBACK_COMPARE_MATCH_A_PTR1 ) (void) = NULL;
    static void  ( *TMR_CALLBACK_COMPARE_MATCH_B_PTR1 ) (void) = NULL;
    static  void  ( *TMR_CALLBACK_OVERFLOW_PTR1 ) (void) = NULL;
    static  void  ( *TMR_CALLBACK_INPUT_CAPTURE_PTR1 ) (void) = NULL;
    static u16 TMR1_PRESCALE=FALSE;
    static u8 TMR1_MODE = FALSE;
    static u16 TMR1_CTCA_COUNTER = 0, TMR1_CTCB_COUNTER = 0,  
                     TMR1_ICR_COUNTER=0, TMR1_OVF_COUNTER = 0;

    #define TMR_OC1_DDR  (*(volatile u8*)(0x31))
    #define TMR_OC1_PORT (*(volatile u8*)(0x32))
    #define TMR_OC1A_PIN     5
    #define TMR_OC1B_PIN     4

    #define TMR_TCCR1A          (*(volatile u8*)(0x4F))

    #define TMR_TCCR1A_COM1A1 7
    #define TMR_TCCR1A_COM1A0 6
    #define TMR_TCCR1A_COM1B1 5
    #define TMR_TCCR1A_COM1B0 4
    #define TMR_TCCR1A_FOC1A    3
    #define TMR_TCCR1A_FOC1B    2
    #define TMR_TCCR1A_WGM11  1
    #define TMR_TCCR1A_WGM10  0

    #define TMR_TCCR1B          (*(volatile u8*)(0x4E))
    #define TMR_TCCR1B_ICNC1 7
    #define TMR_TCCR1B_ICES 6
    #define TMR_TCCR1B_WGM13 4
    #define TMR_TCCR1B_WGM12   3
    #define TMR_TCCR1B_CS12   2
    #define TMR_TCCR1B_CS11 1
    #define TMR_TCCR1B_CS10 0

    #define TMR_TIMSK_TOIE1   2
    #define TMR_TIMSK_OCIE1B 3 
    #define TMR_TIMSK_OCIE1A 4 
    #define TMR_TIMSK_TICIE1   5



    #define TMR_TIFR_TOV1  2
    #define TMR_TIFR_OCF1B   3
    #define TMR_TIFR_OCF1A   4  
    #define TMR_TIFR_ICF1   5

    #define TMR_TCNT1H         (*(volatile u8*)(0x4D))
    #define TMR_TCNT1L          (*(volatile u8*)(0x4C))

    #define TMR_TCNT1  TMR_TCNT1L+ (TMR_TCNT1H<<4)

    #define TMR_OCR1AH         (*(volatile u8*)(0x4B))
    #define TMR_OCR1AL          (*(volatile u8*)(0x4A))

    #define TMR_OCR1A  TMR_OCR1AL+ (TMR_OCR1AH<<4)


    #define TMR_OCR1BH         (*(volatile u8*)(0x49))
    #define TMR_OCR1BL          (*(volatile u8*)(0x48))

    #define TMR_OCR1B  TMR_OCR1BL+ (TMR_OCR1BH<<4)

    #define TMR_ICR1H         (*(volatile u8*)(0x47))
    #define TMR_ICR1L          (*(volatile u8*)(0x46))

    #define TMR_ICR1  TMR_ICR1L+ (TMR_ICR1H<<4)

#endif

#if TMR_ENABLE_TMR2 == TRUE

    static void  ( *TMR_CALLBACK_COMPARE_MATCH_PTR2 ) (void) = NULL;
    static  void  ( *TMR_CALLBACK_OVERFLOW_PTR2 ) (void) = NULL;
    static u16 TMR2_PRESCALE=FALSE;
    static u8 TMR2_MODE = FALSE;
    static u32 TMR2_CTC_COUNTER = 0, TMR2_OVF_COUNTER = 0;

    #define TMR_OC2_DDR  (*(volatile u8*)(0x31))
    #define TMR_OC2_PORT (*(volatile u8*)(0x32))
    #define TMR_OC2_PIN     7
    

    #define TMR_TIMSK_TOIE2 6
    #define TMR_TIMSK_OCIE2 7

    #define TMR_TIFR_TOV2  6
    #define TMR_TIFR_OCF2 7

    #define TMR_SFIOR_PSR2 1

    #define TMR_TCCR2         (*(volatile u8*)(0x45))
    #define TMR_TCCR2_FOC2      7
    #define TMR_TCCR2_WGM20  6 
    #define TMR_TCCR2_COM21   5
    #define TMR_TCCR2_COM20   4
    #define TMR_TCCR2_WGM21  3
    #define TMR_TCCR2_CS22       2
    #define TMR_TCCR2_CS21       1
    #define TMR_TCCR2_CS20       0

    #define TMR_TCNT2          (*(volatile u8*)(0x44))
    #define TMR_OCR2         (*(volatile u8*)(0x43))


    #define TMR_ASSR         (*(volatile u8*)(0x42))
    #define TMR_ASSR_AS2          3
    #define TMR_ASSR_TCN2UB   2
    #define TMR_ASSR_OCR2UB   1
    #define TMR_ASSR_TCR2UB    0


#endif
/*The OCF0 bit is set (one) when a compare match occurs between the Timer/Counter0 and the
data in OCR0 – Output Compare Register0. OCF0 is cleared by hardware when executing the
corresponding interrupt handling vector. Alternatively, OCF0 is cleared by writing a logic one to
the flag. When the I-bit in SREG, OCIE0 (Timer/Counter0 Compare Match Interrupt Enable), and
OCF0 are set (one), the Timer/Counter0 Compare Match Interrupt is executed.*/
/*The bit TOV0 is set (one) when an overflow occurs in Timer/Counter0. TOV0 is cleared by hardware
when executing the corresponding interrupt handling vector. Alternatively, TOV0 is cleared
by writing a logic one to the flag. When the SREG I-bit, TOIE0 (Timer/Counter0 Overflow Interrupt
Enable), and TOV0 are set (one), the Timer/Counter0 Overflow interrupt is executed. In
phase correct PWM mode, this bit is set when Timer/Counter0 changes counting direction at
$00.*/

#endif