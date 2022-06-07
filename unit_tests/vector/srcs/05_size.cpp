/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_size.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 09:14:41 by cmariot           #+#    #+#             */
/*   Updated: 2022/06/07 18:25:07 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

int	size_test(void)
{
	std::vector<int>		std;
	ft::vector<int>			ft;

	if (std.size() != ft.size())
		return (1);
	return (0);
}
