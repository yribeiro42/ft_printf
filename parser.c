/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 16:17:00 by yribeiro          #+#    #+#             */
/*   Updated: 2017/10/06 13:58:42 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"


char	*parse_flags(char **format, t_parser *p)
{
	if (**format == '-' || **format == '+' || **format == ' ' || **format == '#'
		|| **format == '0')
	{
		if (**format == '-')
			p->left_justify = 1;
		else if(**format == '+')
			p->sign = 1;
		else if(**format == ' ')
			p->space = 1;
		else if(**format == '#')
			p->htag = 1;
		else if (**format == '0')
			p->zero = 1;
		(*format)++;
		return (parse_flags(format, p));
	}
	return (*format);
}

char	*parse_width(char **format, t_parser *p)
{
	int ret;

	ret = 0;
	while (ft_isdigit(**format))
	{
		ret = ret * 10 + (**format - '0');
		(*format)++;
	}
	p->width = ret;
	return (*format);
}

char	*parse_precision(char **format, t_parser *p)
{
	int ret;

	ret = 0;
	if (**format == '.')
	{
		(*format)++;
		while (ft_isdigit(**format))
		{
			ret = ret * 10 + (**format - '0');
			(*format)++;
		}
	}
	p->precision = ret;
	return (*format);
}

char	*parse_length(char **format, t_parser *p)
{
	if (**format == 'l' && *(*format + 1) == 'l')
	{
		p->length = ll;
		*(*format) = *(*format + 2);
	}
	else if (**format == 'h' && *(*format + 1) == 'h')
	{
		p->length = hh;
		*(*format) = *(*format + 2);
	}
	else if (**format == 'h' || **format == 'l' || **format == 'j' || **format == 'z')
	{
		if (**format == 'h')
			p->length = h;
		else if (**format == 'l')
			p->length = l;
		else if (**format == 'j')
			p->length = j;
		else if (**format == 'z')
			p->length = z;
		return ((*format)++);
	}
	return (*format);
}
