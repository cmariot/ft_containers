/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   14_max_size.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 10:31:52 by cmariot           #+#    #+#             */
/*   Updated: 2022/08/29 10:59:51 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

int	map_max_size_test(void)
{
	ft::map<int, char>	ft_map;

	ft_map.insert(ft::pair<int, char>(1, 'a'));
	ft_map.insert(ft::pair<int, char>(2, 'b'));
	ft_map.insert(ft::pair<int, char>(3, 'c'));

	if (ft_map.size() > ft_map.max_size())
		return (1);

	ft_map.insert(ft::pair<int, char>(1, 'a'));
	ft_map.insert(ft::pair<int, char>(2, 'b'));
	ft_map.insert(ft::pair<int, char>(3, 'c'));

	if (ft_map.size() > ft_map.max_size())
		return (1);

	ft_map.clear();

	if (ft_map.size() > ft_map.max_size())
		return (1);

	//std::map<int, char>	std_test;

	//std::cout << std_test.max_size() << std::endl;
	//std::cout << ft_map.max_size() << std::endl;

	return (0);
}
