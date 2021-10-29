#include <reg51.h>
sbit sw = P1^0;
sbit buzz = P1^1;

void delay(unsigned int delayInMs)
{
	unsigned int i,j;
	
	for(i=0;i<delayInMs;i++)
	{
		for(j=0;j<113;j++);
	}
}

void buzzfun()
{
	buzz = 1;
	delay(1000);
	buzz = 0;
	delay(1000);
	buzz = 1;
	delay(1000);
	buzz = 0;
	delay(1000);
	buzz = 1;
	delay(1000);
	buzz = 0;
}

void main()
{
	sw=1;
	buzz = 0;
	while(1)
	{
		if(sw==0)
		{
			buzzfun();
			delay(50);
		}
	}
}