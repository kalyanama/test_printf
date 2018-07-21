
#include "../inc/printers.h"

size_t get_numlen(size_t usigned_num, short base, bool is_unsigned)
{
	size_t len;
	ssize_t signed_num;

	signed_num = (ssize_t)usigned_num;
	len = 1;
	if (is_unsigned)
		while (usigned_num /= base)
			len++;
	else
		while (signed_num /= base)
			len++;
	return (len);
}

void print_num(size_t unsigned_num, bool is_unsigned)
{
	ssize_t signed_num;

	signed_num = (ssize_t)unsigned_num;
	if (is_unsigned) {
		if (unsigned_num / 10)
			print_num(unsigned_num / 10, is_unsigned);
		ft_putchar((char)(unsigned_num % 10 + '0'));
	}
	else
	{
//        if (*sign)
//            signed_num < 0 ? ft_putchar('-') : ft_putchar('+');
		if (signed_num / 10)
			print_num((size_t)(signed_num / 10), is_unsigned);
		ft_putchar((char)(FT_ABS(signed_num % 10) + '0'));
	}
}

int print_width(t_handler *h, size_t value_len) {
	int chars;

	chars = 0;
	if (h->precision > (int)value_len)
		value_len += h->precision - value_len;
	//TODO needed ?
	value_len += h->flags.space_flag;
	value_len += h->flags.force_sign && h->specifier == S_DECIMAL;
	value_len += h->flags.hash && h->specifier == OCTAL;
	value_len += ((h->specifier == HEX_LOWER || h->specifier == HEX_UPPER) && h->flags.hash) * 2;
	if(h->specifier != CHAR && h->specifier !=INVALID_SPECIFIER)
		h->flags.pad_zero =
			(h->precision == -1 && h->flags.pad_zero && !h->flags.pad_right);
	while(h->width > value_len)
	{
		ft_putchar((char) (h->flags.pad_zero ? '0' : ' '));
		chars++;
		h->width--;
	}
	return (chars);
}

int     print_precision(int prec, size_t value_len)
{
	int chars;

	chars = 0;
	while(prec > (int)value_len)
	{
		ft_putchar('0');
		chars++;
		prec--;
	}
	return (chars);
}

ssize_t manage_length_signed(ssize_t val, t_length length)
{
	if (length == HH)
		return ((char)val);
	else if (length == H)
		return ((short) val);
	else if (length == L)
		return ((long)val);
	else if (length == LL)
		return ((long long) val);
	else if (length == J)
		return ((intmax_t)val);
	else if (length == Z)
		return ((ssize_t)val);
	else
		return ((int)val);
}

size_t manage_length_unsigned(size_t val, t_length length)
{
	if (length == HH)
		return ((unsigned char)val);
	else if (length == H)
		return ((unsigned short) val);
	else if (length == L)
		return ((unsigned long)val);
	else if (length == LL)
		return ((unsigned long long) val);
	else if (length == J)
		return ((uintmax_t)val);
	else if (length == Z)
		return ((size_t)val);
	else if (length == DEFAULT_LENGTH)
		return ((unsigned)val);
	else
		return (val);
}
//TODO add to libft
char *convert_base(size_t unsgnd, int base, t_specifier specifier, bool is_unsigned)
{
	char	*ret;
	size_t		len;
	char    a;
	ssize_t sgnd;

	a = (char) (specifier == HEX_LOWER ? 'a' : 'A');
	if (base < 2 || base > 16)
		return (NULL);
	len = get_numlen(unsgnd, (short) base, is_unsigned);
	if(!(ret = ft_strnew(len + 1)))
		return(NULL);
	sgnd = (ssize_t)unsgnd;
	if (is_unsigned)
		while (len--)
		{
			ret[len] = (char) (unsgnd % base + (unsgnd % base < 10 ? '0' : a - 10));
			unsgnd /= base;
		}
	else
		while (len--)
		{
			ret[len] = (char) (FT_ABS(sgnd % base) + '0');
			sgnd /= base;
		}
	return(ret);
}

bool check_null_value_and_prec(int prec, char **result)
{
	if (prec == 0 && ft_strequ(*result, ZERO))
	{
		ft_strdel(result);
		return false;
	}
	return true;
}


int print_prefix(t_handler *h, bool neg_sign)
{
	if (h->flags.hash)
	{
		if (h->specifier == OCTAL)
		{
			ft_putchar('0');
			return (1);
		}
		if (h->specifier == HEX_LOWER || h->specifier == HEX_UPPER)
		{
			ft_putchar('0');
			ft_putchar((char)(h->specifier == HEX_LOWER ? 'x' : 'X'));
			return (2);
		}
	}
	if (h->flags.force_sign && h->specifier == S_DECIMAL)
	{
		if (neg_sign)
			ft_putchar('-');
		else
			ft_putchar('+');
		return (1);
	}
	return (0);
}

int print_value(t_handler *h, char *result, size_t len, bool neg_sign)
{
	int chars_printed;

	chars_printed = 0;
	chars_printed += (int) len;
	if(h->flags.pad_right)
	{
		chars_printed += print_prefix(h, neg_sign);
		chars_printed += print_precision(h->precision, len);
		ft_putstr(result);
		chars_printed += print_width(h, len);
	}
	else
	{
		chars_printed += h->flags.pad_zero ? print_prefix(h, neg_sign) : 0;
		chars_printed += print_width(h, len);
		chars_printed += h->flags.pad_zero ? 0 : print_prefix(h, neg_sign);
		chars_printed += print_precision(h->precision, len);
		ft_putstr(result);
	}
	return (chars_printed);
}

//TODO add to libft
char	*ft_strndup(const char *src, size_t size)
{
	char	*dest;

	dest = ft_strnew(size);
	if (dest)
		ft_strncpy(dest, src, size);
	return (dest);
}
//TODO add to libft
unsigned int count_bits(unsigned int value)
{
	unsigned int count;

	if (value == 0)
		return (1);
	count = 0;
	while (value)
	{
		value >>= 1;
		count++;
	}
	return (count);
}

inline int cmp_len(t_length curr, t_length new)
{
	return (new - curr);
}