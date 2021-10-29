#include<reg51.h>
#define led P1  //port declaration
sbit sw = P2^0;

void delay (int); 

void delay (int d)  //loop for delay generation
{
	unsigned char i;
	for(;d>0;d--)    
		for(i=100;i>0;i--);
}

void main()
{
	unsigned char j;
		for(j=1;j<255;j++)
		{
			led= j;
			delay(1000);
			while(1)
			{
				if(sw == 0)
					break;
			}
		}
}