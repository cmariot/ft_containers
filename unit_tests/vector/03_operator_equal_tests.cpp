/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_operator_equal_tests.cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 09:14:14 by cmariot           #+#    #+#             */
/*   Updated: 2022/08/26 15:33:08 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

int	operator_equal_test(void)
{
	// Operator = on default constructor
	{
		ft::vector<char>	ft_default;
		ft::vector<char>	ft_default_equal;

		ft_default_equal = ft_default;

		std::vector<char>	std_default;
		std::vector<char>	std_default_equal;

		std_default_equal = std_default;

		if (ft_default_equal.size() != std_default_equal.size())
			return (-1);
		if (ft_default_equal.capacity() != std_default_equal.capacity())
			return (-1);
		for (size_t i = 0 ; i < ft_default.size() ; i++)
			if (ft_default_equal[i] != std_default_equal[i])
				return (-1);
	}


	// Operator = on fill constructor
	{
		size_t	n		= 5;
		int 	value	= 42;

		ft::vector<int>			ft_fill(n, value);
		ft::vector<int>			ft_fill_equal;

		ft_fill_equal = ft_fill;

		std::vector<int>		std_fill(n, value);
		std::vector<int>		std_fill_equal;

		std_fill_equal = std_fill;

		if (ft_fill.size() != std_fill.size())
			return (-1);
		if (ft_fill_equal.size() != std_fill_equal.size())
			return (-1);
		if (ft_fill_equal.capacity() != std_fill_equal.capacity())
			return (-1);
		for (size_t i = 0 ; i < ft_fill_equal.size() ; i++)
			if (ft_fill_equal[i] != std_fill_equal[i])
				return (-1);




		// Operator = on copy constructor
		{
			ft::vector<int>			ft_copy(ft_fill);
			ft::vector<int>			ft_copy_equal;

			ft_copy_equal = ft_copy;

			std::vector<int>		std_copy(std_fill);
			std::vector<int>		std_copy_equal;

			std_copy_equal = std_copy;

			if (ft_copy_equal.size() != std_copy_equal.size())
				return (-1);
			if (ft_copy_equal.capacity() != std_copy_equal.capacity())
				return (-1);
			for (size_t i = 0 ; i < ft_copy_equal.size() ; i++)
				if (ft_copy_equal[i] != std_copy_equal[i])
					return (-1);
		}



		// Range constructor
		{
			ft::vector<int>			ft_range(ft_fill.begin(), ft_fill.end());
			ft::vector<int>			ft_range_equal;

			ft_range_equal = ft_range;

			std::vector<int>		std_range(std_fill.begin(), std_fill.end());
			std::vector<int>		std_range_equal;

			std_range_equal = std_range;

			if (ft_range_equal.size() != std_range_equal.size())
				return (-1);
			if (ft_range_equal.capacity() != std_range_equal.capacity())
				return (-1);
			for (size_t i = 0 ; i < ft_range_equal.size() ; i++)
				if (ft_range_equal[i] != std_range_equal[i])
					return (-1);
		}


		// Leaks tests
		ft::vector<int>	ft_leaks_1;
		ft::vector<int>	ft_leaks_2(static_cast<size_t>(5), 42);

		ft_leaks_2 = ft_leaks_1;

		ft::vector<int>	ft_empty;

		if (ft_leaks_2.size() != ft_empty.size())
			return (-1);
		if (ft_leaks_2.capacity() < ft_leaks_2.size())
			return (-1);
		for (size_t i = 0 ; i < ft_leaks_2.size() ; i++)
			if (ft_leaks_2[i] != ft_empty[i])
				return (-1);

	}
	return (0);
}
