/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elagouch <elagouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 15:32:30 by elagouch          #+#    #+#             */
/*   Updated: 2026/01/24 18:40:48 by elagouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_H
# define TESTS_H

# include "libunit.h"

// LAUNCHERS
int	strlen_launcher(void);
int	atoi_launcher(void);
int	strncmp_launcher(void);

// strlen
int	test_basic(void);
int	test_null(void);
int	test_large(void);

// atoi
int	atoi_ok_test(void);
int	atoi_ko_test(void);
int	atoi_sigsegv_test(void);
int	atoi_sigbus_test(void);

//strncmp
int strncmp_ok_test(void);
int strncmp_ko_test(void);


#endif // !TESTS_H
