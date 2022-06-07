/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   09_empty.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 09:15:15 by cmariot           #+#    #+#             */
/*   Updated: 2022/06/07 18:27:22 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

int	empty_test(void)
{
	std::vector<int>		std;
	ft::vector<int>			ft;

	if (std.empty() != ft.empty())
		return (1);
	return (0);
}
