#include "DPIOH.h"
#include "MacrosH.h"
#include "tm4c123gh6pm.h"
#include "TimerH.h"
void LED_vINIT(unsigned char portname,unsigned char pinumber) // this function initialize pin in a port as led 
{
	DIO_vSETPINDIR(portname,pinumber,1);
}
void LED_vON(unsigned char portname,unsigned char pinumber)	// this function turns  the led on
{
	DIO_vWRITEPIN(portname,pinumber,1);
}	
void LED_vOFF(unsigned char portname,unsigned char pinumber)// this function turn led off
{
	DIO_vWRITEPIN(portname,pinumber,0);
}
void LED_vTOG(unsigned char portname,unsigned char pinumber)//this function toggle the property of the led >> if it was on it will be off 
{
	DIO_vTOGGLEPIN(portname,pinumber);
}
/*void LED_Flash(unsigned char portname,unsigned char pinumber,unsigned char NO_Flashes)
{
	char i;
	for (i = NO_Flashes;i>0;i--)
	{
		DIO_vWRITEPIN(portname,pinumber,1);
		TIMER_SEC(1);
		DIO_vWRITEPIN(portname,pinumber,0);
		TIMER_SEC(1);
	}
}*/