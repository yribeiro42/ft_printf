/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yribeiro <yribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 16:39:35 by yribeiro          #+#    #+#             */
/*   Updated: 2017/10/26 13:24:17 by yribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

long long	get_xnumber_length(t_parser *p, va_list **args)
{
	long number;

	number = va_arg(**args, long long);
	if (p->length == HH)
		number = (unsigned char)number;
	else if (p->length == H)
		number = (unsigned short)number;
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

char	*ft_strupper(char *s)
{
	char	*cpy;
	int		i;

	i = 0;
	cpy = ft_strnew(ft_strlen(s) + 1);
	while (s[i] != '\0')
	{
		cpy[i] = ft_toupper(s[i]);
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

int		process_hex(t_parser *p, va_list **args)
{
	long long	number;
	char		*retnbr;

	number = get_xnumber_length(p, args);
	retnbr = ft_itoa_base_u(number, 16);
	if (p->precision)
		process_precision(&retnbr, p);
	if (p->zero)
		process_zero(&retnbr, p);
	if (p->htag)
		process_htag(&retnbr, p);
	if (p->left)
		process_left(&retnbr, p);
	if (p->width && !p->precision)
		process_width(&retnbr, p);
	if (p->width)
		process_width(&retnbr, p);
	if (p->specifier == UPPERHEX)
		retnbr = ft_strupper(retnbr);
	ft_putstr(retnbr);
	return (ft_strlen(retnbr));
}
