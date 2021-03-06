/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_constructors.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 17:17:42 by cmariot           #+#    #+#             */
/*   Updated: 2022/07/21 21:07:08 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

int	constructors_tests(void)
{
	ft::map<int, char>	ft_map;

	ft_map.insert(ft::pair<int, char>(1, 'a'));
	ft_map.insert(ft::pair<int, char>(2, 'b'));
	ft_map.insert(ft::pair<int, char>(3, 'c'));
	ft_map.insert(ft::pair<int, char>(4, 'd'));

	ft_map._tree.print();
	std::cout << ft_map.size() << std::endl;

	ft_map.clear();
	std::cout << ft_map.size() << std::endl;



	std::map<int, char> std_map;

	std_map.insert(std::make_pair<int, char>(1, 'b'));
	std_map.insert(std::make_pair<int, char>(0, 'a'));
	std_map.insert(std::make_pair<int, char>(2, 'c'));
	std_map.insert(std::make_pair<int, char>(3, 'd'));

	std::cout << std_map.begin()->second << std::endl;


	return (0);
}
