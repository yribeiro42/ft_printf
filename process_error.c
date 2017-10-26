/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yribeiro <yribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 15:11:27 by yribeiro          #+#    #+#             */
/*   Updated: 2017/10/26 15:35:02 by yribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		process_error(t_parser *p, va_list **args)
{
	char	chr;
	char	*str;

	//printf("[%c]\n",p->specifier);
	//chr = (char)va_arg(**args, int);
	str = malloc(sizeof(*str) * 2);
	//if (!chr)
//	{
//		ft_putchar(0);
//		return (1);
//	}
	str[0] = p->specifier;
	str[1] = '\0';
	if (p->left)
		process_left(&str, p);
	if (p->width)
		process_width(&str, p);
	ft_putstr(str);
	return (ft_strlen(str));
}