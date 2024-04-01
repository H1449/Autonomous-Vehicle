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
#include "BIT_MATH.H"
#include "STD_TYPES.H"
#include "AT_REG.H"  //this file is written by me to include all essential uncategorized addresses

//include header files of the driver
#include "EXTI_CONFIG.H"
#include "EXTI_PRIVATE.H"
#include "EXTI_INTERFACE.H"

void  ( *EXTI_CALLBACK_PTR ) (void) = NULL;

void EXTI_vInit()  // set all pins of all ports OUTPUT and HIGH
{

    #if  TRUE == EXTI_INT0_EN

#if  EXTI_INT0_SENSE_CONTROL == EXTI_LOW_LEVEL 

    CLEAR_BIT(EXTI_MCUCR, EXTI_MCUCR_ISC10) ;
    CLEAR_BIT(EXTI_MCUCR, EXTI_MCUCR_ISC11) ;

#elif  EXTI_INT0_SENSE_CONTROL == EXTI_ANY

    SET_BIT(EXTI_MCUCR, EXTI_MCUCR_ISC10) ;
CLEAR_BIT(EXTI_MCUCR, EXTI_MCUCR_ISC11) ;
    
#elif  EXTI_INT0_SENSE_CONTROL == EXTI_FALLING

    CLEAR_BIT(EXTI_MCUCR, EXTI_MCUCR_ISC10) ;
    SET_BIT(EXTI_MCUCR, EXTI_MCUCR_ISC11) ;

#elif  EXTI_INT0_SENSE_CONTROL == EXTI_RISING

    SET_BIT(EXTI_MCUCR, EXTI_MCUCR_ISC10) ;
    SET_BIT(EXTI_MCUCR, EXTI_MCUCR_ISC11) ;
    
#endif
#endif

#if  TRUE == EXTI_INT1_EN

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

    #if  TRUE == EXTI_INT2_EN



    #if EXTI_INT2_SENSE_CONTROL == EXTI_RISING

        SET_BIT(EXTI_MCUCSR, EXTI_MCUCSR_ISC2) ;
    
    #else

        CLEAR_BIT(EXTI_MCUCSR, EXTI_MCUCSR_ISC2) ;

    #endif
    #endif


}

void EXTI_EN()
{
     SET_BIT( SREG , SREG_I_GIE ) ; //enable global interrupt BIT in the SREG
    //(First Key)
}

void EXTI_DIS()
{
     CLEAR_BIT( SREG , SREG_I_GIE ) ; //enable global interrupt BIT in the SREG
    //(First Key)
}

void EXTI_INT0_EN()
{
    SET_BIT(EXTI_GICR , EXTI_GIFR_INTF0);// set INT0 GIFR (Second Key)
}

void EXTI_INT0_DIS()
{
    CLEAR_BIT(EXTI_GICR , EXTI_GIFR_INTF0);// Clear INT0 GIFR (Second Key)
}

void EXTI_INT1_EN()
{
   SET_BIT(EXTI_GICR , EXTI_GIFR_INTF1);
}

void EXTI_INT1_DIS()
{
    CLEAR_BIT(EXTI_GICR , EXTI_GIFR_INTF1);
}

void EXTI_INT2_EN()
{
        SET_BIT(EXTI_GICR , EXTI_GICR_INT2);
}

void EXTI_INT2_DIS()
{
        CLEAR_BIT(EXTI_GICR , EXTI_GICR_INT2);
}


void EXTI_CALLBACK( void *( function ) (void) )
{
	EXTI_CALLBACK_PTR = function ;
}

void __vector_1(void)  
         if (EXTI_CALLBACK_PTR != NULL)
    {
        EXTI_CALLBACK_PTR();
    }
    
    }
   
    void __vector_2(void)  
    {
        if (EXTI_CALLBACK_PTR != NULL)
    {
        EXTI_CALLBACK_PTR();
    } 
    }
   
    
        void __vector_3(void)  
    {
        if (EXTI_CALLBACK_PTR != NULL)
            {
                EXTI_CALLBACK_PTR();
             }
    }

    


