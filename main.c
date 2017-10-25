#include "printf.h"

int	main(void)
{
	int	ret;


	ret = printf("%s %s", "this", "is");
	printf("\n[%d]\n", ret);
	printf("\n");
	ft_printf("%s %s", "this", "is");
	return (0);
}
