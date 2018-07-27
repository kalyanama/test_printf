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
		ft_strcpy(buffer, "ESC"); //space == ESC
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

	if (!str)
		return (NULL);
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
static bool precision_cut(char *src, char **dest, int prec)
{
	if (prec < 0 || prec >= (int)ft_strlen(src))
	{
		*dest = src;
		return (0);
	}
	*dest = ft_strnew((size_t)prec);
	if (*dest)
		ft_strncpy(*dest, src, (size_t)prec);
	return (1);
}

int print_string(t_handler *h, va_list args)
{
	int		chars_printed;
	char	*value;
	bool	is_cut;
	char 	*to_free;

	chars_printed = 0;
	to_free = NULL;
	if (h->length == L && h->sp == 's')
		value = get_wstr(va_arg(args, wchar_t *), h->prec);
	else
		value = va_arg(args, char *);
	if (h->sp == 'r')
		value = show_non_printable(value);
	if (value == NULL)
	{
		value = ft_strdup("(null)");
		if (!(h->prec < 0 || h->prec >= (int)ft_strlen(value)))
			to_free = value;
	}
	is_cut = precision_cut(value, &value, h->prec);
	h->prec = -1;
	chars_printed += print_value(h, value, ft_strlen(value), false);
	if (to_free)
		ft_strdel(&to_free);
	if (is_cut || h->sp == 'r' || h->length == L)
		ft_strdel(&value);
	return (chars_printed);
}

//Error (line 57): function get_wstr has 29 lines
//Error (line 90): function print_string has 36 lines