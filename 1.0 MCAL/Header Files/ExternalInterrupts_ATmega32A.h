/*
 * ExternalInterrupts.h
 *
 * Created: 12/5/2019 8:52:46 PM
 *  Author: Hamdy
 */ 


#ifndef EXTERNALINTERRUPTS_H_
#define EXTERNALINTERRUPTS_H_

	
	#include "Microcontroller_config.h"
	#include "StdTypes.h"
	
/********************************** User Defined Types for External Interrupt Handling *************************************/
	typedef enum
	{
		EXTINT0,
		EXTINT1,
		EXTINT2,
	}ExtInt_Number;

	typedef enum
	{
		EXTINT_LOWLVL,
		EXTINT_RISING,
		EXTINT_FALLING,
		/* any logical change */
		EXTINT_BOTHEDGE,                               
	}ExtInt_Mode;

/********************************** Call Back Pointers for External Interrupt Handling *************************************/
	extern void (*volatile EXTINT0_FunctionPtr)(void);     
	extern void (*volatile EXTINT1_FunctionPtr)(void);
	extern void (*volatile EXTINT2_FunctionPtr)(void);
	
/********************************** Functions prototype for External Interrupt Handling *************************************/

	extern void ExternalInterrupt_Configure(ExtInt_Number IntNumber,ExtInt_Mode Mode);

	extern void ExternalInterrupt_Disable(ExtInt_Number IntNumber);
	
#endif /* EXTERNALINTERRUPTS_H_ */
