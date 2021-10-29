#include<reg52.h>
sbit out = P1^0;

void ms_delay()  
{	
	TL0=0x00;           
	TH0=0x0EE; // 5ms
	TR0=1;
		
	while(!TF0);
		
	TR0=0; 
	TF0=0; 
}

void main()
{
	TMOD=0X01; //timer 0, mode 1
	while(1)
	{
		out=0XFF;
		ms_delay();	
		out=0X00;
		ms_delay();		
	}
}