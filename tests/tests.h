/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elagouch <elagouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 15:32:30 by elagouch          #+#    #+#             */
/*   Updated: 2026/01/24 16:16:20 by elagouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_H
# define TESTS_H

# include "libunit.h"

// LAUNCHERS
int strlen_launcher(void);

// libunit
int test_ok(void);
int test_ko(void);
int test_sigsegv(void);
int test_sigbus(void);

// strlen
int test_basic(void);
int test_null(void);

#endif // !TESTS_H
