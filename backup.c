#include <avr/io.h>
#include<util/delay.h>
#define F_CPU 16000000UL
char digit[15]=
{
	0b01111110,
	0b00001100,
	0b10110110,
	0b10011110,
	0b11001100,
	0b11011010,
	0b11111010,
	0b00001110,
	0b11111110,
	0b11011110,
	0b00000000
};
void send_d(int tx)
{
	PORTD=digit[tx];
}

void dancinglight()
{
	char i;
	while(1)
	{
		i=2;
		while(i&0b01111111)
		{
			PORTD=i;
			i<<=1;
			_delay_ms(100);
		}
		//_delay_ms(500);
	}
}
int main()
{
	DDRC=0xFF;
	DDRD=0xFF;
	DDRB=0xFF;

	PORTD=0xff;
	while(1)
	{
		PORTD=0xFF;
		_delay_ms(100);
		PORTD<<=1;
	}

}
/*
void measure(int adc_value)
{
		if(adc_value>1000) send_d(1);
		else if(adc_value>900) send_d(2);
		else if(adc_value>800) send_d(3);  
		else if(adc_value>700) send_d(4);
		else if(adc_value>600) send_d(5);
		else if(adc_value>500) send_d(6);
		else send_d(0);
}
int tmp()
{
		//ADC_Init();
	DDRD=0xFF;
	DDRB=0xFF;
	int i,sleep=500,blink=50;
	unsigned  int adc_value;	

	PORTD=0xFF;

	PORTB=0x00;

	ADCSRA  = (1<<ADEN) | (1<<ADPS2) | (1<<ADPS0);
	ADMUX=0x05;

	int s;
  	while(1) {
		ADCSRA  |= (1<<ADSC);	// Start conversion
		while (ADCSRA &  (1<<ADSC));
		
		s=adc_value = ADCW;
			//Store ADC result
		i=s/1000;
		s=s%1000;
		send_d(i);
		_delay_ms(sleep);



		i=s/100;
		s=s%100;
		send_d(i);
		_delay_ms(sleep);



		i=s/10;
		s=s%10;
		send_d(i);
		_delay_ms(sleep);



		//i=s%10;
		//s=s/10;
		send_d(s);
		_delay_ms(sleep);


		send_d(10);
		_delay_ms(1000);
	}
}
*/
