/*
 * LED.h
 *
 * Created: 4/2/2020 7:14:42 PM
 *  Author: Khaled Osama Eraky
 */ 


#ifndef LED_H_
#define LED_H_

	#include "DIO.h"
	
	typedef enum
	{
		LED_OFF,
		LED_ON,	
		LED_TOGGLE,
	}LEDstate;
	
	typedef enum
	{
		LEDPort_OFF,
		LEDPort_ON,	
		LEDPort_TOGGLE,
	}portState;
	
	typedef struct
	{
		DIO_Struct * LED_Dio;
		pinNumber LED_pin;	
	}ledDatatype;
	
	void LEDSetup(ledDatatype led);
	void LEDControl(ledDatatype led, LEDstate state);
	void Eight_LEDSetup(ledDatatype led);
	void Eight_LEDControl(ledDatatype led, portState state);
#endif /* LED_H_ */
