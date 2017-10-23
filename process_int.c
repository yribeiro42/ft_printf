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

int		process_int(t_parser *p, va_list **args)
{
	intmax_t	number;
	char 		*str;

	if (p->specifier == DECIMAL)
		number = get_number_length(p, args);
	str = ft_itoa(number);
	if (p->showsign)
		process_sign(&str);
	if (p->precision)
		process_precision(&str, p);
	if (p->width && p->zero)
		process_zero(&str, p);
	if (p->width)
		process_width(&str, p);
	ft_putstr(str);
	return (ft_strlen(str));
}