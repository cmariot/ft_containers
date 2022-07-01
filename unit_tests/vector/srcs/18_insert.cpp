/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   18_insert.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 09:16:36 by cmariot           #+#    #+#             */
/*   Updated: 2022/07/01 09:16:22 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

int	insert_test(void)
{
	ft::vector<int>		ft_test(10, 42);
	std::vector<int>	std_test(10, 42);

	ft_test.insert(ft_test.begin(), 0);
	std_test.insert(std_test.begin(), 0);
	if (ft_test.size() != std_test.size())
		return (-1);
	for (size_t i = 0 ; i < ft_test.size() ; i++)
		if (ft_test[i] != std_test[i])
			return (-1);

	size_t	len = 6;
	ft_test.insert(ft_test.begin(), len, 6);
	std_test.insert(std_test.begin(), len, 6);
	if (ft_test.size() != std_test.size())
		return (-1);
	for (size_t i = 0 ; i < ft_test.size() ; i++)
		if (ft_test[i] != std_test[i])
			return (-1);

	ft::vector<int> ft_vct(10);
	ft::vector<int> ft_vct2;

	std::vector<int> std_vct(10);
	std::vector<int> std_vct2;

	for (unsigned long int i = 0; i < ft_vct.size(); ++i)
	{
		ft_vct[i] = (ft_vct.size() - i) * 3;
		std_vct[i] = (std_vct.size() - i) * 3;
	}

	ft_vct2.insert(ft_vct2.end(), 42);
	ft_vct2.insert(ft_vct2.begin(), 2, 21);
	std_vct2.insert(std_vct2.end(), 42);
	std_vct2.insert(std_vct2.begin(), 2, 21);
	if (ft_vct2.size() != std_vct2.size())
		return (-1);
	for (size_t i = 0 ; i < ft_vct2.size() ; i++)
		if (ft_vct2[i] != std_vct2[i])
			return (-1);

	ft_vct2.insert(ft_vct2.end() - 2, 42);
	std_vct2.insert(std_vct2.end() - 2, 42);
	if (ft_vct2.size() != std_vct2.size())
		return (-1);
	for (size_t i = 0 ; i < ft_vct2.size() ; i++)
		if (ft_vct2[i] != std_vct2[i])
			return (-1);

	ft_vct2.insert(ft_vct2.end(), 2, 84);
	std_vct2.insert(std_vct2.end(), 2, 84);
	if (ft_vct2.size() != std_vct2.size())
		return (-1);
	for (size_t i = 0 ; i < ft_vct2.size() ; i++)
		if (ft_vct2[i] != std_vct2[i])
			return (-1);

	ft_vct2.resize(4);
	std_vct2.resize(4);
	if (ft_vct2.size() != std_vct2.size())
		return (-1);
	for (size_t i = 0 ; i < ft_vct2.size() ; i++)
		if (ft_vct2[i] != std_vct2[i])
			return (-1);

	ft_vct2.insert(ft_vct2.begin() + 2, ft_vct.begin(), ft_vct.end());
	std_vct2.insert(std_vct2.begin() + 2, std_vct.begin(), std_vct.end());
	if (ft_vct2.size() != std_vct2.size())
		return (-1);
	for (size_t i = 0 ; i < ft_vct2.size() ; i++)
		if (ft_vct2[i] != std_vct2[i])
			return (-1);

	ft_vct.clear();
	std_vct.clear();
	if (ft_vct.size() != std_vct.size())
		return (-1);
	for (size_t i = 0 ; i < ft_vct.size() ; i++)
		if (ft_vct[i] != std_vct[i])
			return (-1);

//	if (ft_test.capacity() != std_test.capacity())
//	{
//		std::cout << "Capacity : ft = " << ft_test.capacity() << " std = " << std_test.capacity() << std::endl;
//		return (103);
//	}
	return (0);
}
