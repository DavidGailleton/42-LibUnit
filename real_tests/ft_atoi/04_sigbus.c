#include "../tests.h"

int	atoi_sigbus_test(void)
{
	return (ft_atoi((void *) -2147483648));
}
