/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bidirectional_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 19:38:11 by cmariot           #+#    #+#             */
/*   Updated: 2022/08/08 05:26:52 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIDIRECTIONAL_ITERATOR_HPP
# define BIDIRECTIONAL_ITERATOR_HPP

# include <iostream>

# include "map.hpp"
# include "random_access_iterator.hpp"

namespace	ft
{

	template <class Pair>
	class bidirectional_iterator
	{

		public :

			typedef ft::iterator_traits<iterator<std::bidirectional_iterator_tag, Node<Pair> > >	traits;

			typedef ft::Node<Pair>							node;

			typedef typename traits::iterator_category		iterator_category;
			typedef typename traits::value_type				value_type;
			typedef typename traits::difference_type		difference_type;
			typedef typename traits::pointer				pointer;
			typedef typename traits::reference				reference;

			// [X] DEFAULT CONSTRUCTOR
			bidirectional_iterator(void) :
				_node(NULL)
			{
				return ;
			};

			// [X] COPY CONSTRUCTOR
			bidirectional_iterator(node *ptr) :
				_node(ptr)
			{
				return ;
			};

			// [X] COPY ASSIGNATION (=)
			bidirectional_iterator operator = (const const_bidirectional_iterator<Pair> & rhs)
			{
				this->_node = rhs._node;
				return (*this);
			};

			// [X] DESTRUCTOR
			~bidirectional_iterator(void)
			{
				return ;
			};

			// [X] DEREFERENCE
			Pair & operator * (void)
			{
				return (*(_node->_pair));
			};

			// [X] DEREFERENCE
			Pair* operator -> (void) const
			{
				return (_node->_pair);
			};

			// [X] PREFIX INCREMENTATION
			bidirectional_iterator & operator ++ (void)
			{
				if (_node->_right_child)
				{
					Node<Pair>	*left = _node->_right_child;
					while (left->_left_child)
						left = left->_left_child;
					_node = left;
				}
				else
				{ 
					Node<Pair>	*cur = _node;
					Node<Pair>	*parent = cur->_parent;
					while (parent && cur == parent->_right_child)
					{
						cur = cur->_parent;
						parent = parent->_parent;
					}
					_node = parent;
				}
				return (*this);
			};

			// [X] SUFIX INCREMENTATION
			bidirectional_iterator operator ++ (int)
			{
				bidirectional_iterator	tmp(*this);

				operator++();
				return (tmp);
			};

			// [X] PREFIX DECREMENTATION
			bidirectional_iterator & operator -- (void)
			{
				if (_node)
				{
					if (_node->_left_child)
					{
						Node<Pair>	*left = _node->_left_child;
						while (left->_right_child)
							left = left->_right_child;
						_node = left;
					}
					else
					{
						Node<Pair>	*cur = _node;
						Node<Pair>	*parent = cur->_parent;
						while (parent && cur == parent->_left_child)
						{
							cur = cur->_parent;
							parent = parent->_parent;
						}
						_node = parent;
					}
				}
				return (*this);
			};

			// [X] SUFIX DECREMENTATION
			bidirectional_iterator operator -- (int)
			{
				bidirectional_iterator	tmp(*this);

				if (_node)
					operator--();
				return (tmp);
			};

			// [X] OPERATOR ==
			bool operator == (const bidirectional_iterator & rhs) const
			{
				return (_node == rhs._node);
			};
			bool operator == (const const_bidirectional_iterator<Pair> & rhs) const
			{
				return (_node == rhs._node);
			};

			// [X] OPERATOR !=
			bool operator != (const bidirectional_iterator & rhs) const
			{
				return (_node != rhs._node);
			};
			bool operator != (const const_bidirectional_iterator<Pair> & rhs) const
			{
				return (_node != rhs._node);
			};

		public :

			Node<Pair>		*_node;

	};

	template <class Pair>
	class const_bidirectional_iterator
	{

		public :

			typedef ft::iterator_traits<iterator<std::bidirectional_iterator_tag, const Node<Pair> > >	traits;
			
			typedef ft::Node<Pair>							node;

			typedef typename traits::iterator_category		iterator_category;
			typedef typename traits::value_type				value_type;
			typedef typename traits::difference_type		difference_type;
			typedef typename traits::pointer				pointer;
			typedef typename traits::reference				reference;

			// [X] DEFAULT CONSTRUCTOR
			const_bidirectional_iterator(void) :
				_node(NULL)
			{
				return ;
			};

			// [X] COPY CONSTRUCPairOR
			const_bidirectional_iterator(node *ptr) :
				_node(ptr)
			{
				return ;
			};
			const_bidirectional_iterator(const bidirectional_iterator<Pair> & rhs) :
				_node(rhs._node)
			{
				return ;
			};
			const_bidirectional_iterator(const const_bidirectional_iterator & rhs) :
				_node(rhs._node)
			{
				return ;
			};

			// [X] COPY ASSIGNATION (=)
			const_bidirectional_iterator operator = (const const_bidirectional_iterator & rhs)
			{
				if (this == &rhs)
					return (*this);
				this->_node = rhs._node;
				return (*this);
			};
			const_bidirectional_iterator operator = (const bidirectional_iterator<Pair> & rhs)
			{
				this->_node = rhs._node;
				return (*this);
			};

			// [X] DESTRUCTOR
			~const_bidirectional_iterator(void)
			{
				return ;
			};

			// [X] DEREFERENCE
			const Pair & operator * (void)
			{
				return (*(_node->_pair));
			};

			// [X] DEREFERENCE
			const Pair* operator -> (void) const
			{
				return (_node->_pair);
			};

			// [X] PREFIX INCREMENTATION
			const_bidirectional_iterator & operator ++ (void)
			{
				if (_node->_right_child)
				{
					Node<Pair>	*left = _node->_right_child;
					while (left->_left_child)
						left = left->_left_child;
					_node = left;
				}
				else
				{ 
					Node<Pair>	*cur = _node;
					Node<Pair>	*parent = cur->_parent;
					while (parent && cur == parent->_right_child)
					{
						cur = cur->_parent;
						parent = parent->_parent;
					}
					_node = parent;
				}
				return (*this);
			};

			// [X] SUFIX INCREMENTATION
			const_bidirectional_iterator operator ++ (int)
			{
				const_bidirectional_iterator	tmp(*this);

				operator++();
				return (tmp);
			};

			// [X] PREFIX DECREMENTATION
			const_bidirectional_iterator & operator -- (void)
			{
				if (_node->_left_child)
				{
					Node<Pair>	*left = _node->_left_child;
					while (left->_right_child)
						left = left->_right_child;
					_node = left;
				}
				else
				{
					Node<Pair>	*cur = _node;
					Node<Pair>	*parent = cur->_parent;
					while (parent && cur == parent->_left_child)
					{
						cur = cur->_parent;
						parent = parent->_parent;
					}
					_node = parent;
				}
				return (*this);
			};

			// [X] SUFIX DECREMENTATION
			const_bidirectional_iterator operator -- (int)
			{
				const_bidirectional_iterator	tmp(*this);

				operator--();
				return (tmp);
			};

			// [X] OPERATOR ==
			bool operator == (const const_bidirectional_iterator & rhs) const
			{
				return (_node == rhs._node);
			};
			bool operator == (const bidirectional_iterator<Pair> & rhs) const
			{
				return (_node == rhs._node);
			};

			// [X] OPERATOR !=
			bool operator != (const const_bidirectional_iterator & rhs) const
			{
				return (_node != rhs._node);
			};
			bool operator != (const bidirectional_iterator<Pair> & rhs) const
			{
				return (_node != rhs._node);
			};


		public :

			Node<Pair>		*_node;

	};
//	template <class Pair>
//	class const_bidirectional_iterator
//	{
//
//		public :
//
//			typedef ft::iterator_traits<iterator<std::bidirectional_iterator_tag, const Node<Pair> > >	traits;
//
//			typedef typename traits::iterator_category		iterator_category;
//			typedef typename traits::value_type				value_type;
//			typedef typename traits::difference_type		difference_type;
//			typedef typename traits::pointer				pointer;
//			typedef typename traits::reference				reference;
//
//			// [X] DEFAULPair CONSPairRUCPairOR
//			const_bidirectional_iterator(void) :
//				_node(NULL)
//			{
//				return ;
//			};
//
//			// [X] COPY CONSPairRUCPairOR
//			const_bidirectional_iterator(pointer ptr) :
//				_node(ptr)
//			{
//				return ;
//			};
//			const_bidirectional_iterator(ft::bidirectional_iterator<Pair> & rhs) :
//				_node(rhs.node)
//			{
//				return ;
//			};
//
//			operator const_bidirectional_iterator<const Pair>(void) const
//			{
//				return (const_bidirectional_iterator<Pair>(this->_node));
//			}
//
//			// [X] COPY ASSIGNAPairION (=)
//			const_bidirectional_iterator operator = (const const_bidirectional_iterator & rhs)
//			{
//				if (this == &rhs)
//					return (*this);
//				this->_node = rhs._node;
//				return (*this);
//			};
//			const_bidirectional_iterator operator = (const bidirectional_iterator<Pair> & rhs)
//			{
//				if (this == &rhs)
//					return (*this);
//				this->_node = rhs._node;
//				return (*this);
//			};
//
//
//			// [X] DESPairRUCPairOR
//			~const_bidirectional_iterator(void)
//			{
//				return ;
//			};
//
//			// [X] DEREFERENCE
//			Pair & operator * (void)
//			{
//				return (*(_node->_pair));
//			};
//
//			// [X] DEREFERENCE
//			Pair* operator -> (void) const
//			{
//				return (_node->_pair);
//			};
//
//			// [X] PREFIX INCREMENPairAPairION
//			const_bidirectional_iterator & operator ++ (void)
//			{
//				if (_node->_right_child)
//				{
//					Node<Pair>	*left = _node->_right_child;
//					while (left->_left_child)
//						left = left->_left_child;
//					_node = left;
//				}
//				else
//				{ 
//					Node<Pair>	*cur = _node;
//					Node<Pair>	*parent = cur->_parent;
//					while (parent && cur == parent->_right_child)
//					{
//						cur = cur->_parent;
//						parent = parent->_parent;
//					}
//					_node = parent;
//				}
//				return (*this);
//			};
//
//			// [X] SUFIX INCREMENPairAPairION
//			const_bidirectional_iterator operator ++ (int)
//			{
//				const_bidirectional_iterator	tmp(*this);
//
//				operator++();
//				return (tmp);
//			};
//
//			// [X] PREFIX DECREMENPairAPairION
//			const_bidirectional_iterator & operator -- (void)
//			{
//				if (_node->_left_child)
//				{
//					Node<Pair>	*left = _node->_left_child;
//					while (left->_right_child)
//						left = left->_right_child;
//					_node = left;
//				}
//				else
//				{
//					Node<Pair>	*cur = _node;
//					Node<Pair>	*parent = cur->_parent;
//					while (parent && cur == parent->_left_child)
//					{
//						cur = cur->_parent;
//						parent = parent->_parent;
//					}
//					_node = parent;
//				}
//				return (*this);
//			};
//
//			// [X] SUFIX DECREMENPairAPairION
//			const_bidirectional_iterator operator -- (int)
//			{
//				const_bidirectional_iterator	tmp(*this);
//
//				operator--();
//				return (tmp);
//			};
//
//			// [X] OPERAPairOR ==
//			bool operator == (const const_bidirectional_iterator & rhs) const
//			{
//				return (_node == rhs._node);
//			};
//
//			// [X] OPERAPairOR ==
//			bool operator == (const bidirectional_iterator<Pair> & rhs) const
//			{
//				return (_node == rhs._node);
//			};
//
//			// [X] OPERAPairOR !=
//			bool operator != (const const_bidirectional_iterator & rhs) const
//			{
//				return (_node != rhs._node);
//			};
//
//			// [X] OPERAPairOR !=
//			bool operator != (const bidirectional_iterator<Pair> & rhs) const
//			{
//				return (_node != rhs._node);
//			};
//
//		public :
//
//			const Node<Pair>		*_node;
//
//	};
//

};

#endif
