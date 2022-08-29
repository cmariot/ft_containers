/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   08_iterators.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 20:04:06 by cmariot           #+#    #+#             */
/*   Updated: 2022/08/29 10:53:14 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

int	map_iterator_tests(void)
{
	ft::map<int, char>	ft_map;

	ft_map.insert(ft::pair<int, char>(1, 'a'));
	ft_map.insert(ft::pair<int, char>(2, 'b'));
	ft_map.insert(ft::pair<int, char>(3, 'c'));

	// ITERATORS
	ft::map<int, char>::iterator	it;
	ft::map<int, char>::iterator	ite;
	it = ft_map.begin();
	ite = ft_map.end();
	while (it != ite)
	{
		//std::cout << it->first << ":" << it->second << std::endl;
		++it;
	}

	// CONST ITERATORS
	ft::map<int, char>::const_iterator	cit = ft_map.begin();
	ft::map<int, char>::const_iterator	cite = ft_map.end();
	while (cit != cite)
	{
		//std::cout << cit->first << ":" << cit->second << std::endl;
		++cit;
	}

	// REVERSE ITERATORS
	ft::map<int, char>::reverse_iterator	rit;
	ft::map<int, char>::reverse_iterator	rite;
	rit = ft_map.rbegin();
	rite = ft_map.rend();
	while (rit != rite)
	{
		//std::cout << rit->first << ":" << rit->second << std::endl;
		++rit;
	}
	// REVERSE CONST ITERATORS
	ft::map<int, char>::reverse_iterator	crit = ft_map.rbegin();
	ft::map<int, char>::reverse_iterator	crite = ft_map.rend();
	while (crit != crite)
	{
		//std::cout << crit->first << ":" << crit->second << std::endl;
		++crit;
	}

	return (0);
}
