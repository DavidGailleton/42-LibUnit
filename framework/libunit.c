/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libunit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaillet <dgaillet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 12:43:35 by dgaillet          #+#    #+#             */
/*   Updated: 2026/01/25 13:24:44 by elagouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libunit.h"
#include <fcntl.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

static void	print_wtermsig(int signal)
{
	if (signal == 11)
		ft_putstr_fd("[\x1B[33mSIGSEGV\x1B[0m]\n", 1);
	else if (signal == 7)
		ft_putstr_fd("[\x1B[33mSIGBUS\x1B[0m]\n", 1);
	else if (signal == 6)
		ft_putstr_fd("[\x1B[33mSIGABRT\x1B[0m]\n", 1);
	else if (signal == 8)
		ft_putstr_fd("[\x1B[33mSIGFPE\x1B[0m]\n", 1);
	else if (signal == 13)
		ft_putstr_fd("[\x1B[33mSIGPIPE\x1B[0m]\n", 1);
	else if (signal == 4)
		ft_putstr_fd("[\x1B[33mSIGILL\x1B[0m]\n", 1);
}

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
		print_wtermsig(WTERMSIG(status));
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

int	launcher_helper(struct s_helper h, const char *fn_name,
		t_unit_test *test_list)
{
	int	status;

	h.wpid = wait(&status);
	if (h.wpid < 0)
		return (1);
	h.ok_tests += interpret_status(status, fn_name, get_test_at(test_list,
				h.i)->title);
	return (0);
}

int	launch_tests(t_unit_test *test_list, const char *fn_name)
{
	t_h	h;

	h.ok_tests = 0;
	h.i = -1;
	while (++h.i < (int)count_tests(test_list))
	{
		h.wpid = fork();
		if (h.wpid < 0)
			return (1);
		else if (h.wpid == 0)
		{
			dup2(open("/dev/null", O_WRONLY), STDOUT_FILENO);
			exit(!get_test_at(test_list, h.i)->func());
		}
		else if (launcher_helper(h, fn_name, test_list))
			return (1);
	}
	print_passed_test(h.ok_tests, test_list);
	return (0);
}
