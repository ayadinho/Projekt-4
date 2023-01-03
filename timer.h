#ifndef TIMER_H_
#define TIMER_H_

#include "main.h"


typedef enum
{
	TIMER_SEL_0,
	TIMER_SEL_1, 
	TIMER_SEL_NONE 

}timer_sel_t;


/*************************************************************************************************
*volatile uint32_t counter: H�r har vi en r�knare som r�knar upp till 32-bitar

*uint32_t max_count: Detta �r v�rat max v�rde som v�r uppr�kning ska g� upp till 

*volatile uint8_t* timsk: Detta �r pekare till maskregister som ska g�ra en aktivering f�r avbrott

*uint8_t timsk_bit: avbrott i maskregistert som mostvarar en bit i aktivering av avbrott

*timer_sel_t timer_sel_t: Timerkrets vi har valt
***************************************************************************************************/
typedef struct
{
	volatile uint32_t counter; 
	uint32_t max_count;		   
	volatile uint8_t* timsk;   
	uint8_t timsk_bit;		   
	timer_sel_t	timer_sel_t;   
	
} timer_t;

/********************************************************************************
*timer_interrupt_enabled: H�r kollar den ifall avbrottet �r aktiverat eller inte
********************************************************************************/
static inline bool timer_interrupt_enabled(const timer_t* self)
{
	return (*(self->timsk) & (1 << self->timsk_bit));
}
/********************************************************************************
* timer_elapsed: N�r r�knaren r�knat till max s� nollst�lls det genom att kolla
om det var true eller false
********************************************************************************/
bool timer_elapsed(timer_t* self);



static inline void timer_reset_counter(timer_t* self)
{
	self->counter = 0;
	return;
}


void timer_reset(timer_t* self);


void timer_get_new_time_ms(timer_t* self, const double time_ms);


static inline void timer_get_new_max_count(timer_t* self, const uint32_t max_count)
{
	self->max_count = max_count;
	return;
}



/********************************************************************************
* timer_init: Initering av timerkrets som m�ts i millisekunder 
********************************************************************************/
void timer_init(timer_t* self, const timer_sel_t timer_sel_t, const double time_ms);

/********************************************************************************
* timer_clear: Detta nollst�ller v�ran timer
********************************************************************************/
void timer_clear(timer_t* self);

/********************************************************************************
* timer_enable_interrupt: Aktiverar avbrott n�r r�knaren f�tt en s� kallad overflow
eller n�r den har r�knat upp till sitt tal
********************************************************************************/
static inline void timer_enable_interrupt(timer_t* self)
{
	asm("SEI");
	*(self->timsk) |= (1 << self->timsk_bit);
	return;
}

/********************************************************************************
* timer_disable_interrupt: H�r inaktiverar vi avbrott
********************************************************************************/
static inline void timer_disable_interrupt(timer_t* self)
{
	*(self->timsk) &= ~(1 << self->timsk_bit);
}

/********************************************************************************
* timer_count: H�r r�knas v�ran angivna tid
********************************************************************************/
static inline void timer_count(timer_t* self)
{
	self->counter++;
	return;
}





#endif /* TIMER_H_ */