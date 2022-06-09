/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_constructor_tests.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 14:49:23 by cmariot           #+#    #+#             */
/*   Updated: 2022/06/09 12:33:47 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

int	constructor_test(void)
{
	//Default constructor
	{
		ft::vector<char>	ft_default;
		std::vector<char>	std_default;
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
			std::vector<int>	std_copy(std_fill);
		}
	}
	return (0);
}
