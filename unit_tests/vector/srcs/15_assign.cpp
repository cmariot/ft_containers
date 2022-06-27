/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   15_assign.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 09:15:59 by cmariot           #+#    #+#             */
/*   Updated: 2022/06/27 09:02:44 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

int	assign_test(void)
{
	ft::vector<int>		ft_test;
	std::vector<int>	std_test;

	// Assign by size and value test
	{
		size_t	size = 1000;
		int		value = 6;

		ft_test.assign(size, value);
		std_test.assign(size, value);
		if (ft_test.size() != std_test.size())
			return (-1);
		for (size_t i = 0 ; i < ft_test.size() ; i++)
			if (ft_test[i] != std_test[i])
				return (-1);
		if (ft_test.capacity() != std_test.capacity())
			return (-1);
	}

	// Assign by iterators test
	{
		ft::vector<int>			ft_tmp(static_cast<size_t>(444), 42);
		std::vector<int>		std_tmp(static_cast<size_t>(444), 42);

		ft_test.assign(ft_tmp.begin(), ft_tmp.end());
		std_test.assign(std_tmp.begin(), std_tmp.end());
		if (ft_test.size() != std_test.size())
			return (-1);
		for (size_t i = 0 ; i < ft_test.size() ; i++)
			if (ft_test[i] != std_test[i])
				return (-1);
		
		//Additionally, in the range version (1), if InputIterator is not at least of a forward iterator category
		//(i.e., it is just an input iterator) the new capacity cannot be determined beforehand and the operation
		//incurs in additional logarithmic complexity in the new size (reallocations while growing).
		//
		//capacity = 1000
		//
		//if (ft_test.capacity() != std_test.capacity())
		//{
		//	std::cout << "TMP CAP : " << tmp.capacity() << std::endl;
		//	std::cout << "FT CAP : " << ft_test.capacity() << " vs " << std_test.capacity() << std::endl;
		//	return (103);
		//}
	}


	return (0);
}
