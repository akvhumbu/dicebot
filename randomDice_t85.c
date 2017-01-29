/*

Name:		dicebot
Date:		07.12.2016
Author:		ofes
µC:		ATtiny85
Edit:		08.12.2016, 10.12.2016, -
Comment:	

*/

#define F_CPU 1000000

#include <stdio.h>
#include <avr/io.h>
#include <util/delay.h>

#define LED35 PB0		// it is possible to connect two led's to the same output pin! 
#define LED4 PB1		// CAUTION: check datasheet: PB4 & PB3 location!
#define LED26 PB2		// CAUTION: it is only possible to use PB5 as an i/o-pin when RSTDSBL is aktivated (not used here)
#define LED17 PB3		// you will no longer be able to use the ispmk2-programmer. only the stk500
#define TASTER PB4		// TASTER = BUTTON in german, sorry guys :)

void one();																					
void two();
void three();
void four();
void five();
void six();

/*	main	*/

void main()	
{
	DDRB |= ( (1 << LED35) | (1 << LED4) | (1 << LED26) | (1 << LED17) );					// OUTPUTS 
	DDRB &= ~(1 << TASTER);											// INPUTS								
														// no pull ups needed -> externeal pull downs in use (10k resistor)
	
	while(1)												// stay inside endless loop until BUTTON == HIGH
	{
		while(PINB & (1 << TASTER) )									// as soons as BUTTON == HIGH exec. this loop
		{ 
			one();
			
			if( !(PINB & (1 << TASTER)) )								// as soon as BUTTON == LOW exec. this if condition (break, to escape the 'while(PINB & (1 << TASTER) )' loop)
			{
				PORTB |= (1 << LED4);								// leave the the led combination for 1 sec and 'break' the loop to: while(PINB & (1 << TASTER) )
				_delay_ms(1000);
				PORTB &= ~(1 << LED4);
				_delay_ms(1000);
				
				break;										
			}
			
			two();											// well thats it :)
			
			if( !(PINB & (1 << TASTER)) )
			{
				PORTB |= (1 << LED17);
				_delay_ms(1000);
				PORTB &= ~(1 << LED17);
				_delay_ms(1000);
				
				break;
			}
			
			three();
			
			if( !(PINB & (1 << TASTER)) )
			{
				PORTB |= ( (1 << LED4) | (1 << LED17) );
				_delay_ms(1000);
				PORTB &= ~( (1 << LED4) | (1 << LED17) );
				_delay_ms(1000);	
				
				break;		
			}
			
			four();
			
			if( !(PINB & (1 << TASTER)) )
			{
				PORTB |= ( (1 << LED17) | (1 << LED35) );
				_delay_ms(1000);
				PORTB &= ~( (1 << LED17) | (1 << LED35) );
				_delay_ms(1000);
				
				break;
			}
			
			five();
			
			if( !(PINB & (1 << TASTER)) )
			{
				PORTB |= ( (1 << LED4) | (1 << LED17) | (1 << LED35) );
				_delay_ms(1000);
				PORTB &= ~( (1 << LED4) | (1 << LED17) | (1 << LED35) );
				_delay_ms(1000);
				
				break;
			}
			
			six();
			
			if( !(PINB & (1 << TASTER)) )
			{
				PORTB |= ( (1 << LED26) | (1 << LED17) | (1 << LED35) );
				_delay_ms(1000);
				PORTB &= ~( (1 << LED26) | (1 << LED17) | (1 << LED35) );
				_delay_ms(1000);
				
				break;
			}
		}
	}
}

/*	subroutines	*/

void one()
{
	PORTB |= (1 << LED4);
	_delay_ms(50);
	PORTB &= ~(1 << LED4);
	_delay_ms(50);
}

void two()
{
	PORTB |= (1 << LED17);
	_delay_ms(50);
	PORTB &= ~(1 << LED17);
	_delay_ms(50);
}

void three()
{
	PORTB |= ( (1 << LED4) | (1 << LED17) );
	_delay_ms(50);
	PORTB &= ~( (1 << LED4) | (1 << LED17) );
	_delay_ms(50);
}

void four()
{
	PORTB |= ( (1 << LED17) | (1 << LED35) );
	_delay_ms(50);
	PORTB &= ~( (1 << LED17) | (1 << LED35) );
	_delay_ms(50);
}

void five()
{
	PORTB |= ( (1 << LED4) | (1 << LED17) | (1 << LED35) );
	_delay_ms(50);
	PORTB &= ~( (1 << LED4) | (1 << LED17) | (1 << LED35) );
	_delay_ms(50);
}

void six()
{
	PORTB |= ( (1 << LED26) | (1 << LED17) | (1 << LED35) );
	_delay_ms(50);
	PORTB &= ~( (1 << LED26) | (1 << LED17) | (1 << LED35) );
	_delay_ms(50);
}
