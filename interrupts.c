#include "header.h"

/********************************************************************************
* ISR: Alla interrupts som behövs för för tempsensor och knappen så de fungerar
* PCICR: De övriga bitar som vi bibehåller
* TIMSK0: Här sätts en timer från 0 till 300 ms
*tmp36_temp_print: Mäter våran temperatur
*timer_reset_counter: Nollställer våran timer 1  
********************************************************************************/

ISR(PCINT0_vect)
{
	PCICR &= ~(1 << PCIE0);
	TIMSK0 = (1 << TOIE0);
	
	
	if(BUTTON1_IS_PRESSED)
	{
		tmp36_temp_print(&temp1);
		timer_reset_counter(&timer1);
	}
	return;
}

ISR (TIMER0_OVF_vect)
{
	timer_count(&timer0);
	
	if (timer_elapsed(&timer0))
	{
		PCICR |= (1 << PCIE0);
		timer_disable_interrupt(&timer0);
	}
}

ISR (TIMER1_COMPA_vect)
{
	timer_count(&timer1);

	if (timer_elapsed(&timer1))
	{
		tmp36_temp_print(&temp1);
	}

	return;
}