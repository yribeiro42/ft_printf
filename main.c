#include "printf.h"

int	main(void)
{
	int	ret;

	ret = printf("%hU", 4294967296);
	//printf("\n[%d]\n", ret);
	printf("\n");
	ft_printf("%hU", 4294967296);
	return (0);
}
