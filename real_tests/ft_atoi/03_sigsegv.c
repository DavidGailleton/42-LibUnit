#include "../tests.h"
#include <stdlib.h>

int	atoi_sigsegv_test(void)
{
	return (ft_atoi(NULL));
}
