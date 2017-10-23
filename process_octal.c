/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_octal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yribeiro <yribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 16:26:31 by yribeiro          #+#    #+#             */
/*   Updated: 2017/10/23 16:39:48 by yribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		process_octal(t_parser *p, va_list **args)
{
	intmax_t	number;
	char		*retnbr;

	number = va_arg(**args, unsigned int);
	retnbr = ft_itoa_base(number, 8);
	ft_putstr(retnbr);
	return (ft_strlen(retnbr));
}
