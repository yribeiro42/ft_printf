/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yribeiro <yribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 17:00:55 by yribeiro          #+#    #+#             */
/*   Updated: 2017/09/21 21:33:36 by yribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int 	process()
{
	traverse = format;
	while (*traverse != '%')
	{
		ft_putchar(*traverse);
		traverse++;
	}
	traverse++;
	parse_flags(*format, )
}

int		ft_printf(char *format, ...)
{
	int		size;

	va_list args;

	va_start(args, format);
	size = process(args, format);
	
	va_end(args);
	return (size);
}


int	main()
{
	t_parser *p;

	p = malloc(sizeof(t_parser));

	ft_printf("test%+d" , 10);
	printf("\n%+d\n", 10);
	
	return (0);
}