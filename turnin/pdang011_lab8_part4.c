/*	Author: Patrick Dang
 *  	Partner(s) Name: 
 *	Lab Section: 028
 *	Assignment: Lab #8  Exercise #2
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 *
 *	Video Link: https://drive.google.com/open?id=18fvE2-aPCNcie-WjEK1Sl7T9uYiItEWI
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
	unsigned char LED;
	const unsigned short MAX = 0x0380;

	ADC_init();
    /* Insert your solution below */
    while (1) {
	    sensor = ADC;

	    if(sensor < (MAX / 8)){
		LED = 0x01;
	    }
	    else if(sensor < (MAX / 4)){
		LED = 0x03;
	    }
	    else if(sensor < (MAX / 8) * 3){
		LED = 0x07;
	    }
	    else if(sensor < (MAX / 2)){
		LED = 0x0F;
	    }
	    else if(sensor < (MAX / 8) * 5){
		LED = 0x1F;
	    }
	    else if(sensor < (MAX / 4) * 3){
		LED = 0x3F;
	    }
	    else if(sensor < (MAX / 8) * 7){
		LED = 0x7F;
	    }
	    else if(sensor <= MAX){
		LED = 0xFF;
	    }
	    PORTB = LED;
    }
    return 1;
}
