
#include "../inc/printers.h"

size_t			get_numlen(size_t usigned_num, int base, bool is_unsigned)
{
	size_t	len;
	ssize_t	signed_num;

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

void			print_num(size_t unsigned_num, bool is_unsigned)
{
	ssize_t signed_num;

	signed_num = (ssize_t)unsigned_num;
	if (is_unsigned)
	{
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

//TODO add to libft

char			*convert_base(size_t unsgnd, int base,
                              bool upper_case, bool is_unsigned)
{
	char	*ret;
	size_t	len;
	char	a;
	ssize_t	sgnd;

	a = (char)(upper_case ? 'A' : 'a');
	if (base < 2 || base > 16)
		return (NULL);
	len = get_numlen(unsgnd, base, is_unsigned);
	if (!(ret = ft_strnew(len + 1)))
		return (NULL);
	sgnd = (ssize_t)unsgnd;
	if (is_unsigned)
		while (len--)
		{
			ret[len] = (char)(unsgnd % base +
								(unsgnd % base < 10 ? '0' : a - 10));
			unsgnd /= base;
		}
	else
		while (len--)
		{
			ret[len] = (char)(FT_ABS(sgnd % base) + '0');
			sgnd /= base;
		}
	return (ret);
}

bool			check_val_prec(int prec, char **result)
{
	if (prec == 0 && ft_strequ(*result, ZERO))
	{
		ft_strdel(result);
		return (false);
	}
	return (true);
}

//TODO add to libft

char			*ft_strndup(const char *src, size_t size)
{
	char	*dest;

	dest = ft_strnew(size);
	if (dest)
		ft_strncpy(dest, src, size);
	return (dest);
}

//TODO add to libft

unsigned int	count_bits(unsigned int value)
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

int				cmp_len(t_length curr, t_length new)
{
	return (new - curr);
}

// Error: 42 header not at top of the file
// Error: 9 functions in the file
// Error (line 81): function convert_base has 26 lines
