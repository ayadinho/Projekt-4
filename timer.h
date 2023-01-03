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
*volatile uint32_t counter: Här har vi en räknare som räknar upp till 32-bitar

*uint32_t max_count: Detta är vårat max värde som vår uppräkning ska gå upp till 

*volatile uint8_t* timsk: Detta är pekare till maskregister som ska göra en aktivering för avbrott

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
*timer_interrupt_enabled: Här kollar den ifall avbrottet är aktiverat eller inte
********************************************************************************/
static inline bool timer_interrupt_enabled(const timer_t* self)
{
	return (*(self->timsk) & (1 << self->timsk_bit));
}
/********************************************************************************
* timer_elapsed: När räknaren räknat till max så nollställs det genom att kolla
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
* timer_init: Initering av timerkrets som möts i millisekunder 
********************************************************************************/
void timer_init(timer_t* self, const timer_sel_t timer_sel_t, const double time_ms);

/********************************************************************************
* timer_clear: Detta nollställer våran timer
********************************************************************************/
void timer_clear(timer_t* self);

/********************************************************************************
* timer_enable_interrupt: Aktiverar avbrott när räknaren fått en så kallad overflow
eller när den har räknat upp till sitt tal
********************************************************************************/
static inline void timer_enable_interrupt(timer_t* self)
{
	asm("SEI");
	*(self->timsk) |= (1 << self->timsk_bit);
	return;
}

/********************************************************************************
* timer_disable_interrupt: Här inaktiverar vi avbrott
********************************************************************************/
static inline void timer_disable_interrupt(timer_t* self)
{
	*(self->timsk) &= ~(1 << self->timsk_bit);
}

/********************************************************************************
* timer_count: Här räknas våran angivna tid
********************************************************************************/
static inline void timer_count(timer_t* self)
{
	self->counter++;
	return;
}





#endif /* TIMER_H_ */