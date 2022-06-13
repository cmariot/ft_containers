/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   14_back.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 09:15:53 by cmariot           #+#    #+#             */
/*   Updated: 2022/06/13 14:14:47 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

int	back_test(void)
{
	std::vector<int>	vector;
	for (int i = 0; i < 100 ; i++)
		vector.push_back(i);
		
	ft::vector<int>		ft_vector(vector.begin(), vector.end());
	if (vector.back() != 99)
		return (-1);

	return (0);
}
