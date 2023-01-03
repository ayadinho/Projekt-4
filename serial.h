#ifndef SERIAL_H_
#define SERIAL_H_

#include "main.h"
/********************************************************************************
* serial_print_string: här har vi en pekare som går till våran text 
 stycke som skriver ut vårat ord
********************************************************************************/
void serial_print_string(const char* s);


/********************************************************************************
* serial_print_integer: Här skrivs det ut heltal 
********************************************************************************/
void serial_print_integer(const int32_t number);


/********************************************************************************
* serial_print_unsigned: Detta skriver ut positiva tal
********************************************************************************/
void serial_print_unsigned(const uint32_t number);


/********************************************************************************
* serial_print_double: Här skrivs det ut flyttal till terminalen
********************************************************************************/
void serial_print_double(const double number);


/********************************************************************************
* serial_init: Här är det överföring av hastigheten
********************************************************************************/
void serial_init(const uint32_t baud_rate_kbps);


/********************************************************************************
* serial_print_char: Här skrivs det ut ett tecken till våran terminal
********************************************************************************/
void serial_print_char(const char c);





#endif /* SERIAL_H_ */