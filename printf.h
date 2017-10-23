/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yribeiro <yribeiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/21 16:11:25 by yribeiro          #+#    #+#             */
/*   Updated: 2017/10/23 15:27:45 by yribeiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "libft/libft.h"
#include "colors.h"

typedef	enum s_specifier
{
	STRING, POINTER, DECIMAL, OCTAL, UNSIGNEDECI, LOWERHEX, UPPERHEX, CHARACTER,
	ERROR
}			t_specifier;

typedef enum s_length
{
	DEFAULT, HH, H, L, LL, J, Z
}			t_length;

typedef struct 	s_parser
{
	int			left;
	int			showsign;
	int			space;
	int			htag;
	int			zero;
	int			width;
	int			precision;
	t_length	length;
	t_specifier	specifier;
}				t_parser;


int		ft_printf(char *format, ...);

// parser //

char	*parse_flags(char **format, t_parser *p);
char	*parse_width(char **format, t_parser *p);
char	*parse_precision(char **format, t_parser *p);
char	*parse_length(char **format, t_parser *p);

// specifier //

t_specifier	return_specifier(char format);
int		parse_specifier(char **format, t_parser *p);

// process //

int		process_int(t_parser *p, va_list **args);
int		process_pointer(t_parser *p, va_list **args);
int		process_string(t_parser *p, va_list **args);
void	process_sign(char **str);
void	process_width(char **str, t_parser *p);
void	process_zero(char **str, t_parser *p);
void	process_precision(char **str, t_parser *p);

int		get_specifier(t_parser *p, va_list **args);