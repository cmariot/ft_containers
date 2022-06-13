/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   12_at.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 09:15:39 by cmariot           #+#    #+#             */
/*   Updated: 2022/06/13 14:43:50 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

int	at_test(void)
{
	std::vector<int>	vector;
	for (int i = 0; i < 100 ; i++)
		vector.push_back(i);
		
	ft::vector<int>		ft_vector(vector.begin(), vector.end());

	for (size_t i = 0 ; i < ft_vector.size() ; i++)
		if (ft_vector.at(i) != vector.at(i))
			return (-1);

	// Exception when trying to get an element at an out of range index
	try
	{
		vector.at(42000);
	}
	catch (std::out_of_range &exception)
	{
		std::cerr << exception.what() << std::endl;
	}

	try
	{
		ft_vector.at(42000);
	}
	catch (std::out_of_range &exception)
	{
		std::cerr << exception.what() << std::endl;
	}

	return (0);
}
