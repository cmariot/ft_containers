/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_iterators.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 09:14:27 by cmariot           #+#    #+#             */
/*   Updated: 2022/06/21 10:20:56 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"
#include <iostream>     // std::cout
#include <iterator>     // std::iterator, std::input_iterator_tag



int	iterators_test(void)
{
	ft::vector<int>		ft_iterators(static_cast<size_t>(5), 0);

	// Assign elements to their new value with iterators
	int	i = 0;
	for (ft::vector<int>::iterator begin = ft_iterators.begin() ; begin != ft_iterators.end() ; begin++)
	{
		*begin = i;
		i++;
	}

	// Check value with iterators
	i = 0;
	for (ft::vector<int>::iterator begin = ft_iterators.begin() ; begin != ft_iterators.end() ; begin++)
	{
		if (*begin != i)
			return (-1);
		i++;
	}

	// Reverse iterator
	// + Const ?
	//
	//


	return (-1);
}
