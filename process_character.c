/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_character.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 22:37:31 by anonymous         #+#    #+#             */
/*   Updated: 2017/10/23 22:41:28 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		process_character(t_parser *p, va_list **args)
{
	char	chr;

	chr = va_arg(**args, int);
	ft_putchar(chr);
	return (1);
}
