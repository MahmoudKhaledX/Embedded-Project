void Button_A_Pushed(void)
{
  LCD_Cmd( 0x01 );  // clear display
  LCD_Cmd( 0x80 );  // display the data on the first row of LCD
	LCD_Write_String ("Popcorn");// display popcorn on the screen
	TIMER_SEC(2);  // delay for 2 seconds /change this to the new timer/
}

unsigned char Button_B_Pushed (void)
{
	unsigned char Kilos;
	unsigned char Check_Result;
	unsigned char Defrosted_Time;
	Check:
	LCD_Cmd(0x01);												/*Clears the LCD display */
	LCD_Cmd(0x80);												/* Takes cursor to beginning of first row */
	LCD_Write_String("Beef Weight?");
	TIMER_SEC(2);            /*dont change this timer to the new one*/
	Kilos = KEYPAD_u8READ( 'C','E'); /* check if there is a delay to enable the user to press any button */
	Check_Result = Valid_Input(Kilos);
	if (Check_Result == 1)
	{
		LCD_Cmd(0x01);
		LCD_Write_Weight(Kilos);
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
	LCD_Cmd(0x01);												/*Clears the LCD display */
	LCD_Cmd(0x80);												/* Takes cursor to beginning of first row */
	LCD_Write_String("Chicken Weight?");
	Check:
	Kilos = KEYPAD_u8READ( 'C','E'); /* write port name when you know which port is connected to the keypad */
	Check_Result = Valid_Input(Kilos);
	if (Check_Result == 1)
	{
		LCD_Cmd(0x01);
		LCD_Write_Weight(Kilos);
		Defrosted_Time = Kilos * 0.2 * 60;
		return Defrosted_Time;
	}
	else
	{
		LCD_error_msg();
		goto Check;
	}
}
while(KEYPAD_u8READ(dakhalo hena port_Outname,port_inname ==0xFF)
{}
unsigned char input=KEYPAD_u8READ;
if(input=="D")
{

clear lcd function ;
print lcd function ("cooking timee") ;

unsigned char seconds_small=0,seconds_big=0,minutes_small=0,minutes_big =0 ;
unsigned char i=0;
for(i=0;i<4;i++)
{
while(KEYPAD_u8READ(dakhalo hena port_Outname,port_inname ==0xFF)
{}
minutes_big=minutes_small;
minutes_small=seconds_big;
seconds_big=seconds_small;
seconds_small=KEYPAD_u8READ((dakhalo hena port_Outname,port_inname);
use lcd print function to print minutes_big minutes_small : seconds_big seconds_small
while(KEYPAD_u8READ(dakhalo hena port_Outname,port_inname ==0xFF)
{
if(SW1==0)
{LCD FUNCTION TO CLEAR
	i=0
}
if(SW2==0)
{
i=4
break;

}



}


}
