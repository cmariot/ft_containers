/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   08_iterators.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 20:04:06 by cmariot           #+#    #+#             */
/*   Updated: 2022/07/28 13:14:22 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

int	iterator_tests(void)
{
	ft::map<int, char>	ft_map;

	ft_map.insert(ft::pair<int, char>(1, 'a'));
	ft_map.insert(ft::pair<int, char>(2, 'b'));
	ft_map.insert(ft::pair<int, char>(3, 'c'));

	ft::map<int, char>::iterator	it;
	ft::map<int, char>::iterator	ite;

	it = ft_map.begin();
	ite = ft_map.end();

	while (it != ite)
	{
		std::cout << it->first << ":" << it->second << std::endl;
		it++;
	}
	while (it != ft_map.begin())
	{
		std::cout << it->first << ":" << it->second << std::endl;
		it--;
	}
	return (0);
}
