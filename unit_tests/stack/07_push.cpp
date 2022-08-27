/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   07_push.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 19:17:36 by cmariot           #+#    #+#             */
/*   Updated: 2022/08/27 09:03:13 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

int	stack_push_tests(void)
{
	ft::stack<int>	ft_stack;
	
	if (ft_stack.size() != 0)
		return (1);

	ft_stack.push(1);
	ft_stack.push(2);
	ft_stack.push(3);
	ft_stack.push(4);
	ft_stack.push(5);

	if (ft_stack.empty() == true)
		return (1);

	if (ft_stack.size() != 5)
		return (1);

	for (int i = 0 ; i != 5 ; ++i)
		ft_stack.pop();


	if (ft_stack.size() != 0 || ft_stack.empty() == false)
		return (1);


	for (size_t i = 0 ; i < 100 ; i++)
	{
		ft_stack.push(i);
		if (ft_stack.top() != static_cast<int>(i))
			return (1);
		if (ft_stack.size() != i + 1)
			return (1);
	}

	if (ft_stack.size() != 100)
		return (1);
	
	return (0);
}
