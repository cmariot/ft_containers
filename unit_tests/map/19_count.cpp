/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   19_count.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 10:32:26 by cmariot           #+#    #+#             */
/*   Updated: 2022/08/29 12:04:48 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

int	map_count_test(void)
{
	ft::map<int, char>	ft_map;

	// INSERT VALUES
	ft::vector<ft::pair<int, char> >	ft_vector;
	for (int i = 0 ; i < 10 ; ++i)
		ft_vector.insert(ft_vector.end(), ft::make_pair<int, char>(i, 'a' + i));
	ft_map.insert(ft_vector.begin(), ft_vector.end());

	// FOUND
	for (int i = 0 ; i < 10 ; ++i)
	{
		if (ft_map.count(i) == 0)
			return (1);
	}

	// NOT FOUND
	if (ft_map.count(42) == 1)
		return (1);

	return (0);
}
