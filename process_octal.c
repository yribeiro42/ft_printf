/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_octal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yribeiro <yribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 16:26:31 by yribeiro          #+#    #+#             */
/*   Updated: 2017/10/24 14:03:17 by yribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		process_octal(t_parser *p, va_list **args)
{
	intmax_t	number;
	char		*retnbr;
	char		*addstr;
	int			offset;

	number = va_arg(**args, unsigned int);
	retnbr = ft_itoa_base(number, 8);
	if (p->width && p->zero)
		process_zero(&retnbr, p);
	if (p->htag == 1)
	{
		p->width--;
		ft_putchar('0');
	}
	if (p->width)
		process_width(&retnbr, p);
	ft_putstr(retnbr);
	return (ft_strlen(retnbr));
}
