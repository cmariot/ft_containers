/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_max_size.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 09:14:47 by cmariot           #+#    #+#             */
/*   Updated: 2022/06/14 18:54:37 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

int	max_size_test(void)
{
	//Default constructor
	{
		ft::vector<char>	ft_default;
		std::vector<char>	std_default;

		if (ft_default.max_size() != std_default.max_size())
			return (-1);
	}

	//Fill constructor
	{
		size_t	n		= 5;
		int 	value	= 42;

		ft::vector<int>			ft_fill(n, value);
		std::vector<int>		std_fill(n, value);

		if (ft_fill.max_size() != std_fill.max_size())
			return (-1);

		// Copy constructor
		{
			ft::vector<int>		ft_copy(ft_fill);
			std::vector<int>	std_copy(std_fill);

			if (ft_copy.max_size() != std_copy.max_size())
				return (-1);
		}

		// Range constructor
		{
			ft::vector<int>		ft_range(ft_fill.begin(), ft_fill.end());
			std::vector<int>	std_range(std_fill.begin(), std_fill.end());

			if (ft_range.max_size() != std_range.max_size())
				return (-1);
		}
	}

	// Difference selon les systemes

	return (0);
}
