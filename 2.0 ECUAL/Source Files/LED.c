/*
 * Led.c
 *
 * Created: 11/21/2019 7:14:51 PM
 *  Author: Hamdy
 */ 

	#include "LED.h"
	
	#define portOutput  (0xFF)
	#define portHigh    (0xFF)
	#define portLow    (0x00)
	
	
	void LEDSetup(ledDatatype led)
	{
		DIO_pinConfigure(led.LED_Dio,led.LED_pin,OUTPUT);
	}
	
	void LEDControl(ledDatatype led, LEDstate state)
	{
		switch(state)
		{
			// LED_OFF is the same as LED_ON_REVERSED
			case LED_OFF:
			DIO_pinWrite(led.LED_Dio,led.LED_pin,LOW);
			break;
			case LED_ON:
			DIO_pinWrite(led.LED_Dio,led.LED_pin,HIGH);
			break;
			case LED_TOGGLE:
			DIO_pinWrite(led.LED_Dio,led.LED_pin,!DIO_pinRead(led.LED_Dio,led.LED_pin));
			break;
			default:
			break;
		}	
	}


void Eight_LEDSetup(ledDatatype led)
{
	DIO_portConfigure(led.LED_Dio,portOutput);
}
void Eight_LEDControl(ledDatatype led, portState state)
{
	switch(state)
	{
		// LED_OFF is the same as LED_ON_REVERSED
		case LEDPort_OFF:
		DIO_portWrite(led.LED_Dio,portLow);
		break;
		case LEDPort_ON:
		DIO_portWrite(led.LED_Dio,portHigh);
		break;
		case LEDPort_TOGGLE:
		DIO_portWrite(led.LED_Dio,!DIO_portRead(led.LED_Dio));
		break;
		default:
		break;
	}
}