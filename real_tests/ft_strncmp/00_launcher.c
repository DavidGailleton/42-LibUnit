#include "../tests.h"

int	strncmp_launcher(void)
{
	t_unit_test	*testlist;
	size_t		res;

	testlist = NULL;
	load_test(&testlist, "OK test", &atoi_ok_test);
	res = launch_tests(testlist, "ft_strncmp");
	clear_tests(&testlist);
	return (res);

}
