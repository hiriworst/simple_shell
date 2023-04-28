#include "main.h"

/**
 *_puts - string_echos the output from the func
 *@out_put_line_string: ing to be printed
 *
 **/
void _puts(char *out_put_line_string)

{
	int digit_num;

	for (digit_num = 0 ; out_put_line_string[digit_num] != '\0' ; digit_num++)
	{
		_putchar(out_put_line_string[digit_num]);
	}
	_putchar('\n');
}
