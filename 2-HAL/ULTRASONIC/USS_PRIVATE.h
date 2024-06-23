/******************************************************************************************
**************************AUTHOR: Mohamed Hesham Hassan**************************
**********************************DATE: 01.04.2024**************************************
****************************CONTACT: +201115581391**********************************
************************EMAIL: mohamedhassan5401@outlook.com*********************
************************DRIVER: Ultrasonic Sensor****************************************
***********************************VERSION: 0.0.1****************************************
*******************************FILE: USS_PRIVATE.H**************************************
*******************************************************************************************/

#ifndef USS_PRIVATE_H 

#define USS_PRIVATE_H

#define USS_SPEED_OF_SOUND_mm_PER_ms 343
#define USS_OCR_VALUE 20
#define USS_TIME_TICK_TIME_s TMR2_PRESCALE/F_CPU
#define USS_PERIOD_ms (USS_OCR_VALUE*USS_TIME_TICK_TIME_s*1000)
#define USS_MEASURE_DISTANCE_mm(TIME_ms)   (u32) ( (USS_SPEED_OF_SOUND_mm_PER_ms/2)*TIME_ms)
static u8 TRIGGER_PORT;
static u8 ECHO_PIN;
static u16 counter = 0;
static f32 time_ms = 0.0;

#endif