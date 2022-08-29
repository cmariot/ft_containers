/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   13_size.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 10:31:47 by cmariot           #+#    #+#             */
/*   Updated: 2022/08/29 10:57:22 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

int	map_size_test(void)
{
	ft::map<int, char>	ft_map;

	ft_map.insert(ft::pair<int, char>(1, 'a'));
	ft_map.insert(ft::pair<int, char>(2, 'b'));
	ft_map.insert(ft::pair<int, char>(3, 'c'));

	ft_map.clear();

	if (ft_map.size() != 0)
		return (1);

	ft_map.insert(ft::pair<int, char>(1, 'a'));
	ft_map.insert(ft::pair<int, char>(2, 'b'));
	ft_map.insert(ft::pair<int, char>(3, 'c'));

	if (ft_map.size() != 3)
		return (1);

	ft_map.clear();

	if (ft_map.size() != 0)
		return (1);
	return (0);
}
