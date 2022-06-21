/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 16:26:01 by cmariot           #+#    #+#             */
/*   Updated: 2022/06/21 12:19:36 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include <cstddef>

namespace	ft
{

	// ITERATOR CATEGORIES :
	// Empty classes to identify the category of an iterator

		// InputIterator
		struct input_iterator_tag
		{
		};

		// ForwardIterator
		struct forward_iterator_tag
		{
		};

		// BidirectionalIterator
		struct bidirectional_iterator_tag
		{
		};

		// RandomAccessIterator
		struct random_access_iterator_tag
		{
		};

		// OutputIterator
		struct output_iterator_tag
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
	};
	template <class T>
	class iterator_traits<T*>
	{
	};
	template <class T>
	class iterator_traits<const T*>
	{
	};


	// INPUT ITERATOR
	template <class T>
	class input_iterator : ft::iterator<ft::input_iterator_tag, T>
	{

		public :

			typedef ft::input_iterator_tag		iterator_category;
			typedef std::ptrdiff_t				difference_type;
			typedef T							value_type;
			typedef T *							pointer;
			typedef T &							reference;
			typedef const T &					const_reference;

		private :

	};

	// OUTPUT ITERATOR
	template <class T>
	class output_iterator : ft::iterator<ft::output_iterator_tag, T>
	{

		public :

			typedef ft::output_iterator_tag			iterator_category;
			typedef std::ptrdiff_t					difference_type;
			typedef T								value_type;
			typedef T *								pointer;
			typedef T &								reference;
			typedef const T &						const_reference;

		private :

	};

	// FORWARD ITERATOR
	template <class T>
	class forward_iterator : ft::input_iterator<T>, ft::output_iterator<T>
	{

		public :

			typedef ft::forward_iterator_tag		iterator_category;
			typedef std::ptrdiff_t					difference_type;
			typedef T								value_type;
			typedef T *								pointer;
			typedef T &								reference;
			typedef const T &						const_reference;

		private :

	};

	// BIDIRECTIONAL ITERATOR
	template <class T>
	class bidirectional_iterator : ft::forward_iterator<T>
	{

		public :

			typedef ft::bidirectional_iterator_tag	iterator_category;
			typedef std::ptrdiff_t					difference_type;
			typedef T								value_type;
			typedef T *								pointer;
			typedef T &								reference;
			typedef const T &						const_reference;

		private :

	};

	// RANDOM ACCESS ITERATOR
	template <class T>
	class random_access_iterator : ft::bidirectional_iterator<T>
	{

		public :

			typedef ft::random_access_iterator_tag	iterator_category;
			typedef std::ptrdiff_t					difference_type;
			typedef T								value_type;
			typedef T *								pointer;
			typedef T &								reference;
			typedef const T &						const_reference;

		private :

	};


//	template <class T>
//	class random_access_iterator : ft::iterator<std::random_access_iterator_tag, T>
//	{
//
//		public :
//
//			//ITERATORS
//				typedef std::forward_iterator_tag	iterator_category;
//				typedef std::ptrdiff_t				difference_type;
//				typedef T							value_type;
//				typedef T *							pointer;
//				typedef T &							reference;
//				typedef const T &					const_reference;
//
//				// CONSTRUCTOR
//				iterator(pointer ptr) :
//					m_ptr(ptr)
//				{
//					return ;
//				};
//
//				// DEREFERENCE
//				reference operator * (void) const
//				{
//					return (*m_ptr);
//				}
//
//				// DEREFERENCE
//				pointer operator -> (void)
//				{
//					return (m_ptr);
//				}
//
//				// PREFIX INCREMENTATION
//				iterator & operator ++ (void)
//				{
//					m_ptr++;
//					return (*this);
//				}
//
//				// SUFIX INCREMENTATION
//				iterator operator ++ (int)
//				{
//					iterator tmp(*this);
//					++(*this);
//					return (tmp);
//				}
//
//				// COMPARAISON ==
//				friend bool operator == (const iterator & a, const iterator & b)
//				{
//					return (a.m_ptr == b.m_ptr);
//				};
//
//				// COMPARAISON !=
//				friend bool operator != (const iterator & a, const iterator & b)
//				{
//					return (a.m_ptr != b.m_ptr);
//				};
//
//
//				private :
//
//					pointer		m_ptr;
//
//			};
//	};

};

#endif
