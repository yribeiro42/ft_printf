#include "printf.h"

int	main(void)
{
	int	ret;

	ret = printf("%04.3i", 42);
	//printf("\n[%d]\n", ret);
	printf("\n");
	ft_printf("%04.3i", 42);
	return (0);
}
