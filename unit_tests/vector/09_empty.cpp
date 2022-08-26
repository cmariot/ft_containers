/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   09_empty.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 09:15:15 by cmariot           #+#    #+#             */
/*   Updated: 2022/06/13 18:53:57 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

int	empty_test(void)
{
	//Default constructor
	{
		ft::vector<char>	ft_default;
		std::vector<char>	std_default;

		if (ft_default.empty() != std_default.empty() || ft_default.empty() != true)
			return (-1);
	}

	//Fill constructor
	{
		size_t	n		= 5;
		int 	value	= 42;

		ft::vector<int>			ft_fill(n, value);
		std::vector<int>		std_fill(n, value);

		if (ft_fill.empty() != std_fill.empty() || ft_fill.empty() != false)
			return (-1);

		// Copy constructor
		{
			ft::vector<int>		ft_copy(ft_fill);
			std::vector<int>	std_copy(std_fill);

			if (ft_copy.empty() != std_copy.empty() || ft_copy.empty() != false)
				return (-1);
		}

		// Range constructor
		{
			ft::vector<int>		ft_range(ft_fill.begin(), ft_fill.end());
			std::vector<int>	std_range(std_fill.begin(), std_fill.end());

			if (ft_range.empty() != std_range.empty() || ft_range.empty() != false)
				return (-1);
		}
	}
	return (0);
}
