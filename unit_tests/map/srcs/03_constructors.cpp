/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_constructors.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 17:17:42 by cmariot           #+#    #+#             */
/*   Updated: 2022/07/26 05:06:25 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

#include <map>

int	constructors_tests(void)
{
	ft::map<int, char>	ft_map;
	std::map<int, char>	std_map;

	ft_map.insert(ft::pair<int, char>(1, 'a'));
	ft_map.insert(ft::pair<int, char>(2, 'b'));
	ft_map.insert(ft::pair<int, char>(3, 'c'));

	std_map.insert(std::pair<int, char>(1, 'a'));
	std_map.insert(std::pair<int, char>(2, 'b'));
	std_map.insert(std::pair<int, char>(3, 'c'));

	ft::map<int, char>	ft_range(std_map.begin(), std_map.end()); 
//	ft_map.insert(ft::pair<int, char>(1, 'a'));
	//ft_map.insert(ft::pair<int, char>(2, 'b'));
	//ft_map.insert(ft::pair<int, char>(3, 'c'));
	//ft_map.insert(ft::pair<int, char>(4, 'd'));

//	ft_map._tree.print();
//	std::cout << "ICI : " << ft_map.begin()->first << std::endl;
	//std::cout << ft_map.size() << std::endl;

	//ft_map.clear();
	//std::cout << ft_map.size() << std::endl;


//	std::map<int, char> std_map;
//
//	std_map.insert(std::make_pair<int, char>(1, 'b'));
//	std_map.insert(std::make_pair<int, char>(4, 'a'));
//	std_map.insert(std::make_pair<int, char>(2, 'c'));
//	std_map.insert(std::make_pair<int, char>(3, 'd'));
//
//	std::cout << std_map.begin()->first << std::endl;


	return (0);
}
