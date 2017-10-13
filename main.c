#include "printf.h"

int	main(void)
{
	printf(   YEL "%.5d\n" RESET, 42);
	ft_printf(GRN "%.5d\n" RESET, 42);
	return (0);
}
