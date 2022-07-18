/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_RBTree_tests.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 15:18:00 by cmariot           #+#    #+#             */
/*   Updated: 2022/07/18 13:26:46 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

int	RBTree_test(void)
{
	ft::RedBlackTree<int, char, std::allocator<ft::pair<const int, char> >, std::less<int> >		rbt;

	rbt.add(3, 'A');
	rbt.add(1, 'A');
	rbt.add(5, 'A');
	rbt.add(7, 'A');
	rbt.add(6, 'A');
	rbt.add(8, 'A');
	rbt.add(9, 'A');
	rbt.add(10, 'A');

	rbt.print();

	return (0);
}
