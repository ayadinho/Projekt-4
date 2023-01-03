
#ifndef HEADER_H_
#define HEADER_H_

#include "main.h"
#include "adc.h"
#include "timer.h"
#include "tmp36.h"
#include "serial.h"


/********************************************************************************
* extern: Detta definerar namn på de olika structar samt vad de skall göra
********************************************************************************/
extern timer_t timer0, timer1;
extern tmp36_t temp1;

void setup(void);




#endif /* HEADER_H_ */