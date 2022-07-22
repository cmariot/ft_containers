/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_RBTree_tests.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 15:18:00 by cmariot           #+#    #+#             */
/*   Updated: 2022/07/21 20:31:31 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

int	RBTree_test(void)
{
	ft::RedBlackTree<int, char,  std::allocator<ft::pair<const int, char> >, std::less<int> >		rbt;

	rbt.add(13, 'A');
	rbt.add(8, 'A');
	rbt.add(17, 'A');
	rbt.add(1, 'A');
	rbt.add(11, 'A');
	rbt.add(15, 'A');
	rbt.add(25, 'A');
	rbt.add(6, 'A');
	rbt.add(22, 'A');
	rbt.add(27, 'A');

	rbt.print();

	return (0);
}
