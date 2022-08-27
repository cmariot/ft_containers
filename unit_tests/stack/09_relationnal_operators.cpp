/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   09_relationnal_operators.cpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 19:17:00 by cmariot           #+#    #+#             */
/*   Updated: 2022/08/27 23:07:45 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

int	stack_relational_operators_tests(void)
{
	ft::vector<int>	vector1(5, 42);
	ft::vector<int>	vector2(5, 0);

	ft::stack<int>	ft_1(vector1);
	ft::stack<int>	ft_2(vector2);

	if (ft_1 == ft_2)
		return (1);
	if (!(ft_1 != ft_2))
		return (1);
	if (ft_1 < ft_2)
		return (1);
	if (ft_1 <= ft_2)
		return (1);
	if (!(ft_1 > ft_2))
		return (1);
	if (!(ft_1 >= ft_2))
		return (1);

	ft::stack<int>	ft_3(vector1);

	if (!(ft_1 == ft_3))
		return (1);
	if (ft_1 != ft_3)
		return (1);
	if (ft_1 < ft_3)
		return (1);
	if (!(ft_1 <= ft_3))
		return (1);
	if (ft_1 > ft_3)
		return (1);
	if (!(ft_1 >= ft_3))
		return (1);

	return (0);
}
