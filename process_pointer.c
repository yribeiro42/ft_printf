#include "printf.h"


int		process_pointer(t_parser *p, va_list **args)
{
	void	*ptr;
	int 	ret;
	char	*retptr;

	(void)p;
	ptr = va_arg(**args, void*);
	if (!ptr)
		retptr = ft_strnew(2);
	if (ptr)
		retptr = ft_itoa_base_u((unsigned long long)ptr, 16);
	if (p->precision)
	{
		printf("1\n");
		process_precision(&retptr, p);
	}
	process_htag(&retptr, p);
	if (p->width)
		process_width(&retptr, p);
	ft_putstr(retptr);
	ret = ft_strlen(retptr);
	free(retptr);
	return (ret + 2);
}
