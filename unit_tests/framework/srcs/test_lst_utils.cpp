/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lst_utils.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 23:35:51 by cmariot           #+#    #+#             */
/*   Updated: 2022/06/07 21:11:31 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.hpp"

t_test	*new_test_list(std::string function, std::string test_name,
			void *test_add, std::string expected_output)
{
	t_test		*ret;

	ret = new t_test;
	if (ret)
	{
		ret->function = function;
		ret->test_name = test_name;
		ret->test_add = (int (*)(void))test_add;
		ret->expected_output = expected_output;
		ret->filename = ret->function + "_" + ret->test_name + ".log";
		ret->status = -2;
		ret->next = NULL;
		return (ret);
	}
	else
		return (NULL);
}

t_test	*get_last_test(t_test *test)
{
	if (test)
	{
		while (test->next)
			test = (t_test *)test->next;
		return (test);
	}
	else
		return (NULL);
}

void	add_test_to_list(t_test **test, t_test *ret)
{
	t_test	*tmp;

	if (test)
	{
		if (*test == NULL)
			*test = ret;
		else
		{
			tmp = get_last_test(*test);
			tmp->next = ret;
		}
	}
}

void	clear_test_list(t_test **test)
{
	t_test	*tmp;

	if (test)
	{
		while (*test)
		{
			tmp = (*test)->next;
			delete *test;
			*test = tmp;
		}
	}
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
