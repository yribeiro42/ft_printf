/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yribeiro <yribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 17:37:51 by anonymous         #+#    #+#             */
/*   Updated: 2017/10/20 18:28:23 by yribeiro         ###   ########.fr       */
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
	if (format == 'c' || format == 'C')
		return (CHARACTER);
	else
		return (ERROR);
}

int		parse_specifier(char **format, t_parser *p)
{
	p->specifier = return_specifier(**format);
//	printf("spec = [%d]\n", p->specifier);
	return (0);
}