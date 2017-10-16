#include "printf.h"

// sS p oO uU x X cC dDi

void	*process_sign(char **str)
{
	if (**str != '-')
		*str = ft_strjoin("+", *str);
}

void	*process_width(char **str, t_parser *p)
{
	if (p->specifier == 2 || p->specifier == 0)
	{
		while (ft_strlen(*str) < p->width)
			*str = ft_strjoin(" ", *str);
	}
}

void	*process_zero(char **str, t_parser *p)
{
	while (ft_strlen(*str) < p->width)
	{
		*str = ft_strjoin("0", *str);
	}
}

void	*process_precision(char **str, t_parser *p)
{
	while (ft_strlen(*str) < p->precision)
	{
		*str = ft_strjoin("0", *str);
	}
}
