/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_unit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elagouch <elagouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 14:35:57 by elagouch          #+#    #+#             */
/*   Updated: 2026/01/24 14:38:20 by elagouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util_unit.h"
#include <stdlib.h>

int	dummy(void)
{
	return (1);
}

int	main(void)
{
	t_unit_test	*testlist;

	testlist = NULL;
	load_test(&testlist, "hi", &dummy);
}

/* we loop over instead of shifting the pointer to make sure we don't skip
unexisting tests and end up in unallocated/invalid memory */
t_unit_test	*get_test_at(t_unit_test *head, size_t target_idx)
{
	size_t	j;

	j = 0;
	while ((j < target_idx) && head)
	{
		head = head->next;
		j++;
	}
	return (head);
}

size_t	count_tests(t_unit_test *head)
{
	size_t	j;

	j = 0;
	while (head)
	{
		head = head->next;
		j++;
	}
	return (j);
}

/**
 * @brief util function to get last test of the chain
 */
t_unit_test	*get_last(t_unit_test *head)
{
	while (head->next)
		head = head->next;
	return (head);
}

/**
 * @brief util function to allocate a new test
 */
t_unit_test	*alloc_test(const char *title, int (*test_func)(void))
{
	t_unit_test	*p;

	p = malloc(sizeof(t_unit_test));
	p->title = ft_strdup(title);
	p->func = test_func;
	p->next = NULL;
	return (p);
}

size_t	load_test(t_unit_test **head_ptr, const char *title,
		int (*test_func)(void))
{
	t_unit_test	*p;
	t_unit_test	*last;

	if (!head_ptr)
		return (-1);
	if (!*head_ptr)
	{
		p = alloc_test(title, test_func);
		if (!p)
			return (-1);
		*head_ptr = p;
		return (0);
	}
	last = get_last(*head_ptr);
	last->next = alloc_test(title, test_func);
	if (!last->next)
		return (-1);
	return (0);
}

void	clear_tests(t_unit_test **head_ptr)
{
	t_unit_test	*head;
	t_unit_test	*next;

	next = *head_ptr;
	while (head)
	{
		head = *head_ptr;
		next = head->next;
		head->next = NULL;
		free(head->title);
		head->title = NULL;
		head->func = NULL;
		head = next;
	}
}
