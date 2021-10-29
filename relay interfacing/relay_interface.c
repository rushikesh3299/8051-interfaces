#include <reg51.h>
sbit relay_pin = P3^0;
sbit sw = P1^0;

void delay(unsigned int timeInMs)
{
	int i,j;
	for(i=0;i<timeInMs;i++)
	{
		for(j=0;j<113;j++);
	}
}

void main()
{
	sw=1;
	while(1)
	{
		if(sw == 0)
		{
			relay_pin=1;
			delay(100);
		}
		else
		{
			relay_pin=0;
			delay(100);
		}
	}
}