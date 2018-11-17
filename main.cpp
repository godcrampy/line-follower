

/*
 */
#define F_CPU 1000000
#include <avr/io.h>
#include <avr/sfr_defs.h>
#include <stdio.h>
#include <util/delay.h>

//  LEFT MOTOR IS PIN C 1 & 2
//  RIGHT MOTOR IS PIN 3  &  4
int previousPosition = 1;
int isPin(int n)
{
    return bit_is_clear(PINA,n);//returns true if there is white line under
}
void turnLeft(){
		PORTD=0b00100000;//D5
		//PORTD|=(1<<5);
		//PORTD&=~(1<<2 | 1<<3 | 1<<4);
	previousPosition=0;
}
void turnRight(){
		PORTD=0b00000100;
		//PORTD|=(1<<2);
		//PORTD&=~(1<<5 | 1<<3  |1<<4);
	previousPosition=2;
	
}
void moveForward(){
	  PORTD=0b00100100;
	 // PORTD|=(1<<2 | 1<<5);
	 // PORTD&=~(1<<3 | 1<<4);
	  previousPosition=1;        
}
void blank(){
	if(previousPosition=0)
		{turnLeft();}
	else if(previousPosition=2)
		{turnRight();}
	else
		{moveForward();}	
}

void stop()
{
	PORTD = 0x00;//&=~(1<<2 | 1<<5 | 1<<3 | 1<<4);
}
int main()

{
    DDRA=0x00;
    DDRD=0xFF;
	char memory;
	
    while(1)
    {
		
	
		
		if(!bit_is_clear(PINA,1) && !bit_is_clear(PINA,2) && !bit_is_clear(PINA,3))
		{
			if(memory=='r')
			PORTD=0b00100000;
			else if(memory=='l')
			PORTD=0b00000100;
			else
			PORTD=0b00100100;
		}			
		else if(bit_is_clear(PINA,1) && bit_is_clear(PINA,2) && !bit_is_clear(PINA,3))
			{
				 //right
				memory= 'r';
				PORTD=0b00100000;
			}
		else if(!bit_is_clear(PINA,1) && bit_is_clear(PINA,2) && bit_is_clear(PINA,3))
			{
				 //left
				 memory='l';
				PORTD=0b00000100;
			}
		else if(!bit_is_clear(PINA,1) && bit_is_clear(PINA,2) && !bit_is_clear(PINA,3))
			{
				PORTD=0b00100100; //forward
				memory='f';
			}
		else if(bit_is_clear(PINA,1) && !bit_is_clear(PINA,2) && !bit_is_clear(PINA,3))
			{
				 //right
				memory='r';
				PORTD=0b00100000;
			}
		else if(!bit_is_clear(PINA,1) && !bit_is_clear(PINA,2) && bit_is_clear(PINA,3))
			{
				memory='l';
				PORTD=0b00000100;
				 //left
			}

		else if(bit_is_clear(PINA,1) && bit_is_clear(PINA,2) && bit_is_clear(PINA,3))
				{
					PORTD=0x00;
				}
			
	}
    return 0;
}