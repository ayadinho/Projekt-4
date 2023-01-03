#include "main.h"
#ifndef ADC_H_
#define ADC_H_

typedef struct
{
	uint8_t pin;
	uint16_t adc_on_us;
	uint16_t adc_off_us;
	
} adc_t;


/********************************************************************************
* adc_init: Här visar det vad self pekar på när man definerar den
********************************************************************************/
void adc_init(adc_t* self, const uint8_t pin);


/********************************************************************************
* adc_duty_cycle: Här räknas det hur mycket ström som ska gå ut
********************************************************************************/
double adc_duty_cycle(adc_t* self);



uint16_t adc_read(adc_t* self);


void adc_get_values(adc_t* self, const uint16_t period_us);



#endif /* ADC_H_ */