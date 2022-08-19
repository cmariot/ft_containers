/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 21:43:27 by cmariot           #+#    #+#             */
/*   Updated: 2022/08/18 09:15:31 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_ITERATOR_HPP
# define MAP_ITERATOR_HPP

# include "iterator_traits.hpp"
# include "const_map_iterator.hpp"

namespace ft
{

	template <class Key, class Value, class Iter>
		class map_iterator
		{

			// MEMBER TYPES
			public:

				typedef Iter															iterator_type;
				typedef ft::bidirectional_iterator_tag									iterator_category;
				typedef typename ft::iterator_traits<iterator_type>::value_type			value_type;
				typedef typename ft::iterator_traits<iterator_type>::difference_type	difference_type;
				typedef typename ft::iterator_traits<iterator_type>::pointer			pointer;
				typedef typename ft::iterator_traits<iterator_type>::reference			reference;
				typedef node<Key, Value>*												nodePointer;

			// MEMBER OBJECTS
			private:

				nodePointer																_ptr;

			// MEMBER FUNCTIONS
			public:

				// DEFAULT CONSTRUCTOR
				map_iterator(nodePointer _ptr = NULL) :
					_ptr(_ptr)
				{
					return ;
				};

				// OPERATOR =
				map_iterator& operator = (const map_iterator& other)
				{
					if (this == &other)
						return (*this);
					_ptr = other._ptr;
					return (*this);
				};

				// OPERATOR = FOR CONST ITERATOR
				map_iterator& operator = (const const_map_iterator<Key, Value, Iter> & other)
				{
					_ptr = other._ptr;
					return (*this);
				};

				// DESTRUCTOR
				~map_iterator(void)
				{
					return ;
				};

				// BASE
				nodePointer base(void) const
				{
					return (_ptr);
				};

				// OPERATOR ==
				bool operator == (const map_iterator& other) const
				{
					return (_ptr == other.base());
				};

				// OPERATOR !=
				bool operator != (const map_iterator& other) const
				{
					return (_ptr != other.base());
				};

				// DEREFERENCE
				reference operator * (void) const
				{
					return (*(_ptr->data));
				};

				// DEREFERENCE
				pointer operator -> (void) const
				{
					if (_ptr)
						return (_ptr->data);
					return (NULL);
				};

				// PRE-INCREMENTATION
				map_iterator& operator ++ (void)
				{
					_ptr = next(_ptr);
					return (*this);
				};

				// POST-INCREMENTATION
				map_iterator operator ++ (int)
				{
					map_iterator	tmp(*this);

					_ptr = next(_ptr);
					return (tmp);
				};

				// PRE-DECREMENATION
				map_iterator & operator -- (void)
				{
					_ptr = prev(_ptr);
					return (*this);
				};

				// POST-DECREMENATION
				map_iterator operator -- (int)
				{
					map_iterator	tmp(*this);

					_ptr = prev(_ptr);
					return (tmp);
				};

			private:

				nodePointer maximum(nodePointer node)
				{
					while (node->right->color != NIL)
						node = node->right;
					return (node);
				};

				nodePointer minimum(nodePointer node)
				{
					while (node->left->color != NIL) 
						node = node->left;
					return (node);
				};

				nodePointer next(nodePointer node)
				{
					if (node->color == NIL)
						return (node);
					if (node->right->color != NIL)
						return (minimum(node->right));
					nodePointer _ptr = node->parent;
					while (_ptr->color != NIL && node == _ptr->right)
					{
						node = _ptr;
						_ptr = _ptr->parent;
					}
					return (_ptr);
				};

				nodePointer prev(nodePointer node)
				{
					if (node->color == NIL)
						return (node->parent);
					if (node->color != NIL && node->left->color != NIL)
						return (maximum(node->left));
					nodePointer _ptr = node->parent;
					while (_ptr->color != NIL && node == _ptr->left)
					{
						node = _ptr;
						_ptr = _ptr->parent;
					}
					if (_ptr->color != NIL)
						return (_ptr);
					return (node);
				};

		}; // END OF MAP_ITERATOR CLASS

}; // END OF NAMESPACE FT

#endif
