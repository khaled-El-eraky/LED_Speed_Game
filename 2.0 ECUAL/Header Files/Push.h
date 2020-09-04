/*
 * Push.h
 *
 * Created: 11/28/2019 6:34:30 PM
 *  Author: Hamdy
 */ 


#ifndef PUSH_H_
#define PUSH_H_

#include "Microcontroller_config.h"
#include "ExternalInterrupts_ATmega32A.h"
#include "DIO.h"
#include <util/delay.h>

typedef enum
{
	SW_NOTPRESSED,
	SW_PRESSEDHIGH,
	SW_PRESSEDLOW
}ButtonSw_state;

typedef struct 
{
   DIO_Struct *	 Button_Dio;
   pinNumber Button_Pin;
   pinMode	 InputMode;
   digitalState PrevButton_State;
}ButtonSw_datatype;


void ButtonSw_Setup(ButtonSw_datatype * Button);
ButtonSw_state ButtonSw_Read(ButtonSw_datatype * Button);
void ButtonSw_Interrupt(ExtInt_Number INTNumber,ExtInt_Mode INTMode);

#endif /* PUSH_H_ */
