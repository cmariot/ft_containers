/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   08_pop.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 19:17:20 by cmariot           #+#    #+#             */
/*   Updated: 2022/08/27 09:15:42 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

int	stack_pop_tests(void)
{
	ft::vector<int> ft_vector(5, 42);
	
	ft::stack<int>	ft_stack(ft_vector);

	if (ft_stack.size() != 5)
		return (1);

	size_t	n = ft_stack.size();

	while (ft_stack.empty() == false)
	{
		if (ft_stack.top() != 42)
			return (1);
		ft_stack.pop();
		if (ft_stack.size() !=  --n)
			return (1);
	}

	return (0);
}
