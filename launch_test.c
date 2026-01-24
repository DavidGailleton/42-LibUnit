/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaillet <dgaillet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 12:43:35 by dgaillet          #+#    #+#             */
/*   Updated: 2026/01/24 12:43:37 by dgaillet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include "libft.h"
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

static int	test_func(t_unit_test *test_node)
{
	int	res;

	res = test_node->func;

}

static size_t	interpret_status(int status, const char *fn_name, char *test_name)
{
	ft_putstr_fd(fn_name, 1);
	ft_putstr_fd(" : ", 1);
	ft_putstr_fd(test_name, 1);
	ft_putstr_fd(" : ", 1);
	if (WIFEXITED(status))
	{
		if (WEXITSTATUS(status))
			ft_putstr_fd("[KO]\n", 1);
		else
		{
			ft_putstr_fd("[OK]\n", 1);
			return (1);
		}
	}
	else if (WIFSIGNALED(status))
	{
		if (WTERMSIG(status) == 11)
			ft_putstr_fd("[SIGSEGV]\n", 1);
		else if (WTERMSIG(status) == 10)
			ft_putstr_fd("[SIGBUS]\n", 1);
	}
	return (0);
}

static void	print_passed_test(size_t ok_tests, t_unit_test *test_list)
{
	ft_putnbr_fd(ok_tests, 1);
	ft_putchar_fd('/', 1);
	ft_putnbr_fd(total_node(test_list));
	ft_putstr_fd(" tests checked", 1);
}

int	launch_tests(t_unit_test *test_list, const char *fn_name)
{
	size_t	ok_tests;
	pid_t	wpid;
	int		status;

	ok_tests = 0;
	while (1)
	{
		wpid = fork();
		if (wpid < 0)
			return (1);
		else if (wpid == 0)
			test_func(test_func);
		else
		{
			wpid = wait(&status);
			if (wpid < 0)
				return (1);
			ok_tests += interpret_status(status, fn_name, test_node->title);
		}
	}
	print_passed_test(ok_tests, test_list);
	return (0);
}
