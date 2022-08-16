/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 23:55:04 by cmariot           #+#    #+#             */
/*   Updated: 2022/08/16 04:53:57 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/pair.hpp"
#include "red_black_tree.hpp"

int main(void)
{
	RBTree<int, ft::pair<int, char>, std::allocator<ft::pair<int, char> > >  tree;

	tree.insert(ft::make_pair<int, char>(7, 'a'));
	tree.insert(ft::make_pair<int, char>(13, 'a'));
	tree.insert(ft::make_pair<int, char>(18, 'a'));
	tree.insert(ft::make_pair<int, char>(10, 'a'));
	tree.insert(ft::make_pair<int, char>(22, 'a'));
	tree.insert(ft::make_pair<int, char>(8, 'a'));
	tree.insert(ft::make_pair<int, char>(11, 'a'));
	tree.insert(ft::make_pair<int, char>(26, 'a'));
	tree.insert(ft::make_pair<int, char>(2, 'a'));
	tree.insert(ft::make_pair<int, char>(6, 'a'));
	tree.insert(ft::make_pair<int, char>(13, 'a'));

	tree.deleteByVal(7);
	tree.deleteByVal(13);
//	tree.deleteByVal(18);
//	tree.deleteByVal(10);
//	tree.deleteByVal(22);
//	tree.deleteByVal(8);
//	tree.deleteByVal(11);
//	tree.deleteByVal(26);
//	tree.deleteByVal(2);
//	tree.deleteByVal(6);
//	tree.deleteByVal(13);

  return (0);
}
