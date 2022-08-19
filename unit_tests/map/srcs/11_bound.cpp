/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   11_bound.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 16:41:57 by cmariot           #+#    #+#             */
/*   Updated: 2022/08/18 10:33:33 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

int	bound_tests(void)
{
	ft::map<int, char>	ft_map;

	ft_map.insert(ft::make_pair<int, char>(0, 'a'));
	ft_map.insert(ft::make_pair<int, char>(1, 'b'));
	ft_map.insert(ft::make_pair<int, char>(2, 'c'));
	ft_map.insert(ft::make_pair<int, char>(3, 'd'));
	ft_map.insert(ft::make_pair<int, char>(4, 'e'));
	ft_map.insert(ft::make_pair<int, char>(5, 'f'));

	std::cout << ft_map.lower_bound(2)->first << std::endl;

	ft::map<char,int> mymap;
	ft::map<char,int>::iterator itlow, itup;

	mymap['a'] = 20;
	mymap['b'] = 40;
	mymap['c'] = 60;
	mymap['d'] = 80;
	mymap['e'] = 100;

	itlow = mymap.lower_bound('b');   // itlow points to b
	itup  = mymap.upper_bound('d');   // itup points to e (not d!)

	mymap.print();


	mymap.erase(mymap.begin(), mymap.end());        // erases [itlow,itup)

	mymap.print();

	// print content:
	for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
		std::cout << it->first << " => " << it->second << std::endl;

	return (0);
}
