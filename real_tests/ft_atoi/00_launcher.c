/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaillet <dgaillet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 16:22:35 by dgaillet          #+#    #+#             */
/*   Updated: 2026/01/25 15:13:36 by elagouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"

int	atoi_launcher(void)
{
	t_unit_test	*testlist;
	size_t		res;

	testlist = NULL;
	load_test(&testlist, "OK test", &atoi_ok_test, 0);
	load_test(&testlist, "KO test", &atoi_ko_test, 0);
	load_test(&testlist, "SIGSEGV test", &atoi_sigsegv_test, 0);
	load_test(&testlist, "SIGBUS test", &atoi_sigbus_test, 0);
	res = launch_tests(testlist, "atoi");
	clear_tests(&testlist);
	return (res);
}
