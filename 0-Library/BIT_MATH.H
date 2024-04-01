//*****************************************************************************************/
//**************************AUTHOR: Mohamed Hesham Hassan***********************//
//**********************************DATE: 11.02.2024**********************************//
//****************************CONTACT: +201115581391*****************************//
//************************EMAIL: mohamedhassan5401@outlook.com****************//
//************************DRIVER: BIT_MATH; bitwise math operatioins***************//
//***********************************VERSION: 0.0.1**********************************//
//*******************************FILE: BIT_MATH.H************************************//
//*************************************************************************************/

#ifndef BIT_MATH_H // Header guard . (if file is not defined then define it)
#define BIT_MATH_H
//this file contain function like macros for bitwise operations like setting and getting bit from a registar for instance
//register is a 8-bit group

//register operations
#define SET_REG(REG) REG |= 0xFF 
// set all register to HIGH

#define CLEAR_REG(REG) REG &= 0x00 // CLEAR all register to LOW

//bit operations
#define SET_BIT(REG,INDEX)          REG |= (1<<INDEX) // set current bit to HIGH
#define CLEAR_BIT(REG,INDEX)     REG &= ~(1<<INDEX)// CLEAR current bit to LOW
#define GET_BIT(REG,INDEX)         0x01 && (REG>>INDEX)// GET current bit 
#define TOGGLE_BIT(REG,INDEX)  REG ^= (1<<INDEX) // Toggle current bit
#define ASSIGN_BIT(REG , INDEX , LEV)  REG=( ( REG | (1<<INDEX)) *LEV )   + ( ( REG &= ~(1<<INDEX))*(!LEV) ) //ASSIGN current bit

//nipple is 4-bit group (half register) each register has low and high nipple (high nipple) XXXX XXXX (low nipple)
//nipple operations
#define ASSIGN_NIP(REG,LEV,N)   REG &= (0xF0 - LEV*0xE1)  + N<<(4*LEV)//(REG*LEV) + ( ( (-1* LEV) +~LEV ) * ((REG>>4)<<4) ) + (N)<<(4*LEV) //assign nipple to value

#endif