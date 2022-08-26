/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_map_launcher.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 14:19:08 by cmariot           #+#    #+#             */
/*   Updated: 2022/08/26 19:26:09 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

int	stack_launcher(void)
{
	s_test	*tests = NULL;
	std::string function_name = "STACK";

	load_test(&tests, function_name, "Constructor", (void *)&stack_constructors_tests, "");
	load_test(&tests, function_name, "Destructor", (void *)&stack_destructors_tests, "");
	load_test(&tests, function_name, "Operator =", (void *)&stack_operator_equal_tests, "");
	load_test(&tests, function_name, "Top       ", (void *)&stack_top_tests, "");
	load_test(&tests, function_name, "Empty     ", (void *)&stack_empty_tests, "");
	load_test(&tests, function_name, "Size      ", (void *)&stack_size_tests, "");
	load_test(&tests, function_name, "Push      ", (void *)&stack_push_tests, "");
	load_test(&tests, function_name, "Pop       ", (void *)&stack_pop_tests, "");
	load_test(&tests, function_name, "Relational", (void *)&stack_relational_operators_tests, "");
	return (launch_tests(&tests));
}
