

#ifndef SOURCE_01_MCAL_GIE_HEADER_GIE_H_
#define SOURCE_01_MCAL_GIE_HEADER_GIE_H_

#include "STD_TYPES.h"
#include "Bit_Math.h"


#define GIE_SREG	(*(volatile u8* )(0x5f))

// i-bit is the Global Interrupt Enable bit
// According to Atmega32 data sheet
#define GIE_l_bit	7





void GIE_EnableGlobalInterrupt();  //  asm("SEI")
void GIE_DisableGlobalInterrupt(); //  asm("CLI")


#endif /* SOURCE_01_MCAL_GIE_HEADER_GIE_H_ */
