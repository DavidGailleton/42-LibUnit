#include "../tests.h"

int	strncmp_launcher(void)
{
	t_unit_test	*testlist;
	size_t		res;

	testlist = NULL;
	load_test(&testlist, "OK test", &strncmp_ok_test);
	load_test(&testlist, "KO test", &strncmp_ko_test);
	res = launch_tests(testlist, "ft_strncmp");
	clear_tests(&testlist);
	return (res);

}
