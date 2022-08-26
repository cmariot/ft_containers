/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_map_launcher.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 14:19:08 by cmariot           #+#    #+#             */
/*   Updated: 2022/08/26 15:18:19 by cmariot          ###   ########.fr       */
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
	load_test(&tests, function_name, "Clear test", (void *)&map_clear_tests, "");
	load_test(&tests, function_name, "Val_Key comp", (void *)&map_value_key_comp_tests, "");
	load_test(&tests, function_name, "Swap tests", (void *)&map_swap_tests, "");
	load_test(&tests, function_name, "Iterators", (void *)&map_iterator_tests, "");
	load_test(&tests, function_name, "Empty test", (void *)&map_empty_test, "");
	load_test(&tests, function_name, "Relational", (void *)&map_relational_ope, "");
	load_test(&tests, function_name, "Bound test", (void *)&map_bound_tests, "");
	return (launch_tests(&tests));
}
