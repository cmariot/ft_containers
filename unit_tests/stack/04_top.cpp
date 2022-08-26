/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_top.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 19:18:05 by cmariot           #+#    #+#             */
/*   Updated: 2022/08/26 20:05:49 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

int	stack_top_tests(void)
{
	ft::stack<int>		ft_stack;
	std::stack<int>		std_stack;
	int					i;

	i = 0;
	while (i < 100)
	{
		ft_stack.push(i);
		std_stack.push(i);
		++i;
	}

	while (ft_stack.empty() == false && std_stack.empty() == false)
	{
		//std::cout << ft_stack.top() << std::endl;
		if (ft_stack.top() != std_stack.top())
			return (1);
		ft_stack.pop();
		std_stack.pop();
		--i;
	}
	return (0);
}
