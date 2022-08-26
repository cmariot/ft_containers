/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_operator_equal.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 19:20:15 by cmariot           #+#    #+#             */
/*   Updated: 2022/08/26 20:00:51 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

template <class T, class C>
	int	compare_stack(ft::stack<T, C> ft, std::stack<T, C> std)
	{
		if (ft.size() != std.size())
			return (1);
		while (ft.empty() == false && std.empty() == false)
		{
			if (ft.top() != std.top())
				return (1);
			ft.pop();
			std.pop();
		}
		return (0);
	}


int	stack_operator_equal_tests(void)
{
	// vector
	ft::vector<int>							vector(5, 42);

	// stack construct with vector
	ft::stack<int>							container_constructor(vector);
	std::stack<int, ft::vector<int> >		std_container_constructor(vector);

	// empty stack
	ft::stack<int>							empty;
	std::stack<int, ft::vector<int> >		std_empty;

	if (compare_stack<int, ft::vector<int> >(empty, std_empty))
		return (1);

	// empty = stack(vector)
	empty = container_constructor;
	std_empty = std_container_constructor;

	if (compare_stack<int, ft::vector<int> >(container_constructor, std_container_constructor))
		return (1);

	if (compare_stack<int, ft::vector<int> >(empty, std_empty))
		return (1);

	return (0);
}
