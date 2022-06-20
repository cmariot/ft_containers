/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   16_push_back.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 09:16:10 by cmariot           #+#    #+#             */
/*   Updated: 2022/06/20 15:17:49 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

int	push_back_test(void)
{
	ft::vector<char>		ft_vector;
	std::vector<char>	std_vector;

	for (size_t i = 0 ; i < 150 ; i++)
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
