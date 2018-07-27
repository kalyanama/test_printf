#include "../inc/printers.h"
static ssize_t			length_signed(ssize_t val, t_length length)
{
	if (length == HH)
		return ((signed char)val);
	else if (length == H)
		return ((short)val);
	else if (length == L)
		return ((long)val);
	else if (length == LL)
		return ((long long)val);
	else if (length == J)
		return ((intmax_t)val);
	else if (length == Z)
		return ((ssize_t)val);
	else
		return ((int)val);
}

static size_t			length_unsigned(size_t val, t_length length)
{
	if (length == HH)
		return ((unsigned char)val);
	else if (length == H)
		return ((unsigned short)val);
	else if (length == L)
		return ((unsigned long)val);
	else if (length == LL)
		return ((unsigned long long)val);
	else if (length == J)
		return ((uintmax_t)val);
	else if (length == Z)
		return ((size_t)val);
	else
		return ((unsigned)val);
}

static int get_base(char specifier)
{
	if (specifier == 'b')
		return (2);
	else if (specifier == 'o')
		return (8);
	else if (specifier == 'u')
		return (10);
	else if (specifier == 'x' || specifier == 'X' || specifier == 'p')
		return (16);
	else
		return (-1);
}

int	print_num_signed(t_handler *h, va_list args)
{
	int			chars_printed;
	char		*result;
	ssize_t		value;
	size_t		len;

	chars_printed = 0;
	value = length_signed(va_arg(args, ssize_t), h->length);
	result = convert_base((size_t)value,
						  DECIMAL_BASE, false, SIGNED_NUM);
	len = ft_strlen(result) * check_val_prec(h->prec, &result);
	h->flags.force_sign = h->flags.force_sign || value < 0;
	chars_printed += print_value(h, result, len, value < 0);
	ft_strdel(&result);
	return (chars_printed);
}

int print_num_unsigned(t_handler *handler, va_list args)
{
	int		chars_printed;
	char	*result;
	size_t	value;
	size_t	len;

	chars_printed = 0;
	value = length_unsigned(va_arg(args, size_t), handler->length);
	result = convert_base(value, get_base(handler->sp), handler->sp == 'X', UNSIGNED_NUM);
	len = ft_strlen(result) * check_val_prec(handler->prec, &result);
	if (handler->sp == 'o')
	{
			handler->flags.hash *= !(value == 0 && handler->prec);
			handler->flags.hash *= (handler->prec <= (int)len);
	}
	if (handler->sp == 'x' || handler->sp == 'X')
		handler->flags.hash *= value != 0;
	if(handler->sp == 'p')
		handler->flags.hash = true;
	chars_printed += print_value(handler,result, len, false);
	if (result)
		ft_strdel(&result);
	return (chars_printed);
}