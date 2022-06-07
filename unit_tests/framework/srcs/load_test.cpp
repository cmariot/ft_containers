/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_test.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 22:04:08 by cmariot           #+#    #+#             */
/*   Updated: 2022/06/07 22:14:20 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.hpp"

static void	add_test_to_list(t_test **test, t_test *ret)
{
	t_test	*tmp;

	if (test)
	{
		if (*test == NULL)
			*test = ret;
		else
		{
			tmp = *test;
			while (tmp->next != NULL)
				tmp = tmp->next;
			tmp->next = ret;
		}
	}
}

static t_test	*new_test_list(std::string function, std::string test_name,
			void *test_add, std::string expected_output)
{
	t_test		*new_list;

	new_list = new t_test;
	if (new_list)
	{
		new_list->function = function;
		new_list->test_name = test_name;
		new_list->test_add = (int (*)(void))test_add;
		new_list->expected_output = expected_output;
		new_list->filename = new_list->function + "_" + new_list->test_name + ".log";
		new_list->status = -2;
		new_list->next = NULL;
		return (new_list);
	}
	else
		return (NULL);
}

/*
 * First arg : Address of the t_test linked list, used to store all the tests
 * Second arg : Name of the function, will be print on the tester output
 * Third arg : Name of the test, same as second arg
 * Fourth arg : Pointer on the function to execute in the test
 * Fifth : Expected output, set "" to disble the test
 */

void	load_test(t_test **test, std::string function, std::string test_name,
			void *function_add, std::string expected_output)
{
	if (test == NULL)
		*test = new_test_list(function, test_name,
				function_add, expected_output);
	else
		add_test_to_list(test, new_test_list(function, test_name,
				function_add, expected_output));
}
