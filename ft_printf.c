/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yribeiro <yribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 12:03:28 by yribeiro          #+#    #+#             */
/*   Updated: 2017/10/24 18:38:42 by yribeiro         ###   ########.fr       */
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
	if (p->left)
		p->zero = 0;
	return (0);
}

/*int 	process(va_list *args, char *format)
{
	t_parser p;
	char	*lookup;
	int		ret;

	lookup = ft_strchr(format, '%');
	if (!lookup)
	{
		ft_putstr(format);
		return (ft_strlen(format));
	}
	else
	{
		ft_copyuntil(format, '%');
		ft_bzero(&p, sizeof(t_parser));
		parser(&lookup, &p);
		ret = get_specifier(&p, &args);
	}
	return (ret);
}*/


int 	process(va_list *args, char *format)
{
	t_parser p;
	int		ret;
	int		chrs;

	chrs = 0;
	while (*format != '\0')
	{
		if (*format == '%' && *(format + 1) == '%')
		{
			ft_putchar('%');
			format = format + 2;
		}
		if (*format == '%')
		{
			ft_bzero(&p, sizeof(t_parser));
			parser(&format, &p);
			ret = get_specifier(&p, &args);
		}
		else
		{
			ft_putchar(*format);
			chrs++;
		}
		format++;
	}
	return (ret + chrs);
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
