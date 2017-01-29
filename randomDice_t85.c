/*

Name:		Random Dice
Datum:		07.12.2016
Autor:		Filip
µC:			ATtiny 85
Edit:		08.12.2016, 10.12.2016, -
Bemerkung:	Dies ist eine elektronische Würfelsimulation. Realisiert wird Sie mit einem
			ATtiny 85. ACHTUNG: Manche Pins haben besondere Eigenschaften (siehe unten).
			Grundsätzlich ist diese Programmausführung nicht sehr schön, da hier nicht
			mit Interrupts sondern mit while-Schleifen und if-Abfragen gearbeitet wird.

*/

#define F_CPU 1000000

#include <stdio.h>
#include <avr/io.h>
#include <util/delay.h>

#define LED35 PB0		// Es können je zwei LED zusammengefasst werde!
#define LED4 PB1		// ACHTUNG: siehe DS: PB4 und PB3 sind vertauscht!
#define LED26 PB2		// ACHTUNG: PB5 kann nur als I/O-Pin verwendet, wenn man RSTDSBL aktiviert!
#define LED17 PB3		// danach kann man aber NICHT mehr mit dem ISP programmieren! nur mehr mit dem stk500
#define TASTER PB4

void one();																					// void in de.: leere #themoreyouknow
void two();
void three();
void four();
void five();
void six();

/*	Hauptprogramm	*/

void main()
{
	DDRB |= ( (1 << LED35) | (1 << LED4) | (1 << LED26) | (1 << LED17) );					// AUSGÄNGE
	DDRB &= ~(1 << TASTER);																	// EINGÄNGE // keine internen Wiederstände nötig, da externe Pull-downs verwendet werden
	
	
	while(1)									// durchlaufe die leere Schleife solange, bis der Taster HIGH am Eingang schaltet
	{
		while(PINB & (1 << TASTER) )			// wenn Tastereingang == HIGH führe diese Schleife aus
		{ 
			one();
			
			if( !(PINB & (1 << TASTER)) )		// wenn Tastereingang == LOW führe diese if-Abfrage aus
			{
				PORTB |= (1 << LED4);			// Lass die gegebene Nummer 1sec stehen und unterbreche dann diese Schleife: while(PINB & (1 << TASTER) )
				_delay_ms(1000);
				PORTB &= ~(1 << LED4);
				_delay_ms(1000);
				
				break;							// Befehl zum unterbrechen
			}
			
			two();								// mache den selben spaß für die restlichen Nummern :)
			
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

/*	Unterprogramme	*/

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
