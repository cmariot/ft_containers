/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_operator_equal.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 10:31:40 by cmariot           #+#    #+#             */
/*   Updated: 2022/08/29 12:21:38 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

int	map_equal_test(void)
{
	// DEFAULT CONSTRUCTOR : EMPTY MAP
	ft::map<int, char>	ft_map;
	ft::map<int, char>	ft_copy;
	ft::map<int, char>	ft_backup;

	ft_map.insert(ft::pair<int, char>(1, 'a'));
	ft_map.insert(ft::pair<int, char>(2, 'b'));
	ft_map.insert(ft::pair<int, char>(3, 'c'));

	// OPERATOR =
	ft_copy = ft_map;
	ft_copy = ft_backup;


	// DEFAULT CONSTRUCTOR : EMPTY MAP
	ft::map<std::string, char>	ft_map2;
	ft::map<std::string, char>	ft_copy2;
	ft::map<std::string, char>	ft_backup2;

	ft_map2.insert(ft::pair<std::string, char>("test1", 'a'));
	ft_map2.insert(ft::pair<std::string, char>("test2", 'b'));
	ft_map2.insert(ft::pair<std::string, char>("test3", 'c'));

	// OPERATOR =
	ft_copy2 = ft_map2;
	ft_copy2 = ft_backup2;

	return (0);
}
