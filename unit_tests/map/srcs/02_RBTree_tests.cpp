/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_RBTree_tests.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 15:18:00 by cmariot           #+#    #+#             */
/*   Updated: 2022/07/25 17:43:57 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

// TO DO :
// - [X] Declare a new RBT (constructor)
// - [X] Add a pair in the RBT (insert)
// - [ ] Iterate in the nodes of the tree and return a pair (iterators)
// - [ ] Find a pair in the tree depending its key / value (find)
// - [ ] Delete a pair in the RBT (del)

int	RBTree_test(void)
{
	ft::RedBlackTree<int, char,  std::allocator<ft::pair<const int, char> >, std::less<int> >		rbt;

	rbt.add(13, 'A');
	rbt.add(8, 'A');
	rbt.add(17, 'A');
	rbt.add(-1, 'A');
	rbt.add(11, 'A');
	rbt.add(15, 'A');
	rbt.add(25, 'A');
	rbt.add(6, 'A');
	rbt.add(22, 'A');
	rbt.add(27, 'A');

	rbt.print();
	
	rbt.begin();
	rbt.end();

	//std::map<int, char> std_map;

	//std_map.insert(std::make_pair(2, 'a'));
	//std_map.insert(std::make_pair(3, 'a'));
	//std_map.insert(std::make_pair(4, 'a'));
	//std_map.insert(std::make_pair(5, 'a'));
	//std_map.insert(std::make_pair(-1, 'a'));
	//std_map.insert(std::make_pair(6, 'a'));

	//std::cout << std_map.begin()->first << std::endl;

	return (0);
}
