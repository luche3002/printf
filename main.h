#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

/* Custom printf function */
int _printf(const char *format, ...);

/* Functions to handle specific format specifiers */
int print_char(va_list args);
int print_string(va_list args);
int print_percent(void);
int print_integer(va_list args);  /* Declaration for handling %d and %i */

#endif /* MAIN_H */
