/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_destructor.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 06:47:58 by cmariot           #+#    #+#             */
/*   Updated: 2022/08/29 09:14:59 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

int	map_destructor_tests(void)
{
	// DEFAULT CONSTRUCTOR : EMPTY MAP
	ft::map<int, char>	ft_map;

	ft_map.insert(std::pair<int, char>(1, 'a'));
	ft_map.insert(std::pair<int, char>(2, 'b'));
	ft_map.insert(std::pair<int, char>(3, 'c'));

	// RANGE CONSTRUCTOR
	ft::map<int, char>	ft_range(ft_map.begin(), ft_map.end()); 

	// COPY CONSTRUCTOR
	ft::map<int, char>	ft_copy(ft_map);

	// OPERATOR =
	ft_copy = ft_map;

	return (0);
}
