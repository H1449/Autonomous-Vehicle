/*
 * main.c
 *
 * Created: 4/11/2024 1:30:18 AM
 *  Author: Mohamed
 */ 

/*LIBRARIES*/
#define F_CPU 16000000UL
#include <util/delay.h>
#include "AT_REG.H"
#include "main.h"

#include "BIT_MATH.H" //include essential header files (BIT_MATH and STD_TYPES)
#include "STD_TYPES.H"


/*MACAL*/
/*GPIO Driver*/
#include "GPIO_CONFIG.H"
#include "GPIO_PRIVATE.H"
#include "GPIO_INTERFACE.H"
/*TMR Driver*/
#include "TMR_CONFIG.H"
#include "TMR_PRIVATE.H"
#include "TMR_INTERFACE.H"
/*GPIO Driver*/
#include "GPIO_CONFIG.H"
#include "GPIO_PRIVATE.H"
#include "GPIO_INTERFACE.H"

/*HAL*/
/*LCD Driver*/
#include "LCD_CONFIG.H"
#include "LCD_PRIVATE.H"
#include "LCD_INTERFACE.H"
/*SRVO Driver*/
#include "SRVO_CONFIG.H"
#include "SRVO_PRIVATE.H"
#include "SRVO_INTERFACE.H"
/*USS Driver*/
#include "USS_CONFIG.H"
#include "USS_PRIVATE.H"
#include "USS_INTERFACE.H"
/*DCMTR Driver*/
#include "DCMTR_CONFIG.H"
#include "DCMTR_PRIVATE.H"
#include "DCMTR_INTERFACE.H"

int main(void)
{
	u8 str[] = "TL3 3ENY!!!";
	LCD_vInit();
	
	LCD_vSend_String(str);
	//AV_vInit(); 
	//TMR_TMR1_vInit(TMR_MODE_NORMAL , TMR_PRESCALE_1);
	//u8 DISTANCES[3] = {} ;



    while(1)
	{
		
    //{
		
	/*	while(USS_u8GET_DISTANCE() > AV_MIN_DISTANCE_TO_OBSTICLE_CM)
		{
			DCMTR_MOVE_FORWARD();
		}
		DCMTR_STOP();
		SRVO_vSend_PWM_IO_ANGLE_N90();
		DISTANCES[0] = USS_u8GET_DISTANCE();
		_delay_ms(100);
		SRVO_vSend_PWM_IO_ANGLE0();
		DISTANCES[1] = USS_u8GET_DISTANCE();
		_delay_ms(100);
		SRVO_vSend_PWM_IO_ANGLE90();
		DISTANCES[2] = USS_u8GET_DISTANCE();
		if (DISTANCES[0] > DISTANCES[1] )
		{
			if (DISTANCES[0] > DISTANCES[2] )
			{	
				DCMTR_ROTATE_LEFT();
				continue;
			}
			else
			if ( DISTANCES[2] > DISTANCES[0] )
			{
				DCMTR_ROTATE_RIGHT();
				continue;
			}
			else
			{
				DCMTR_ROTATE_RIGHT();
				DCMTR_ROTATE_RIGHT();
				continue;
			}
			
		}
	
		
    }*/
}
	}
/*
void AV_vInit()
{
	LCD_vInit();
	USS_vInit();
	SRVO_vInit();
	DCMTR_vInit();
}*/
