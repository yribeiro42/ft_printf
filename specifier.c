/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yribeiro <yribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 17:37:51 by anonymous         #+#    #+#             */
/*   Updated: 2017/10/24 19:37:42 by yribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// sS p oO uU x X cC dDi


#include "printf.h"

t_specifier	return_specifier(char format)
{
	if (format == 'd' || format == 'D' || format == 'i')
		return (DECIMAL);
	if (format == 's' || format == 'S')
		return (STRING);
	if (format == 'p')
		return (POINTER);
	if (format == 'o' || format == 'O')
		return (OCTAL);
	if (format == 'u' || format == 'U')
		return (UNSIGNEDECI);
	if (format == 'x')
		return (LOWERHEX);
	if (format == 'X')
		return (UPPERHEX);
	if (format == 'c')
		return (CHARACTER);
	if (format == 'C')
		return (WIDECHAR);
	else
		return (ERROR);
}

int		parse_specifier(char **format, t_parser *p)
{
	p->specifier = return_specifier(**format);
	if (p->specifier == ERROR)
		ft_putstr_fd("Specifier error", 2);
	return (0);
}

int		get_specifier(t_parser *p, va_list **args)
{
	int		read;

	read = 0;
	if (p->specifier == STRING)
		read = process_string(p, args);
	else if (p->specifier == POINTER)
		read = process_pointer(p, args);
	else if (p->specifier == DECIMAL)
		read = process_int(p, args);
	else if (p->specifier == OCTAL)
		read = process_octal(p, args);
	else if (p->specifier == LOWERHEX || p->specifier == UPPERHEX)
		read = process_hex(p, args);
	else if (p->specifier == UNSIGNEDECI)
		read = process_unsigned(p, args);
	else if (p->specifier == WIDECHAR)
		read = process_wchar(p, args);
	else if (p->specifier == CHARACTER)
		read = process_character(p, args);
	return (read);
}
