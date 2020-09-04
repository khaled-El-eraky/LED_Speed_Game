/*
 * LED_Speed_Game.c
 *
 * Created: 2/5/2020 12:20:21 AM
 *  Author: Khaled Osama Eraky
 */ 


#include "LED.h"
#include "LedSpeedGame.h"


int main()
{
	ResetGame();
	Player1_initiate();
	Player2_initiate();
	
	while(1)
	{
		Led_Update();
	}
}