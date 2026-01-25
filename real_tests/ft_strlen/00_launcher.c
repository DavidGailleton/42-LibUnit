/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elagouch <elagouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 15:32:32 by elagouch          #+#    #+#             */
/*   Updated: 2026/01/24 16:34:12 by elagouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"

int	strlen_launcher(void)
{
	t_unit_test	*testlist;
	size_t		res;

	testlist = NULL;
	load_test(&testlist, "null", &test_null);
	load_test(&testlist, "basic", &test_basic);
	load_test(&testlist, "large", &test_large);
	res = launch_tests(testlist, "strlen");
	clear_tests(&testlist);
	return (res);
}
