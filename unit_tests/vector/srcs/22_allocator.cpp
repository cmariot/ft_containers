/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   22_allocator.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 09:17:09 by cmariot           #+#    #+#             */
/*   Updated: 2022/06/13 16:09:54 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

int	allocator_test(void)
{
	ft::vector<int>		ft_test;
	std::vector<int>	std_test;

	if (std_test.get_allocator() != ft_test.get_allocator())
		return (-1);
	return (0);
}
