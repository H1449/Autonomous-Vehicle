//*****************************************************************************************/
//**************************AUTHOR: Mohamed Hesham Hassan***********************//
//**********************************DATE: 01.04.2024**********************************//
//****************************CONTACT: +201115581391*****************************//
//************************EMAIL: mohamedhassan5401@outlook.com****************//
//************************DRIVER: Ultrasonic Sensor**********************************//
//***********************************VERSION: 0.0.1**********************************//
//*******************************FILE: USS_PROGRAM.C******************************//
//************************************************************************************/
//include essential header files (BIT_MATH and STD_TYPES)
#include "BIT_MATH.H"
#include "STD_TYPES.H"
#include "AT_REG.H"  //this file is written by me to include all essential uncategorized addresses

//include header files of the driver
#include "TMR_CONFIG.H"
#include "TMR_PRIVATE.H"
#include "TMR_INTERFACE.H"

#include "USS_CONFIG.H"
#include "USS_PRIVATE.H"
#include "USS_INTERFACE.H"

void USS_vInit()
{
    TMR_TMR1_vInit(TMR_MODE_NORMAL , TMR_PRESCALE_1);

    SET_BIT(USS_TRIG_DDR , USS_TRIG_PIN);

    CLEAR_BIT(USS_ECHO_DDR , USS_ECHO_PIN);
    

} 

u8 USS_u8GET_DISTANCE()
{
    u16 time = 0;
    u8 distance = 0;

    TMR_TMR1_CLEAR_TMR_COUNTER();
    TMR_TMR1_INPUT_CAPTURE_EDGE_SELECT(TMR_RISING_EDGE);
    TMR_TMR1_CLEAR_INPUT_CAPTURE_FLAG();
    TMR_TMR1_CLEAR_TMR_OVF_FLAG();

    CLEAR_BIT(USS_TRIG_PORT , USS_TRIG_PIN);
    _delay_us(2);
    SET_BIT(USS_TRIG_PORT , USS_TRIG_PIN);
    _delay_us(10);
    CLEAR_BIT(USS_TRIG_PORT , USS_TRIG_PIN);

    while (! TMR_TMR1_IS_INPUT_CAPTURED()); //wait for rising edge
    time = TMR_ICR1;
    TMR_TMR1_INPUT_CAPTURE_EDGE_SELECT(TMR_FALLING_EDGE);
    TMR_TMR1_CLEAR_INPUT_CAPTURE_FLAG();

    while (! TMR_TMR1_IS_INPUT_CAPTURED()); //wait for Falling edge
    time = TMR_ICR1 - time ;// total no of tiks counted
    time = time * 0.0000000625; //time in seconds
    distance = 100*(343 * time/2); //distance in cm
    return distance;
}



