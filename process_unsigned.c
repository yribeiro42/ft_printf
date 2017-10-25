/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 17:26:51 by yribeiro          #+#    #+#             */
/*   Updated: 2017/10/25 22:28:05 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

long long	get_unumber_length(t_parser *p, va_list **args)
{
	long number;

	number = va_arg(**args, long long);
	if (p->length == HH)
		number = (char)number;
	else if (p->length == H)
		number = (short)number;
	else if (p->length == L)
		number = (long)number;
	else if (p->length == LL)
		number = (long long)number;
	else if (p->length == J)
		number = (intmax_t)number;
	else if (p->length == Z)
		number = (size_t)number;
	else if (p->length == DEFAULT)
		number = (unsigned int)number;
	return (number);
}

int		process_unsigned(t_parser *p, va_list **args)
{
	intmax_t	number;
	char		*retnbr;

	number = get_unumber_length(p, args);
	retnbr = ft_itoa(number);
	if (p->precision)
		process_precision(&retnbr, p);
	if (p->left)
		process_left(&retnbr, p);
	if (p->width && p->zero)
		process_zero(&retnbr, p);
	if (p->width)
		process_width(&retnbr, p);
	ft_putstr(retnbr);
	return (ft_strlen(retnbr));
}
