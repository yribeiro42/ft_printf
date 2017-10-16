#include "printf.h"

void	process_pointer(t_parser *p, va_list **args)
{
	char	*str;

	str = va_arg(**args, void*);
	ft_putstr(str);
}