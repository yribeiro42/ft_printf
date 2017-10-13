/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yribeiro <yribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 17:00:55 by yribeiro          #+#    #+#             */
/*   Updated: 2017/10/13 14:28:20 by yribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

// %[flags][width][.precision][length]specifier

void	check_parsing(t_parser *p)
{
	if (p->left)
		printf("FLAGS OK\n");
	if (p->width)
		printf("WIDTH OK\n");
	if (p->precision)
		printf("PRECISION OK\n");
	printf("LENGTH = %d\n", p->length);
}

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
	//check_parsing(p);
	(*lookup)++;
	return (0);
}

int 	process(va_list *args, char *format)
{
	t_parser p;
	char	*lookup;

	lookup = ft_strchr(format, '%');
	if (!lookup)
		ft_putstr(format);
	ft_copyuntil(format, '%');
	parser(&lookup, &p);
	process_int(&p, &args);
	return (0);
}

int		ft_printf(char *format, ...)
{
	int		ret;

	va_list args;

	va_start(args, format);
	ret = process(&args, format);
	va_end(args);
	return (ret);
}
