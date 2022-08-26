/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   13_front.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 09:15:46 by cmariot           #+#    #+#             */
/*   Updated: 2022/06/13 14:17:37 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

int	front_test(void)
{
	std::vector<int>	vector;
	for (int i = 0; i < 100 ; i++)
		vector.push_back(i);
		
	ft::vector<int>		ft_vector(vector.begin(), vector.end());
	if (vector.front() != 0)
		return (-1);

	//SIGSEGV dans les deux cas : OK
	//ft::vector<int>			empty;
	//std::vector<int>			empty2;
	//if (empty.front() != 0)
	//	return (-1);

	return (0);
}
