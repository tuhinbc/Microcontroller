#include <avr/io.h>
#include<util/delay.h>


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

int is_ok()
{
	return (!test(3))&&(!test(4));
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
	//DDRB=0b00000001;
	DDRB=0xFF;
	int i;
	int delay=1;//ms
	
	//PULL UP
	//on(1);
	//on(2);


	//on(0);
	//_delay_ms(1000);
	//
	//off(0);
	//_delay_ms(1000);

  	while(1) {
		//if(test(1)) on(0);
		//else off(0);
		PORTB=0xFF;
		_delay_ms(delay);
		PORTB=0x00;
		_delay_ms(delay);
		delay=delay+50;
		if(delay==1000)delay=1;
	}

}
