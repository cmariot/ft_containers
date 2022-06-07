/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lst_utils.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 23:35:51 by cmariot           #+#    #+#             */
/*   Updated: 2022/06/07 22:05:23 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.hpp"

void	clear_test_list(t_test **test)
{
	t_test	*tmp;

	if (test)
	{
		while (*test)
		{
			tmp = (*test)->next;
			delete *test;
			*test = tmp;
		}
	}
}
