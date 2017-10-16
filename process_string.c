#include "printf.h"

void	process_string(t_parser *p, va_list **args)
{
	char	*str;
	char	*addstr;
	int		offset;

	str = va_arg(**args, char*);
	addstr = ft_strnew(offset);
	offset = p->width - ft_strlen(str);
	str = ft_strdup(str);
	ft_memset(addstr, ' ', offset);
	if (p->width && p->left)
		ft_strjoin(str, addstr);
	if(p->width)
		process_width(&str, p);
	ft_putstr(str);
}