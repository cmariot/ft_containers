/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   23_relational.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 09:17:19 by cmariot           #+#    #+#             */
/*   Updated: 2022/06/14 21:05:16 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

int	relational_test(void)
{
	size_t	nb = 42;

	ft::vector<int> test(nb, 4);
	ft::vector<int> test2(nb, 4);

	if (test != test2)
		return (-1);
	if (!(test == test2))
		return (-1);
	return (0);
}
