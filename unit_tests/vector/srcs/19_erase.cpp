/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   19_erase.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 09:16:45 by cmariot           #+#    #+#             */
/*   Updated: 2022/06/14 12:38:11 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

int	erase_test(void)
{
	ft::vector<int>		ft_vector;
	std::vector<int>	std_vector;

	for (size_t i = 0 ; i < 100 ; i++)
	{
		ft_vector.push_back(i);
		std_vector.push_back(i);
	}


	for (size_t i = 0 ; i < 100 ; i++)
	{
		ft_vector.erase(ft_vector.begin());
		std_vector.erase(std_vector.begin());
		if (ft_vector.size() != std_vector.size())
			return (-1);
		if (ft_vector.capacity() != std_vector.capacity())
			return (-1);
		if (ft_vector.empty() != std_vector.empty())
			return (-1);
	}
	return (0);
}
