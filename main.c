#include "printf.h"

int	main(void)
{
	printf(   YEL "%05d\n" RESET, 10);
	ft_printf(GRN "%05d\n" RESET, 10);
	return (0);
}
