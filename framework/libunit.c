/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libunit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaillet <dgaillet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 12:43:35 by dgaillet          #+#    #+#             */
/*   Updated: 2026/01/25 14:25:04 by elagouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

static void	print_wtermsig(int ffd, int signal)
{
  char *sigs[14];

  sigs[4] = "SIGKILL";
  sigs[6] = "SIGABRT";
  sigs[7] = "SIGBUS";
  sigs[8] = "SIGFPE";
  sigs[11] = "SIGSEGV";
  sigs[13] = "SIGPIPE";

	ft_putstr_fd("[\x1B[33m", 1);
	ft_putstr_fd("[", ffd);
  ft_putstr_fd(sigs[signal], 1);
  ft_putstr_fd(sigs[signal], ffd);
  ft_putstr_fd("\x1B[0m]\n", 1);
  ft_putstr_fd("]\n", ffd);
}

static size_t	interpret_status(int ffd, int status, const char *fn_name,
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

static void	print_passed_test(int ffd, size_t ok_tests, t_unit_test *test_list)
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

int	launcher_helper(int ffd, struct s_helper *h, const char *fn_name,
		t_unit_test *test_list)
{
	int	status;

	h->wpid = wait(&status);
	if (h->wpid < 0)
		return (1);
	h->ok_tests += interpret_status(ffd, status, fn_name, get_test_at(test_list,
				h->i)->title);
	return (0);
}

int handleOut(const char *fn_name) {
  char *tmp;
  int fd;

  tmp = ft_strjoin(fn_name, ".log");
  if (!tmp)
    return -1;
  fd = open(tmp, O_WRONLY | O_CREAT | O_TRUNC, 0644);
  free(tmp);
  return (fd);
}

int	launch_tests(t_unit_test *test_list, const char *fn_name)
{
  int ffd;
	t_h	h;

	h.ok_tests = 0;
	h.i = -1;
  ffd = handleOut(fn_name);
  if (ffd < 0)
    return (1);
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
		else if (launcher_helper(ffd, &h, fn_name, test_list))
			return (1);
	}
	print_passed_test(ffd, h.ok_tests, test_list);
  close(ffd);
	return (0);
}
