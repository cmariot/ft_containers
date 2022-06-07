/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_max_size.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 09:14:47 by cmariot           #+#    #+#             */
/*   Updated: 2022/06/07 18:26:32 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

int	max_size_test(void)
{
	std::vector<int>		std;
	ft::vector<int>			ft;

	if (std.max_size() != ft.max_size())
		return (1);
	return (0);
}
