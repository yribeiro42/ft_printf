/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_wstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 22:45:03 by anonymous         #+#    #+#             */
/*   Updated: 2017/10/23 22:50:41 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_putwstr(wchar_t *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft_putwchar(str[i]);
		i++;
	}
}

int		ft_wstrsize(wchar_t *wstr)
{
	int size;
	int i;

	i = 0;
	size = 0;
	while (wstr[i])
	{
		if (wstr[i] <= 127)
			size += 1;
		else if (wstr[i] <= 2047)
			size += 2;
		else if (wstr[i] <= 65535)
			size += 3;
		else if (wstr[i] <= 1114111)
			size += 4;
		i++;
	}
	return (size);
}

int		process_wstr(t_parser *p, va_list **args)
{
	wchar_t	*str;
	int		ret;

	str = va_arg(**args, wchar_t*);
	if (!str)
		str = "(null)";
	ret = ft_wstrsize(str);
	ft_putwstr(str);
	return (ret);
}
