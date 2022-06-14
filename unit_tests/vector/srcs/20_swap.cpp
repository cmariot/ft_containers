/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   20_swap.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 09:16:54 by cmariot           #+#    #+#             */
/*   Updated: 2022/06/14 14:42:13 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

int	swap_test(void)
{
	ft::vector<int>	foo(static_cast<size_t>(3), 100);   // three ints with a value of 100
	ft::vector<int>	foo_copy(foo);
	
	ft::vector<int>	bar(static_cast<size_t>(5), 200);   // five ints with a value of 200
	ft::vector<int>	bar_copy(bar);

	foo.swap(bar);

	for (unsigned i = 0; i < foo.size() ; i++)
		if (foo[i] != bar_copy[i])
			return (-1);

	for (unsigned i = 0; i < bar.size() ; i++)
		if (bar[i] != foo_copy[i])
			return (-1);

	return (0);
}
