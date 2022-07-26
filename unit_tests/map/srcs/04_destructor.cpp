/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_destructor.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 06:47:58 by cmariot           #+#    #+#             */
/*   Updated: 2022/07/26 06:50:04 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

int	destructor_tests(void)
{
	ft::map<int, char>	ft_map;

	ft_map.insert(ft::pair<int, char>(1, 'a'));
	ft_map.insert(ft::pair<int, char>(2, 'b'));
	ft_map.insert(ft::pair<int, char>(3, 'c'));

	std::map<int, char>	std_map;
	std_map.insert(std::pair<int, char>(1, 'a'));
	std_map.insert(std::pair<int, char>(2, 'b'));
	std_map.insert(std::pair<int, char>(3, 'c'));

	ft::map<int, char>	ft_range(std_map.begin(), std_map.end()); 

	// A tester apres l'implementation des iterateurs begin, end et ++
	//ft::map<int, char>	ft_copy(ft_range);

	//ft::map<int, char>	ft_equal = ft_copy;

	return (0);
}
