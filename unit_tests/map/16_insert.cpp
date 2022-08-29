/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   16_insert.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 10:32:08 by cmariot           #+#    #+#             */
/*   Updated: 2022/08/29 16:23:50 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

int	map_insert_test(void)
{
	ft::map<int, char>	ft_map;

	// INSERT A RANGE
	ft::vector<ft::pair<int, char> >	ft_vector;
	for (int i = 0 ; i < 10 ; ++i)
		ft_vector.insert(ft_vector.end(), ft::make_pair<int, char>(i, 'a' + i));
	ft_map.insert(ft_vector.begin(), ft_vector.end());

	// INSERT A VALUE
	ft_map.insert(ft::make_pair<int, char>(42, '~'));

	// INSERT A VALUE WITH A HINT
	ft_map.insert(ft_map.end(), ft::make_pair<int, char>(100, '*'));


	// PRINT THE MAP
	for (ft::map<int, char>::iterator it = ft_map.begin() ; it != ft_map.end() ; ++it)
	{
		//std::cout << it->first << it->second << std::endl;
	}
	return (0);
}
