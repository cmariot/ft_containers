/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   17_erase.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 10:32:13 by cmariot           #+#    #+#             */
/*   Updated: 2022/08/29 11:21:33 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

int	map_erase_test(void)
{
	ft::map<int, char>	ft_map;

	// INSERT A RANGE
	ft::vector<ft::pair<int, char> >	ft_vector;
	for (int i = 0 ; i < 10 ; ++i)
		ft_vector.insert(ft_vector.end(), ft::make_pair<int, char>(i, 'a' + i));
	ft_map.insert(ft_vector.begin(), ft_vector.end());

	// ERASE A POS
	ft_map.erase(++(ft_map.begin()));
	for (ft::map<int, char>::iterator it = ft_map.begin() ; it != ft_map.end() ; ++it)
	{
		//std::cout << it->first << it->second << std::endl;
	}

	// ERASE A RANGE
	ft_map.erase(--(ft_map.end()), ft_map.end());
	for (ft::map<int, char>::iterator it = ft_map.begin() ; it != ft_map.end() ; ++it)
	{
		//std::cout << it->first << it->second << std::endl;
	}

	return (0);
}
