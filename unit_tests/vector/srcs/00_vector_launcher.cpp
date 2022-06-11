/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_vector_launcher.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 14:19:08 by cmariot           #+#    #+#             */
/*   Updated: 2022/06/11 12:59:35 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

int	to_do(void)
{
	return (1);
}

int	vector_launcher(void)
{
	s_test	*tests = NULL;
	std::string function_name = "VECTOR";

	load_test(&tests, function_name, "Constructor", (void *)&constructor_test, "");
	//load_test(&tests, function_name, "Destructor", (void *)&destructor_test, "");
	//load_test(&tests, function_name, "Operator=", (void *)&operator_equal_test, "");
	//load_test(&tests, function_name, "Iterators", (void *)&iterators_test, "");
	//load_test(&tests, function_name, "Size", (void *)&size_test, "");
	//load_test(&tests, function_name, "Max_size", (void *)&max_size_test, "");
	//load_test(&tests, function_name, "Resize", (void *)&resize_test, "");
	//load_test(&tests, function_name, "Capacity", (void *)&capacity_test, "");
	//load_test(&tests, function_name, "Empty", (void *)&empty_test, "");
	//load_test(&tests, function_name, "Reserve", (void *)&reserve_test, "");
	//load_test(&tests, function_name, "Orerator []", (void *)&operators_test, "");
	//load_test(&tests, function_name, "Access At", (void *)&at_test, "");
	//load_test(&tests, function_name, "Front", (void *)&front_test, "");
	//load_test(&tests, function_name, "Back", (void *)&back_test, "");
	//load_test(&tests, function_name, "Assign", (void *)&to_do, "");
	//load_test(&tests, function_name, "Push_back", (void *)&push_back_test, "");
	//load_test(&tests, function_name, "Pop_back", (void *)&pop_back_test, "");
	//load_test(&tests, function_name, "Insert", (void *)&insert_test, "");
	//load_test(&tests, function_name, "Erase", (void *)&erase_test, "");
	//load_test(&tests, function_name, "Swap", (void *)&swap_test, "");
	//load_test(&tests, function_name, "Clear", (void *)&clear_test, "");
	//load_test(&tests, function_name, "Allocator", (void *)&allocator_test, "");
	//load_test(&tests, function_name, "Relational", (void *)&relational_test, "");
	//load_test(&tests, function_name, "Swap", (void *)&swap2_test, "");
	return (launch_tests(&tests));
}
