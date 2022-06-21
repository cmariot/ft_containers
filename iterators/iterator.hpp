/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 16:26:01 by cmariot           #+#    #+#             */
/*   Updated: 2022/06/21 16:42:59 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include <cstddef>
# include <iostream>

namespace	ft
{

	// Iterators are a generalization of pointers that allow a C++ program to work with
	// different data structures (containers) in a uniform manner.

	// ITERATOR CATEGORIES :
	// Empty types to identify the category of an iterator

		// InputIterator
		struct input_iterator_tag
		{
		};

		// OutputIterator
		struct output_iterator_tag
		{
		};

		// ForwardIterator
		struct forward_iterator_tag : public input_iterator_tag
		{
		};

		// BidirectionalIterator
		struct bidirectional_iterator_tag : public forward_iterator_tag
		{
		};

		// RandomAccessIterator
		struct random_access_iterator_tag : public bidirectional_iterator_tag
		{
		};


	// ITERATOR BASE CLASS
	// This is a base class template that can be used to derive iterator classes from it.
	// It is not an iterator class and does not provide any of the functionality an iterator is expected to have.
	
	// This base class only provides some member types,
	// which in fact are not required to be present in any iterator type (iterator types have no specific member requirements),
	// but they might be useful, since they define the members needed for the default iterator_traits class template
	// to generate the appropriate instantiation automatically (and such instantiation is required to be valid for all iterator types).

	template <class Category, class T, class Distance = ptrdiff_t, class Pointer = T *, class Reference =  T&>
	struct iterator
	{

		typedef Category  iterator_category;
		typedef T         value_type;
		typedef Distance  difference_type;
		typedef Pointer   pointer;
		typedef Reference reference;

	};


	// ITERATOR TRAITS
	// Traits class defining properties of iterators.
	// For every iterator type, a corresponding specialization of iterator_traits class template shall be defined
	template <class Iterator>
	class iterator_traits
	{
		public :

			typedef typename Iterator::iterator_category	iterator_category;
			typedef typename Iterator::value_type			value_type;
			typedef typename Iterator::difference_type		difference_type;
			typedef typename Iterator::pointer				pointer;
			typedef typename Iterator::reference			reference;

	};
	
	template <class T>
	class iterator_traits<T*>
	{

		public :

			typedef random_access_iterator_tag				iterator_category;
			typedef T										value_type;
			typedef ptrdiff_t								difference_type;
			typedef T*										pointer;
			typedef T&										reference;

	};
	
	template <class T>
	class iterator_traits<const T*>
	{

		public :

			typedef random_access_iterator_tag				iterator_category;
			typedef T										value_type;
			typedef ptrdiff_t								difference_type;
			typedef const T*								pointer;
			typedef const T&								reference;

	};


	// INPUT ITERATOR
	template <class T>
	class input_iterator
	{

		public :

			typedef ft::iterator_traits<iterator<input_iterator_tag, T> >	traits;

			typedef typename traits::iterator_category		iterator_category;
			typedef typename traits::value_type				value_type;
			typedef typename traits::difference_type		difference_type;
			typedef typename traits::pointer				pointer;
			typedef typename traits::reference				reference;

			// COPY CONSTRUCTOR
			input_iterator(pointer ptr) :
				m_ptr(ptr)
			{
				return ;
			};

			// COPY ASSIGNATION (=)
			reference operator = (input_iterator x)
			{
				this->m_ptr = x->m_ptr;
				return (*this);
			};

			// DESTRUCTOR
			~input_iterator(void)
			{
				return ;
			};

			// OPERATOR ==
			friend bool operator == (const input_iterator & a, const input_iterator & b)
			{
				return (a.m_ptr == b.m_ptr);
			};

			// OPERATOR !=
			friend bool operator != (const input_iterator & a, const input_iterator & b)
			{
				return (a.m_ptr != b.m_ptr);
			};
			
			// DEREFERENCE
			reference operator * (void) const
			{
				return (*m_ptr);
			}

			// DEREFERENCE
			pointer operator -> (void)
			{
				return (m_ptr);
			}

			// PREFIX INCREMENTATION
			input_iterator & operator ++ (void)
			{
				m_ptr++;
				return (*this);
			}

			// SUFIX INCREMENTATION
			input_iterator operator ++ (int)
			{
				input_iterator tmp(*this);
				++(*this);
				return (tmp);
			}

		private :

			pointer		m_ptr;

	};

	// OUTPUT ITERATOR
	template <class T>
	class output_iterator
	{

		public :

			typedef ft::iterator_traits<iterator<output_iterator_tag, T> >	traits;

			typedef typename traits::iterator_category		iterator_category;
			typedef typename traits::value_type				value_type;
			typedef typename traits::difference_type		difference_type;
			typedef typename traits::pointer				pointer;
			typedef typename traits::reference				reference;

		private :

			pointer		m_ptr;

	};

	// FORWARD ITERATOR
	template <class T>
	class forward_iterator
	{

		public :

			typedef ft::iterator_traits<iterator<forward_iterator_tag, T> >	traits;

			typedef typename traits::iterator_category		iterator_category;
			typedef typename traits::value_type				value_type;
			typedef typename traits::difference_type		difference_type;
			typedef typename traits::pointer				pointer;
			typedef typename traits::reference				reference;

		private :

			pointer		m_ptr;

	};

	// BIDIRECTIONAL ITERATOR
	template <class T>
	class bidirectional_iterator
	{

		public :

			typedef ft::iterator_traits<iterator<bidirectional_iterator_tag, T> >	traits;

			typedef typename traits::iterator_category		iterator_category;
			typedef typename traits::value_type				value_type;
			typedef typename traits::difference_type		difference_type;
			typedef typename traits::pointer				pointer;
			typedef typename traits::reference				reference;

		private :

			pointer		m_ptr;

	};

	// RANDOM ACCESS ITERATOR
	template <class T>
	class random_access_iterator
	{

		public :

			typedef ft::iterator_traits<iterator<random_access_iterator_tag, T> >	traits;

			typedef typename traits::iterator_category		iterator_category;
			typedef typename traits::value_type				value_type;
			typedef typename traits::difference_type		difference_type;
			typedef typename traits::pointer				pointer;
			typedef typename traits::reference				reference;

		private :

			pointer		m_ptr;

	};
};

#endif
