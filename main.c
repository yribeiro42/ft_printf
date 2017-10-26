#include "printf.h"

int	main(void)
{
	int	ret;

	ret = printf("%p\n", (void*)0);
	//printf("\n[%d]\n", ret);
	//printf("\n");
	ft_printf("%p", (void*)0);
	return (0);
}
