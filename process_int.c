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

void	process_switch(char **str, t_parser *p)
{
	ft_switch(str);
}

int		process_int(t_parser *p, va_list **args)
{
	intmax_t	number;
	char 		*str;

	number = get_number_length(p, args);
	if (number < 0)
		p->neg = 1;
	str = ft_itoa(number);
	if (p->precision)
		process_precision(&str, p);
	if (p->zero)
		process_zero(&str, p);
	if (p->showsign/* || p->neg*/)
		process_sign(&str, p);
	if (p->space)
		process_space(&str, p);
	if (p->left)
		process_left(&str, p);
	if (p->width && p->zero)
		process_zero(&str, p);
	if (p->width)
		process_width(&str, p);
	if (p->neg && (p->zero || p->precision))
		process_switch(&str, p);
	ft_putstr(str);
	return (ft_strlen(str));
}
