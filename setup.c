#include "header.h"

timer_t timer0, timer1;
tmp36_t temp1;

static inline void init_ports(void)
{
	PORTB = (1 << BUTTON1);
	return;
}

/********************************************************************************
* PCICR: Här aktiveras det avbrott på våran PCINT0_vect
* PCMSK0: Här aktiveras avbrott på de de knapparna vi har valt 
********************************************************************************/
static inline void init_interrupts(void)
{
	PCICR = (1 << PCINT0); 
	PCMSK0 = (1 << BUTTON1); 
	return;
}


/********************************************************************************
* setup: Här initieras knapp med avbrott, Två timerkretsar med avbrott och 
		 temperaturmätaren
********************************************************************************/
void setup(void)
{
	tmp36_init(&temp1,PORTC2);
	
	init_ports();
	init_interrupts();
	
	timer_init(&timer0, TIMER_SEL_0, 300);
	
	timer_init(&timer1, TIMER_SEL_1, 60000);
	timer_enable_interrupt(&timer1);
	
	tmp36_temp_print(&temp1);
}