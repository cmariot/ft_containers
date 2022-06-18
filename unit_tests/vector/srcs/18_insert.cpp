/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   18_insert.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 09:16:36 by cmariot           #+#    #+#             */
/*   Updated: 2022/06/17 12:44:55 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

int	insert_test(void)
{
	ft::vector<int>		ft_test(static_cast<size_t>(10), 42);
	std::vector<int>	std_test(static_cast<size_t>(10), 42);

	ft_test.insert(ft_test.begin(), 0);
	std_test.insert(std_test.begin(), 0);
	if (ft_test.size() != std_test.size())
		return (101);
	for (size_t i = 0 ; i < ft_test.size() ; i++)
		if (ft_test[i] != std_test[i])
			return (102);

	size_t	len = 6;
	ft_test.insert(ft_test.begin(), len, 6);
	std_test.insert(std_test.begin(), len, 6);
	if (ft_test.size() != std_test.size())
		return (101);
	for (size_t i = 0 ; i < ft_test.size() ; i++)
		if (ft_test[i] != std_test[i])
			return (102);


//	if (ft_test.capacity() != std_test.capacity())
//	{
//		std::cout << "Capacity : ft = " << ft_test.capacity() << " std = " << std_test.capacity() << std::endl;
//		return (103);
//	}
	return (0);
}
