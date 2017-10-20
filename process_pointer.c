#include "printf.h"


int		process_pointer(t_parser *p, va_list **args)
{
	void	*ptr;
	int ret;
	char	*retptr;

	ptr = va_arg(**args, void*);
	retptr = ft_itoa_base((unsigned int)ptr, 16);
	ft_putstr("0x");
	ft_putstr(retptr);
	ret = ft_strlen(retptr);
	free(retptr);
	return (ret + 2);
}
