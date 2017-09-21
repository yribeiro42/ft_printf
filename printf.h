/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yribeiro <yribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 16:11:25 by yribeiro          #+#    #+#             */
/*   Updated: 2017/09/21 20:12:28 by yribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"

typedef struct 	s_parser
{
	int			left_justify;
	int			sign;
	int			space;
	int			htag;
	int			zero;
	
}				t_parser;

int		ft_printf(char *format, ...);