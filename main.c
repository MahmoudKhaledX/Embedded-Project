#include "ButtonH.h"
#include "LEDH.h"
#include "DPIOH.h"
#include "TimerH.h"
#include "KeyPadH.h"
#include "BuzzerH.h"
int main (void)
{	int x;

PORT_vInit('f');
BUTTON_vINIT_PULLUP('F',0);
LED_vINIT('F',1);
LED_vINIT('F',3);
while(1)
{
	

		LED_vON('F',1);

		TIMER_1SEC(10);


			LED_vOFF('F',1);
			TIMER_1SEC(10);


}}