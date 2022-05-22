#include "LCDH.h"
#include "TimerH.h"
#include "KeyPadH.h"
#include "Needed_FunctionsH.h"
#include "ButtonH.h"
#include "LEDH.h"
#include "BuzzerH.h"
#include "Option_FunctionsH.h"

void Display_Start(void)
{
		LCD_Cmd(0x01);
		LCD_Cmd(0x80);
    LCD_Write_String("Please choose");
	  LCD_Cmd(0xC0);
	  LCD_Write_String("A,B,C or D");
}

void LCD_error_msg(void)
{
	LCD_Cmd(0x01);
	LCD_Cmd(0x80);
	LCD_Write_String("Err");
	TIMER_SEC(2);				/*no check here*/
}

void LCD_error_msg2(void)
{
	LCD_Cmd(0x01);
	LCD_Cmd(0x80);
	LCD_Write_String("Please enter");
	LCD_Cmd(0xC0);
	LCD_Write_String("a valid time");
	
}

void LCD_error_msg3(void)
{
	LCD_Cmd(0x01);
	LCD_Cmd(0x80);
	LCD_Write_String("Please enter a valid number");
}

void LCD_error_msg4(void)
{
	LCD_Cmd(0x01);
	LCD_Cmd(0x80);
	LCD_Write_String("Please choose a valid option");
	check_SW3('D',2);
}

void pause_display( unsigned char minutes, unsigned char seconds ) /*use it if sw1 is pressed one time*/
{  
   LCD_Cmd(0x01);
   LCD_Cmd(0x80);
   LCD_Write_String("Paused!");
   LCD_Cmd(0xC5);
   LCD_Write_String("left");
   LCD_WRITE_MINUTES_SECONDS(minutes,seconds);		
	 while((BUTTON_u8READ('D',2)==0) && (check_SWITCHES('F',4)==0)) {}
	 if(check_SWITCHES('F',4)==0)  /*sw1*/
		{
			Stopcooking_dispaly();
		}
		if(check_SWITCHES('F',0) == 1) /*sw2*/
		{
			Continue_cooking(minutes,seconds);
		}
   /*LCD_Write_Char('s')*/
}

void Stopcooking_dispaly (void)	
{
   LCD_Cmd(0x01); 
   LCD_Cmd(0x80); 
   LCD_Write_String("Cooking");
   LCD_Cmd(0xc0);
   LCD_Write_String("stopped!");
	 TIMER_SEC(1);
	 Microwave_States();
}

unsigned char Time_to_Sec(unsigned char minutes_big,unsigned char minutes_small,unsigned char seconds_big,unsigned char seconds_small)
{
	unsigned char time_sec;
	unsigned char minutes=minutes_big*10+minutes_small;
	unsigned char seconds=seconds_big*10+seconds_small;
	Valid_time(minutes,seconds);
	time_sec = 60*minutes+seconds;
	return time_sec;
	//if choose (D) enter Total time in seconds in function Start Cooking
}

void check_SW3(unsigned char portname,unsigned char pinumber)
	/* check sw3 at the beginning, Commands may be deleted if you use it in the main as a while loop condition	*/
{	
	if(BUTTON_u8READ('D',2)==0)
	{
	LCD_Cmd(0x01);
	LCD_Cmd(0x80);
	LCD_Write_String("Close the Door");
	while ( BUTTON_u8READ('D',2) == 0)
		{}
	}
}
	
unsigned char check_SWITCHES (unsigned char portname,unsigned char pinumber)  //check sw1,sw2 
{ 
	unsigned char x;
  x = BUTTON_u8READ(portname,pinumber);    
  if(x == 1)
{
   return 0;
}
else
   return 1;
}
void LCD_Write_Weight(unsigned char weight)   //Writes the given weight on the LCD screen
{
	LCD_Write_Char(weight);
	LCD_Write_String("Kg");
	TIMER_SEC(2);
}
void Valid_time(unsigned char minutes,unsigned char seconds)
{
	if(minutes>30 || (minutes == 0 && seconds == 0))
	{
		LCD_error_msg2();
	}
	else if(minutes==30)
	{
		if(seconds>0)
		{
			LCD_error_msg2();
		}
		else
		{}
	}
	else
	{}
}

unsigned char Valid_Input(unsigned char Input)  // Checks if the input given is valid or not
{
		if (0<Input && Input<10)
			return 1;
		else
			return 0;
}

void Valid_Input2(unsigned char Input)
{
		if(Input<10)
		{}
			else
			{
				LCD_error_msg3();
			}
}

void Cooking(unsigned char Cooking_Time)
{
	check_SW3('D',2);
	LCD_Cmd(0x01);
	LCD_Cmd(0x80);
	LCD_Write_String("Cooking...");
	LCD_Cmd(0xC5);
	LCD_Write_String("left");
	Count_Down(Cooking_Time);
	
}

void Count_Down(unsigned char time)
{
	int i;
	for(i=time;i>=0;i--)
	{
		LCD_Cmd(0xC0);
		LCD_Write_Char(i);			/*check LCD if the new number overwrites the previous one*/
		/*LCD_Write_Char('s');*/
		TIMER_SEC2(1);
		if(BUTTON_u8READ('D',2)==0)  /*sw3*/
		{
			check_SW3('D',2);
			Continue_cooking(i);
		}
		if(check_SWITCHES('F',4) == 1) /*sw1*/
		{
			pause_display(i);
		}
  }
}

void Flash_LEDs_Buzzer(unsigned char Number_Flashes)
{
	unsigned char i;
	for (i = Number_Flashes;i>0;i--)
	{
		LED_vON('F',1); 
	  LED_vON('F',2);
	  LED_vON('F',3);
		BUZZER_vON('D',3);
	  TIMER_MS(500);
		LED_vOFF('F',1);
		LED_vOFF('F',2);
		LED_vOFF('F',3);
		BUZZER_vOFF('D',3);
		TIMER_MS(500);
	}
}

void Count_Down_D_Button( unsigned char minutes, unsigned char seconds)
{
unsigned char i,temp,j ;
	for (i=minutes;i>=0;i--)
	{
				if(i !=minutes)
				{
					temp=59;
				}
				else
				{		
				temp=seconds;
				}

					for(j=temp;j>=0;j--)
					{
						LCD_WRITE_MINUTES_SECONDS(i,j);
						TIMER_SEC2(1);
					}
	}
}

void LCD_WRITE_MINUTES_SECONDS(unsigned char minutes,unsigned char seconds)
{
		unsigned char minutes_big,minutes_small,seconds_big,seconds_small;

		minutes_big=(minutes/10);
		minutes_small=(minutes%10);
		seconds_big=(seconds/10);
		seconds_small=(seconds%10);
		LCD_Write_Number(minutes_big);
		LCD_Write_Number(minutes_small);
		LCD_Write_Char(':');
		LCD_Write_Number(seconds_big);
		LCD_Write_Number(seconds_small);
}

void Display_LCD_D(unsigned char seconds_small, unsigned char seconds_big, unsigned char minutes_small, unsigned char minutes_big)
{
	LCD_Cmd(0x01);
	LCD_Cmd(0x85);
	LCD_Write_Number(minutes_big);
	LCD_Write_Number(minutes_small);
	LCD_Write_String(" :");
	LCD_Write_Number(seconds_big);
	LCD_Write_Number(seconds_small);
}

void Continue_cooking( unsigned char minutes, unsigned char seconds )
{ 
     LCD_Cmd(0x01);
     LCD_Cmd(0x80);
     LCD_Write_String("Cooking...");
		 LCD_Cmd(0xc5);
     LCD_Write_String("left");
     Count_Down(minutes,seconds);
     Finish_Cooking();
}
void Finish_Cooking(void)	 //Indicates that the cooking operation has finished
{
	LCD_Cmd(0x01);
	LCD_Cmd(0x80);
	LCD_Write_String("Cooking");
	LCD_Cmd(0xC0);
	LCD_Write_String("Done");
	Flash_LEDs_Buzzer(3);
}


