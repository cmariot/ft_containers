/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   07_swap.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 08:01:52 by cmariot           #+#    #+#             */
/*   Updated: 2022/07/26 08:06:53 by cmariot          ###   ########.fr       */
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


	ft_map.swap(ft_map2);


	return (0);
}
