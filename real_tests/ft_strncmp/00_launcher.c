/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaillet <dgaillet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 12:05:05 by dgaillet          #+#    #+#             */
/*   Updated: 2026/01/25 12:05:17 by dgaillet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"

int	strncmp_launcher(void)
{
	t_unit_test	*testlist;
	size_t		res;

	testlist = NULL;
	load_test(&testlist, "Basic test", &strncmp_basic_test);
	load_test(&testlist, "Len test", &strncmp_len_test);
	load_test(&testlist, "High len test", &strncmp_high_len_test);
	res = launch_tests(testlist, "ft_strncmp");
	clear_tests(&testlist);
	return (res);
}
