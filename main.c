#include "main.h"
#include <stdio.h>

int main(void)
{
	int count;

	/* Test case 1: Single character */
	count = _printf("Character: %c\n", 'A');
	printf("Returned: %d\n", count); /* Compare with: Character: A */

	/* Test case 2: String */
	count = _printf("String: %s\n", "Hello");
	printf("Returned: %d\n", count); /* Compare with: String: Hello */

	/* Test case 3: Percent sign */
	count = _printf("Percent sign: %%\n");
	printf("Returned: %d\n", count); /* Compare with: Percent sign: % */

	/* Test case 4: Null string */
	count = _printf("Null string: %s\n", NULL);
	printf("Returned: %d\n", count); /* Compare with: Null string: (null) */

	/* Test case 5: Multiple specifiers */
	count = _printf("Multiple: %c %s %%\n", 'X', "Test");
	printf("Returned: %d\n", count); /* Compare with: Multiple: X Test % */

	/* Test case 6: Format specifier at end of string */
	count = _printf("End with percent %\n");
	printf("Returned: %d\n", count); /* Compare with: End with percent % */

	return 0;
}
