/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   17_pop_back.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 09:16:26 by cmariot           #+#    #+#             */
/*   Updated: 2022/06/14 11:08:44 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

int	pop_back_test(void)
{
	ft::vector<int>		ft_vector;
	std::vector<int>	std_vector;

	for (int i = 0 ; i < 1000 ; i++)
	{
		ft_vector.push_back(i);
		std_vector.push_back(i);
	}

	int	i = 0;
	while (ft_vector.empty() == false && std_vector.empty() == false)
	{
		ft_vector.pop_back();
		std_vector.pop_back();
		if (ft_vector[i] != std_vector[i])
			return (-1);
		else if (ft_vector.capacity() != std_vector.capacity())
			return (-1);
		else if (ft_vector.size() != std_vector.size())
			return (-1);
		i++;
	}
	return (0);
}
