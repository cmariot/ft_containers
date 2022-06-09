/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_size.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 09:14:41 by cmariot           #+#    #+#             */
/*   Updated: 2022/06/09 12:12:54 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

int	size_test(void)
{
	// Size of an empty vector
	{
		std::vector<int>		std;
		ft::vector<int>			ft;

		if (std.size() != ft.size())
			return (1);
	}

	// Size of a vector
	{
		size_t	n		= 5;
		int 	value	= 42;

		ft::vector<int>			ft_fill(n, value);
		std::vector<int>		std_fill(n, value);
		
		if (std_fill.size() != ft_fill.size())
			return (1);
	}

	return (0);
}
