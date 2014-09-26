#define F_CPU 12000000
#include <avr/io.h>
#include<util/delay.h>
//#include"remote.h"
#include <avr/interrupt.h>
#define s_on on(3)
#define s_off off(3)
#define d_on on(4)
#define d_off off(4)
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
   for (i = 0; i < 200; i++)
      _delay_ms(10);
} 
void send(char a)
{
	if(a&(1<<0))PORTB|=(1<<3);else PORTB&=~(1<<3);
	if(a&(1<<1))PORTB|=(1<<2);else PORTB&=~(1<<2);
	if(a&(1<<2))PORTC|=(1<<0);else PORTC&=~(1<<0);
	if(a&(1<<3))PORTC|=(1<<1);else PORTC&=~(1<<1);
	if(a&(1<<4))PORTC|=(1<<2);else PORTC&=~(1<<2);
	if(a&(1<<5))PORTC|=(1<<3);else PORTC&=~(1<<3);
	if(a&(1<<6))PORTC|=(1<<4);else PORTC&=~(1<<4);
	if(a&(1<<7))PORTC|=(1<<5);else PORTC&=~(1<<5);
}
int main()
{
	//DDRB=0b00000001;
	DDRB=0xff;
	DDRC=0xff;
	//DDRD=0xff;
	uint8_t cmd=0;
	//RemoteInit();
	char i=0;
	TCNT0=0xF2;
	TCCR0=0x01;
	TIFR
	while(1)
	{
		
	}
	while(1)
	{
		//cmd=GetRemoteCmd(0);
		//send(cmd);
		send(i++);
		_delay_ms(1000);
	}
	return 0;
}
