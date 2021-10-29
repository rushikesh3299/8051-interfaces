#include<reg51.h>

sbit clk = P3^2;
sbit start = P3^3;
sbit eoc = P3^4;
sbit oe = P3^1;
sbit ale = P3^0;


void timer0() interrupt 1  // TIMER 0 interrupt ISR
{
    clk=~clk;
}


void delay(int t)      // delay function
{
	int j;
	for(j=0;j<t*1275;j++);
}


void main()
{
	eoc=1;             // make eoc an input
	ale=0;
	oe=0;
	start=0;

	TMOD=0x02;    // timer 0 in mode 2
	TH0=0xc2;   //for 15khz clk
	IE=0x82; //  set timer 0 interrupt
	TR0=1;   // start timer 0

	while(1)
	{ 
		ale=1;  // send high to low pulse on start and ale pin
		start=1;
		delay(1);
		ale=0;
		start=0;
		
		while(eoc==1);     // wait for conversion
		while(eoc==0); 

		oe=1;
		P2 = P1;
		oe=0;

	}

}