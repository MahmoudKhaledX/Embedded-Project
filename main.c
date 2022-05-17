#include "ButtonH.h"
#include "LEDH.h"
#include "DPIOH.h"
#include "TimerH.h"
#include "KeyPadH.h"
#include "BuzzerH.h"
#include "LCDH.h"


void LCD_error_msg4(void)
{
	LCD_Cmd(0x01);
	LCD_Cmd(0x80);
	LCD_Write_String("Please choose a valid option");
	check_SW3('D',2);
}
unsigned char Valid_Input(unsigned char Input)  // Checks if the input given is valid or not
{
		if (0<Input && Input<10)
			return 1;
		else
			return 0;
}
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