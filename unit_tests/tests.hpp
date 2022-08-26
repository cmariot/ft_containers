/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 15:03:15 by cmariot           #+#    #+#             */
/*   Updated: 2022/08/26 19:22:18 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONTAINERS_HPP
# define FT_CONTAINERS_HPP

# include "libunit.hpp"

/* ************************************************************************** */
/*                                                                            */
/*                                    VECTOR                                  */
/*                                                                            */
/* ************************************************************************** */

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
int		assign_test(void);
int		push_back_test(void);
int		pop_back_test(void);
int		insert_test(void);
int		erase_test(void);
int		swap_test(void);
int		clear_test(void);
int		allocator_test(void);
int		relational_test(void);
int		swap2_test(void);


/* ************************************************************************** */
/*                                                                            */
/*                                     STACK                                  */
/*                                                                            */
/* ************************************************************************** */

# include "stack.hpp"
# include <stack>

int		stack_launcher(void);

int		stack_constructors_tests(void);
int		stack_destructors_tests(void);
int		stack_operator_equal_tests(void);
int		stack_top_tests(void);
int		stack_empty_tests(void);
int		stack_size_tests(void);
int		stack_push_tests(void);
int		stack_pop_tests(void);
int		stack_relational_operators_tests(void);


/* ************************************************************************** */
/*                                                                            */
/*                                     MAP                                    */
/*                                                                            */
/* ************************************************************************** */

# include "map.hpp"
# include <map>

int		map_launcher(void);
int		pair_test(void);
int		RBTree_test(void);
int		map_constructors_tests(void);
int		map_destructor_tests(void);
int		map_clear_tests(void);
int		map_value_key_comp_tests(void);
int		map_swap_tests(void);
int		map_iterator_tests(void);
int		map_empty_test(void);
int		map_relational_ope(void);
int		map_bound_tests(void);


#endif
