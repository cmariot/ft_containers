/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_iterators.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 09:14:27 by cmariot           #+#    #+#             */
/*   Updated: 2022/06/27 14:53:18 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"
#include <iostream>
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

		if (*b != 0)
			return (-1);
		
		++b;
		if (*b != 1)
			return (-1);
		
		(void)b++;
		if (*b != 2)
			return (-1);
		
		*b++;
		if (*b != 3)
			return (-1);

	}

	//FORWARD_ITERATOR
	{
		ft::forward_iterator<int> a(&vect[0]);
		ft::forward_iterator<int> b = a;
		ft::forward_iterator<int> c;
		ft::forward_iterator<int>();

		int	i = 0;
		while (*b != 9)
		{
			if (*b != i)
				return (-1);
			i++;
			b++;
		}
	}

	//BIDIRECTIONAL_ITERATOR
	{
		ft::bidirectional_iterator<int> a(&vect[9]);

		int	i = 9;
		while (*a != 0)
		{
			if (*a != i)
				return (-1);
			--i;
			--a;
		}

		ft::bidirectional_iterator<int> b(&vect[9]);

		int	j = 9;
		while (*b != 0)
		{
			if (*b != j)
				return (-1);
			--j;
			b--;
		}

		ft::bidirectional_iterator<int> c(&vect[9]);

		int	k = 9;
		while (*c-- != 0)
		{
			--k;
			if (*c != k)
				return (-1);
		}
	}


	// RANDOM_ACCESS_ITERATORS
	{
		ft::random_access_iterator<int> a(&vect[0]);
		std::ptrdiff_t					diff = 3;

		ft::random_access_iterator<int> b = a + diff;
		if (*b != 3)
			return (-1);

		ft::random_access_iterator<int> c = a + diff - (diff - 1);
		if (*c != 1)
			return (-1);

		b += diff;
		if (*b != 6)
			return (-1);
		c += 2;
		c -= 1;
		if (*c != 2)
			return (-1);

		if (!(c < b))
			return (-1);
		if (c > b)
			return (-1);
		if (c >= b)
			return (-1);
		if (!(c <= b))
			return (-1);
	}

	return (0);
}
