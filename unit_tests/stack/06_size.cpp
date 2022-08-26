/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_size.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 19:17:41 by cmariot           #+#    #+#             */
/*   Updated: 2022/08/26 20:19:38 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

template <class T, class C>
	int	compare_stack(ft::stack<T, C> ft, std::stack<T, C> std)
	{
		if (ft.size() != std.size())
			return (1);
		while (ft.size() != 0 && std.size() != 0)
		{
			if (ft.top() != std.top())
				return (1);
			ft.pop();
			std.pop();
		}
		return (0);
	}

int	stack_size_tests(void)
{

	// DEFAULT CONSTRUCTOR
	ft::stack<int>							default_constructor;
	std::stack<int, ft::vector<int> >		std_default_constructor;

	if (default_constructor.size() != 0 || std_default_constructor.size() != 0)
		return (1);

	if (compare_stack<int, ft::vector<int> >(default_constructor, std_default_constructor))
		return (1);


	// CONTAINER CONSTRUCTOR
	ft::vector<int>							vector(5, 42);

	ft::stack<int>							container_constructor(vector);
	std::stack<int, ft::vector<int> >		std_container_constructor(vector);

	if (container_constructor.size() != 5 || std_container_constructor.size() != 5)
		return (1);

	if (compare_stack<int, ft::vector<int> >(container_constructor, std_container_constructor))
		return (1);


	return (0);
}
