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

	number = 0;
	if (p->specifier == DECIMAL)
		number = get_number_length(p, args);
	str = ft_itoa(number);
	if (p->precision)
		process_precision(&str, p);
	if (p->zero)
		process_zero(&str, p);
	if (p->showsign)
		process_sign(&str);
	if (p->space)
		process_space(&str, p);
	if (p->left)
		process_left(&str, p);
	if (p->width && p->zero)
		process_zero(&str, p);
	if (p->width)
		process_width(&str, p);
	ft_putstr(str);
	return (ft_strlen(str));
}

 // if (parsed->dot && strchr("sSdiouxX", parsed->type))
 //    ft_handle_precision(parsed, &str);
 //  if (parsed->plus && strchr("di", parsed->type))
 //    ft_handle_plus(&str);
 //  if (parsed->space && !parsed->plus && strchr("di", parsed->type && strchr(str, '-')))
 //    ft_handle_space(&str);
 //  if (parsed->minus)
 //    ft_handle_minus(parsed, &str);
 //  if (parsed->zero && !parsed->minus && strchr("diouxX", parsed->type))
 //    ft_handle_zero(parsed, &str);
 //  if (parsed->width && (!parsed->zero || !parsed->minus))
 //    ft_handle_width(parsed, &str);
 //  if (strchr("di", parsed->type) && strchr(str, '-') && (parsed->zero || parsed->dot))
 //    ft_switch(&str);