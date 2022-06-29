/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   15_assign.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 09:15:59 by cmariot           #+#    #+#             */
/*   Updated: 2022/06/29 18:48:38 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

int	assign_test(void)
{
	ft::vector<int>		ft_test;
	std::vector<int>	std_test;

	// Assign by size and value test
	{
		ft_test.assign(100, 6);
		std_test.assign(100, 6);
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
		ft::vector<int>			ft_tmp(44, 42);
		std::vector<int>		std_tmp(44, 42);

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
		if (ft_test.capacity() != std_test.capacity())
		{
			//return (103);
		}
	}

	ft::vector<int> vct(7);
	ft::vector<int> vct_two(4);
	ft::vector<int> vct_three;
	ft::vector<int> vct_four;

	for (unsigned long int i = 0; i < vct.size(); ++i)
		vct[i] = (vct.size() - i) * 3;
	for (unsigned long int i = 0; i < vct_two.size(); ++i)
		vct_two[i] = (vct_two.size() - i) * 5;


	vct_three.assign(vct.begin(), vct.end());
	vct.assign(vct_two.begin(), vct_two.end());
	vct_two.assign(2, 42);
	vct_four.assign(4, 21);
	vct_four.assign(6, 84);
	vct.assign(5, 53);
	vct_two.assign(vct_three.begin(), vct_three.begin() + 3);



	std::vector<int> std_vct(7);
	std::vector<int> std_vct_two(4);
	std::vector<int> std_vct_three;
	std::vector<int> std_vct_four;

	for (unsigned long int i = 0; i < std_vct.size(); ++i)
		std_vct[i] = (std_vct.size() - i) * 3;
	for (unsigned long int i = 0; i < std_vct_two.size(); ++i)
		std_vct_two[i] = (std_vct_two.size() - i) * 5;

	std_vct_three.assign(std_vct.begin(), std_vct.end());
	std_vct.assign(std_vct_two.begin(), std_vct_two.end());
	std_vct_two.assign(2, 42);
	std_vct_four.assign(4, 21);
	std_vct_four.assign(6, 84);
	std_vct.assign(5, 53);
	std_vct_two.assign(std_vct_three.begin(), std_vct_three.begin() + 3);

	if (vct.size() != std_vct.size())
		return (-1);
	for (size_t i = 0 ; i < vct.size() ; i++)
		if (vct[i] != std_vct[i])
			return (-1);

	if (vct_two.size() != std_vct_two.size())
		return (-1);
	for (size_t i = 0 ; i < vct_two.size() ; i++)
		if (vct_two[i] != std_vct_two[i])
			return (-1);
	
	if (vct_three.size() != std_vct_three.size())
		return (-1);
	for (size_t i = 0 ; i < vct.size() ; i++)
		if (vct_three[i] != std_vct_three[i])
			return (-1);

	if (vct_four.size() != std_vct_four.size())
		return (-1);
	for (size_t i = 0 ; i < vct_four.size() ; i++)
		if (vct_four[i] != std_vct_four[i])
			return (-1);

	return (0);
}
