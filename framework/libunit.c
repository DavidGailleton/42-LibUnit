/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libunit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaillet <dgaillet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 12:43:35 by dgaillet          #+#    #+#             */
/*   Updated: 2026/01/25 14:47:25 by elagouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"
#include <fcntl.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int	launcher_helper(int ffd, struct s_helper *h, const char *fn_name,
		t_unit_test *test_list)
{
	int	status;

	h->wpid = waitpid(h->wpid, &status, WCONTINUED);
	if (h->wpid < 0)
		return (1);
	h->ok_tests += interpret_status(ffd, status, fn_name, get_test_at(test_list,
				h->i)->title);
	return (0);
}

int	handle_out(const char *fn_name)
{
	char	*tmp;
	int		fd;

	tmp = ft_strjoin(fn_name, ".log");
	if (!tmp)
		return (-1);
	fd = open(tmp, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	free(tmp);
	return (fd);
}

int	launch_tests(t_unit_test *test_list, const char *fn_name)
{
	int	ffd;
	t_h	h;

	h.ok_tests = 0;
	h.i = -1;
	ffd = handle_out(fn_name);
	if (ffd < 0)
		return (1);
	while (++h.i < (int)count_tests(test_list))
	{
		h.wpid = fork();
		if (h.wpid < 0)
			return (1);
		else if (h.wpid == 0)
		{
      alarm(5);
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
