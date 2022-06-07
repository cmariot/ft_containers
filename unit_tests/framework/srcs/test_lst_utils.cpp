/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lst_utils.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 23:35:51 by cmariot           #+#    #+#             */
/*   Updated: 2022/06/07 15:38:10 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.hpp"

t_test	*ft_rettest_lst(std::string function, std::string test_name,
			void *test_add, std::string expected_output)
{
	t_test		*ret;

	ret = new t_test;
	if (ret)
	{
		ret->function = function;
		ret->test_name = test_name;
		ret->test_add = (int (*)())test_add;
		ret->expected_output = expected_output;
		ret->filename = ret->function + "_" + ret->test_name + ".log";
		ret->status = -2;
		ret->next = NULL;
		return (ret);
	}
	else
		return (NULL);
}

t_test	*ft_lasttest_lst(t_test *test)
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

void	ft_addtest_lst(t_test **test_add, t_test *ret)
{
	t_test	*tmp;

	if (test_add)
	{
		if (*test_add == NULL)
			*test_add = ret;
		else
		{
			tmp = ft_lasttest_lst(*test_add);
			tmp->next = ret;
		}
	}
}

void	ft_cleartest_lst(t_test **test, bool opt)
{
	t_test	*tmp;

	while (*test)
	{
		tmp = (*test)->next;
		if (opt == 1)
			unlink((*test)->filename.c_str());
		delete *test;
		*test = tmp;
	}
}

void	load_test(t_test **test, std::string function, std::string test_name,
			void *function_add, std::string expected_output)
{
	if (test == NULL)
		*test = ft_rettest_lst(function, test_name,
				function_add, expected_output);
	else
		ft_addtest_lst(test, ft_rettest_lst(function, test_name,
				function_add, expected_output));
}
