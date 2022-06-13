/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_constructor_tests.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 14:49:23 by cmariot           #+#    #+#             */
/*   Updated: 2022/06/13 10:58:51 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

int	constructor_test(void)
{
	//Default constructor
	{
		ft::vector<char>	ft_default;
		std::vector<char>	std_default;

		if (ft_default.size() != std_default.size())
			return (1);
		if (ft_default.capacity() != std_default.capacity())
			return (1);
		if (ft_default.empty() != std_default.empty())
			return (1);
	}

	//Fill constructor
	{
		size_t	n		= 5;
		int 	value	= 42;

		ft::vector<int>			ft_fill(n, value);
		std::vector<int>		std_fill(n, value);

		if (ft_fill.size() != std_fill.size())
			return (1);
		if (ft_fill.capacity() != std_fill.capacity())
			return (1);
		if (ft_fill.empty() != std_fill.empty())
			return (1);
		for (size_t i = 0 ; i < ft_fill.size() ; i++)
			if (ft_fill[i] != std_fill[i])
				return (1);

		// Copy constructor
		{
			ft::vector<int>		ft_copy(ft_fill);
			std::vector<int>	std_copy(std_fill);

			if (ft_copy.size() != std_copy.size())
				return (1);
			if (ft_copy.capacity() != std_copy.capacity())
				return (1);
			if (ft_copy.empty() != std_copy.empty())
				return (1);
			for (size_t i = 0 ; i < ft_copy.size() ; i++)
				if (ft_copy[i] != std_copy[i])
					return (1);
		}

		// Range constructor
		{
			ft::vector<int>		ft_range(std_fill.begin(), std_fill.end());
			std::vector<int>	std_range(std_fill.begin(), std_fill.end());

			if (ft_range.size() != std_range.size())
				return (1);
			if (ft_range.capacity() != std_range.capacity())
				return (1);
			if (ft_range.empty() != std_range.empty())
				return (1);
			for (size_t i = 0 ; i < ft_range.size() ; i++)
				if (ft_range[i] != std_range[i])
					return (1);
		}
	}
	return (0);
}
