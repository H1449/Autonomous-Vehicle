//*****************************************************************************************/
//**************************AUTHOR: Mohamed Hesham Hassan***********************//
//**********************************DATE: 01.04.2024**********************************//
//****************************CONTACT: +201115581391*****************************//
//************************EMAIL: mohamedhassan5401@outlook.com****************//
//************************DRIVER: DC Motor Driver ******** *************************//
//***********************************VERSION: 0.0.1**********************************//
//*******************************FILE: DCMTR_INTERFACE_H.H***************** **************//
//************************************************************************************/

#ifndef DCMTR_INTERFACE_H 
// Header guard . (if file is not defined then define it)
#define DCMTR_INTERFACE_H

void DCMTR_vInit();

void DCMTR_MOVE_FORWARD();

void DCMTR_STOP();

void DCMTR_MOVE_BACKWARD();

void DCMTR_TURN_RIGHT();

void DCMTR_TURN_LEFT();

void DCMTR_ROTATE_RIGHT();

void DCMTR_ROTATE_LEFT();

void DCMTR_STEP_FORWARD();

void DCMTR_STEP_BACKWARDS();

void DCMTR_TURN_180(u8 Direction);



#endif