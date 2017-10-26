/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 12:03:28 by yribeiro          #+#    #+#             */
/*   Updated: 2017/10/26 21:50:06 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_copyuntil(char *str, char until)
{
	while (*str && *str != until)
	{
		ft_putchar(*str);
		str++;
	}
}

int		parser(char **lookup, t_parser *p)
{
	(*lookup)++;
	parse_flags(lookup, p);
	parse_width(lookup, p);
	parse_precision(lookup, p);
	parse_length(lookup, p);
	parse_specifier(lookup, p);
	if (p->left)
		p->zero = 0;
	if (p->showsign)
		p->space = 0;
	return (0);
}

int		process(va_list *args, char *format)
{
	t_parser	p;
	int			ret;
	int			chrs;

	chrs = 0;
	ret = 0;
	while (*format != '\0')
	{
		if (*format == '%')
		{
			ft_bzero(&p, sizeof(t_parser));
			parser(&format, &p);
			ret += get_specifier(&p, &args);
		}
		else
		{
			ft_putchar(*format);
			chrs++;
		}
		format++;
	}
	return (ret + chrs);
}

int		ft_printf(char *format, ...)
{
	int			ret;
	va_list		args;

	va_start(args, format);
	ret = process(&args, format);
	printf("(%d)\n", ret);
	va_end(args);
	return (ret);
}
