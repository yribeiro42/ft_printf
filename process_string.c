#include "printf.h"

int		process_string(t_parser *p, va_list **args)
{
	char	*str;
	//char	*addstr;
	int		offset;

	str = va_arg(**args, char*);
	offset = 0;
	if (!str)
		str = "(null)";
	//if (p->width)
	//	offset = p->width - ft_strlen(str);
	//addstr = ft_strnew(offset);
	//str = ft_strdup(str);
	//ft_memset(addstr, ' ', offset);
	if (p->precision)
		process_precision(&str, p);
	if (p->left)
		process_left(&str, p);
	//if (p->width && p->left)
	//	ft_strjoin(str, addstr);
	if(p->width)
		process_width(&str, p);
	ft_putstr(str);
	return (ft_strlen(str));
}
