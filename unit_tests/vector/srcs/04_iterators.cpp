/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_iterators.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 09:14:27 by cmariot           #+#    #+#             */
/*   Updated: 2022/06/21 19:34:33 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"
#include <iostream>     // std::cout
#include <iterator>     // std::iterator, std::input_iterator_tag
#include <typeinfo>


int	iterators_test(void)
{
	//ITERATOR_TRAITS
	{
		typedef ft::iterator_traits<const int *>	traits;

		if (typeid (traits::iterator_category) != typeid (ft::random_access_iterator_tag))
			return (-1);
	}


	ft::vector<int>		vect;
	for (int i = 0 ; i < 10 ; i++)
		vect.push_back(i);


	//INPUT_ITERATOR
	{
		ft::input_iterator<int> a(&vect[0]);
		ft::input_iterator<int> b = a;

		if (a != b)
			return (-1);
		else if (!(a == b))
			return (-1);

		if (*a != 0)
			return (-1);
		
		++a;
		if (*a != 1)
			return (-1);
		
		(void)a++;
		if (*a != 2)
			return (-1);
		
		*a++;
		if (*a != 3)
			return (-1);

	}

	//OUTPUT_ITERATOR
	{
		ft::output_iterator<int> a(&vect[0]);
		ft::output_iterator<int> b = a;

		if (*a != 0)
			return (-1);
		
		++a;
		if (*a != 1)
			return (-1);
		
		(void)a++;
		if (*a != 2)
			return (-1);
		
		*a++;
		if (*a != 3)
			return (-1);

	}

	return (0);
}
