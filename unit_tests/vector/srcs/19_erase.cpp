/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   19_erase.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 09:16:45 by cmariot           #+#    #+#             */
/*   Updated: 2022/06/29 19:27:44 by cmariot          ###   ########.fr       */
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


	for (size_t i = 0 ; i < 10 ; i++)
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

	//Remove the 5 first elements
	ft_vector.erase(ft_vector.begin(), ft_vector.begin() + 5);
	//Remove the third element
	ft_vector.erase(ft_vector.begin() + 3);

	//Remove the 5 first elements
	std_vector.erase(std_vector.begin(), std_vector.begin() + 5);
	//Remove the third element
	std_vector.erase(std_vector.begin() + 3);

	if (ft_vector.size() != std_vector.size())
		return (-1);
	for (size_t i = 0 ; i < 10 ; i++)
	{
		if (ft_vector.capacity() != std_vector.capacity())
			return (-1);
		if (ft_vector.empty() != std_vector.empty())
			return (-1);
	}
	return (0);
}
