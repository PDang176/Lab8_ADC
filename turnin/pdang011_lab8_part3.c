/*	Author: Patrick Dang
 *  	Partner(s) Name: 
 *	Lab Section: 028
 *	Assignment: Lab #8  Exercise #2
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 *
 *	Video Link: https://drive.google.com/open?id=18dsmRQmdDFdt76w-r0-SiVQ01W4NEMxS
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

void ADC_init(){
	ADCSRA |= (1 << ADEN) | (1 << ADSC) | (1 << ADATE);
}

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFF; PORTB = 0x00;

	unsigned short sensor;
	const unsigned short MAX = 0x0380;

	ADC_init();
    /* Insert your solution below */
    while (1) {
	sensor = ADC;
	if(sensor >= MAX / 2){
		PORTB = 0x01;
	}
	else{
		PORTB = 0x00;
	}
    }
    return 1;
}
