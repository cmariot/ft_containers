/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_map_launcher.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 14:19:08 by cmariot           #+#    #+#             */
/*   Updated: 2022/07/26 08:05:44 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

int	map_launcher(void)
{
	s_test	*tests = NULL;
	std::string function_name = "MAP";

	load_test(&tests, function_name, "Pair MakePair", (void *)&pair_test, "");
	load_test(&tests, function_name, "RedBlackTree", (void *)&RBTree_test, "");
	load_test(&tests, function_name, "Constructor", (void *)&constructors_tests, "");
	load_test(&tests, function_name, "Destructor", (void *)&destructor_tests, "");
	load_test(&tests, function_name, "Clear test", (void *)&clear_tests, "");
	load_test(&tests, function_name, "Val_Key comp", (void *)&value_key_comp_tests, "");
	load_test(&tests, function_name, "Swap tests", (void *)&swap_tests, "");
	return (launch_tests(&tests));
}
