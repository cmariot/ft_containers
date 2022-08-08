/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_constructors.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 17:17:42 by cmariot           #+#    #+#             */
/*   Updated: 2022/08/08 04:08:25 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"
#include <list>

int	constructors_tests(void)
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

//	ft::map<int, char>				mp(ft_map.begin(), ft_map.end());
//	ft::map<int, char>::iterator	it = mp.begin();
//	ft::map<int, char>::iterator	ite = mp.end();



	std::list<ft::pair<const int, int> > lst;
	unsigned int lst_size = 7;
	for (unsigned int i = 0; i < lst_size; ++i)
		lst.push_back(ft::make_pair<const int, int>(lst_size - i, i));

	ft::map<const int, int> mp(lst.begin(), lst.end());
	ft::map<const int, int>::iterator it = mp.begin(), ite = mp.end();

	ft::map<const int, int> mp_range(it, --(--ite));
	for (int i = 0; it != ite; ++it)
		it->second = ++i * 5;

	it = mp.begin();
	ite = --(--mp.end());
	ft::map<const int, int> mp_copy(mp);
	for (int i = 0; it != ite; ++it)
		it->second = ++i * 7;

	mp = mp_copy;
	mp_copy = mp_range;
	mp_range.clear();



	//std::cout << ite->first << std::endl;

//	ft::map<int, char>				mp_range(it, --(--ite));
//	for (int i = 0; it != ite; ++it)
//			it->second = ++i * 5;
//
//	it = mp.begin();
//	ite = --(--mp.end());
//	
//	ft::map<int, char>				mp_copy(mp);
//	for (int i = 0; it != ite; ++it)
//			it->second = ++i * 7;
//
//	mp = mp_copy;
//	mp_copy = mp_range;
//	mp_range.clear();
//
	// A tester apres l'implementation des iterateurs begin, end et ++
	//ft::map<int, char>	ft_copy(ft_range);

	return (0);
}
