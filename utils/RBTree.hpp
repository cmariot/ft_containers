/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBTree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 15:21:29 by cmariot           #+#    #+#             */
/*   Updated: 2022/08/02 05:47:19 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RBTree_HPP
# define RBTree_HPP

# include <iostream>

# include "../utils/pair.hpp"

namespace ft
{
	/*
	 * Red-Black Tree : a kind of self balancing binary search tree.
	 *
	 * Rules :
	 * - Every node is red or black
	 * - The root is always black
	 * - New insertion are always red
	 * - Every path from root to leaf has the same number of black nodes
	 * - No path can have two consecutive red nodes
	 * - Any NULL node is black
	 *
	 * If any rule is not satisfied : Rebalance the tree
	 */

	template <class Pair, class Allocator = std::allocator<Pair> >
	class Node
	{
		// PUBLIC MEMBER OBJECTS
		public :

			Allocator						_alloc;
			Pair							*_pair;
			Node<Pair, Allocator>			*_parent;
			Node<Pair, Allocator>			*_left_child;
			Node<Pair, Allocator>			*_right_child;
			bool							_is_left_child;
			bool							_black;

		// PUBLIC MEMBER FUNCTIONS
		public :

			// Node Constructor
			Node(Pair pair, Allocator alloc) :
				_alloc(alloc)
			{
				_pair = _alloc.allocate(1);
				_alloc.construct(_pair, pair);
				_parent = NULL;
				_left_child = NULL;
				_right_child = NULL;
				_black = false;
				_is_left_child = false;
				return ;
			};

			// Node Destructor
			~Node(void)
			{
				_alloc.deallocate(_pair, 1);
			};
	};


	template <class Key, class Pair, class Allocator, class Compare = std::less<typename Pair::first_type> >
	class RedBlackTree
	{
		// PUBLIC MEMBER TYPES
		public :

			typedef Compare					key_compare;
			typedef Allocator				allocator_type;

		// PUBLIC MEMBER OBJECTS
		public :

			Node<Pair, Allocator>			*_root;
			allocator_type					_alloc;
			key_compare						_comp;

		// PRIVATE MEMBER FUNCTIONS
		private :

			void	rightLeftRotate(Node<Pair, Allocator> *node)
			{
				rightRotate(node->_right_child);
				leftRotate(node);
			};

			void	leftRightRotate(Node<Pair, Allocator> *node)
			{
				leftRotate(node->_left_child);
				rightRotate(node);
			};

			void	rightRotate(Node<Pair, Allocator> *node)
			{
				Node<Pair, Allocator> *tmp = node->_left_child;

				node->_left_child = tmp->_right_child;
				if (node->_left_child != NULL)
				{
					node->_left_child->_parent = node;
					node->_left_child->_is_left_child = true;
				}
				if (node->_parent == NULL)
				{
					_root = tmp;
					tmp->_parent = NULL;
				}
				else
				{
					tmp->_parent = node->_parent;
					if (node->_is_left_child == false)
					{
						tmp->_is_left_child = false;
						tmp->_parent->_right_child = tmp;
					}
					else
					{
						tmp->_is_left_child = true;
						tmp->_parent->_left_child = tmp;
					}
				}
				tmp->_right_child = node;
				node->_is_left_child = false;
				node->_parent = tmp;
			};

			void	leftRotate(Node<Pair, Allocator> *node)
			{
				Node<Pair, Allocator> *tmp = node->_right_child;

				node->_right_child = tmp->_left_child;
				if (node->_right_child != NULL)
				{
					node->_right_child->_parent = node;
					node->_right_child->_is_left_child = false;
				}
				if (node->_parent == NULL)
				{
					_root = tmp;
					tmp->_parent = NULL;
				}
				else
				{
					tmp->_parent = node->_parent;
					if (node->_is_left_child == true)
					{
						tmp->_is_left_child = true;
						tmp->_parent->_left_child = tmp;
					}
					else
					{
						tmp->_is_left_child = false;
						tmp->_parent->_right_child = tmp;
					}
				}
				tmp->_left_child = node;
				node->_is_left_child = true;
				node->_parent = tmp;
			};

			// If node->_parent and node are left children -> right rotation
			// If node->_parent and node are right children -> left rotation
			// If node->_parent is a left child and node is a rigth child -> left-rigth rotation
			// If node->_parent is a right child and node is a left child -> right-left rotation
			void	rotate(Node<Pair, Allocator> *node)
			{
				if (node->_is_left_child == true)
				{
					if (node->_parent->_is_left_child == true)
					{
						//node->_parent and node are left children
						rightRotate(node->_parent->_parent);
						node->_black = false;
						node->_parent->_black = true;
						if (node->_parent->_right_child != NULL)
							node->_parent->_right_child->_black = false;
						return ;
					}
					//node->_parent is a right child and node is a left child
					rightLeftRotate(node->_parent->_parent);
					node->_black = true;
					node->_right_child->_black = false;
					node->_left_child->_black = false;
					return ;
				}
				if (node->_parent->_is_left_child == false)
				{
					//node->_parent and node are right children
					leftRotate(node->_parent->_parent);
					node->_black = false;
					node->_parent->_black = true;
					if (node->_parent->_left_child != NULL)
						node->_parent->_left_child->_black = false;
					return ;
				}
				//node->_parent is a left child and node is a right child
				leftRightRotate(node->_parent->_parent);
				node->_black = true;
				node->_right_child->_black = false;
				node->_left_child->_black = false;
				return ;
			};

			// Make a rotation or a color flip depending the color of the node aunt
			void	correctTree(Node<Pair, Allocator> *node)
			{
				if (node->_parent->_is_left_child == true)
				{
					if (node->_parent->_parent)
					{
						// Aunt is node->parent->parent->_right_child
						if (node->_parent->_parent->_right_child == NULL
								|| node->_parent->_parent->_right_child->_black == true)
						{
							// Aunt is black -> rotation
							return (rotate(node));
						}
						// Aunt is red -> color flip
						if (node->_parent->_parent->_right_child != NULL)
							node->_parent->_parent->_right_child->_black = true;
						node->_parent->_parent->_black = false;
					}
					node->_parent->_black = true;
					return ;
				}
				// Aunt is node->parent->parent->_left_child
				if (node->_parent->_parent)
				{
					if (node->_parent->_parent->_left_child == NULL
							|| node->_parent->_parent->_left_child->_black == true)
					{
						// Aunt is black -> rotation
						return (rotate(node));
					}
					// Aunt is red -> color flip
					if (node->_parent->_parent->_left_child != NULL)
						node->_parent->_parent->_left_child->_black = true;
					node->_parent->_parent->_black = false;
				}
				node->_parent->_black = true;
				return ;
			};

			// After an insertion check and correct the tree depending the RBT rules
			void	checkColor(Node<Pair, Allocator> *node)
			{
				if (node == NULL || node->_parent == NULL)
					return ;
				// If 2 consecutive red nodes
				if (node->_black == false && node->_parent->_black == false)
					correctTree(node);
				// Check until the root
				checkColor(node->_parent);
			};

			// Add new_node bellow the parent node
			void	add(Node<Pair, Allocator> *parent, Node<Pair, Allocator> *new_node)
			{
				if (_comp(parent->_pair->first, new_node->_pair->first))
				{
					// Add to the right
					if (parent->_right_child == NULL)
					{
						parent->_right_child = new_node;
						new_node->_parent = parent;
						new_node->_is_left_child = false;
						checkColor(new_node);
						return ;
					}
					return (add(parent->_right_child, new_node));
				}
				// Add to the left
				if (parent->_left_child == NULL)
				{
					parent->_left_child = new_node;
					new_node->_parent = parent;
					new_node->_is_left_child = true;
					checkColor(new_node);
					return ;
				}
				return (add(parent->_left_child, new_node));
			};

			void	print(Node<Pair, Allocator> *node, std::string indent, bool last)
			{
				if (node != NULL)
				{
					std::cout << indent;
					if (last == true)
					{
						std::cout << "R----";
						indent += "     ";
					}
					else
					{
						std::cout << "L----";
						indent += "|    ";
					}
					if (node->_black == true)
						std::cout << node->_pair->first << " (BLACK)" << std::endl;
					else
						std::cout << node->_pair->first << " (RED)" << std::endl;
					print(node->_left_child, indent, false);
					print(node->_right_child, indent, true);
				}
			};

			void	destructor(Node<Pair, Allocator> *node)
			{
				if (node)
				{
					destructor(node->_left_child);
					destructor(node->_right_child);
					delete node;
					node = NULL;
				}
			};

		public :

			// RBT Constructor
			RedBlackTree(const allocator_type & allocator = allocator_type(),
					const key_compare & compare = key_compare()) :
				_root(NULL),
				_alloc(allocator),
				_comp(compare)
			{
				return ;
			};

			// RBT Destructor
			~RedBlackTree(void)
			{
				if (_root != NULL)
				{
					destructor(_root);
				}
			};

			// Add a new node to the tree,
			// If the tree is empty set a new node to _root
			// Else call a recursive function to add the node bellow
			void	add(Pair pair)
			{
				Node<Pair, Allocator>	*node = new Node<Pair, Allocator>(pair, _alloc);
				if (_root == NULL)
				{
					_root = node;
					_root->_black = true;
					return ;
				}
				add(_root, node);
				return ;
			};

			// Print the tree
			void	print()
			{
				if (_root != NULL)
				{
					print(_root, "", true);
				}
			};

			Node<Pair, Allocator> *find(typename Pair::first_type & key) const
			{
				Node<Pair, Allocator>	*node = _root;

				while (node != NULL)
				{
					if (node->_pair->first > key)
						node = node->_left_child;
					else if (node->_pair->first < key)
						node = node->_right_child;
					else
						return (node);
				}
				return (NULL);
			}

			// Return a pair<Key, Value> on the smalest element
			Node<Pair, Allocator>	*begin(void)
			{
				if (_root == NULL)
					return (NULL);
				else
				{
					Node<Pair, Allocator>	*_tmp = _root;

					while (_tmp->_left_child != NULL)
						_tmp = _tmp->_left_child;
					return (_tmp);
				}
			};

			// Return a pair<Key, Value> on the biggest element
			Node<Pair, Allocator>	*end(void)
			{
				if (_root == NULL)
					return (NULL);
				else
				{
					Node<Pair, Allocator>	*_tmp = _root;

					while (_tmp->_right_child != NULL)
						_tmp = _tmp->_right_child;
					_tmp = _tmp->_right_child;
					return (_tmp);
				}
			};

	};

};

#endif
