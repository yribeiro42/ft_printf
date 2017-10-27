/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_pointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yribeiro <yribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 15:03:56 by yribeiro          #+#    #+#             */
/*   Updated: 2017/10/27 15:22:33 by yribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		process_pointer(t_parser *p, va_list **args)
{
	void	*ptr;
	int		ret;
	char	*retptr;

	(void)p;
	ptr = va_arg(**args, void*);
	retptr = ft_itoa_base_u((unsigned long long)ptr, 16);
	ft_putstr("0x");
	ft_putstr(retptr);
	ret = ft_strlen(retptr);
	free(retptr);
	return (ret + 2);
}
