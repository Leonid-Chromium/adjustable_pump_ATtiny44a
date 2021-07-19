/*
 * ButtonTest4.c
 *
 * Created: 18.07.2021 12:42:21
 * Author : Leo
 */ 

#include <avr/io.h>
#include <util/delay.h>

#define F_CPU 1000000 UL

#define LED PORTB
#define LED1 PORTB0
#define LED2 PORTB1
#define LED3 PORTB2

#define BUTT PINA
#define BUTTP PINA0
#define BUTTM PINA1
#define BUTTS PINA2

int stime = 1000;

void delay(int ms){
	for(;ms;ms--)
	_delay_ms(1);
}

void warningBlink(int ms)
{
	LED |= (1<<LED3);
	delay(ms);
	LED |= (0<<LED3);
}

void mybuttons(void)
{
	if (BUTT & 1<<BUTTM)
	{
		if (stime>500)
		{
			stime-=100;
			warningBlink(100);
		}
		else
		{
			warningBlink(100);
			_delay_ms(50);
			warningBlink(100);
		}
	}
	else
	{
		warningBlink(100);
	}
	if (BUTT & 1<<BUTTP)
	{
		if (stime<3000)
		{
			stime+=100;
			warningBlink(100);
		}
		else
		{
			warningBlink(100);
			_delay_ms(50);
			warningBlink(100);
		}
	}
	else
	{
		warningBlink(100);
	}
}

void blink()
{
	LED ^= 3;//(1<<LED1)|(1<<LED2);
	delay(stime);
	mybuttons();
	LED ^= 3;//(1<<LED1)|(1<<LED2);
	delay(stime);
	mybuttons();
}

void init(void)
{
	DDRA = 0b00000000; //port A is in
	DDRB = 0b11111111; //port B is out
	PORTA = 0b11111111; //high
	PORTB = 0b00000000; //LED1 is on, LED2 is off
	while (BUTT & 1<<BUTTS)
	{
	}
	warningBlink(1000);
	LED |= 1<<LED1;
}

int main(void)
{
	init();
    while (1) 
    {
		blink();
    }
}