#include "main.h"
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

int handle_format(char spec, va_list args);
int print_char(va_list args);
int print_string(va_list args);
int print_percent(void);
int print_number(int n);
int print_binary(va_list args);

/**
 * _printf - Custom printf function
 * @format: Format string
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, count = 0;

	if (!format)
		return (-1);

	va_start(args, format);
	while (format && format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (!format[i])
				return (-1);
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
		case 'b':
			count += print_binary(args);
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

	if (!str)
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
 * print_number - Prints an integer
 * @n: Number to print
 * Return: Number of characters printed
 */
int print_number(int n)
{
	char buffer[32];
	int i = 0, j, count = 0;
	unsigned int num;

	if (n == 0)
		return (write(1, "0", 1));

	if (n < 0)
	{
		write(1, "-", 1);
		num = -n;
		count++;
	}
	else
	{
		num = n;
	}

	while (num > 0)
	{
		buffer[i++] = '0' + (num % 10);
		num /= 10;
	}

	for (j = i - 1; j >= 0; j--)
	{
		write(1, &buffer[j], 1);
		count++;
	}

	return (count);
}

/**
 * print_binary - Prints an unsigned int in binary
 * @args: Argument list
 * Return: Number of characters printed
 */
int print_binary(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	char buffer[32];
	int i = 0, j, count = 0;

	if (n == 0)
		return (write(1, "0", 1));

	while (n > 0)
	{
		buffer[i++] = '0' + (n % 2);
		n /= 2;
	}

	for (j = i - 1; j >= 0; j--)
	{
		write(1, &buffer[j], 1);
		count++;
	}

	return (count);
}
