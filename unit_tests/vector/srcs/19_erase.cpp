/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   19_erase.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 09:16:45 by cmariot           #+#    #+#             */
/*   Updated: 2022/07/01 08:57:48 by cmariot          ###   ########.fr       */
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
	std_vector.erase(std_vector.begin(), std_vector.begin() + 5);
	if (ft_vector.size() != std_vector.size())
		return (-1);
	//Remove the third element
	ft_vector.erase(ft_vector.begin() + 3);
	std_vector.erase(std_vector.begin() + 3);
	if (ft_vector.size() != std_vector.size())
		return (-1);


	ft::vector<std::string> vct(10);

	for (unsigned long int i = 0; i < vct.size(); ++i)
		vct[i] = std::string((vct.size() - i), i + 65);

	vct.erase(vct.begin() + 2);

	vct.erase(vct.begin());
	vct.erase(vct.end() - 1);
	vct.erase(vct.begin(), vct.begin() + 3);
	vct.erase(vct.end() - 3, vct.end() - 1);

	vct.push_back("Hello");
	vct.push_back("Hi there");
	std::cout << *(vct.end() - 1) << std::endl;
	vct.erase(vct.end() - 3, vct.end());

	vct.push_back("ONE");
	vct.push_back("TWO");
	vct.push_back("THREE");
	vct.push_back("FOUR");
	vct.erase(vct.begin(), vct.end());


	ft_vector.erase(ft_vector.begin() + 5, ft_vector.begin() + 10);
	std_vector.erase(std_vector.begin() + 5, std_vector.begin() + 10);

	if (ft_vector.size() != std_vector.size())
		return (-1);
	for (size_t i = 0 ; i < ft_vector.size() ; i++)
		if (ft_vector[i] != std_vector[i])
			return (-1);

	return (0);
}
