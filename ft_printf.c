/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 17:00:55 by yribeiro          #+#    #+#             */
/*   Updated: 2017/10/06 16:17:34 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

// %[flags][width][.precision][length]specifier

int		parser(char **format, t_parser *p)
{
	int		ret;
	if ((*(*format + 1)) == '\0')
		return (0);
	parse_flags(format, p);
	parse_width(format, p);
	parse_precision(format, p);
	parse_length(format, p);
	parse_specifier(format, p);
	return (0);
}

int 	process(va_list *args, char *format, size_t ret)
{
	char		*lookup;
	t_parser	p;

	lookup = ft_strchr(format, '%');
	if (*format == '\0')
		return (ret);
	if (!*lookup)
	{
		ft_putstr(format);
		return (ft_strlen(format));
	}
	else
	{
		ft_bzero(&p, sizeof(p));
		parser(&format, &p);
		return (process(args, format, ret));
	}
}

int		ft_printf(char *format, ...)
{
	int		size;

	va_list args;

	va_start(args, format);
	size = process(&args, format, 0);
	va_end(args);
	return (size);
}
