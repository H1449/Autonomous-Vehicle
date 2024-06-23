//*****************************************************************************************/
//**************************AUTHOR: Mohamed Hesham Hassan***********************//
//**********************************DATE: 23.02.2024**********************************//
//****************************CONTACT: +201115581391*****************************//
//************************EMAIL: mohamedhassan5401@outlook.com****************//
//************************DRIVER: EXTI; External Interrupt Perepheral****************//
//***********************************VERSION: 0.0.1**********************************//
//*******************************FILE: EXTI_PRIVATE.C*******************************//
//*************************************************************************************/

#ifndef EXTI_PRIVATE_H 
// Header guard . (if file is not defined then define it)
#define EXTI_PRIVATE_H

#define EXTI_MCUCR  ( ( * (volatile u8 *) 0X55 ) )// MCU Control Register 
/* The MCU Control Register contains control bits for interrupt sense control and general MCU
functions.
The External Interrupt 1 is activated by the external pin INT1 if the SREG I-bit and the corresponding
interrupt mask in the GICR are set. The level and edges on the external INT1 pin that
activate the interrupt are defined in Table 34. The value on the INT1 pin is sampled before
detecting edges. If edge or toggle interrupt is selected, pulses that last longer than one clock
period will generate an interrupt. Shorter pulses are not guaranteed to generate an interrupt. If
low level interrupt is selected, the low level must be held until the completion of the currently
executing instruction to generate an interrupt.*/

#define EXTI_MCUCR_ISC00 0
#define EXTI_MCUCR_ISC01 1
/*The External Interrupt 0 is activated by the external pin INT0 if the SREG I-flag and the corresponding
interrupt mask are set. The level and edges on the external INT0 pin that activate the
interrupt are defined in Table 35. The value on the INT0 pin is sampled before detecting edges.
If edge or toggle interrupt is selected, pulses that last longer than one clock period will generate
an interrupt. Shorter pulses are not guaranteed to generate an interrupt. If low level interrupt is
selected, the low level must be held until the completion of the currently executing instruction to
generate an interrupt.*/
/*ISC01 ISC00 Description
0 0 The low level of INT0 generates an interrupt request.
0 1 Any logical change on INT0 generates an interrupt request.
1 0 The falling edge of INT0 generates an interrupt request.
1 1 The rising edge of INT0 generates an interrupt request.*/

#define EXTI_MCUCR_ISC10 2
#define EXTI_MCUCR_ISC11 3 
/*The External Interrupt 1 is activated by the external pin INT1 if the SREG I-bit and the corresponding
interrupt mask in the GICR are set. The level and edges on the external INT1 pin that
activate the interrupt are defined in Table 34. The value on the INT1 pin is sampled before
detecting edges. If edge or toggle interrupt is selected, pulses that last longer than one clock
period will generate an interrupt. Shorter pulses are not guaranteed to generate an interrupt. If
low level interrupt is selected, the low level must be held until the completion of the currently
executing instruction to generate an interrupt.*/
/*ISC11 ISC10 Description
0 0 The low level of INT1 generates an interrupt request.
0 1 Any logical change on INT1 generates an interrupt request.
1 0 The falling edge of INT1 generates an interrupt request.
1 1 The rising edge of INT1 generates an interrupt request.*/

#define EXTI_MCUCSR  ( ( * (volatile u8 *) 0X54 ) ) //MCU Control and Status Register
/*The Asynchronous External Interrupt 2 is activated by the external pin INT2 if the SREG I-bit and
the corresponding interrupt mask in GICR are set. If ISC2 is written to zero, a falling edge on
INT2 activates the interrupt. If ISC2 is written to one, a rising edge on INT2 activates the interrupt.
Edges on INT2 are registered asynchronously. Pulses on INT2 wider than the minimum
pulse width given in Table 36 will generate an interrupt. Shorter pulses are not guaranteed to
generate an interrupt. When changing the ISC2 bit, an interrupt can occur. Therefore, it is recommended
to first disable INT2 by clearing its Interrupt Enable bit in the GICR Register. Then,
the ISC2 bit can be changed. Finally, the INT2 Interrupt Flag should be cleared by writing a logical
one to its Interrupt Flag bit (INTF2) in the GIFR Register before the interrupt is re-enabled.*/
#define EXTI_MCUCSR_ISC2 6

#define EXTI_GICR     ( ( * (volatile u8 *) 0X5B ) ) //General Interrupt Control Register
#define EXTI_GICR_INT0 6
/*When the INT0 bit is set (one) and the I-bit in the Status Register (SREG) is set (one), the external
pin interrupt is enabled. The Interrupt Sense Control0 bits 1/0 (ISC01 and ISC00) in the MCU
General Control Register (MCUCR) define whether the External Interrupt is activated on rising
and/or falling edge of the INT0 pin or level sensed. Activity on the pin will cause an interrupt
request even if INT0 is configured as an output. The corresponding interrupt of External Interrupt
Request 0 is executed from the INT0 interrupt vector.*/
#define EXTI_GICR_INT1 7
/*When the INT1 bit is set (one) and the I-bit in the Status Register (SREG) is set (one), the external
pin interrupt is enabled. The Interrupt Sense Control1 bits 1/0 (ISC11 and ISC10) in the MCU
General Control Register (MCUCR) define whether the External Interrupt is activated on rising
and/or falling edge of the INT1 pin or level sensed. Activity on the pin will cause an interrupt
request even if INT1 is configured as an output. The corresponding interrupt of External Interrupt
Request 1 is executed from the INT1 interrupt Vector.*/
#define EXTI_GICR_INT2 5
/*When the INT2 bit is set (one) and the I-bit in the Status Register (SREG) is set (one), the external
pin interrupt is enabled. The Interrupt Sense Control2 bit (ISC2) in the MCU Control and
Status Register (MCUCSR) defines whether the External Interrupt is activated on rising or falling
edge of the INT2 pin. Activity on the pin will cause an interrupt request even if INT2 is configured
as an output. The corresponding interrupt of External Interrupt Request 2 is executed from the
INT2 Interrupt Vector.*/
#define EXTI_GICR_IVCE  0 // Interrupt Vector Change Enable
/*The IVCE bit must be written to logic one to enable change of the IVSEL bit. IVCE is cleared by
hardware four cycles after it is written or when IVSEL is written. Setting the IVCE bit will disable
interrupts, as explained in the IVSEL*/
#define EXTI_GICR_IVSEL 1 // Interrupt Vector Select
/*When the IVSEL bit is cleared (zero), the Interrupt Vectors are placed at the start of the Flash
memory. When this bit is set (one), the interrupt vectors are moved to the beginning of the Boot
Loader section of the Flash. The actual address of the start of the Boot Flash section is determined
by the BOOTSZ fuses. Refer to the section “Boot Loader Support – Read-While-Write
Self-Programming” on page 244 for details. To avoid unintentional changes of Interrupt Vector
tables, a special write procedure must be followed to change the IVSEL bit:
1. Write the Interrupt Vector Change Enable (IVCE) bit to one.
2. Within four cycles, write the desired value to IVSEL while writing a zero to IVCE.
Interrupts will automatically be disabled while this sequence is executed. Interrupts are disabled
in the cycle IVCE is set, and they remain disabled until after the instruction following the write to
IVSEL. If IVSEL is not written, interrupts remain disabled for four cycles. The I-bit in the Status
Register is unaffected by the automatic disabling.*/

#define EXTI_GIFR     ( ( * (volatile u8 *) 0X5A ) ) //General Interrupt Flag Register
#define EXTI_GIFR_INTF0 6
/*When an edge or logic change on the INT0 pin triggers an interrupt request, INTF0 becomes set
(one). If the I-bit in SREG and the INT0 bit in GICR are set (one), the MCU will jump to the corresponding
interrupt vector. The flag is cleared when the interrupt routine is executed.
Alternatively, the flag can be cleared by writing a logical one to it. This flag is always cleared
when INT0 is configured as a level interrupt.*/
#define EXTI_GIFR_INTF1 7
/*When an edge or logic change on the INT1 pin triggers an interrupt request, INTF1 becomes set
(one). If the I-bit in SREG and the INT1 bit in GICR are set (one), the MCU will jump to the corresponding
Interrupt Vector. The flag is cleared when the interrupt routine is executed.
Alternatively, the flag can be cleared by writing a logical one to it. This flag is always cleared
when INT1 is configured as a level interrupt.*/
#define EXTI_GIFR_INTF2 5
/*When an event on the INT2 pin triggers an interrupt request, INTF2 becomes set (one). If the Ibit
in SREG and the INT2 bit in GICR are set (one), the MCU will jump to the corresponding
Interrupt Vector. The flag is cleared when the interrupt routine is executed. Alternatively, the flag
can be cleared by writing a logical one to it. Note that when entering some sleep modes with the
INT2 interrupt disabled, the input buffer on this pin will be disabled. This may cause a logic
change in internal signals which will set the INTF2 Flag. See “Digital Input Enable and Sleep
Modes” on page 53 for more information.*/

#define EXTI_LOW_LEVEL 0
#define EXTI_ANY             1
#define EXTI_FALLING      2
#define EXTI_RISING        3

#endif
/*END OF FILE*/