/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_RBTree_tests.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 15:18:00 by cmariot           #+#    #+#             */
/*   Updated: 2022/08/08 07:47:53 by cmariot          ###   ########.fr       */
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
	// Constructor
	ft::RedBlackTree<int, ft::pair<const int, char>, std::allocator<ft::pair<const int, char> >, std::less<int> >		rbt;

	// Add elements
	rbt.add(ft::pair<const int, char>(13, 'Z'));
	rbt.add(ft::pair<const int, char>(8, 'Z'));
	rbt.add(ft::pair<const int, char>(17, 'Z'));
	rbt.add(ft::pair<const int, char>(-1, 'Z'));
	rbt.add(ft::pair<const int, char>(11, 'Z'));
	rbt.add(ft::pair<const int, char>(15, 'Z'));
	rbt.add(ft::pair<const int, char>(25, 'Z'));
	rbt.add(ft::pair<const int, char>(6, 'Z'));
	rbt.add(ft::pair<const int, char>(22, 'Z'));
	rbt.add(ft::pair<const int, char>(27, 'Z'));

	// Print the tree
	rbt.print();

	////Find key
	ft::pair<int, char> ft_pair = ft::make_pair<int, char>(6, 'A');
	if (rbt.find(ft_pair.first) == NULL)
		std::cout << "Not found" << std::endl;


	rbt.del(8);

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
