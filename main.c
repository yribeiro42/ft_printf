#include "printf.h"

int	main(void)
{
	int	ret;

	ret = printf("%p", 140721448039903);
	//printf("\n[%d]\n", ret);
	printf("\n");
	ft_printf("%p", 140721448039903);
	return (0);
}
