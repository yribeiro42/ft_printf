/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 16:17:00 by yribeiro          #+#    #+#             */
/*   Updated: 2017/10/03 17:15:31 by anonymous        ###   ########.fr       */
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
}

char	*parse_precision(char **format, t_parser *p)
{
	int ret;

	ret = 0;
	
}
