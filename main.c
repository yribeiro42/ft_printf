#include "printf.h"

int	main(void)
{
	int n = 10;
	int *p_n = &n;

	printf(   YEL "%p\n" RESET, p_n);
	ft_printf(GRN "%p\n" RESET, p_n);
	return (0);
}
