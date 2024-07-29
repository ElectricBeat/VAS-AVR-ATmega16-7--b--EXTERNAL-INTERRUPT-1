/*
 * EXTERNAL INTERRUPT 1.c
 *
 * Created: 29-07-2024 13:16:08
 * Author : SRIDHAR
 */ 

#define F_CPU 1000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

/*Interrupt Service Routine for INT1*/
ISR(INT1_vect)
{
	PORTC	=	PORTC ^ (1<<0);		/* Toggle PORTC */
	_delay_ms(50);					/* Software debouncing control delay */
}

int main(void)
{
	DDRC	=	DDRC | (1<<0);		/* Make PORTC as output PORT*/
	PORTC	=	PORTC | (0<<0);		/* Make pull down low */

	DDRD	=	DDRD & (~(1<<3));	/* PORTD as input */
	PORTD	=	PORTD | (1<<3);		/* Make pull up high */

	GICR	=	1<<INT1;			/* Enable INT1*/
	MCUCR	=	1<<ISC11 | 1<<ISC10;/* Trigger INT1 on rising edge */

	sei();							/* Enable Global Interrupt */

	/* Replace with your application code */
	while (1)
	{
		
	}
}