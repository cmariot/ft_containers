/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_operator_equal_tests.cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 09:14:14 by cmariot           #+#    #+#             */
/*   Updated: 2022/06/09 13:41:44 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

int	operator_equal_test(void)
{
	{
		ft::vector<char>	ft_default;
		ft::vector<char>	test(5, 'a');

		test = ft_default;
		if (test.size() != ft_default.size())
			return (1);
	}
	{
		std::vector<char>	ft_default;
		std::vector<char>	test(5, 'a');

		test = ft_default;
		if (test.size() != ft_default.size())
			return (1);
	}
	return (0);
}
