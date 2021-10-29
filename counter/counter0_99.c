#include<reg52.h>
sbit count_T0=P3^4;
sbit RS=P0^5;
sbit RW=P0^6;
sbit E=P0^7;


void ms_delay( unsigned int time)
{
	unsigned int i,j;
	for(i=0;i<time;i++)
	{
		for(j=0;j<113;j++);
	}
}

void send(unsigned int command_value , unsigned char c_or_d) //send command to LCD
{
	P2=command_value;
	RW=0;
	RS=c_or_d;
	E=1;
	ms_delay(10);
	E=0;
}	

void lcd_init()
{
	send(0x38, 0);  //2 lines and 5x7 matrix
	send(0x0C,0);   //display on cursor off
	send(0X01,0);   //clear display screen
}

void main()
{
	unsigned char i;
	unsigned int cnt_val;
		
	// counter initialization
	TMOD=0X06; //counter 0, mode 2, 8 bit_autoreload mode
	count_T0=1; // p3.4 input pin
	lcd_init();
	while(1)
	{
		
		TH0=0x00;
		TL0=0x00;	// count value initialize	
		TR0=1; 		//counter 0 on

		while(!TF0) // monitoring TF0 flag
		{
			send(0x80,0)	; // force cursor on 1st line and 1st col	
			
			cnt_val = TL0;	 //while devidng by decimal step in below step the hex values in TL0 are converted 
											//to decimal & then divided, thats why we get decimal count at outputp(lcd)
			
			i = cnt_val/10; 				//Get the Ten's place
			send(i + 0x30, 1);			//	 i + 0x30;			// Convert it to ASCII
				
			i = cnt_val%10 ;			//Get the unit place		
			send(i + 0x30, 1);	// Convert it to ASCII for LCD
			
			if (cnt_val == 100)   // restricting count 00 to 99
			{
				break;
			}
		}
		TF0=0;  //reset flag
		TR0=0; //off counter 
	}
}