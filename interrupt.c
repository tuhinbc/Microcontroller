#define F_CPU 12000000
#include <avr/io.h>
#include<util/delay.h>
#include"remote.h"
//#include <avr/interrupt.h>
int on(int i)
{
	PORTB|=(1<<i);
}
int off(int i)
{
	PORTB&=~(1<<i);
}
int don(int i)
{
	PORTD|=(1<<i);
}
int doff(int i)
{
	PORTD&=~(1<<i);
}
void delay_ms(void)
{
   uint8_t i;
   for (i = 0; i < 100; i++)
      _delay_ms(10);
} 
int main()
{
	DDRB=0b00010000;
	//DDRB=0xff;
	//DDRD=0xff;
	//goto tu;

	uint8_t cmd=0;

   RemoteInit();

   //LCDInit(LS_BLINK);

   //LCDClear();

   //LCDWriteString("IR RemoteDecoder");
   //LCDWriteStringXY(0,1,"Key Code:");
   _delay_ms(1000);
	on(4);
	_delay_ms(100);
	off(4);
   while(1)
   {
      cmd=GetRemoteCmd(1);
      if(cmd==255)on(4);
	  //else doff(4);
   }


	tu:
	while(1)
	{
		don(4);
		//_delay_ms(10000);
		delay_ms();
		doff(4);
		delay_ms();
		//_delay_ms(10000);
	}
	return 0;
}
