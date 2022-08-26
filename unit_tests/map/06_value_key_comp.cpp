/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_value_key_comp.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 07:14:17 by cmariot           #+#    #+#             */
/*   Updated: 2022/08/26 15:18:51 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

int	map_value_key_comp_tests(void)
{
	ft::map<int, char>	ft_map;


	int	value1 = 2;
	int	value2 = 1;

	bool key_comp = ft_map.key_comp()(value1, value2);

	ft::pair<int, char> pair1 = ft::make_pair<int, char>(value1, 'A');
	ft_map.insert(pair1);
	ft::pair<int, char> pair2 = ft::make_pair<int, char>(value2, 'B');
	bool value_comp = ft_map.value_comp()(*(ft_map.begin()), pair2);

	if (key_comp != value_comp)
		return (1);

	return (0);
}
