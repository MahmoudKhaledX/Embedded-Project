void LCD_error_msg(void);
void LCD_error_msg2(void);
void LCD_error_msg3(void);
void LCD_error_msg4(void);
unsigned char Valid_Input(unsigned char Input);
void Valid_Input2(unsigned char Input);
void Display_Start(void);
void Valid_time(unsigned char minutes,unsigned char seconds);
void LCD_Write_Weight(unsigned char weight);
unsigned char Time_to_Sec(unsigned char minutes_big,unsigned char minutes_small,unsigned char seconds_big,unsigned char seconds_small);
void Count_Down(unsigned char time);
unsigned char check_SWITCHES (unsigned char portname,unsigned char pinumber);
void check_SW3(unsigned char portname,unsigned char pinumber);
void pause_display( unsigned char remaining_time ) ;
void Stopcooking_dispaly (void);
void Cooking(unsigned char Cooking_Time);