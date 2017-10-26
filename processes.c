/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yribeiro <yribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 14:06:53 by yribeiro          #+#    #+#             */
/*   Updated: 2017/10/26 17:42:27 by yribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

// sS p oO uU x X cC dDi

void	process_sign(char **str, t_parser *p)
{
	if (!p->neg)
		*str = ft_strjoin("+", *str);
}

void	process_space(char **str, t_parser *p)
{
	if (**str != '-' && !p->showsign)
		*str = ft_strjoin(" ", *str);
}

void	process_left(char **str, t_parser *p)
{
	while (ft_strlen(*str) < p->width)
		*str = ft_strjoin(*str, " ");
}

void	process_htag(char **str, t_parser *p)
{
	if (p->specifier == LOWERHEX || p->specifier == POINTER)
		*str = ft_strjoin("0x", *str);
	if (p->specifier == UPPERHEX)
		*str = ft_strjoin("0X", *str);
	if (p->specifier == OCTAL)
		*str = ft_strjoin("0", *str);
}

void	process_width(char **str, t_parser *p)
{
	while (ft_strlen(*str) < p->width)
		*str = ft_strjoin(" ", *str);
}

void	process_zero(char **str, t_parser *p)
{
	if (p->precision && p->specifier == DECIMAL)
		return ;
	if (p->htag && (p->specifier == LOWERHEX || p->specifier == UPPERHEX))
		p->width -= 2;
	if ((p->showsign && !p->neg) && p->width > 0)
		p->width--;
	while (ft_strlen(*str) < p->width)
		*str = ft_strjoin("0", *str);
}

void	process_precision(char **str, t_parser *p)
{
	if (p->specifier == STRING)
		*str = ft_strndup(*str, p->precision);
	else
	{
		while (ft_strlen(*str) < p->precision)
		{
			*str = ft_strjoin("0", *str);
		}
	}
}
