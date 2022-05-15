#include "DPIOH.h"
#include "tm4c123gh6pm.h"


void TIMER_INIT(void) //call this function to intialize the timer
{
NVIC_ST_CTRL_R = 0; // 1) disable SysTick during setup
NVIC_ST_RELOAD_R = 0x00FFFFFF ; // 2) maximum reload value
NVIC_ST_CURRENT_R = 0; // 3) any write to cURRENT clears it
NVIC_ST_CTRL_R = 0x00000005; // 4) enable SysTick with core clock
}
	
void TIMERCOUNTER_xHZ(unsigned long delay) // you will never call this function we use in implementation of other functions
{

	NVIC_ST_CTRL_R =0;
	NVIC_ST_RELOAD_R= delay-1;
	NVIC_ST_CURRENT_R=0;
	NVIC_ST_CTRL_R=0x5;
while ((NVIC_ST_CTRL_R & 0x00010000 )==0);	
}
void TIMER_1MS(unsigned long times)//call it to wait "X" ms send X as argument with the amount of MS you want to wait
{
	int i;
	for(i=0; i<times;i++)
	{
		TIMERCOUNTER_xHZ(16000);
	}
	
	
}
void TIMER_1SEC(unsigned long times)//call it to wait "X" second send X as argument with the amount of seconds you want to wait
{
	int i;
	for(i=0; i<times;i++)
	{
		TIMER_1MS(1000);
	}
	
	
}
void TIMER_1US(unsigned long times)//call it to wait "X" us send X as argument with the amount of uS you want to wait
{
	int i;
	for(i=0; i<times;i++)
	{
		TIMERCOUNTER_xHZ(16);
	}
}