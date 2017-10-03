/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 17:00:55 by yribeiro          #+#    #+#             */
/*   Updated: 2017/10/03 14:44:24 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int 	process(va_list *args, char *format, size_t ret)
{
	char	*lookup;

	lookup = ft_strchr(format, '%');
	if (*format == '\0')
		return (ret);
	if (!*lookup)
	{
		ft_putstr(format);
		ret = ft_strlen(format);
	}
	else
	{
		
		return (process(args, format, ret));
	}


}

int		ft_printf(char *format, ...)
{
	int		size;

	va_list args;

	va_start(args, format);
	size = process(&args, format, 0);
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