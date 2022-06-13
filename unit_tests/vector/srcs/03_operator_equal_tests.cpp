/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_operator_equal_tests.cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 09:14:14 by cmariot           #+#    #+#             */
/*   Updated: 2022/06/13 11:03:33 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

int	operator_equal_test(void)
{
	//Default constructor
	{
		ft::vector<char>	ft_default;
		ft::vector<char>	ft_default_equal;

		ft_default_equal = ft_default;
	}

	//Fill constructor
	{
		size_t	n		= 5;
		int 	value	= 42;

		ft::vector<int>			ft_fill(n, value);
		ft::vector<int>			ft_fill_equal;

		ft_fill_equal = ft_fill;

		std::vector<int>		std_fill(n, value);

		// Copy constructor
		{
			ft::vector<int>		ft_copy(ft_fill);
			ft::vector<int>		ft_copy_equal;

			ft_copy_equal = ft_copy;
		}

		// Range constructor
		{
			ft::vector<int>		ft_range(std_fill.begin(), std_fill.end());
			ft::vector<int>		ft_range_equal;

			ft_range_equal = ft_range;
			ft_range_equal = ft_range;
		}
	}
	return (0);
}
