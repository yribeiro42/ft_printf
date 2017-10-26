/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yribeiro <yribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 15:14:04 by yribeiro          #+#    #+#             */
/*   Updated: 2017/10/26 18:29:41 by yribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		process_string(t_parser *p, va_list **args)
{
	char	*str;

	str = va_arg(**args, char*);
	if (!str)
		str = "(null)";
	if (p->precision)
		process_precision(&str, p);
	if (p->left)
		process_left(&str, p);
	if(p->width)
		process_width(&str, p);
	ft_putstr(str);
	return (ft_strlen(str));
}
