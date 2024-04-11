//*****************************************************************************************/
//**************************AUTHOR: Mohamed Hesham Hassan***********************//
//**********************************DATE: 11.04.2024**********************************//
//****************************CONTACT: +201115581391*****************************//
//************************EMAIL: mohamedhassan5401@outlook.com****************//
//************************DRIVER: Ultrasonic Sensor**********************************//
//***********************************VERSION: 0.0.1**********************************//
//*******************************FILE: Autonomous Vehicle Header File**************//
//************************************************************************************/

#ifndef AV_H 
// Header guard . (if file is not defined then define it)
#define AV_H

#define AV_MIN_DISTANCE_TO_OBSTICLE_CM 40


/*LIBRARIES*/
#include <util/delay.h>
#include "BIT_MATH.H" //include essential header files (BIT_MATH and STD_TYPES)
#include "STD_TYPES.H"
#include "AT_REG.H"  

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

void AV_vInit();

void AV_vInit()
{
    LCD_vInit();
    USS_vInit();
    SRVO_vInit();
    DCMTR_vInit();
}


#endif