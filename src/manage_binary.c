
#include "../inc/printers.h"

#define BINARY_BASE 2

int print_binary(t_handler *handler, va_list args)
{
	int chars_printed;
	uintmax_t value;
	char *result;
	size_t len;

	chars_printed = 0;
	value = manage_length_unsigned(va_arg(args, uintmax_t), handler->length);
	result = convert_base(value, BINARY_BASE, handler->specifier, UNSIGNED_NUM);
	len = ft_strlen(result) * check_null_value_and_prec(handler->precision, &result);
	chars_printed += print_value(handler, result, len, false);
	ft_strdel(&result);
	return (chars_printed);
}