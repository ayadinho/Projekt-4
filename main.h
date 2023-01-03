#ifndef MAIN_H_
#define MAIN_H_

/********************************************************************************
* F_CPU: Klockfrkevensen, 16MHz
********************************************************************************/
#define F_CPU 16000000UL 

/********************************************************************************
* De biblotek som har anv�nds
********************************************************************************/
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/********************************************************************************
 BUTTON1: V�ran kanpp som �r inst�lld till PORTB5
 TMP36: V�ran temperatur sensor som �r inst�lld till PORTC2
********************************************************************************/
#define BUTTON1 PORTB5
#define TMP36 PORTC2

#define BUTTON1_IS_PRESSED (PINB & (1 << BUTTON1))

/********************************************************************************
*TIMER_INTERRUPT_MS: Tiden som �r mellan varje avbrott
********************************************************************************/
#define TIMER_INTERRUPT_MS 0.128 

#define set(reg, bit) reg |= (1 << bit)
#define clr(reg, bit) reg &= ~(1 << bit)
#define read(reg, bit) (reg & (1 << bit))

extern volatile bool timer1_enable;


#endif /* MAIN_H_ */