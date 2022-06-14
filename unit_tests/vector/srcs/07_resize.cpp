/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   07_resize.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 09:14:56 by cmariot           #+#    #+#             */
/*   Updated: 2022/06/14 16:17:07 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

int	resize_test(void)
{
	ft::vector<int>		ft_vector;
	std::vector<int>	std_vector;

	for (int i = 0 ; i < 10 ; i++)
	{
		ft_vector.push_back(i);
		std_vector.push_back(i);
	}

	//Bigger size w/ defaut value
	size_t	new_size = 15;

	ft_vector.resize(new_size);
	std_vector.resize(new_size);
	if (ft_vector.size() != std_vector.size())
		return (-1);
	if (ft_vector.capacity() != std_vector.capacity())
		return (-1);
	for (size_t i = 0 ; i < ft_vector.size() ; i++)
		if (ft_vector[i] != std_vector[i])
			return (-1);

	//Same size w/ defaut value
	new_size = 15;

	ft_vector.resize(new_size);
	std_vector.resize(new_size);
	if (ft_vector.size() != std_vector.size())
		return (-1);
	if (ft_vector.capacity() != std_vector.capacity())
		return (-1);
	for (size_t i = 0 ; i < ft_vector.size() ; i++)
		if (ft_vector[i] != std_vector[i])
			return (-1);

	//Smaller size w/ defaut value
	new_size = 5;

	ft_vector.resize(new_size);
	std_vector.resize(new_size);
	if (ft_vector.size() != std_vector.size())
		return (-1);
	if (ft_vector.capacity() != std_vector.capacity())
		return (-1);
	for (size_t i = 0 ; i < ft_vector.size() ; i++)
		if (ft_vector[i] != std_vector[i])
			return (-1);

	//Same size w/ defined value
	new_size = 5;

	ft_vector.resize(new_size, 6);
	std_vector.resize(new_size, 6);
	if (ft_vector.size() != std_vector.size())
		return (-1);
	if (ft_vector.capacity() != std_vector.capacity())
		return (-1);
	for (size_t i = 0 ; i < ft_vector.size() ; i++)
		if (ft_vector[i] != std_vector[i])
			return (-1);

	//Bigger size w/ defined value
	new_size = 15;

	ft_vector.resize(new_size, 42);
	std_vector.resize(new_size, 42);
	if (ft_vector.size() != std_vector.size())
		return (-1);
	if (ft_vector.capacity() != std_vector.capacity())
		return (-1);
	for (size_t i = 0 ; i < ft_vector.size() ; i++)
		if (ft_vector[i] != std_vector[i])
			return (-1);

	//Smaller size w/ defined value
	new_size = 5;

	ft_vector.resize(new_size, 21);
	std_vector.resize(new_size, 21);
	if (ft_vector.size() != std_vector.size())
		return (-1);
	if (ft_vector.capacity() != std_vector.capacity())
		return (-1);
	for (size_t i = 0 ; i < ft_vector.size() ; i++)
		if (ft_vector[i] != std_vector[i])
			return (-1);



	return (0);
}
