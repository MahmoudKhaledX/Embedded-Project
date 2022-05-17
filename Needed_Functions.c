void Display_Start(void)
{
		LCD_Cmd(0x01);
		LCD_Cmd(0x80);
		LCD_Write_String("Please Choose an Option");
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
	LCD_Write_String("Please enter a valid time");
}

void LCD_error_msg3(void)
{
	LCD_Cmd(0x01);
	LCD_Cmd(0x80);
	LCD_Write_String("Please enter a valid number");
}

void pause_display( unsigned char remaining_time ) 
{  
   LCD_Cmd(0x01);
   LCD_Cmd(0x80);
   LCD_Write_String("Paused!");
   LCD_Cmd(0xC5);
   LCD_Write_String("left");
   LCD_Cmd(0xC0);
   LCD_Write_Char(remaining_time);
}
void Stopcooking_dispaly (void)	
{
   LCD_Cmd(0x01); 
   LCD_Cmd(0x80); 
   LCD_Write_String("Cooking");
   LCD_Cmd(0xc0);
   LCD_Write_String("stopped!");
		TIMER_SEC(2);
}

unsigned char Time_to_Sec(unsigned char minutes_big,unsigned char minutes_small,unsigned char seconds_big,unsigned char seconds_small)
{
	unsigned char time_sec;
	
	time_sec = 60*10*minutes_big+60*minutes_small+10*seconds_big+seconds_small;
	return time_sec;
	//if choose (D) enter Total time in seconds in function Start Cooking
}

void check_Sw3 
	(if ( BUTTON_u8READ(  portname, pinumber) == 1) // switch 3 is pressed
				LCD_Cmd(0x01);
	      LCD_Cmd(0x80);
	LCD_Write_String("Close the Door");
	else
		 start Cooking(Cooking_Time)
			)
	
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