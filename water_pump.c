#include <avr/io.h>
#include<util/delay.h>
#include <avr/eeprom.h>
#define EEADDR 0x00
#define EEDATA 1

int stat(int send,int receive)
{
	PORTB|=(1<<send);
	_delay_ms(100);
	int i=PINB&(1<<receive);
	PORTB&=~(1<<send);
	return i;
}
int test(int i)
{
	return (PINB&(1<<i));
}
int on(int i)
{
	PORTB|=(1<<i);
}
int off(int i)
{
	PORTB&=~(1<<i);
}
int is_full()
{
	return (!test(3))&&(!test(4));
}
int is_empty()
{
	return test(4)&&test(3);
}
void turn_on()
{
	on(0);
}
void turn_off()
{
	off(0);
}
int main()
{
	//DDRD=0xFF;
	DDRB=0b00000001;

	int i;
	int delay=5000;//ms
	
	//PULL UP
	on(3);
	on(4);

	//
	off(0);
	_delay_ms(delay);
	//read from EEPROM
	if(eeprom_read_byte((uint8_t*)EEADDR)) 
	{
		turn_on();
		_delay_ms(delay);
	}
  	while(1) {
		if(is_full())
		{
			turn_off();
			eeprom_write_byte ((uint8_t*)EEADDR,0);
		}
		_delay_ms(delay);
		if(is_empty())
		{
			turn_on();
			eeprom_write_byte ((uint8_t*)EEADDR,1);
		}
		_delay_ms(delay);
	}

}









