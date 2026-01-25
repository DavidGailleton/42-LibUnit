/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elagouch <elagouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 15:32:32 by elagouch          #+#    #+#             */
/*   Updated: 2026/01/25 15:09:00 by elagouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"

int	libunit_launcher(void)
{
	t_unit_test	*testlist;
	size_t		res;

	testlist = NULL;
	load_test(&testlist, "successful", &test_ok, 0);
	load_test(&testlist, "unsuccessful", &test_ko, 0);
	load_test(&testlist, "sigsegv", &test_sigsegv, 0);
	load_test(&testlist, "sigbus", &test_sigbus, 0);
	res = launch_tests(testlist, "libunit");
	clear_tests(&testlist);
	return (res);
}
