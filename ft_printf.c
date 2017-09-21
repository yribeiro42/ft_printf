/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yribeiro <yribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 17:00:55 by yribeiro          #+#    #+#             */
/*   Updated: 2017/09/21 17:36:34 by yribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_printf(const char *format, ...)
{
	char	*traverse;
	int		i;


	va_list args;
	va_start(args, format);
	traverse = format;
	while (*traverse != '%')
	{
		ft_putchar(*traverse);
		traverse++;
	}
	ft_putchar(*traverse);

	va_end(args);
}