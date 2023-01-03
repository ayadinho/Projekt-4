#ifndef SERIAL_H_
#define SERIAL_H_

#include "main.h"
/********************************************************************************
* serial_print_string: h�r har vi en pekare som g�r till v�ran text 
 stycke som skriver ut v�rat ord
********************************************************************************/
void serial_print_string(const char* s);


/********************************************************************************
* serial_print_integer: H�r skrivs det ut heltal 
********************************************************************************/
void serial_print_integer(const int32_t number);


/********************************************************************************
* serial_print_unsigned: Detta skriver ut positiva tal
********************************************************************************/
void serial_print_unsigned(const uint32_t number);


/********************************************************************************
* serial_print_double: H�r skrivs det ut flyttal till terminalen
********************************************************************************/
void serial_print_double(const double number);


/********************************************************************************
* serial_init: H�r �r det �verf�ring av hastigheten
********************************************************************************/
void serial_init(const uint32_t baud_rate_kbps);


/********************************************************************************
* serial_print_char: H�r skrivs det ut ett tecken till v�ran terminal
********************************************************************************/
void serial_print_char(const char c);





#endif /* SERIAL_H_ */