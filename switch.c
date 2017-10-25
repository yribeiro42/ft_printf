/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yribeiro <yribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 18:13:31 by yribeiro          #+#    #+#             */
/*   Updated: 2017/10/25 18:14:23 by yribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void ft_switch(char **str)
{
  int i;

  i = 0;
   while (str[0][i] && str[0][i] != '0')
    i++;
  if (i != (int)ft_strlen(str[0]))
    str[0][i] = '-';
  i++;
  while (str[0][i] && str[0][i] != '-')
    i++;
  if (i != (int)ft_strlen(str[0]))
    str[0][i] = '0';
}

void  process_switch(char **str, t_parser *p)
{
  ft_switch(str);
}
