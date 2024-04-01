//*****************************************************************************************/
//**************************AUTHOR: Mohamed Hesham Hassan***********************//
//**********************************DATE: 11.02.2024**********************************//
//****************************CONTACT: +201115581391*****************************//
//************************EMAIL: mohamedhassan5401@outlook.com****************//
//************************DRIVER: AT_REG; atmega32 (specific) registers file**********//
//***********************************VERSION: 0.1.8**********************************//
//*******************************FILE: AT_REG.H***************************************//
//*************************************************************************************/

#ifndef AT_REG_H // Header guard . (if file is not defined then define it)
#define AT_REG_H

#define F_CPU 16000000UL //Clock Speed

/* This file contain addresses of registers that does not belong to any  perepheral (like status register SREG) */

#define SREG    ( ( * ( volatile u8 * ) 0x5F) )//define status register
/*The Status Register contains information about the result of the most recently executed arithmetic
instruction. This information can be used for altering program flow in order to perform
conditional operations. Note that the Status Register is updated after all ALU operations, as
specified in the Instruction Set Reference. This will in many cases remove the need for using the
dedicated compare instructions, resulting in faster and more compact code.
The Status Register is not automatically stored when entering an interrupt routine and restored
when returning from an interrupt. This must be handled by software.*/

#define SREG_I_GIE 7 //general interrupt enable
/*The Global Interrupt Enable bit must be set for the interrupts to be enabled. The individual interrupt
enable control is then performed in separate control registers. If the Global Interrupt Enable
Register is cleared, none of the interrupts are enabled independent of the individual interrupt
enable settings. The I-bit is cleared by hardware after an interrupt has occurred, and is set by
the RETI instruction to enable subsequent interrupts. The I-bit can also be set and cleared by
the application with the SEI and CLI instructions, as described in the instruction set reference.*/

#define SREG_T_BCS 6 //Bit copy storage
/*The Bit Copy instructions BLD (Bit LoaD) and BST (Bit STore) use the T-bit as source or destination
for the operated bit. A bit from a register in the Register File can be copied into T by the
BST instruction, and a bit in T can be copied into a bit in a register in the Register File by the
BLD instruction.*/

#define SREG_H_HCF 5
/*The Half Carry Flag H indicates a half carry in some arithmetic operations. Half Carry is useful in
BCD arithmetic. See the “Instruction Set Description” for detailed information.*/

#define SREG_S_SB 4 //Sign bit
/*The S-bit is always an exclusive or between the Negative Flag N and the Two’s Complement
Overflow Flag V. See the “Instruction Set Description” for detailed information.*/

#define SREG_V_2COF 3 // Two's Complement Overflow Flag
/*The Two’s Complement Overflow Flag V supports two’s complement arithmetics. See the
“Instruction Set Description” for detailed information.*/

#define SREG_N_NF 2 // Negative Flag
/*The Negative Flag N indicates a negative result in an arithmetic or logic operation. See the
“Instruction Set Description” for detailed information.*/

#define SREG_Z_ZF 1 // Zero Flag
/*The Zero Flag Z indicates a zero result in an arithmetic or logic operation. See the “Instruction
Set Description” for detailed information.*/

#define SREG_C_CF 0 // Carry Flag
/*The Carry Flag C indicates a carry in an arithmetic or logic operation. See the “Instruction Set
Description” for detailed information.*/

//define more macros for readability etc...

//Other Definitions
#define ERROR 0xFF
#define SUCCESS 0x01
#define NULL ((void*)0)

//define booleans 
#define TRUE 1
#define FALSE 0

#define True 1
#define False 0

#define True 1
#define False 0

//define bit states
#define HIGH 1
#define LOW 0

#define High 1
#define Low 0

#define high 1
#define low 0

//define bit directions
#define OUTPUT 1
#define INPUT 0

#define Output 1
#define Input 0

#define output 1
#define input 0

#define HIGH_NIPPLE 1
#define LOW_NIPPLE 0

#endif