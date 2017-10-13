#include "printf.h"

intmax_t	get_number_length(t_parser *p, va_list **args)	 // hh h l ll j z
{
	intmax_t number;

	number = va_arg(**args, intmax_t);
	if (p->length == HH)
		number = (char)number;
	else if (p->length == H)
		number = (short)number;
	else if (p->length == L)
		number = (long)number;
	else if (p->length == LL)
		number = (long long)number;
	else if (p->length == J)
		number = (intmax_t)number;
	else if (p->length == Z)
		number = (size_t)number;
	else if (p->length == DEFAULT)
		number = (int)number;
	return (number);
}

char	*process_sign(char **str)
{
	if (**str != '-')
	{
		*str = ft_strjoin("+", *str);
	}
	return (*str);
}

char	*process_width(char **str, t_parser *p)
{
	while (ft_strlen(*str) < p->width)
	{
		*str = ft_strjoin(" ", *str);
	}
	return (*str);
}

char	*process_precision(char **str, t_parser *p)
{
	while (ft_strlen(*str) < p->precision)
	{
		*str = ft_strjoin("0", *str);
	}
	return (*str);
}

void	process_int(t_parser *p, va_list **args)
{
	intmax_t	number;
	char 		*str;

	if (p->specifier == DECIMAL)
		number = get_number_length(p, args);
	str = ft_itoa(number);
	if (p->showsign)
		str = process_sign(&str);
	if (p->width)
		str = process_width(&str, p);
	if (p->precision)
		str = process_precision(&str, p);
	ft_putstr(str);
}