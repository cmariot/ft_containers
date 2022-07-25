/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBTree.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 15:21:29 by cmariot           #+#    #+#             */
/*   Updated: 2022/07/25 15:39:40 by cmariot          ###   ########.fr       */
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
	 *
	 * 
	 */

	template <class Key, class Value, class Allocator>
	class Node
	{
		public :

			Allocator					_alloc;
			ft::pair<const Key, Value>	*_pair;
			bool						_is_left_child;
			bool						_black;
			Node<Key, Value, Allocator>	*_parent;
			Node<Key, Value, Allocator>	*_left_child;
			Node<Key, Value, Allocator>	*_right_child;

			// Node Constructor
			Node(Key key, Value value, Allocator alloc) :
				_alloc(alloc)
			{
				_pair = _alloc.allocate(1);
				_alloc.construct(_pair, ft::make_pair<Key, Value>(key, value));
				_parent = NULL;
				_left_child = NULL;
				_right_child = NULL;
				_black = false;
				_is_left_child = false;
				return ;
			};

			~Node(void)
			{
				_alloc.deallocate(_pair, 1);
			};
	};


	template <class Key,
			 class Value,
			 class Allocator/* = std::allocator<ft::pair<const Key, Value> > */,
			 class Compare = std::less<Key> >
	class RedBlackTree
	{
		public :

			typedef Compare		key_compare;
			typedef Allocator	allocator_type;

			Node<Key, Value, Allocator>	*_root;
			size_t				_size;
			allocator_type		_alloc;
			key_compare			_comp;


		private :

			void	rightLeftRotate(Node<Key, Value, Allocator> *node)
			{
				rightRotate(node->_right_child);
				leftRotate(node);
			};

			void	leftRightRotate(Node<Key, Value, Allocator> *node)
			{
				leftRotate(node->_left_child);
				rightRotate(node);
			};

			void	rightRotate(Node<Key, Value, Allocator> *node)
			{
				Node<Key, Value, Allocator> *tmp = node->_left_child;

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

			void	leftRotate(Node<Key, Value, Allocator> *node)
			{
				Node<Key, Value, Allocator> *tmp = node->_right_child;

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
			void	rotate(Node<Key, Value, Allocator> *node)
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
			void	correctTree(Node<Key, Value, Allocator> *node)
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
			void	checkColor(Node<Key, Value, Allocator> *node)
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
			void	add(Node<Key, Value, Allocator> *parent, Node<Key, Value, Allocator> *new_node)
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

			void	print(Node<Key, Value, Allocator> *node, std::string indent, bool last)
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

			void	destructor(Node<Key, Value, Allocator> *node)
			{
				if (node != NULL)
				{
					destructor(node->_left_child);
					destructor(node->_right_child);
					delete node;
					node = NULL;
				}
			};

		public :

			Node<Key, Value, Allocator>	*next(void)
			{
				return (NULL);
			};

			// RBT Constructor
			RedBlackTree(const allocator_type & allocator = allocator_type(),
					const key_compare & compare = key_compare())
			{
				_root = NULL;
				_size = 0;
				_alloc = allocator;
				_comp = compare;
			};

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
			void	add(Key key, Value value)
			{
				Node<Key, Value, Allocator>	*node = new Node<Key, Value, Allocator>(key, value, _alloc);
				if (_root == NULL)
				{
					_root = node;
					_root->_black = true;
					_size++;
					return ;
				}
				_size++;
				add(_root, node);
				return ;
			};

			void	print()
			{
				if (_root != NULL)
				{
					print(_root, "", true);
				}
			};
	};

};

#endif
