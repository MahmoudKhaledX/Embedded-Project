#include "LCDH.h"
#include "TimerH.h"
#include "KeyPadH.h"
#include "Needed_FunctionsH.h"
#include "ButtonH.h"
#include "Option_FunctionsH.h"


void Button_A_Pushed(void)
{
  LCD_Cmd( 0x01 ); 									 // clears LCD display
  LCD_Cmd( 0x80 );  								// Takes cursor to beginning of first row 
	LCD_Write_String ("Popcorn");			// display popcorn on the screen
	TIMER_SEC(2);  										// delay for 2 seconds
}

unsigned char Button_B_Pushed (void)
{
	unsigned char Kilos;
	unsigned char Check_Result;
	unsigned char Defrosted_Time;
	Check:
	LCD_Cmd(0x01);												// Clears the LCD display
	LCD_Cmd(0x80);												// Takes cursor to beginning of first row
	LCD_Write_String("Beef Weight?");
	TIMER_SEC(2);            
	Kilos = KEYPAD_u8READ( 'C','E'); 			// gets the weight from the keypad
	Check_Result = Valid_Input(Kilos);		// checks if the input weight is a valid number
	if (Check_Result == 1)
	{
		LCD_Cmd(0x01);
		LCD_Write_Weight(Kilos);						// prints the input weight on the LCD
		Defrosted_Time = Kilos * 0.5 * 60;
		return Defrosted_Time;
	}
	else
	{
		LCD_error_msg();
		goto Check;
	}
}
		
unsigned char Button_C_Pushed (void)
{
	unsigned char Kilos;
	unsigned char Check_Result;
	unsigned char Defrosted_Time;
	LCD_Cmd(0x01);												// Clears the LCD display
	LCD_Cmd(0x80);												// Takes cursor to beginning of first row
	LCD_Write_String("Chicken Weight?");
	Check:
	Kilos = KEYPAD_u8READ( 'C','E'); 			// gets the weight from the keypad
	Check_Result = Valid_Input(Kilos);		// checks if the input weight is a valid number
	if (Check_Result == 1)
	{
		LCD_Cmd(0x01);
		LCD_Write_Weight(Kilos);						// prints the input weight on the LCD
		Defrosted_Time = Kilos * 0.2 * 60;
		return Defrosted_Time;
	}
	else
	{
		LCD_error_msg();
		goto Check;
	}
}
unsigned char Button_D_Pushed()
{
	LCD_Cmd(0x01);
	LCD_Cmd(0x80);
  LCD_Write_String("cooking time?") ;
  unsigned char seconds_small=0;
	unsigned char seconds_big=0; 
	unsigned char minutes_small=0;
	unsigned char minutes_big =0 ;
  unsigned char i;
	LCD_Cmd(0x85);
	LCD_Write_String("00:00");
  for(i=0;i<4;i++)
	{
	 TIMER_MS(700);
	 minutes_big=minutes_small;
   minutes_small=seconds_big;
   seconds_big=seconds_small;
   seconds_small=KEYPAD_u8READ('C','E');
	 Display_LCD_D(seconds_small,seconds_big,minutes_small,minutes_big);
while(KEYPAD_u8READ2('C','E') ==0xFF)
{
if(check_SWITCHES('F',4)==1)
	LCD_Cmd(0x01);
	i=0;
}
if(check_SWITCHES('F',0)==1)
{
i=4;
break;
}
}
	unsigned char Total_Time;
	Total_Time=Time_to_Sec(minutes_big,minutes_small,seconds_big,seconds_small);
	return(Total_Time);
}

void Microwave_States(void)
{
		unsigned char Keypad_Input;
		start:
		Display_Start();
		Keypad_Input=KEYPAD_u8READ('C','E');
		switch (Keypad_Input)
		{
			case 'A':
			{
			  Button_A_Pushed();
			  while(BUTTON_u8READ('D',1)==0) {} // wait until SW2 is pressed to start cooking
				TIMER_MS(200);
			  Cooking(1,0);
			  break;
			}
		  case 'B':
			{
				unsigned char Defrosted_Time;
				unsigned char minutes;
				unsigned char seconds;
				Defrosted_Time=Button_B_Pushed();
				minutes = Defrosted_Time/60;
				seconds = Defrosted_Time%60;
				while(BUTTON_u8READ('D',1)==0) {} // wait until SW2 is pressed to start cooking
				TIMER_MS(200);
				Cooking(minutes,seconds);
				break;
			}
			case 'C':
			{
				unsigned char Defrosted_Time;
				unsigned char minutes;
				unsigned char seconds;
				Defrosted_Time=Button_C_Pushed();
				minutes = Defrosted_Time/60;
				seconds = Defrosted_Time%60;
				while(BUTTON_u8READ('D',1)==0) {}  // wait until SW2 is pressed to start cooking
				TIMER_MS(200);
				Cooking(minutes,seconds);
				break;
			}
		