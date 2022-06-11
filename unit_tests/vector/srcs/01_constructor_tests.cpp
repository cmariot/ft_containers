/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_constructor_tests.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 14:49:23 by cmariot           #+#    #+#             */
/*   Updated: 2022/06/11 13:26:56 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

int	constructor_test(void)
{
	//Default constructor
	{
		std::vector<char>	ft_default;
	}

	//Fill constructor
	{
		size_t	n		= 5;
		int 	value	= 42;

		ft::vector<int>			ft_fill(n, value);
		std::vector<int>		std_fill(n, value);

		// Copy constructor
		{
			ft::vector<int>		ft_copy(ft_fill);
		}

		// Range constructor
		{
			ft::vector<int>		ft_range(std_fill.begin(), std_fill.end());
		}

		// Operator equal
		{
			ft::vector<int>		ft_equal = ft_fill;
			ft_equal = ft_fill;
		}
	}
	return (0);
}
