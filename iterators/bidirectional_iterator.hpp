/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bidirectional_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 19:38:11 by cmariot           #+#    #+#             */
/*   Updated: 2022/07/29 11:36:06 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIDIRECTIONAL_ITERATOR_HPP
# define BIDIRECTIONAL_ITERATOR_HPP

# include <iostream>

# include "map.hpp"
# include "random_access_iterator.hpp"

namespace	ft
{

	template <class T>
	class const_bidirectional_iterator;

	template <class T>
	class bidirectional_iterator
	{

		public :

			typedef ft::iterator_traits<iterator<std::bidirectional_iterator_tag, Node<T> > >	traits;

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
			bidirectional_iterator(pointer ptr) :
				_node(ptr)
			{
				return ;
			};

			// [X] COPY ASSIGNATION (=)
			bidirectional_iterator operator = (const bidirectional_iterator & rhs)
			{
				if (this == &rhs)
					return (*this);
				this->_node = rhs._node;
				return (*this);
			};

			// [X] DESTRUCTOR
			~bidirectional_iterator(void)
			{
				return ;
			};

			// [X] DEREFERENCE
			reference operator * (void)
			{
				return (_node->_pair);
			};

			// [X] DEREFERENCE
			T* operator -> (void) const
			{
				return (_node->_pair);
			};

			// [X] PREFIX INCREMENTATION
			bidirectional_iterator & operator ++ (void)
			{
				if (_node->_right_child)
				{
					Node<T>	*left = _node->_right_child;
					while (left->_left_child)
						left = left->_left_child;
					_node = left;
				}
				else
				{ 
					Node<T>	*cur = _node;
					Node<T>	*parent = cur->_parent;
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

			// [ ] PREFIX DECREMENTATION
			bidirectional_iterator & operator -- (void)
			{
				if (_node->_left_child)
				{
					Node<T>	*left = _node->_left_child;
					while (left->_right_child)
						left = left->_right_child;
					_node = left;
				}
				else
				{
					Node<T>	*cur = _node;
					Node<T>	*parent = cur->_parent;
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
			bidirectional_iterator operator -- (int)
			{
				bidirectional_iterator	tmp(*this);

				operator--();
				return (tmp);
			};

			// [X] OPERATOR ==
			bool operator == (const bidirectional_iterator & rhs) const
			{
				return (_node == rhs._node);
			};

			// [X] OPERATOR !=
			bool operator != (const bidirectional_iterator & rhs) const
			{
				return (_node != rhs._node);
			};
			
			// [X] OPERATOR ==
			bool operator == (const const_bidirectional_iterator<T> & rhs) const
			{
				return (_node == rhs._node);
			};

			// [X] OPERATOR !=
			bool operator != (const const_bidirectional_iterator<T> & rhs) const
			{
				return (_node != rhs._node);
			};

		public :

			Node<T>		*_node;

	};

	template <class T>
	class const_bidirectional_iterator
	{

		public :

			typedef ft::iterator_traits<iterator<std::bidirectional_iterator_tag, Node<T> > >	traits;

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

			// [X] COPY CONSTRUCTOR
			const_bidirectional_iterator(pointer ptr) :
				_node(ptr)
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

			// [X] DESTRUCTOR
			~const_bidirectional_iterator(void)
			{
				return ;
			};

			// [X] DEREFERENCE
			reference operator * (void)
			{
				return (_node->_pair);
			};

			// [X] DEREFERENCE
			T* operator -> (void) const
			{
				return (_node->_pair);
			};

			// [X] PREFIX INCREMENTATION
			const_bidirectional_iterator & operator ++ (void)
			{
				if (_node->_right_child)
				{
					Node<T>	*left = _node->_right_child;
					while (left->_left_child)
						left = left->_left_child;
					_node = left;
				}
				else
				{ 
					Node<T>	*cur = _node;
					Node<T>	*parent = cur->_parent;
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

			// [ ] PREFIX DECREMENTATION
			const_bidirectional_iterator & operator -- (void)
			{
				if (_node->_left_child)
				{
					Node<T>	*left = _node->_left_child;
					while (left->_right_child)
						left = left->_right_child;
					_node = left;
				}
				else
				{
					Node<T>	*cur = _node;
					Node<T>	*parent = cur->_parent;
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
			bool operator == (const bidirectional_iterator<T> & rhs) const
			{
				return (_node == rhs._node);
			};

			// [X] OPERATOR !=
			bool operator != (const bidirectional_iterator<T> & rhs) const
			{
				return (_node != rhs._node);
			};
			
			// [X] OPERATOR ==
			bool operator == (const const_bidirectional_iterator<T> & rhs) const
			{
				return (_node == rhs._node);
			};

			// [X] OPERATOR !=
			bool operator != (const const_bidirectional_iterator<T> & rhs) const
			{
				return (_node != rhs._node);
			};

		public :

			Node<T>		*_node;

	};
};

#endif
