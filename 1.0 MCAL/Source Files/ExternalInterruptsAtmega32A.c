/*
 * ExternalInterruptsAtmega32A.c
 *
 * Created: 12/5/2019 8:53:16 PM
 *  Author: Hamdy
 */ 

#include "ExternalInterrupts_ATmega32A.h"
#include "Microcontroller_config.h"

#define NULL_Ptr    ((void*)0x00)


/*****************************************  Defines FOR External Interrupt Handling ************************************************/

#define INT0VECTOR	_VECTOR(1)             /*the address of int0 in vector table in flash and accessed by an attribute _vector */
#define INT1VECTOR	_VECTOR(2)
#define INT2VECTOR	_VECTOR(3)

/*pointer to function points to NULL_Ptr till the app layer make it point to another function  */
void (*volatile EXTINT0_FunctionPtr)(void)=NULL_Ptr;    
void (*volatile EXTINT1_FunctionPtr)(void)=NULL_Ptr;
void (*volatile EXTINT2_FunctionPtr)(void)=NULL_Ptr;

/***************************************** AVR External Interrupt ISRs ************************************************/

ISR(INT0VECTOR)
{
	/*This check as if the interrupt happened and the function isn't handled the code will stuck as it point to NULL_Ptr*/
	if (EXTINT0_FunctionPtr != NULL_Ptr)
	{
		EXTINT0_FunctionPtr();
	}
}

ISR(INT1VECTOR)
{
		if (EXTINT1_FunctionPtr != NULL_Ptr)
		{
			EXTINT1_FunctionPtr();
		}	
}

ISR(INT2VECTOR)
{
	if (EXTINT2_FunctionPtr != NULL_Ptr)
	{
		EXTINT2_FunctionPtr();
	}	
}

/***************************************** External Interrupt Functions ************************************************/


	void ExternalInterrupt_Configure(ExtInt_Number IntNumber,ExtInt_Mode Mode)
	{
		switch(IntNumber)
		{
			case EXTINT0:
			/* Disable Int0 >> as the worest case senario when the int is falling and I need it logical change 
			so while conversion the low mode will be active*/      
			ATMEGA32_GICR->bits.b6=LOW;
									
			/* Configure Int0 */
			switch (Mode)
			{
				case EXTINT_LOWLVL:
				ATMEGA32A_MCUCR->bits.b0=LOW;					/* for data sheet ICS0 table */
				ATMEGA32A_MCUCR->bits.b1=LOW;
				break;
				case EXTINT_BOTHEDGE:
				ATMEGA32A_MCUCR->bits.b0=HIGH;
				ATMEGA32A_MCUCR->bits.b1=LOW;
				break;
				case EXTINT_FALLING:
				ATMEGA32A_MCUCR->bits.b0=LOW;
				ATMEGA32A_MCUCR->bits.b1=HIGH;
				break;
				case EXTINT_RISING:
				ATMEGA32A_MCUCR->bits.b0=HIGH;
				ATMEGA32A_MCUCR->bits.b1=HIGH;
				break;
				default:
				break;
			}
			// Enable int0
			ATMEGA32_GICR->bits.b6=HIGH;
			break;
			
			case EXTINT1:
			ATMEGA32_GICR->bits.b7=LOW;
			switch (Mode)
			{
				case EXTINT_LOWLVL:
				ATMEGA32A_MCUCR->bits.b2=LOW;
				ATMEGA32A_MCUCR->bits.b3=LOW;
				break;
				case EXTINT_BOTHEDGE:
				ATMEGA32A_MCUCR->bits.b2=HIGH;
				ATMEGA32A_MCUCR->bits.b3=LOW;
				break;
				case EXTINT_FALLING:
				ATMEGA32A_MCUCR->bits.b2=LOW;
				ATMEGA32A_MCUCR->bits.b3=HIGH;
				break;
				case EXTINT_RISING:
				ATMEGA32A_MCUCR->bits.b2=HIGH;
				ATMEGA32A_MCUCR->bits.b3=HIGH;
				break;
				default:
				break;
			}
			ATMEGA32_GICR->bits.b7=HIGH;
			break;
			
			case EXTINT2:
			ATMEGA32_GICR->bits.b5=LOW;
			switch (Mode)
			{
				case EXTINT_FALLING:
				ATMEGA32_MCUCSR->bits.b6=LOW;
				break;
				case EXTINT_RISING:
				ATMEGA32_MCUCSR->bits.b6=HIGH;
				break;
				case EXTINT_LOWLVL:
				case EXTINT_BOTHEDGE:
				default:	  
				break;
			}
			ATMEGA32_GICR->bits.b5=HIGH;
			break;
		}
	}
	
	void ExternalInterrupt_Disable(ExtInt_Number IntNumber)
	{
			switch(IntNumber)
			{
				case EXTINT0:
				ATMEGA32_GICR->bits.b6=LOW;
				break;
				case EXTINT1:
				ATMEGA32_GICR->bits.b7=LOW;
				break;
				case EXTINT2:
				ATMEGA32_GICR->bits.b5=LOW;
				break;
			}	
	}
	
	
