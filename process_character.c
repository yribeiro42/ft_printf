/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_character.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yribeiro <yribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 22:37:31 by anonymous         #+#    #+#             */
/*   Updated: 2017/10/27 17:22:14 by yribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		process_character(t_parser *p, va_list **args)
{
	char	chr;
	char	*str;
	int		ret;

	chr = (char)va_arg(**args, int);
	str = malloc(sizeof(*str) * 2);
	if (!chr)
	{
		ft_putchar(0);
		return (1);
	}
	str[0] = chr;
	str[1] = '\0';
	if (p->left)
		process_left(&str, p);
	if (p->width)
		process_width(&str, p);
	ft_putstr(str);
	ret = ft_strlen(str);
	ft_strdel(&str);
	return (ret);
}
