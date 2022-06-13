/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_size.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 09:14:41 by cmariot           #+#    #+#             */
/*   Updated: 2022/06/13 11:15:20 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

int	size_test(void)
{
	//Default constructor
	{
		ft::vector<char>	ft_default;
		std::vector<char>	std_default;

		if (ft_default.size() != std_default.size() || ft_default.size() != 0)
			return (1);
	}

	//Fill constructor
	{
		size_t	n		= 5;
		int 	value	= 42;

		ft::vector<int>			ft_fill(n, value);
		std::vector<int>		std_fill(n, value);

		if (ft_fill.size() != std_fill.size() || ft_fill.size() != n)
			return (1);

		// Copy constructor
		{
			ft::vector<int>		ft_copy(ft_fill);
			std::vector<int>	std_copy(std_fill);

			if (ft_copy.size() != std_copy.size() || ft_copy.size() != n)
				return (1);
		}

		// Range constructor
		{
			ft::vector<int>		ft_range(std_fill.begin(), std_fill.end());
			std::vector<int>	std_range(std_fill.begin(), std_fill.end());

			if (ft_range.size() != std_range.size() || ft_range.size() != n)
				return (1);
		}

		// A tester : size() apres modification des vecteurs

	}
	return (0);

}
