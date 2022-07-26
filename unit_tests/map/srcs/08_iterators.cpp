/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   08_iterators.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 20:04:06 by cmariot           #+#    #+#             */
/*   Updated: 2022/07/26 20:13:46 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

int	iterator_tests(void)
{
	ft::map<int, char>	ft_map;

	ft_map.insert(ft::pair<int, char>(1, 'a'));
	ft_map.insert(ft::pair<int, char>(2, 'b'));
	ft_map.insert(ft::pair<int, char>(3, 'c'));

	std::cout << ft_map.begin()->first << std::endl;
	
	std::cout << ft_map.end()->first << std::endl;

	return (0);
}
