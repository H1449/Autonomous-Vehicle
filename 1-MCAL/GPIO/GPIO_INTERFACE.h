//*****************************************************************************************/
//**************************AUTHOR: Mohamed Hesham Hassan***********************//
//**********************************DATE: 11.02.2024**********************************//
//****************************CONTACT: +201115581391*****************************//
//************************EMAIL: mohamedhassan5401@outlook.com****************//
//************************DRIVER: GPIO; General purpose input output***************//
//***********************************VERSION: 0.0.1**********************************//
//*******************************FILE: GPIO_INTERFACE.H****************************//
//*************************************************************************************/

#ifndef GPIO_INTERFACE_H
 // Header guard . (if file is not defined then define it)
#define GPIO_INTERFACE_H

void GPIO_vSET_PORT_DIRECTION(u8 PORT,u8 DIR); // finction to set port direction
void GPIO_vSET_PIN_DIRECTION(u8 PORT,u8 PIN,u8 DIR); // finction to set pin direction in a port
void GPIO_vASSIGN_PORT(u8 PORT,u8 LEV);  // function to assign level to entire hardware port (HIGH or LOW)
void GPIO_vASSIGN_PIN(u8 PORT,u8 PIN,u8 LEV);  // function to assign level to  hardware pin in a port (HIGH or LOW)
void GPIO_TOGGLE_PIN(u8 PORT,u8 PIN); //function to toggle bit in a port
u8 GPIO_u8GET_PIN(u8 PORT,u8 PIN); // function to read current hardware pin in a port return True or False

#endif //end of file