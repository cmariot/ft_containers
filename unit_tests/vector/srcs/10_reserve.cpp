/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10_reserve.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 09:15:23 by cmariot           #+#    #+#             */
/*   Updated: 2022/06/14 17:35:23 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

int	reserve_test(void)
{
	ft::vector<int>					ft_foo;
	std::vector<int>				std_foo;

	for (int i = 0 ; i < 50 ; ++i)
	{
		ft_foo.push_back(i);
		std_foo.push_back(i);
		if (ft_foo.capacity() != std_foo.capacity())
			return (-1);
	}


	ft::vector<int>					ft_bar;
	std::vector<int>				std_bar;

	ft_bar.reserve(100);    // this is the only difference with foo above
	std_bar.reserve(100);   // this is the only difference with foo above
	for (int i = 0 ; i < 100 ; ++i)
	{
		ft_bar.push_back(i);
		std_bar.push_back(i);
		if (ft_bar.capacity() != std_bar.capacity())
			return (-1);
		if (ft_bar[i] != std_bar[i])
			return (-1);
		else if (ft_bar.size() != std_bar.size())
			return (-1);
	}

	ft_bar.reserve(ft_bar.capacity());     // this is the only difference with foo above
	std_bar.reserve(std_bar.capacity());   // this is the only difference with foo above
	for (size_t i = 0 ; i < ft_bar.size() || i < std_bar.size() ; ++i)
	{
		if (ft_bar.capacity() != std_bar.capacity())
			return (-1);
		if (ft_bar[i] != std_bar[i])
			return (-1);
		else if (ft_bar.size() != std_bar.size())
			return (-1);
	}
	return 0;

}
