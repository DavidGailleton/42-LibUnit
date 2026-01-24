/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elagouch <elagouch@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 15:32:30 by elagouch          #+#    #+#             */
/*   Updated: 2026/01/24 16:16:13 by elagouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_H
# define TESTS_H

# include "libunit.h"

// strlen
int test_basic(void);
int test_null(void);

// atoi
int	atoi_ok_test(void);
int	atoi_ko_test(void);
int	atoi_sigsegv_test(void);
int	atoi_sigbus_test(void);


#endif // !TESTS_H
