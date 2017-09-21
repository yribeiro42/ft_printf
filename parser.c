/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yribeiro <yribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 16:17:00 by yribeiro          #+#    #+#             */
/*   Updated: 2017/09/21 20:45:38 by yribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"


char	*parse_flags(char **format, t_parser *p)
{
	if (**format == '-')
		p->left_justify = 1;
	else if(**format == '+')
		p->sign = 1;
	else if(**format == ' ')
		p->space = 1;
	else if(**format == '#')
		p->htag = 1;
	else if (**format == '0')
		p->zero = 1;
	return (*format);
}