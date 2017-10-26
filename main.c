#include "printf.h"

int	main(void)
{
	int	ret;
	int	n = 5;
	int	*i = &n;

	ret = printf("%p\n", &i);
	//printf("\n[%d]\n", ret);
	//printf("\n");
	ft_printf("%p", &i);
	return (0);
}
