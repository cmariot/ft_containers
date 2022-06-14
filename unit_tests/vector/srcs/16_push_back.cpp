/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   16_push_back.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 09:16:10 by cmariot           #+#    #+#             */
/*   Updated: 2022/06/14 10:51:23 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

int	push_back_test(void)
{
	ft::vector<int>		ft_empty;
	std::vector<int>	std_empty;

	for (size_t i = 0 ; i < 10 ; i++)
	{
		ft_empty.push_back(i);
		std_empty.push_back(i);
		if (ft_empty[i] != std_empty[i])
			return (-1);
		std::cout << "CAPACITY : ft = " << ft_empty.capacity() << " std = " << std_empty.capacity() << std::endl;
	}

	std::cout << "END :" << std::endl;
	std::cout << "CAPACITY : ft = " << ft_empty.capacity() << " std = " << std_empty.capacity() << std::endl;
	std::cout << "SIZE : ft = " << ft_empty.size() << " std = " << std_empty.size() << std::endl;


	return (0);
}
