/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   15_operator[].cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 10:32:00 by cmariot           #+#    #+#             */
/*   Updated: 2022/08/29 11:03:22 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

int	map_access_test(void)
{
	ft::map<char, int> mymap;

	mymap['a'] = 20;
	mymap['b'] = 40;
	mymap['c'] = 60;
	mymap['d'] = 80;
	mymap['e'] = 100;

	ft::map<char, int>::iterator	it;
	ft::map<char, int>::iterator	ite;
	it = mymap.begin();
	ite = mymap.end();
	
	while (it != ite)
	{
		//std::cout << it->first << ":" << it->second << std::endl;
		++it;
	}

	mymap['a'] = 0;
	
	it = mymap.begin();
	while (it != ite)
	{
		//std::cout << it->first << ":" << it->second << std::endl;
		++it;
	}

	return (0);
}
