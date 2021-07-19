/*
 * ButtonTest.c
 *
 * Created: 16.07.2021 8:57:28
 * Author : Leo
 */ 

#include <avr/io.h>
#include <avr/delay.h>
#include <avr/interrupt.h>

#define F_CPU = 1000000UL;

#define LED1 PORTA2
#define LED2 PORTA3

#define BUTP PORTA0
#define BUTM PORTA1

int stime = 1000;

void delay(int ms){
	for(;ms;ms--)
	_delay_ms(1);
}

void blink()
{
	PORTA = (1<<LED1)|(0<<LED2);
	delay(stime);
	PORTA = (0<<LED1)|(1<<LED2);
	delay(stime);
}

ISR(PCINT0_vect)
{
	PORTA = (1<<LED1);
}

int main(void)
{
	DDRA |= (1<<LED1)|(1<<LED2)|(0<<BUTM)|(0<<BUTP);
	PORTA |= (1<<BUTP)|(1<<BUTM);
	
	PCMSK0 |= (1<<PCINT0)|(1<<PCINT1);
	GIMSK |= (1<<PCINT0);
	
	
	sei();
	
	while (1)
	{
//		blink();
	}
}

