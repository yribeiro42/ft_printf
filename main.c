#include "printf.h"

int	main(void)
{
	int	ret;

	ret = printf("%#08x", 42);
	//printf("\n[%d]\n", ret);
	printf("\n");
	ft_printf("%#08x", 42);
	return (0);
}
