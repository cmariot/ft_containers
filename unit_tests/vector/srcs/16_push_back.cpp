/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   16_push_back.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 09:16:10 by cmariot           #+#    #+#             */
/*   Updated: 2022/06/14 10:19:58 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

int	push_back_test(void)
{
	ft::vector<int>		ft_vector;
	std::vector<int>	std_vector;

	for (size_t i = 0 ; i < 1000 ; i++)
	{
		ft_vector.push_back(i);
		std_vector.push_back(i);
		if (ft_vector[i] != std_vector[i])
			return (-1);
		else if (ft_vector.capacity() != std_vector.capacity())
			return (-1);
		else if (ft_vector.size() != std_vector.size())
			return (-1);
	}
	return (0);
}
