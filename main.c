#include "main.h"
#include <stdio.h>

int main(void)
{
	int count;

	/* Test case for printing a character */
	count = _printf("Character: %c\n", 'A');
	printf("Printf returned: %d\n", count);

	/* Test case for printing a string */
	count = _printf("String: %s\n", "Hello, World!");
	printf("Printf returned: %d\n", count);

	/* Test case for printing a percent sign */
	count = _printf("Percent sign: %%\n");
	printf("Printf returned: %d\n", count);

	/* Test case for printing an integer (decimal) */
	count = _printf("Integer: %d\n", 123);
	printf("Printf returned: %d\n", count);

	/* Test case for printing an integer (hexadecimal) */
	count = _printf("Hexadecimal: %i\n", 456);
	printf("Printf returned: %d\n", count);

	/* Test case for printing a null string */
	count = _printf("Null string: %s\n", NULL);
	printf("Printf returned: %d\n", count);

	return (0);
}
