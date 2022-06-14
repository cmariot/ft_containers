/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   08_capacity.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 09:15:06 by cmariot           #+#    #+#             */
/*   Updated: 2022/06/14 12:10:21 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

int	capacity_test(void)
{
	//Default constructor
	{
		ft::vector<char>	ft_default;
		std::vector<char>	std_default;

		if (ft_default.capacity() != std_default.capacity() || ft_default.capacity() != 0)
			return (-1);
	}

	//Fill constructor
	{
		size_t	n		= 5;
		int 	value	= 42;

		ft::vector<int>			ft_fill(n, value);
		std::vector<int>		std_fill(n, value);

		if (ft_fill.capacity() != std_fill.capacity() || ft_fill.capacity() != n)
			return (-1);

		// Copy constructor
		{
			ft::vector<int>		ft_copy(ft_fill);
			std::vector<int>	std_copy(std_fill);

			if (ft_copy.capacity() != std_copy.capacity() || ft_copy.capacity() != n)
				return (-1);
		}

		// Range constructor
		{
			ft::vector<int>		ft_range(ft_fill.begin(), ft_fill.end());
			std::vector<int>	std_range(std_fill.begin(), std_fill.end());

			if (ft_range.capacity() != std_range.capacity() || ft_range.capacity() != n)
				return (-1);
		}

		// A tester : capacity() apres modification des vecteurs
		while (ft_fill.empty() == false && std_fill.empty() == false)
		{
			ft_fill.pop_back();
			std_fill.pop_back();
			if (ft_fill.capacity() != std_fill.capacity())
				return (-1);
		}

		for (int i = 0 ; i < 1200 ; i++)
		{
			ft_fill.push_back(i);
			std_fill.push_back(i);
			if (ft_fill.capacity() != std_fill.capacity())
				return (-1);
		}
	}
	return (0);
}
