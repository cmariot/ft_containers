/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_destructor_tests.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 09:12:44 by cmariot           #+#    #+#             */
/*   Updated: 2022/06/13 11:00:03 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

int	destructor_test(void)
{
	//Default constructor
	{
		ft::vector<char>	ft_default;
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
	}
	return (0);
}
