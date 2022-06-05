/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_constructor_tests.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 14:49:23 by cmariot           #+#    #+#             */
/*   Updated: 2022/06/05 19:37:19 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

int	constructor_test(void)
{
	std::vector<char>			std;
	ft::vector<char>			ft;

	if (ft.size() != std.size())
		return (1);
	if (ft.empty() != std.empty())
		return (1);
	if (ft.max_size() != std.max_size())
		return (1);
	else
		return (0);
}
