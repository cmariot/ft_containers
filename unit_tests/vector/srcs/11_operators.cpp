/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   11_operators.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 09:15:30 by cmariot           #+#    #+#             */
/*   Updated: 2022/06/13 14:56:09 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

int	operators_test(void)
{
	std::vector<int>	vector;
	for (int i = 0; i < 100 ; i++)
		vector.push_back(i);
		
	ft::vector<int>		ft_vector(vector.begin(), vector.end());
	for (int i = 0 ; i < 100 ; i++)
		if (vector[i] != i)
			return (-1);
	return (0);
}
