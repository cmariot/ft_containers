/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   red_black_tree.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 20:49:58 by cmariot           #+#    #+#             */
/*   Updated: 2022/08/18 10:06:16 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RED_BLACK_TREE_HPP
# define RED_BLACK_TREE_HPP

# include "make_pair.hpp"

namespace ft
{
	/*
	 * Red-Black Tree : a kind of self balancing binary search red_black_tree.
	 *
	 * Rules :
	 * - Every node is red or black
	 * - The root is always black
	 * - New insertion are always red
	 * - Every path from root to leaf has the same number of black nodes
	 * - No path can have two consecutive red nodes
	 * - Any NULL node is black
	 *
	 * If any rule is not satisfied : Rebalance the red_black_tree
	 */

	template<class Key, class Value, class Compare, class Alloc>
		class red_black_tree
		{

			// MEMBER TYPES
			public:

				typedef Key															key_type;
				typedef Value														mapped_type;
				typedef Compare														key_compare;
				typedef typename Alloc::template rebind< node<Key, Value> >::other	allocator_type;
				typedef typename allocator_type::value_type							value_type;
				typedef typename allocator_type::reference							reference;
				typedef typename allocator_type::const_reference					const_reference;
				typedef typename allocator_type::pointer							pointer;
				typedef typename allocator_type::const_pointer						const_pointer;
				typedef typename allocator_type::size_type							size_type;
				typedef typename allocator_type::difference_type					difference_type;

			// MEMBER OBJECTS
			private:

				allocator_type														_alloc;
				key_compare															_cmp;
				pointer																_root;
				pointer																_nil;
				size_type															_size;

			// PUBLIC MEMBER FUNCTIONS
			public:

				// DEFAULT CONSTRUCTOR
				red_black_tree(void) :
					_alloc(),
					_cmp(key_compare()),
					_root(_alloc.allocate(1)),
					_nil(_root),
					_size(0)
				{
					_alloc.construct(_nil, value_type(key_type(), mapped_type(), NULL, NIL));
				};

				// DEFAULT DESTRUCTOR
				~red_black_tree(void)
				{
					clear(_root);
					free_node(_nil);
				};

				// OPERATOR =
				red_black_tree & operator = (const red_black_tree & other)
				{
					if (this == &other)
						return (*this);
					
					pointer		it = other.begin();
					pointer		ite = other.end();
					
					clear();
					_cmp = other._cmp;
					while (it != ite)
					{
						insert(*it->data);
						it = next(it);
					}
					return (*this);
				};

				// BEGIN
				pointer begin(void)
				{
					return (minimum(_root));
				};

				// CONST BEGIN
				const pointer begin(void) const
				{
					return (minimum(_root));
				};

				// END
				pointer end(void)
				{
					return (_nil);
				};

				// CONST END
				const pointer end(void) const
				{
					return (_nil);
				};

				// SIZE
				size_type size(void) const
				{
					return (_size);
				};

				// MAX SIZE
				size_type max_size(void) const
				{
					return (_alloc.max_size());
				};

				// CLEAR
				void clear(void)
				{
					clear(_root);
					return ;
				};

				// INSERT PAIR
				ft::pair<pointer, bool> insert(ft::pair<key_type, mapped_type> pair)
				{
					pointer	current = _root;
					pointer	parent = _nil;

					while (current != _nil)
					{
						if (pair.first == current->data->first)
							return (ft::make_pair<pointer, bool>(current, false));
						parent = current;
						current = _cmp(pair.first, current->data->first) ? current->left : current->right;
					}

					pointer	new_node = _alloc.allocate(1);

					_alloc.construct(new_node, value_type(pair.first, pair.second, _nil, RED));
					new_node->parent = parent;
					if (parent == _nil)
						_root = new_node;
					else
					{
						if (_cmp(pair.first, parent->data->first))
							parent->left = new_node;
						else
							parent->right = new_node;
					}
					insert_fix(new_node);
					_nil->parent = maximum(_root);
					++_size;
					return (ft::make_pair<pointer, bool>(new_node, true));
				};

				// ERASE KEY
				bool erase(key_type key)
				{
					pointer node = find(_root, key);

					if (node == _nil)
						return (false);
					erase_node(node);
					--_size;
					return (true);
				};

				// SWAP
				void swap(red_black_tree& other)
				{
					std::swap(_nil, other._nil);
					std::swap(_root, other._root);
					std::swap(_cmp, other._cmp);
					std::swap(_alloc, other._alloc);
					std::swap(_size, other._size);
				};

				// FIND KEY
				pointer find(key_type key) const
				{
					return find(_root, key);
				};
				
				// PRINT HELPER
				void	print(pointer node, std::string indent, bool last)
				{
					if (node != _nil)
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
						if (node->color == BLACK)
							std::cout << node->data->first << " (BLACK)" << std::endl;
						else
							std::cout << node->data->first << " (RED)" << std::endl;
						print(node->left, indent, false);
						print(node->right, indent, true);
					}
				};

				// PRINT
				void	print(void)
				{
					if (_root != _nil)
					{
						print(_root, "", true);
					}
				};

			private:

				// FIND HELPER
				pointer find(pointer node, key_type key) const
				{
					if (node != _nil)
					{
						if (node->data->first == key)
							return node;
						else if (_cmp(key, node->data->first))
							return find(node->left, key);
						else
							return find(node->right, key);
					}
					return _nil;
				}

				// MAX
				pointer maximum(pointer node) const
				{
					while (node->color != NIL && node->right->color != NIL)
					{
						node = node->right;
					}
					return (node);
				}

				// MIN
				pointer minimum(pointer node) const
				{
					while (node->color != NIL && node->left->color != NIL)
						node = node->left;
					return (node);
				}

				// PREV
				pointer prev(pointer node)
				{
					if (node->color == NIL)
						return (node->parent);
					else if (node->color != NIL && node->left->color != NIL)
						return (maximum(node->left));

					pointer tmp = node->parent;

					while (tmp->color != NIL && node == tmp->left)
					{
						node = tmp;
						tmp = tmp->parent;
					}
					if (tmp->color != NIL)
						return (tmp);
					else
						return (node);
				}

				// NEXT
				pointer next(pointer node)
				{
					if (node->color == NIL)
						return (node);
					else if (node->right->color != NIL)
						return (minimum(node->right));

					pointer tmp = node->parent;

					while (tmp->color != NIL && node == tmp->right)
					{
						node = tmp;
						tmp = tmp->parent;
					}
					return (tmp);
				}

				// FREE
				void free_node(const pointer& node)
				{
					_alloc.destroy(node);
					_alloc.deallocate(node, 1);
				}

				// CLEAR
				void clear(pointer& node)
				{
					if (node == NULL || node == _nil)
						return;

					clear(node->left);
					clear(node->right);
					if (node == _root)
					{
						free_node(_root);
						_root = _nil;
						_nil->parent = NULL;
						_size = 0;
					}
					else
						free_node(node);
				}

				// DELETE FIX
				void delete_fix(pointer x)
				{
					for (; x != _root && x->color == BLACK;)
					{
						if (x == x->parent->left)
						{
							pointer w = x->parent->right;
							if (w->color == RED)
							{
								w->color = BLACK;
								x->parent->color = RED;
								rotate_left(x->parent);
								w = x->parent->right;
							}
							if (w->left->color == BLACK && w->right->color == BLACK)
							{
								w->color = RED;
								x = x->parent;
							}
							else
							{
								if (w->right->color == BLACK)
								{
									w->left->color = BLACK;
									w->color = RED;
									rotate_right(w);
									w = x->parent->right;
								}
								w->color = x->parent->color;
								x->parent->color = BLACK;
								w->right->color = BLACK;
								rotate_left(x->parent);
								x = _root;
							}
						}
						else
						{
							pointer w = x->parent->left;
							if (w->color == RED)
							{
								w->color = BLACK;
								x->parent->color = RED;
								rotate_right(x->parent);
								w = x->parent->left;
							}
							if (w->right->color == BLACK && w->left->color == BLACK)
							{
								w->color = RED;
								x = x->parent;
							}
							else
							{
								if (w->left->color == BLACK)
								{
									w->right->color = BLACK;
									w->color = RED;
									rotate_left(w);
									w = x->parent->left;
								}
								w->color = x->parent->color;
								x->parent->color = BLACK;
								w->left->color = BLACK;
								rotate_right(x->parent);
								x = _root;
							}
						}
					}
					if (x->color != NIL)
						x->color = BLACK;
					return ;
				}

				// ERASE
				void erase_node(pointer z)
				{
					pointer x;
					pointer y;

					if (z != _nil)
					{
						if (z->left == _nil || z->right == _nil)
							y = z;
						else
						{
							y = z->right;
							while (y->left != _nil)
								y = y->left;
						}
						if (y->left != _nil)
							x = y->left;
						else
							x = y->right;

						if (x != _nil)
							x->parent = y->parent;
						if (y->parent == _nil)
							_root = x;
						else
						{
							if (y == y->parent->left)
								y->parent->left = x;
							else
								y->parent->right = x;
						}
						if (y != z)
						{
							delete z->data;
							z->data = new ft::pair<const key_type, mapped_type>(y->data->first, y->data->second);
						}
						if (y->color == BLACK)
							delete_fix(x);
						_alloc.destroy(y);
						_alloc.deallocate(y, 1);
						_nil->parent = maximum(_root);
					}
				}

				// ROTATE LEFT
				void rotate_left(pointer x)
				{
					pointer y = x->right;

					x->right = y->left;
					if (y->left != _nil)
						y->left->parent = x;
					if (y != _nil)
						y->parent = x->parent;
					if (x->parent == _nil)
						_root = y;
					else
					{
						if (x == x->parent->left)
							x->parent->left = y;
						else
							x->parent->right = y;
					}
					y->left = x;
					if (x != _nil)
						x->parent = y;
					return ;
				}

				// ROTATE RIGHT
				void rotate_right(pointer x)
				{
					pointer y = x->left;

					x->left = y->right;
					if (y->right != _nil)
						y->right->parent = x;
					if (y != _nil)
						y->parent = x->parent;
					if (x->parent == _nil)
						_root = y;
					else
					{
						if (x == x->parent->right)
							x->parent->right = y;
						else
							x->parent->left = y;
					}
					y->right = x;
					if (x != _nil)
						x->parent = y;
					return ;
				}

				// INSERT FIX
				void insert_fix(pointer x)
				{
					while (x != _root && x->parent->color == RED)
					{
						if (x->parent == x->parent->parent->left)
						{
							pointer y = x->parent->parent->right;
							if (y->color == RED)
							{
								x->parent->color = BLACK;
								y->color = BLACK;
								x->parent->parent->color = RED;
								x = x->parent->parent;
							}
							else
							{
								if (x == x->parent->right)
								{
									x = x->parent;
									rotate_left(x);
								}
								x->parent->color = BLACK;
								x->parent->parent->color = RED;
								rotate_right(x->parent->parent);
							}
						}
						else
						{
							pointer y = x->parent->parent->left;
							if (y->color == RED)
							{
								x->parent->color = BLACK;
								y->color = BLACK;
								x->parent->parent->color = RED;
								x = x->parent->parent;
							}
							else
							{
								if (x == x->parent->left)
								{
									x = x->parent;
									rotate_right(x);
								}
								x->parent->color = BLACK;
								x->parent->parent->color = RED;
								rotate_left(x->parent->parent);
							}
						}
					}
					_root->color = BLACK;
				}
		};
};

#endif
