//*****************************************************************************************/
//**************************AUTHOR: Mohamed Hesham Hassan***********************//
//**********************************DATE: 23.02.2024**********************************//
//****************************CONTACT: +201115581391*****************************//
//************************EMAIL: mohamedhassan5401@outlook.com****************//
//************************DRIVER: EXTI; External Interrupt Perepheral****************//
//***********************************VERSION: 0.0.1**********************************//
//*******************************FILE: EXTI_PROG.C*******************************//
//*************************************************************************************/

//include essential header files (BIT_MATH and STD_TYPES)
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "_ATMEGA32_.h"  //this file is written by me to include all essential uncategorized addresses

//include header files of the driver
#include "EXTI_CONFIG.h"
#include "EXTI_PRIVATE.h"
#include "EXTI_INTERFACE.h"

void EXTI_vInit()  
{

#if  EXTI_ENABLE_INT0 == TRUE

        #if  EXTI_INT0_SENSE_CONTROL == EXTI_LOW_LEVEL 

            CLEAR_BIT(EXTI_MCUCR, EXTI_MCUCR_ISC00) ;
            CLEAR_BIT(EXTI_MCUCR, EXTI_MCUCR_ISC01) ;

        #elif  EXTI_INT0_SENSE_CONTROL == EXTI_ANY

            SET_BIT(EXTI_MCUCR, EXTI_MCUCR_ISC00) ;
            CLEAR_BIT(EXTI_MCUCR, EXTI_MCUCR_ISC01) ;
    
        #elif  EXTI_INT0_SENSE_CONTROL == EXTI_FALLING

            CLEAR_BIT(EXTI_MCUCR, EXTI_MCUCR_ISC00) ;
            SET_BIT(EXTI_MCUCR, EXTI_MCUCR_ISC01) ;

        #elif  EXTI_INT0_SENSE_CONTROL == EXTI_RISING

            SET_BIT(EXTI_MCUCR, EXTI_MCUCR_ISC00) ;
            SET_BIT(EXTI_MCUCR, EXTI_MCUCR_ISC01) ;

        #endif
    #endif

#if  EXTI_ENABLE_INT1 == TRUE

    #if  EXTI_INT1_SENSE_CONTROL == EXTI_LOW_LEVEL 

    CLEAR_BIT(EXTI_MCUCR, EXTI_EXTI_MCUCR_ISC10) ;
    CLEAR_BIT(EXTI_MCUCR, EXTI_MCUCR_ISC11) ;

    #elif  EXTI_INT1_SENSE_CONTROL == EXTI_ANY

    SET_BIT(EXTI_MCUCR, EXTI_MCUCR_ISC10) ;
    CLEAR_BIT(EXTI_MCUCR, EXTI_MCUCR_ISC11) ;

    #elif  EXTI_INT1_SENSE_CONTROL == EXTI_FALLING

    CLEAR_BIT(EXTI_MCUCR, EXTI_MCUCR_ISC10) ;
    SET_BIT(EXTI_MCUCR, EXTI_MCUCR_ISC11) ;

    #elif  EXTI_INT0_SENSE_CONTROL == EXTI_RISING

    SET_BIT(EXTI_MCUCR, EXTI_MCUCR_ISC10) ;
    SET_BIT(EXTI_MCUCR, EXTI_MCUCR_ISC11) ;

    #endif
#endif

#if  EXTI_ENABLE_INT2 == TRUE

    #if EXTI_INT2_SENSE_CONTROL == EXTI_RISING

        SET_BIT(EXTI_MCUCSR, EXTI_MCUCSR_ISC2) ;
    
    #else

        CLEAR_BIT(EXTI_MCUCSR, EXTI_MCUCSR_ISC2) ;

    #endif
#endif

}


#if  EXTI_ENABLE_INT0 == TRUE

    void  ( *EXTI_CALLBACK_PTR0 ) (void) = NULL;

    void EXTI_ENABLE_INT0_INTERRUPT(void)
    {
        SET_BIT(EXTI_GICR , EXTI_GICR_INT0);// set INT0  (Second Key)
    }

    void EXTI_DISABLE_INT0_INTERRUPT(void)
    {
        CLEAR_BIT(EXTI_GICR , EXTI_GICR_INT0);// Clear INT0  (Second Key)
    }

void EXTI_vASSIGN_SENSE_CTRL_INT0(u8 sense_ctrl_state)
{
    switch (sense_ctrl_state)
    {
    case EXTI_LOW_LEVEL: 
        CLEAR_BIT(EXTI_MCUCR, EXTI_MCUCR_ISC00) ;
        CLEAR_BIT(EXTI_MCUCR, EXTI_MCUCR_ISC01) ;break;
    case EXTI_FALLING: 
        CLEAR_BIT(EXTI_MCUCR, EXTI_MCUCR_ISC00) ;
        SET_BIT(EXTI_MCUCR, EXTI_MCUCR_ISC01) ; break;
    case EXTI_RISING: 
        SET_BIT(EXTI_MCUCR, EXTI_MCUCR_ISC00) ;
        SET_BIT(EXTI_MCUCR, EXTI_MCUCR_ISC01) ; break;    
    default:  
        SET_BIT(EXTI_MCUCR, EXTI_MCUCR_ISC00) ;
        CLEAR_BIT(EXTI_MCUCR, EXTI_MCUCR_ISC01) ;break;
    }

}

u8 EXTI_u8GET_INT0_FLAG(void)
{
   return GET_BIT(EXTI_GIFR, EXTI_GIFR_INTF0);
}

void EXTI_vCLEAR_INT0_FLAG(void)
{
    SET_BIT(EXTI_GIFR, EXTI_GIFR_INTF0);
    /* The flag is cleared when the interrupt routine is executed.
Alternatively, the flag can be cleared by writing a logical one to it. This flag is always cleared
when INT0 is configured as a level interrupt.*/
}

void EXTI_CALLBACK0( void *( function ) (void) )
{
    EXTI_CALLBACK_PTR0 = function ;
}

void __vector_1(void) {

     if (EXTI_CALLBACK_PTR0 != NULL)
    {
        EXTI_CALLBACK_PTR0();
    }
    
    }

#endif

#if EXTI_ENABLE_INT1 == TRUE

void  ( *EXTI_CALLBACK_PTR1 ) (void) = NULL;

void EXTI_ENABLE_INT1_INTERRUPT(void)
{
   SET_BIT(EXTI_GICR , EXTI_GICR_INT1);
}

void EXTI_DISABLE_INT0_INTERRUPT(void)
{
    CLEAR_BIT(EXTI_GICR , EXTI_GICR_INT1);
}

void EXTI_vASSIGN_SENSE_CTRL_INT1(u8 sense_ctrl_state)
{
    switch (sense_ctrl_state)
    {
    case EXTI_LOW_LEVEL: 
        CLEAR_BIT(EXTI_MCUCR, EXTI_MCUCR_ISC10) ;
        CLEAR_BIT(EXTI_MCUCR, EXTI_MCUCR_ISC11) ;break;
    case EXTI_FALLING: 
        CLEAR_BIT(EXTI_MCUCR, EXTI_MCUCR_ISC10) ;
        SET_BIT(EXTI_MCUCR, EXTI_MCUCR_ISC11) ; break;
    case EXTI_RISING: 
        SET_BIT(EXTI_MCUCR, EXTI_MCUCR_ISC10) ;
        SET_BIT(EXTI_MCUCR, EXTI_MCUCR_ISC11) ; break;    
    default:  
        SET_BIT(EXTI_MCUCR, EXTI_MCUCR_ISC10) ;
        CLEAR_BIT(EXTI_MCUCR, EXTI_MCUCR_ISC11) ;break;
    }

}

u8 EXTI_u8GET_INT1_FLAG(void)
{
   return GET_BIT(EXTI_GIFR, EXTI_GIFR_INTF1);
}

void EXTI_vCLEAR_INT1_FLAG(void)
{
    SET_BIT(EXTI_GIFR, EXTI_GIFR_INTF1);
    /* The flag is cleared when the interrupt routine is executed.
Alternatively, the flag can be cleared by writing a logical one to it. This flag is always cleared
when INT0 is configured as a level interrupt.*/
}

void EXTI_CALLBACK1( void *( function ) (void) )
{
    EXTI_CALLBACK_PTR1 = function ;
}

void __vector_2(void)  
    {
    if (EXTI_CALLBACK_PTR1 != NULL)
    {
        EXTI_CALLBACK_PTR1();
    } 
    }

#endif

#if  EXTI_ENABLE_INT2 == TRUE

void  ( *EXTI_CALLBACK_PTR2 ) (void) = NULL;

void EXTI_ENABLE_INT2_INTERRUPT(void)
{
        SET_BIT(EXTI_GICR , EXTI_GICR_INT2);
}

void EXTI_DISABLE_INT2_INTERRUPT(void)
{
        CLEAR_BIT(EXTI_GICR , EXTI_GICR_INT2);
}

void EXTI_vASSIGN_SENSE_CTRL_INT0(u8 sense_ctrl_state)
{

    if( GET_BIT(EXTI_GICR, EXTI_GICR_INT2) == 1)
    {
        EXTI_DISABLE_INT2_INTERRUPT();
    }

    switch (sense_ctrl_state)
    {
    case EXTI_RISING: 
        SET_BIT(EXTI_MCUCSR, EXTI_MCUCSR_ISC2); break;
    default:  
        CLEAR_BIT(EXTI_MCUCSR, EXTI_MCUCSR_ISC2);break;
    }

    EXTI_ENABLE_INT2_INTERRUPT();

}

u8 EXTI_u8GET_INT2_FLAG(void)
{
     return GET_BIT(EXTI_GIFR, EXTI_GIFR_INTF2);
}

void EXTI_vCLEAR_INT2_FLAG(void)
{
     SET_BIT(EXTI_GIFR, EXTI_GIFR_INTF2);
}

void EXTI_CALLBACK2( void *( function ) (void) )
{
    EXTI_CALLBACK_PTR2 = function ;
}

void __vector_3(void)  
    {
        if (EXTI_CALLBACK_PTR2 != NULL)
            {
                EXTI_CALLBACK_PTR2();
             }
    }

#endif

/*END OF FILE*/