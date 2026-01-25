/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libunit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaillet <dgaillet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 12:43:35 by dgaillet          #+#    #+#             */
/*   Updated: 2026/01/24 16:50:51 by elagouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libunit.h"
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

static size_t	interpret_status(int status, const char *fn_name,
		char *test_name)
{
	ft_putstr_fd((char *)fn_name, 1);
	ft_putstr_fd(" : ", 1);
	ft_putstr_fd(test_name, 1);
	ft_putstr_fd(" : ", 1);
	if (WIFEXITED(status))
	{
		if (WEXITSTATUS(status))
			ft_putstr_fd("[\x1B[31m\x1B[1mKO\x1B[0m]\n", 1);
		else
		{
			ft_putstr_fd("[\x1B[32mOK\x1B[0m]\n", 1);
			return (1);
		}
	}
	else if (WIFSIGNALED(status))
	{
		if (WTERMSIG(status) == 11)
			ft_putstr_fd("[\x1B[33mSIGSEGV\x1B[0m]\n", 1);
		else if (WTERMSIG(status) == 7)
			ft_putstr_fd("[\x1B[33mSIGBUS\x1B[0m]\n", 1);
	}
	return (0);
}

static void	print_passed_test(size_t ok_tests, t_unit_test *test_list)
{
	size_t	total;

	total = count_tests(test_list);
	if (ok_tests == total)
		ft_putstr_fd("\x1B[32m", 1);
	else
		ft_putstr_fd("\x1B[31m", 1);
	ft_putnbr_fd(ok_tests, 1);
	ft_putchar_fd('/', 1);
	ft_putnbr_fd((int)total, 1);
	ft_putstr_fd("\x1B[0m tests succeeded\n\n", 1);
}

int	launch_tests(t_unit_test *test_list, const char *fn_name)
{
	size_t	ok_tests;
	pid_t	wpid;
	int		status;
	int		i;

	ok_tests = 0;
	i = -1;
	while (++i < (int)count_tests(test_list))
	{
		wpid = fork();
		if (wpid < 0)
			return (1);
		else if (wpid == 0)
			exit(!get_test_at(test_list, i)->func());
		else
		{
			wpid = wait(&status);
			if (wpid < 0)
				return (1);
			ok_tests += interpret_status(status, fn_name, get_test_at(test_list,
						i)->title);
		}
	}
	print_passed_test(ok_tests, test_list);
	return (0);
}
