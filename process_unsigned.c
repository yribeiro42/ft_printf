/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yribeiro <yribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 17:26:51 by yribeiro          #+#    #+#             */
/*   Updated: 2017/10/23 17:39:24 by yribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		process_unsigned(t_parser *p, va_list **args)
{
	intmax_t	number;
	char		*retnbr;

	number = va_arg(**args, unsigned int);
	retnbr = ft_itoa(number);
	if (p->precision)
		process_precision(&retnbr, p);
	if (p->width && p->zero)
		process_zero(&retnbr, p);
	if (p->width)
		process_width(&retnbr, p);
	ft_putstr(retnbr);
	return (ft_strlen(retnbr));
}
