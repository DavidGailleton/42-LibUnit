/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elagouch <elagouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 15:32:32 by elagouch          #+#    #+#             */
/*   Updated: 2026/01/24 16:16:24 by elagouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tests.h"

int libunit_launcher(void) {
  t_unit_test *testlist;
  size_t      res;

  testlist = NULL;
  load_test(&testlist, "successful", &test_ok);
  load_test(&testlist, "unsuccessful", &test_ko);
  load_test(&testlist, "sigsegv", &test_ko);
  load_test(&testlist, "sigbus", &test_ko);

  res = launch_tests(testlist, "libunit");
  clear_tests(&testlist);

  return (res);
}
