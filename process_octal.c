/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_octal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yribeiro <yribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 16:26:31 by yribeiro          #+#    #+#             */
/*   Updated: 2017/10/26 13:04:11 by yribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

unsigned long long	get_onumber_length(t_parser *p, va_list **args)
{
	unsigned long long number;

	number = va_arg(**args, unsigned long long);
	if (p->omaj)
		number = (unsigned long)number;
	else if (p->length == HH)
		number = (unsigned char)number;
	else if (p->length == H)
		number = (unsigned int)number;
	else if (p->length == L)
		number = (unsigned long)number;
	else if (p->length == LL)
		number = (unsigned long long)number;
	else if (p->length == J)
		number = (uintmax_t)number;
	else if (p->length == Z)
		number = (size_t)number;
	else if (p->length == DEFAULT)
		number = (unsigned int)number;
	return (number);
}

int		process_octal(t_parser *p, va_list **args)
{
	unsigned long long	number;
	char				*retnbr;

	number = get_onumber_length(p, args);
	retnbr = ft_itoa_base_u(number, 8);
	if (p->precision)
		process_precision(&retnbr, p);
	if (p->width && p->zero)
		process_zero(&retnbr, p);
	if (p->width && !p->precision)
		process_width(&retnbr, p);
	if (p->width)
		process_width(&retnbr, p);
	ft_putstr(retnbr);
	return (ft_strlen(retnbr));
}
