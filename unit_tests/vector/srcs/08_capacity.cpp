/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   08_capacity.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 09:15:06 by cmariot           #+#    #+#             */
/*   Updated: 2022/06/07 18:28:30 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

int	capacity_test(void)
{
	std::vector<int>		std;
	ft::vector<int>			ft;

	if (std.capacity() != ft.capacity())
		return (1);
	return (0);
}
