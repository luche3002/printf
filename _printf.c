#include "main.h"
#include <unistd.h>
#include <stdarg.h>

int handle_format(char spec, va_list args);
int print_char(va_list args);
int print_string(va_list args);
int print_percent(void);
int print_number(int n);

/**
 * _printf - Custom printf function
 * @format: Format string
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, count = 0;

	va_start(args, format);
	while (format && format[i])
	{
		if (format[i] == '%')
		{
			i++;
			count += handle_format(format[i], args);
		}
		else
		{
			write(1, &format[i], 1);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}

/**
 * handle_format - Handles format specifiers
 * @spec: Format specifier character
 * @args: Argument list
 * Return: Number of characters printed
 */
int handle_format(char spec, va_list args)
{
	int count = 0;

	switch (spec)
	{
		case 'c':
			count += print_char(args);
			break;
		case 's':
			count += print_string(args);
			break;
		case '%':
			count += print_percent();
			break;
		case 'd':
		case 'i':
			count += print_number(va_arg(args, int));
			break;
		default:
			write(1, "%", 1);
			write(1, &spec, 1);
			count += 2;
	}
	return (count);
}

/**
 * print_char - Prints a character
 * @args: Argument list
 * Return: Number of characters printed
 */
int print_char(va_list args)
{
	char c = va_arg(args, int);

	return (write(1, &c, 1));
}

/**
 * print_string - Prints a string
 * @args: Argument list
 * Return: Number of characters printed
 */
int print_string(va_list args)
{
	char *str = va_arg(args, char *);
	int len = 0;

	if (str == NULL)
		str = "(null)";
	while (str[len])
		len++;
	return (write(1, str, len));
}

/**
 * print_percent - Prints a percent sign
 * Return: Number of characters printed
 */
int print_percent(void)
{
	return (write(1, "%", 1));
}

/**
 * print_number - Prints an integer number
 * @n: Number to print
 * Return: Number of characters printed
 */
int print_number(int n)
{
	char buffer[11];
	int len = 0;
	unsigned int num;
	unsigned int i;

	if (n < 0)
	{
		write(1, "-", 1);
		num = -n;
		len++;
	}
	else
	{
		num = n;
	}

	if (num == 0)
	{
		buffer[len++] = '0';
	}
	else
	{
		i = 1000000000;
		while (i > 0)
		{
			if (num >= i)
			{
				buffer[len++] = '0' + (num / i);
				num %= i;
			}
			i /= 10;
		}
	}

	return (write(1, buffer, len));
}
