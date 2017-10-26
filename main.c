#include "printf.h"

int	main(void)
{
	int	ret;

	ret = printf("%03.2d", -1);
	printf("\n[%d]\n", ret);
	//printf("\n");
	ft_printf("%03.2d", -1);
	return (0);
}
