#include "printf.h"

int	main(void)
{
	int	ret;

	char *s = "asd";
	ret = printf("{%05s}\n", "abc");
	ft_printf("{%05s}\n", "abc");
	return (0);
}
