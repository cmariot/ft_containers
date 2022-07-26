/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   07_swap.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 08:01:52 by cmariot           #+#    #+#             */
/*   Updated: 2022/07/26 17:58:47 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

int	swap_tests(void)
{
	ft::map<int, char>	ft_map;

	ft_map.insert(ft::pair<int, char>(1, 'a'));
	ft_map.insert(ft::pair<int, char>(2, 'b'));
	ft_map.insert(ft::pair<int, char>(3, 'c'));


	ft::map<int, char>	ft_map2;

	ft_map2.insert(ft::pair<int, char>(4, 'a'));
	ft_map2.insert(ft::pair<int, char>(5, 'b'));
	ft_map2.insert(ft::pair<int, char>(6, 'c'));
	ft_map2.insert(ft::pair<int, char>(7, 'c'));


	if (ft_map.size() != 3 || ft_map2.size() != 4)
		return (1);

	ft_map.swap(ft_map2);
	
	if (ft_map.size() != 4 || ft_map2.size() != 3)
		return (1);
	
	ft::swap(ft_map, ft_map2);
	
	if (ft_map.size() != 3 || ft_map2.size() != 4)
		return (1);

	return (0);
}
