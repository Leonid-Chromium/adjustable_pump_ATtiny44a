/*
 * ButtonTest3.c
 *
 * Created: 16.07.2021 14:56:44
 * Author : Leo
 */ 

#include <avr/io.h>
#include <util/delay.h>

#define F_CPU 1000000 UL

int main(void)
{
	DDRA = 0b00000000; //port A is in
	DDRB = 0b11111111; //port B is out
	PORTA = 0b11111111; //high
	PORTB = 0b00000000; //Led off
    while (1) 
    {
		if (PINA & 1<<PINA0)
		{
			PORTB = 0b00000001;
		}
		else
		{
			PORTB = 0b00000010;
		}
    }
}

