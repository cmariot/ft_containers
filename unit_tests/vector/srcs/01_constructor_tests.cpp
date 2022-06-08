/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_constructor_tests.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 14:49:23 by cmariot           #+#    #+#             */
/*   Updated: 2022/06/08 17:22:42 by cmariot          ###   ########.fr       */
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
		void *	value	= NULL;

		ft::vector<void *>		ft_fill(n, value);
		std::vector<void *>		std_fill(n, value);

		// Copy constructor
		{
			ft::vector<void *>		copy(ft_fill);

			if (copy.size() != ft_fill.size())
				return (1);
		}
	}
	return (0);
}
