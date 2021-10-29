#include<reg51.h>
#define display_port P3      
sbit rs = P2^0;  
sbit rw = P2^1;  
sbit e =  P2^2;  

void msdelay(unsigned int count)
{
    unsigned i,j ;
		for(i=0;i<count;i++)
    for(j=0;j<112;j++);
}

void lcd(unsigned char cmordata, unsigned char cord) 
{
    display_port = cmordata;
    rs= cord;
    rw=0;
    e=1;
    msdelay(1);
    e=0;
		msdelay(5);
}

 void lcd_init()    
{
		msdelay(20);
    lcd(0x38, 0);  
		//msdelay(1);
    lcd(0x0C, 0);  
		//msdelay(1);
    lcd(0x01, 0);  
		//msdelay(1);
    lcd(0x06, 0);  
		//msdelay(1);
		lcd(0x80, 0);  
		//msdelay(1);
		//lcd(0x80, 0);
		//msdelay(1);
}
void main()
{	
		unsigned char arr[]="Embedded System";
		unsigned char k;
    lcd_init();
    for(k=0;k<sizeof(arr);k++)
		{
			lcd(arr[k], 1);
		}
		while(1);
}