/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_destructor_tests.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 09:12:44 by cmariot           #+#    #+#             */
/*   Updated: 2022/06/13 11:09:29 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

// Test for the leaks after the destruction

int	destructor_test(void)
{
	// Destructor for the default constructor
	{
		ft::vector<char>	ft_default;
	}

	// Destructor for the fill constructor
	{
		size_t	n		= 5;
		int 	value	= 42;

		ft::vector<int>			ft_fill(n, value);
		std::vector<int>		std_fill(n, value);

		// Destructor for the copy constructor
		{
			ft::vector<int>		ft_copy(ft_fill);
		}

		// Destructor fot the range constructor
		{
			ft::vector<int>		ft_range(std_fill.begin(), std_fill.end());
		}
	}
	return (0);
}
