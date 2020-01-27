/*	Author: cwelt001
 *  Partner(s) Name: Christian Lee
 *	Lab Section:
 *	Assignment: Lab #5  Exercise #1
 *	Exercise Description: [optional - include for your own benefit]
 *
 *	I acknowledge all content contained herein, excluding template or example
 *	code, is my own original work.
 */
#include <avr/io.h>
#ifdef _SIMULATE_
#include "simAVRHeader.h"
#endif

unsigned char GetBit(unsigned char x, unsigned char k) {
	return ((x & (0x01 << k)) != 0);
}
unsigned char SetBit(unsigned char x, unsigned char k, unsigned char b) {
	return (b ? x | (0x01 << k) : x & ~(0x01 << k));
}

int main(void) {
    /* Insert DDR and PORT initializations */
	DDRA = 0x00; PORTA = 0xFF; // DDR: (1 for output, 0 for input) 
	DDRC = 0xFF; PORTC = 0x00; // PORT used for writing, PIN used for reading
	
	unsigned char tank;
	unsigned char tmp = 0x00;
    /* Insert your solution below */
    while (1) {
		tank = PINA & 0x0F;
			
			if((tank == 0x01) || (tank == 0x02)){
				tmp = 0x60;
			}
			else if ((tank == 0x03) || (tank == 0x04)){
				tmp = 0x70;
			}
			else if ((tank == 0x05) || (tank == 0x06)){
				tmp = 0x38;
			}
			else if ((tank == 0x07) || (tank == 0x08) || (tank == 0x09)){
				tmp = 0x3C;
			}
			else if ((tank == 0x0A) || (tank == 0x0B) || (tank == 0x0C)){
				tmp = 0x3E;
			}
			else if ((tank == 0x0D) || (tank == 0x0E) || (tank == 0x0F)){
				tmp = 0x3F;
			}
			PORTC = tmp;
    }
    return 1;
}
