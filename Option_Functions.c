void Button_A_Pushed(void)
{
  LCD_Cmd( 0x01 );  // clear display
  LCD_Cmd( 0x80 );  // display the data on the first row of LCD
	LCD_Write_String ("Popcorn");// display popcorn on the screen
	TIMER_SEC(2);  // delay for 2 seconds /change this to the new timer/
}