/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   24_swap.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 09:17:28 by cmariot           #+#    #+#             */
/*   Updated: 2022/06/14 16:22:16 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

// test for swap(vector1, vector2)

int	swap2_test(void)
{
	ft::vector<int>	foo(static_cast<size_t>(3), 100);	// three ints with a value of 100
	ft::vector<int>	foo_copy(foo);
	
	ft::vector<int>	bar(static_cast<size_t>(5), 200);	// five ints with a value of 200
	ft::vector<int>	bar_copy(bar);

	ft::swap<int, std::allocator<int> >(foo, bar);

	for (unsigned i = 0; i < foo.size() ; i++)
		if (foo[i] != bar_copy[i])
			return (-1);

	for (unsigned i = 0; i < bar.size() ; i++)
		if (bar[i] != foo_copy[i])
			return (-1);

	return (0);
}
