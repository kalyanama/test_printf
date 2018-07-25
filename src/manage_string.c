/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalanch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 16:14:35 by mmalanch          #+#    #+#             */
/*   Updated: 2018/07/06 16:14:36 by mmalanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/printers.h"

static char	*get_char(const int code, char *buffer)
{
	if (code == 8)
		ft_strcpy(buffer, "BS");
	else if (code == 9)
		ft_strcpy(buffer, "\\t");
	else if (code == 10)
		ft_strcpy(buffer, "\\n");
	else if (code == 13)
		ft_strcpy(buffer, "CR");
	else if (code == 32)
		ft_strcpy(buffer, "ESC");
	else if (code >= 0 && code < 32)
	{
		buffer[0] = '^';
		buffer[1] = (char)('@' + code);
	}
	else
		buffer[0] = (char)code;
	return (buffer);
}

char		*show_non_printable(const char *str)
{
	char *buf;
	char *new;
	char *to_free;

	new = ft_strnew(0);
	buf = ft_strnew(3);
	while (*str)
	{
		to_free = new;
		new = ft_strjoin(new, get_char(*str, buf));
		str++;
		ft_strclr(buf);
		ft_strdel(&to_free);
	}
	ft_strdel(&buf);
	return (new);
}

char		*get_wstr(wchar_t *value, int precision)
{
	char *res;
	char *to_free_res;
	char *wchar;
	char *to_free_wchar;

	if (!value)
		return (NULL);
	res = ft_strnew(0);
	while (*value)
	{
		to_free_res = res;
		wchar = get_wchar(*value);
		to_free_wchar = wchar;
		if (precision != -1)
		{
			precision -= ft_strlen(wchar);
			if ((precision < 0))
			{
				ft_strdel(&to_free_wchar);
				break ;
			}
		}
		res = ft_strjoin(res, wchar);
		ft_strclr(wchar);
		ft_strdel(&to_free_res);
		ft_strdel(&to_free_wchar);
		value++;
	}
	return (res);
}

int			print_string(t_handler *h, va_list args, bool non_printable)
{
	int		chars_printed;
	char	*value;
	size_t	len;
	bool	is_cut;

	chars_printed = 0;
	is_cut = false;
	if (h->length == L && (h->specifier == STRING || h->specifier == CHAR))
		value = (h->specifier == STRING ?
			get_wstr(va_arg(args, wchar_t *), h->precision) :
			get_wchar(va_arg(args, wchar_t)));
	else
	{
		value = va_arg(args, char *);
		value = non_printable ? show_non_printable(value) : value;
	}
	if ((is_cut = (value == NULL && h->precision)))
		value = ft_strndup("(null)", h->precision == -1 ?
			ft_strlen("(null)") : h->precision);
	if (ft_strequ(value, "\0") && h->specifier == CHAR)
		return (int)write(STDOUT_FILENO, "\0", 1);
	len = value ? ft_strlen(value) : 0;
	h->precision *= len != 0;
	if (h->precision != -1 && h->precision < (int)len
		&& !is_cut && !(h->specifier == CHAR))
	{
		value = ft_strndup(value, h->precision);
		len -= len - h->precision;
		is_cut = true;
	}
	else
		h->precision = -1;
	chars_printed += print_value(h, value, len, false);
	if (is_cut || non_printable || h->length == L)
		ft_strdel(&value);
	return (chars_printed);
}

//Error (line 57): function get_wstr has 29 lines
//Error (line 90): function print_string has 36 lines