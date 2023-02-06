

#include "GIE.h"

void GIE_EnableGlobalInterrupt()
{

	SET_BIT(GIE_SREG, GIE_l_bit);  //  asm("SEI")

}

void GIE_DisableGlobalInterrupt()  // DIE
{

	CLR_BIT(GIE_SREG, GIE_l_bit); //  asm("CLI")

}

