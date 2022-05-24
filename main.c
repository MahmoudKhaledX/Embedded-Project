#include "ButtonH.h"
#include "LEDH.h"
#include "DPIOH.h"
#include "TimerH.h"
#include "LCDH.h"
#include "KeyPadH.h"
#include "BuzzerH.h"
#include "Needed_FunctionsH.h"
#include "Option_FunctionsH.h"

int main (void)
{	
PORT_vInit('d');
PORT_vInit('f');
LCD_init();
KEYPAD_INIT('C','E');
while(1)
{		
	   Count_Down(1,0);
		/*Microwave_States();
		Finish_Cooking();*/
}
}
/* SW1 F4
SW2 D4
SW3 D2
BUZZER D3
KEYPAD  COLUMES C4 TO C7
        ROWS    E1 TO E4  
LCD PORT B*/
