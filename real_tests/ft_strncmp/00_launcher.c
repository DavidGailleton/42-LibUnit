/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaillet <dgaillet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 12:05:05 by dgaillet          #+#    #+#             */
/*   Updated: 2026/01/25 15:14:07 by elagouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"

int	strncmp_launcher(void)
{
	t_unit_test	*testlist;
	size_t		res;

	testlist = NULL;
	load_test(&testlist, "OK test", &strncmp_ok_test, 0);
	load_test(&testlist, "KO test", &strncmp_ko_test, 0);
	res = launch_tests(testlist, "ft_strncmp");
	clear_tests(&testlist);
	return (res);
}
