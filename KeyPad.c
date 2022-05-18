#include "ButtonH.h"
#include "LEDH.h"
#include "DPIOH.h"
#include "TimerH.h"
#include "MacrosH.h"
#include "tm4c123gh6pm.h"
void KEYPAD_INIT(unsigned char OUT_portname,unsigned char IN_portname)//Intialize 2 ports to be used for keypad , firt 4 pins in OUT_portname is intialized to be output
{																																			//Intialize 2 ports to be used for keypad , highest 4 pins in IN_portname is intialized to be input pull up bottons	
	DIO_vSETPINDIR (OUT_portname,1,1);
	DIO_vSETPINDIR (OUT_portname,2,1);
	DIO_vSETPINDIR (OUT_portname,3,1);
	DIO_vSETPINDIR (OUT_portname,4,1);
	DIO_vSETPINDIR (IN_portname,4,0);
	DIO_vSETPINDIR (IN_portname,5,0);
	DIO_vSETPINDIR (IN_portname,6,0);
	DIO_vSETPINDIR (IN_portname,7,0);
	DIO_vEABLEPULLUP(IN_portname,4);
	DIO_vEABLEPULLUP(IN_portname,5);
	DIO_vEABLEPULLUP(IN_portname,6);
	DIO_vEABLEPULLUP(IN_portname,7);

}

unsigned char KEYPAD_u8READ(unsigned char OUT_portname,unsigned char IN_portname)
	// this function reads what is pressed on keypad *send to this function port names that the keypad is connected to it*
{
	unsigned char row,coloumn,temp;
	unsigned char returnValue=0xFF;
	unsigned char array[4][4]={{'1','2','3','A'},
															{'4','5','6','B'},
															{'7','8','9','C'},
															{'*','0','#','D'}};
														do
														{
															for(row=0;row<4;row++)
															{
																DIO_vWRITELOWPINS(OUT_portname,0xF);
																DIO_vWRITEPIN(OUT_portname,row,0);
																for(coloumn=0;coloumn<4;coloumn++)
																{
																	temp=DIO_u8READPIN(IN_portname,coloumn+4);
																	if(temp==0)
																	{
																		returnValue=array[row][coloumn];
																		break;
																	}	
																}
																	if(temp==0)
																	{
																		break;
																	}	
																	
															}
															 
														}	
														while(returnValue==0xFF);
														return returnValue;
													}

unsigned char KEYPAD_u8READ2(unsigned char OUT_portname,unsigned char IN_portname)// this function reads what is pressed on keypad *send to this function port names that the keypad is connected to it*
																			// it return the charachter pressed and it returns 0xFF if no key is pressed
{
	char row,coloumn,temp;
	unsigned char returnValue=0xFF;
	unsigned char array[4][4]={{'1','2','3','A'},
															{'4','5','6','B'},
															{'7','8','9','C'},
															{'*','0','#','D'}};
	
															for(row=0;row<4;row++)
															{
																DIO_vWRITELOWPINS(OUT_portname,0xF);
																DIO_vWRITEPIN(OUT_portname,row,0);
																for(coloumn=0;coloumn<4;coloumn++)
																{
																	temp=DIO_u8READPIN(IN_portname,coloumn+4);
																	if(temp==0)
																	{
																		returnValue=array[row][coloumn];
																		break;
																	}	
																}
																	if(temp==0)
																	{
																		break;
																	}	
																	
															}
															return returnValue; 
	
	}
