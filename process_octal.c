/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_octal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 16:26:31 by yribeiro          #+#    #+#             */
/*   Updated: 2017/10/23 22:52:05 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		process_octal(t_parser *p, va_list **args)
{
	intmax_t	number;
	char		*retnbr;

	number = va_arg(**args, unsigned int);
	retnbr = ft_itoa_base(number, 8);
	if (p->htag == 1)
		ft_putchar('0');
	ft_putstr(retnbr);
	return (ft_strlen(retnbr));
}
