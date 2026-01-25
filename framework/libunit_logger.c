/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libunit_logger.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elagouch <elagouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 14:26:54 by elagouch          #+#    #+#             */
/*   Updated: 2026/01/25 14:50:04 by elagouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

static void	print_wtermsig(int ffd, int signal)
{
	static char	*sigs[15];

	sigs[4] = "SIGKILL";
	sigs[6] = "SIGABRT";
	sigs[7] = "SIGBUS";
	sigs[8] = "SIGFPE";
	sigs[11] = "SIGSEGV";
	sigs[13] = "SIGPIPE";
	sigs[14] = "TIMEOUT";
	ft_putstr_fd("[\x1B[33m", 1);
	ft_putstr_fd("[", ffd);
	ft_putstr_fd(sigs[signal], 1);
	ft_putstr_fd(sigs[signal], ffd);
	ft_putstr_fd("\x1B[0m]\n", 1);
	ft_putstr_fd("]\n", ffd);
}

size_t	interpret_status(int ffd, int status, const char *fn_name,
		char *test_name)
{
	ft_putstr_fd((char *)fn_name, 1);
	ft_putstr_fd((char *)fn_name, ffd);
	ft_putstr_fd(" : ", 1);
	ft_putstr_fd(" : ", ffd);
	ft_putstr_fd(test_name, 1);
	ft_putstr_fd(test_name, ffd);
	ft_putstr_fd(" : ", 1);
	ft_putstr_fd(" : ", ffd);
	if (WIFEXITED(status))
	{
		if (WEXITSTATUS(status))
		{
			ft_putstr_fd("[\x1B[31m\x1B[1mKO\x1B[0m]\n", 1);
			ft_putstr_fd("[KO]\n", ffd);
		}
		else
		{
			ft_putstr_fd("[\x1B[32mOK\x1B[0m]\n", 1);
			ft_putstr_fd("[OK]\n", ffd);
			return (1);
		}
	}
	else if (WIFSIGNALED(status))
		print_wtermsig(ffd, WTERMSIG(status));
	return (0);
}

void	print_passed_test(int ffd, size_t ok_tests, t_unit_test *test_list)
{
	size_t	total;

	total = count_tests(test_list);
	if (ok_tests == total)
		ft_putstr_fd("\x1B[32m", 1);
	else
		ft_putstr_fd("\x1B[31m", 1);
	ft_putnbr_fd(ok_tests, 1);
	ft_putnbr_fd(ok_tests, ffd);
	ft_putchar_fd('/', 1);
	ft_putchar_fd('/', ffd);
	ft_putnbr_fd((int)total, 1);
	ft_putnbr_fd((int)total, ffd);
	ft_putstr_fd("\x1B[0m tests succeeded\n\n", 1);
	ft_putstr_fd(" tests succeeded\n\n", ffd);
}
