#include "printf.h"

int	main(void)
{
	int	ret;

	ret = printf("%#o\n", 0);
	//printf("\n[%d]\n", ret);
	//printf("\n");
	ft_printf("%#o", 0);
	return (0);
}
