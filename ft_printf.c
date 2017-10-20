/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yribeiro <yribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 17:00:55 by yribeiro          #+#    #+#             */
/*   Updated: 2017/10/20 19:06:21 by yribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

// %[flags][width][.precision][length]specifier

void	ft_copyuntil(char *str, char until)
{
	while (*str && *str != until)
	{
		ft_putchar(*str);
		str++;
	}
}

int		parser(char **lookup, t_parser *p)
{
	(*lookup)++;
	parse_flags(lookup, p);
	parse_width(lookup, p);
	parse_precision(lookup, p);
	parse_length(lookup, p);
	parse_specifier(lookup, p);
	(*lookup)++;
	return (0);
}

int 	process(va_list *args, char *format)
{
	t_parser p;
	char	*lookup;
	int		ret;

	lookup = ft_strchr(format, '%');
	if (!lookup)
		ft_putstr(format);
	else
	{
		ft_copyuntil(format, '%');
		ft_bzero(&p, sizeof(t_parser));
		parser(&lookup, &p);
		ret = process_pointer(&p, &args);
	}
	printf("%d\n", ret);
	return (ret);
}

int		ft_printf(char *format, ...)
{
	int		ret;

	va_list args;

	va_start(args, format);
	ret = process(&args, format);
	va_end(args);
	while(1);
	return (ret);
}
