#include <reg51.h>
sbit m1 = P2^0;
sbit m2 = P2^1;
sbit en = P2^2;
sbit lr = P2^3;
sbit sw = P2^4;

void delay(unsigned int delayInMs)
{
	unsigned int i,j;
	for(j=0;j<delayInMs;j++)
	{
		for(i=0;i<113;i++);
	}
}

void main()
{
	sw=1;
	lr=1;
	while(1)
	{
		if(sw == 0 && lr == 0 )
		{
			en=1;
			m1=0;
			m2=1;
			delay(200);
		}
		else if(sw == 0 && lr == 1)
		{
			en=1;
			m1=1;
			m2=0;
			delay(200);
		}
		else
		{
			en=0;
			delay(200);
		}
	}
}