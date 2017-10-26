/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 21:59:23 by anonymous         #+#    #+#             */
/*   Updated: 2017/10/26 21:59:36 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*ret;
	char	*cp;
	int		i;

	if (!s1 || !s2 || !(ret = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		return (NULL);
	cp = ret;
	i = 0;
	while (s1[i])
		*ret++ = s1[i++];
	i = 0;
	while (s2[i])
		*ret++ = s2[i++];
	ft_strdel(&s1);
	ft_strdel(&s2);
	return (cp);
}
