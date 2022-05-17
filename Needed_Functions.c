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
}

unsigned char check_SWITCHES (unsigned char portname,unsigned char pinumber)
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