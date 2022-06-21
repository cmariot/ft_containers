/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_iterators.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 09:14:27 by cmariot           #+#    #+#             */
/*   Updated: 2022/06/21 15:24:51 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"
#include <iostream>     // std::cout
#include <iterator>     // std::iterator, std::input_iterator_tag
#include <typeinfo>


int	iterators_test(void)
{
	typedef ft::iterator_traits<const int *>	traits;

	if (typeid (traits::iterator_category) != typeid (ft::random_access_iterator_tag))
		return (-1);

	std::vector<int> vect(4, 42);
	ft::random_access_iterator<int> a(&vect[0]);

	
	return (0);
}
