#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "variadic_functions.h"

/**
 * print_all - prints anything
 * @format: list of types of arguments passed to the function
 * c: char
 * i: integer
 * f: float
 * s: char * (if the string is NULL, print (nil) instead
 *    any other char should be ignored)
 */
void print_all(const char * const format, ...)
{
	va_list args;
	int i = 0, j;
	char *separator = "";
	char *str;

	va_start(args, format)

	while (format && format[i])
	{
		j = 1;
		switch (format[i])
		{
			case 'c':
				printf("%s%c", separator, va_arg(args, int));
				break;
			case 'i':
				printf("%s%d", separator, va_arg(args, int));
				break;
			case 'f':
				printf("%s%f", separator, va_arg(args, double));
				break;
			case 's':
				str = va_arg(args, char *);
				if (!str)
					str = "(nil)";
				printf("%s%s", separator, str);
				break;
			default:
				j = 0;
				break;
		}
		if (j && separator[0] != 0)
			separator = ", ";
		i++;
	}

	printf("\n");
	va_end(args);
}
