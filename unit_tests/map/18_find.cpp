/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   18_find.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 10:32:20 by cmariot           #+#    #+#             */
/*   Updated: 2022/08/29 12:03:05 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

int	map_find_test(void)
{
	ft::map<int, char>	ft_map;

	// INSERT VALUES
	ft::vector<ft::pair<int, char> >	ft_vector;
	for (int i = 0 ; i < 10 ; ++i)
		ft_vector.insert(ft_vector.end(), ft::make_pair<int, char>(i, 'a' + i));
	ft_map.insert(ft_vector.begin(), ft_vector.end());


	for (int i = 0 ; i < 10 ; ++i)
	{
		if (ft_map.find(i) == ft_map.end())
			return (1);
	}

	return (0);
}
