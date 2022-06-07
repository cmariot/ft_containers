/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 14:17:24 by cmariot           #+#    #+#             */
/*   Updated: 2022/06/07 09:25:02 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_HPP
# define TESTS_HPP

# include "libunit.hpp"

# include "vector.hpp"
# include <vector>

int		vector_launcher(void);

int		constructor_test(void);
int		destructor_test(void);
int		operator_equal_test(void);
int		iterators_test(void);
int		size_test(void);
int		max_size_test(void);
int		resize_test(void);
int		capacity_test(void);
int		empty_test(void);
int		reserve_test(void);
int		operators_test(void);
int		at_test(void);
int		front_test(void);
int		back_test(void);
int		push_back_test(void);
int		pop_back_test(void);
int		insert_test(void);
int		erase_test(void);
int		swap_test(void);
int		clear_test(void);
int		allocator_test(void);
int		relational_test(void);
int		swap2_test(void);

#endif
