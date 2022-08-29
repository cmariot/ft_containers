/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_map_launcher.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 14:19:08 by cmariot           #+#    #+#             */
/*   Updated: 2022/08/29 10:55:49 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

int	map_launcher(void)
{
	s_test	*tests = NULL;
	std::string function_name = "MAP";

	load_test(&tests, function_name, "Pair MakePair", (void *)&pair_test, "");
	load_test(&tests, function_name, "RedBlackTree", (void *)&RBTree_test, "");
	load_test(&tests, function_name, "Constructor", (void *)&map_constructors_tests, "");
	load_test(&tests, function_name, "Destructor", (void *)&map_destructor_tests, "");
	load_test(&tests, function_name, "Clear     ", (void *)&map_clear_tests, "");
	load_test(&tests, function_name, "Val_Key comp", (void *)&map_value_key_comp_tests, "");
	load_test(&tests, function_name, "Swap     ", (void *)&map_swap_tests, "");
	load_test(&tests, function_name, "Iterators", (void *)&map_iterator_tests, "");
	load_test(&tests, function_name, "Empty     ", (void *)&map_empty_test, "");
	load_test(&tests, function_name, "Relational", (void *)&map_relational_ope, "");
	load_test(&tests, function_name, "Bound    ", (void *)&map_bound_tests, "");
	load_test(&tests, function_name, "Equal op.", (void *)&map_equal_test, "");
	load_test(&tests, function_name, "Size     ", (void *)&map_size_test, "");
	load_test(&tests, function_name, "Max size", (void *)&map_max_size_test, "");
	load_test(&tests, function_name, "Operator[]", (void *)&map_access_test, "");
	load_test(&tests, function_name, "Insert   ", (void *)&map_insert_test, "");
	load_test(&tests, function_name, "Erase    ", (void *)&map_erase_test, "");
	load_test(&tests, function_name, "Find     ", (void *)&map_find_test, "");
	load_test(&tests, function_name, "Count    ", (void *)&map_count_test, "");
	load_test(&tests, function_name, "Allocator", (void *)&map_allocator_test, "");

	return (launch_tests(&tests));
}
