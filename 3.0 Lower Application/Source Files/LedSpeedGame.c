/*
 * LedSpeedGame.c
 *
 * Created: 2/5/2020 12:27:21 AM
 *  Author: Khaled
 */ 


	#include "ExternalInterrupts_ATmega32A.h"
	#include "DIO.h"
	#include "LED.h"
	#include "Push.h"
	#include <util/delay.h>
	
	#define WinnerTimeBlinking_ms (200)
	
	ledDatatype Player1Led1 = {DIOC,PIN0};
	ledDatatype Player1Led2 = {DIOC,PIN1};
	ledDatatype Player1Led3 = {DIOC,PIN2};
	ledDatatype Player1Led4 = {DIOC,PIN3};
	ledDatatype Player1Led5 = {DIOC,PIN4};
	ledDatatype Player1Led6 = {DIOC,PIN5};
	ledDatatype Player1Led7 = {DIOC,PIN6};
	ledDatatype Player1Led8 = {DIOC,PIN7};

	ledDatatype Player2Led1 = {DIOA,PIN0};
	ledDatatype Player2Led2 = {DIOA,PIN1};
	ledDatatype Player2Led3 = {DIOA,PIN2};
	ledDatatype Player2Led4 = {DIOA,PIN3};
	ledDatatype Player2Led5 = {DIOA,PIN4};
	ledDatatype Player2Led6 = {DIOA,PIN5};
	ledDatatype Player2Led7 = {DIOA,PIN6};
	ledDatatype Player2Led8 = {DIOA,PIN7};

	void ISR_Player1Leds(void);
	void ISR_Player2Leds(void);
	void ISR_ResetGame(void);
	
	vuint8_t counter1=0;
	vuint8_t counter2=0;
	
	ButtonSw_datatype ResetButton   = {DIOB,PIN2,INPUT_PULLUP,LOW};
	ButtonSw_datatype Player1Button = {DIOD,PIN2,INPUT_PULLUP,LOW};
	ButtonSw_datatype Player2Button = {DIOD,PIN3,INPUT_PULLUP,LOW};	
	
	void ResetGame(void)
	{
		ButtonSw_Setup(&ResetButton);
		ButtonSw_Interrupt(EXTINT2,EXTINT_RISING);
		EXTINT2_FunctionPtr = ISR_ResetGame;
	}
	
	void Player1_initiate (void)
	{
		LEDSetup(Player1Led1);
		LEDSetup(Player1Led2);
		LEDSetup(Player1Led3);
		LEDSetup(Player1Led4);
		LEDSetup(Player1Led5);
		LEDSetup(Player1Led6);
		LEDSetup(Player1Led7);
		LEDSetup(Player1Led8); 
		
		ButtonSw_Setup(&Player1Button);
		ButtonSw_Interrupt(EXTINT0,EXTINT_RISING);
		EXTINT0_FunctionPtr = ISR_Player1Leds;
	}


	void Player2_initiate (void)
	{
		LEDSetup(Player2Led1);
		LEDSetup(Player2Led2);
		LEDSetup(Player2Led3);
		LEDSetup(Player2Led4);
		LEDSetup(Player2Led5);
		LEDSetup(Player2Led6);
		LEDSetup(Player2Led7);
		LEDSetup(Player2Led8);
		
		ButtonSw_Setup(&Player2Button);
		ButtonSw_Interrupt(EXTINT1,EXTINT_RISING);
		EXTINT1_FunctionPtr = ISR_Player2Leds;
	}
	
	void ISR_ResetGame(void)
	{
		counter1=0;
		counter2=0;
		ATMEGA32_GICR->bits.b6=1;
		ATMEGA32_GICR->bits.b7=1;
	}
	
	void ISR_Player1Leds(void)
	{
		
		switch(counter1)
		{
			case 0:
			counter1++;
			counter2--;
			break;
			case 1:
			counter1++;
			counter2--;
			break;
			case 2:
			counter1++;
			counter2--;
			break;
			case 3:
			counter1++;
			counter2--;
			break;
			case 4:
			counter1++;
			counter2--;
			break;
			case 5:
			counter1++;
			counter2--;
			break;
			case 6:
			counter1++;
			counter2--;
			break;
			case 7:
			counter1++;
			counter2--;
			break;
			default:
			counter1++;
			break;
		}
	}
	
	
	void ISR_Player2Leds(void)
	{
		
		switch(counter2)
		{
			case 0:
			counter2++;
			counter1--;
			break;
			case 1:
			counter2++;
			counter1--;
			break;
			case 2:
			counter2++;
			counter1--;
			break;
			case 3:
			counter2++;
			counter1--;
			break;
			case 4:
			counter2++;
			counter1--;
			break;
			case 5:
			counter2++;
			counter1--;
			break;
			case 6:
			counter2++;
			counter1--;
			break;
			case 7:
			counter2++;
			counter1--;
			break;
			default:
			counter2++;
			break;
		}	
	}
	
	void Led_Update(void)
	{
		switch(counter1)
		{
			case 0:
			LEDControl(Player1Led1,LED_OFF);
			LEDControl(Player1Led2,LED_OFF);
			LEDControl(Player1Led3,LED_OFF);
			LEDControl(Player1Led4,LED_OFF);
			LEDControl(Player1Led5,LED_OFF);
			LEDControl(Player1Led6,LED_OFF);
			LEDControl(Player1Led7,LED_OFF);
			LEDControl(Player1Led8,LED_OFF);
			break;
			case 1:
			LEDControl(Player1Led1,LED_ON);
			LEDControl(Player1Led2,LED_OFF);
			LEDControl(Player1Led3,LED_OFF);
			LEDControl(Player1Led4,LED_OFF);
			LEDControl(Player1Led5,LED_OFF);
			LEDControl(Player1Led6,LED_OFF);
			LEDControl(Player1Led7,LED_OFF);
			LEDControl(Player1Led8,LED_OFF);
			break;
			case 2:
			LEDControl(Player1Led1,LED_ON);
			LEDControl(Player1Led2,LED_ON);
			LEDControl(Player1Led3,LED_OFF);
			LEDControl(Player1Led4,LED_OFF);
			LEDControl(Player1Led5,LED_OFF);
			LEDControl(Player1Led6,LED_OFF);
			LEDControl(Player1Led7,LED_OFF);
			LEDControl(Player1Led8,LED_OFF);
			break;
			case 3:
			LEDControl(Player1Led1,LED_ON);
			LEDControl(Player1Led2,LED_ON);
			LEDControl(Player1Led3,LED_ON);
			LEDControl(Player1Led4,LED_OFF);
			LEDControl(Player1Led5,LED_OFF);
			LEDControl(Player1Led6,LED_OFF);
			LEDControl(Player1Led7,LED_OFF);
			LEDControl(Player1Led8,LED_OFF);
			break;
			case 4:
			LEDControl(Player1Led1,LED_ON);
			LEDControl(Player1Led2,LED_ON);
			LEDControl(Player1Led3,LED_ON);
			LEDControl(Player1Led4,LED_ON);
			LEDControl(Player1Led5,LED_OFF);
			LEDControl(Player1Led6,LED_OFF);
			LEDControl(Player1Led7,LED_OFF);
			LEDControl(Player1Led8,LED_OFF);
			break;
			case 5:
			LEDControl(Player1Led1,LED_ON);
			LEDControl(Player1Led2,LED_ON);
			LEDControl(Player1Led3,LED_ON);
			LEDControl(Player1Led4,LED_ON);
			LEDControl(Player1Led5,LED_ON);
			LEDControl(Player1Led6,LED_OFF);
			LEDControl(Player1Led7,LED_OFF);
			LEDControl(Player1Led8,LED_OFF);
			break;
			case 6:
			LEDControl(Player1Led1,LED_ON);
			LEDControl(Player1Led2,LED_ON);
			LEDControl(Player1Led3,LED_ON);
			LEDControl(Player1Led4,LED_ON);
			LEDControl(Player1Led5,LED_ON);
			LEDControl(Player1Led6,LED_ON);
			LEDControl(Player1Led7,LED_OFF);
			LEDControl(Player1Led8,LED_OFF);
			break;
			case 7:
			LEDControl(Player1Led1,LED_ON);
			LEDControl(Player1Led2,LED_ON);
			LEDControl(Player1Led3,LED_ON);
			LEDControl(Player1Led4,LED_ON);
			LEDControl(Player1Led5,LED_ON);
			LEDControl(Player1Led6,LED_ON);
			LEDControl(Player1Led7,LED_ON);
			LEDControl(Player1Led8,LED_OFF);
			break;
			case 8:
			ATMEGA32_GICR->bits.b6=0;
			ATMEGA32_GICR->bits.b7=0;
			LEDControl(Player1Led1,LED_ON);
			LEDControl(Player1Led2,LED_ON);
			LEDControl(Player1Led3,LED_ON);
			LEDControl(Player1Led4,LED_ON);
			LEDControl(Player1Led5,LED_ON);
			LEDControl(Player1Led6,LED_ON);
			LEDControl(Player1Led7,LED_ON);
			LEDControl(Player1Led8,LED_ON);
			_delay_ms(WinnerTimeBlinking_ms);
			LEDControl(Player1Led1,LED_OFF);
			LEDControl(Player1Led2,LED_OFF);
			LEDControl(Player1Led3,LED_OFF);
			LEDControl(Player1Led4,LED_OFF);
			LEDControl(Player1Led5,LED_OFF);
			LEDControl(Player1Led6,LED_OFF);
			LEDControl(Player1Led7,LED_OFF);
			LEDControl(Player1Led8,LED_OFF);
			_delay_ms(WinnerTimeBlinking_ms);
			break;
			default:
			break;
		}
		
		switch(counter2)
		{
			case 0:
			LEDControl(Player2Led1,LED_OFF);
			LEDControl(Player2Led2,LED_OFF);
			LEDControl(Player2Led3,LED_OFF);
			LEDControl(Player2Led4,LED_OFF);
			LEDControl(Player2Led5,LED_OFF);
			LEDControl(Player2Led6,LED_OFF);
			LEDControl(Player2Led7,LED_OFF);
			LEDControl(Player2Led8,LED_OFF);
			break;
			case 1:
			LEDControl(Player2Led1,LED_ON);
			LEDControl(Player2Led2,LED_OFF);
			LEDControl(Player2Led3,LED_OFF);
			LEDControl(Player2Led4,LED_OFF);
			LEDControl(Player2Led5,LED_OFF);
			LEDControl(Player2Led6,LED_OFF);
			LEDControl(Player2Led7,LED_OFF);
			LEDControl(Player2Led8,LED_OFF);
			break;
			case 2:
			LEDControl(Player2Led1,LED_ON);
			LEDControl(Player2Led2,LED_ON);
			LEDControl(Player2Led3,LED_OFF);
			LEDControl(Player2Led4,LED_OFF);
			LEDControl(Player2Led5,LED_OFF);
			LEDControl(Player2Led6,LED_OFF);
			LEDControl(Player2Led7,LED_OFF);
			LEDControl(Player2Led8,LED_OFF);
			break;
			case 3:
			LEDControl(Player2Led1,LED_ON);
			LEDControl(Player2Led2,LED_ON);
			LEDControl(Player2Led3,LED_ON);
			LEDControl(Player2Led4,LED_OFF);
			LEDControl(Player2Led5,LED_OFF);
			LEDControl(Player2Led6,LED_OFF);
			LEDControl(Player2Led7,LED_OFF);
			LEDControl(Player2Led8,LED_OFF);
			break;
			case 4:
			LEDControl(Player2Led1,LED_ON);
			LEDControl(Player2Led2,LED_ON);
			LEDControl(Player2Led3,LED_ON);
			LEDControl(Player2Led4,LED_ON);
			LEDControl(Player2Led5,LED_OFF);
			LEDControl(Player2Led6,LED_OFF);
			LEDControl(Player2Led7,LED_OFF);
			LEDControl(Player2Led8,LED_OFF);
			break;
			case 5:
			LEDControl(Player2Led1,LED_ON);
			LEDControl(Player2Led2,LED_ON);
			LEDControl(Player2Led3,LED_ON);
			LEDControl(Player2Led4,LED_ON);
			LEDControl(Player2Led5,LED_ON);
			LEDControl(Player2Led6,LED_OFF);
			LEDControl(Player2Led7,LED_OFF);
			LEDControl(Player2Led8,LED_OFF);
			break;
			case 6:
			LEDControl(Player2Led1,LED_ON);
			LEDControl(Player2Led2,LED_ON);
			LEDControl(Player2Led3,LED_ON);
			LEDControl(Player2Led4,LED_ON);
			LEDControl(Player2Led5,LED_ON);
			LEDControl(Player2Led6,LED_ON);
			LEDControl(Player2Led7,LED_OFF);
			LEDControl(Player2Led8,LED_OFF);
			break;
			case 7:
			LEDControl(Player2Led1,LED_ON);
			LEDControl(Player2Led2,LED_ON);
			LEDControl(Player2Led3,LED_ON);
			LEDControl(Player2Led4,LED_ON);
			LEDControl(Player2Led5,LED_ON);
			LEDControl(Player2Led6,LED_ON);
			LEDControl(Player2Led7,LED_ON);
			LEDControl(Player2Led8,LED_OFF);
			break;
			case 8:
			ATMEGA32_GICR->bits.b6=0;
			ATMEGA32_GICR->bits.b7=0;
			LEDControl(Player2Led1,LED_ON);
			LEDControl(Player2Led2,LED_ON);
			LEDControl(Player2Led3,LED_ON);
			LEDControl(Player2Led4,LED_ON);
			LEDControl(Player2Led5,LED_ON);
			LEDControl(Player2Led6,LED_ON);
			LEDControl(Player2Led7,LED_ON);
			LEDControl(Player2Led8,LED_ON);
			_delay_ms(WinnerTimeBlinking_ms);
			LEDControl(Player2Led1,LED_OFF);
			LEDControl(Player2Led2,LED_OFF);
			LEDControl(Player2Led3,LED_OFF);
			LEDControl(Player2Led4,LED_OFF);
			LEDControl(Player2Led5,LED_OFF);
			LEDControl(Player2Led6,LED_OFF);
			LEDControl(Player2Led7,LED_OFF);
			LEDControl(Player2Led8,LED_OFF);
			_delay_ms(WinnerTimeBlinking_ms);
			break;
			default:
			break;
		}
	}
	
