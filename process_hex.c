/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yribeiro <yribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 16:39:35 by yribeiro          #+#    #+#             */
/*   Updated: 2017/10/23 17:23:57 by yribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_strupper(char *s)
{
	char	*cpy;
	int		i;

	i = 0;
	cpy = ft_strnew(ft_strlen(s) + 1);
	while (s[i] != '\0')
	{
		cpy[i] = ft_toupper(s[i]);
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

int		process_hex(t_parser *p, va_list **args)
{
	intmax_t	number;
	char		*retnbr;

	number = va_arg(**args, unsigned int);
	retnbr = ft_itoa_base(number, 16);
	if (p->specifier == UPPERHEX)
		retnbr = ft_strupper(retnbr);
	ft_putstr(retnbr);
	return (ft_strlen(retnbr));
}
