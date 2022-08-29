/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_constructors.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 17:17:42 by cmariot           #+#    #+#             */
/*   Updated: 2022/08/29 10:46:55 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"
#include <list>

int	map_constructors_tests(void)
{

	// DEFAULT CONSTRUCTOR : EMPTY MAP
	ft::map<int, char>	ft_map;

	ft_map.insert(ft::pair<int, char>(1, 'a'));
	ft_map.insert(ft::pair<int, char>(2, 'b'));
	ft_map.insert(ft::pair<int, char>(3, 'c'));

	// RANGE CONSTRUCTOR
	ft::map<int, char>	ft_range(ft_map.begin(), ft_map.end()); 

	// COPY CONSTRUCTOR
	ft::map<int, char>	ft_copy(ft_map);

	// OPERATOR =
	ft_copy = ft_map;

	return (0);
}
