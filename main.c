#include "printf.h"

int	main(void)
{
	int	ret;


	ret = printf("%lld", 12799999999);
	//printf("\n[%d]\n", ret);
	printf("\n");
	ft_printf("%lld", 12799999999);
	return (0);
}
