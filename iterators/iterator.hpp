/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 16:26:01 by cmariot           #+#    #+#             */
/*   Updated: 2022/07/07 16:52:23 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include <iostream>

namespace	ft
{

	template <class T>
	class const_random_access_iterator;

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

	template <class Category, class T, class Distance = std::ptrdiff_t, class Pointer = T *, class Reference =  T&>
	struct iterator
	{

		typedef Category		iterator_category;
		typedef T				value_type;
		typedef Distance		difference_type;
		typedef Pointer			pointer;
		typedef Reference		reference;

	};


	// ITERATOR TRAITS
	// Traits class defining properties of iterators.
	// For every iterator type, a corresponding specialization of iterator_traits class template shall be defined
	template <class Iterator>
	struct iterator_traits
	{

		typedef typename Iterator::iterator_category	iterator_category;
		typedef typename Iterator::value_type			value_type;
		typedef typename Iterator::difference_type		difference_type;
		typedef typename Iterator::pointer				pointer;
		typedef typename Iterator::reference			reference;

	};
	
	template <class T>
	struct iterator_traits<T*>
	{

		typedef random_access_iterator_tag				iterator_category;
		typedef T										value_type;
		typedef std::ptrdiff_t							difference_type;
		typedef T*										pointer;
		typedef T&										reference;

	};
	
	template <class T>
	struct iterator_traits<const T*>
	{

		typedef random_access_iterator_tag				iterator_category;
		typedef T										value_type;
		typedef std::ptrdiff_t							difference_type;
		typedef const T*								pointer;
		typedef const T&								reference;

	};


	// RANDOM ACCESS ITERATOR
	template <class T>
	class random_access_iterator
	{

		public :

			typedef ft::iterator_traits<iterator<std::random_access_iterator_tag, T> >	traits;

			typedef typename traits::iterator_category		iterator_category;
			typedef typename traits::value_type				value_type;
			typedef typename traits::difference_type		difference_type;
			typedef typename traits::pointer				pointer;
			typedef typename traits::reference				reference;

			// DEFAULT CONSTRUCTOR
			random_access_iterator(void) :
				_ptr(NULL)
			{
				return ;
			};

			// COPY CONSTRUCTOR
			random_access_iterator(pointer ptr) :
				_ptr(ptr)
			{
				return ;
			};

			// COPY ASSIGNATION (=)
			random_access_iterator operator = (const random_access_iterator & rhs)
			{
				if (this == &rhs)
					return (*this);
				this->_ptr = rhs._ptr;
				return (*this);
			};

			// DESTRUCTOR
			~random_access_iterator(void)
			{
				return ;
			};

			// DEREFERENCE
			reference operator * (void)
			{
				return (*_ptr);
			};

			// DEREFERENCE
			pointer operator -> (void)
			{
				return (_ptr);
			};

			// PREFIX INCREMENTATION
			random_access_iterator & operator ++ (void)
			{
				++_ptr;
				return (*this);
			};

			// SUFIX INCREMENTATION
			random_access_iterator operator ++ (int)
			{
				random_access_iterator	tmp(*this);

				operator++();
				return (tmp);
			};

			// PREFIX DECREMENTATION
			random_access_iterator & operator -- (void)
			{
				--_ptr;
				return (*this);
			};

			// SUFIX DECREMENTATION
			random_access_iterator operator -- (int)
			{
				random_access_iterator	tmp(*this);

				operator--();
				return (tmp);
			};

			// OPERATOR ==
			bool operator == (const random_access_iterator & rhs) const
			{
				return (_ptr == rhs._ptr);
			};

			// OPERATOR !=
			bool operator != (const random_access_iterator & rhs) const
			{
				return (_ptr != rhs._ptr);
			};
			
			// OPERATOR >
			bool operator > (const random_access_iterator & rhs) const
			{
				return (_ptr > rhs._ptr);
			};

			// OPERATOR >=
			bool operator >= (const random_access_iterator & rhs) const
			{
				return (_ptr >= rhs._ptr);
			};

			// OPERATOR <
			bool operator < (const random_access_iterator & rhs) const
			{
				return (_ptr < rhs._ptr);
			};

			// OPERATOR <=
			bool operator <= (const random_access_iterator & rhs) const
			{
				return (_ptr <= rhs._ptr);
			};

			// OPERATOR ==
			bool operator == (const const_random_access_iterator<T> & rhs) const
			{
				return (_ptr == rhs._ptr);
			};

			// OPERATOR !=
			bool operator != (const const_random_access_iterator<T> & rhs) const
			{
				return (_ptr != rhs._ptr);
			};
			
			// OPERATOR >
			bool operator > (const const_random_access_iterator<T> & rhs) const
			{
				return (_ptr > rhs._ptr);
			};

			// OPERATOR >=
			bool operator >= (const const_random_access_iterator<T> & rhs) const
			{
				return (_ptr >= rhs._ptr);
			};

			// OPERATOR <
			bool operator < (const const_random_access_iterator<T> & rhs) const
			{
				return (_ptr < rhs._ptr);
			};

			// OPERATOR <=
			bool operator <= (const const_random_access_iterator<T> & rhs) const
			{
				return (_ptr <= rhs._ptr);
			};

			// ARITHMETIC OPERATOR : a + n
			random_access_iterator operator + (difference_type n)
			{
				random_access_iterator tmp(*this);
				tmp += n;
				return (tmp);
			}
			
			// ARITHMETIC OPERATOR : n + a
			friend random_access_iterator operator + (difference_type n, random_access_iterator rhs)
			{
				return (rhs + n);
			}

			// ARITHMETIC OPERATOR : a - n
			random_access_iterator operator - (difference_type n)
			{
				random_access_iterator tmp(*this);
				tmp -= n;
				return (tmp);
			}

			// ARITHMETIC OPERATOR : a - b
			difference_type operator - (random_access_iterator rhs)
			{
				return _ptr - rhs._ptr;
			}

			//OPERATOR +=
			random_access_iterator operator += (difference_type n)
			{
				_ptr += n;
				return (*this);
			};

			//OPERATOR -=
			random_access_iterator operator -= (difference_type n)
			{
				_ptr -= n;
				return (*this);
			};

			//OPERATOR []
			reference operator [] (difference_type n) const
			{
				return *(_ptr + n);
			};

		public :

			pointer		_ptr;

	};

	template <class T>
	class const_random_access_iterator
	{

		public :

			typedef ft::iterator_traits<iterator<std::random_access_iterator_tag, const T> >	traits;

			typedef typename traits::iterator_category		iterator_category;
			typedef typename traits::value_type				value_type;
			typedef typename traits::difference_type		difference_type;
			typedef typename traits::pointer				pointer;
			typedef typename traits::reference				reference;

			// DEFAULT CONSTRUCTOR
			const_random_access_iterator(void) :
				_ptr(NULL)
			{
				return ;
			};

			// COPY CONSTRUCTOR
			const_random_access_iterator(pointer ptr) :
				_ptr(ptr)
			{
				return ;
			};

			const_random_access_iterator(const const_random_access_iterator & rhs)
			{
				_ptr = rhs._ptr;
				return ;
			};

			const_random_access_iterator(const ft::random_access_iterator<T> & rhs)
			{
				_ptr = rhs._ptr;
				return ;
			};

			// COPY ASSIGNATION (=) const_iterator
			const_random_access_iterator operator = (const const_random_access_iterator & rhs)
			{
				if (this == &rhs)
					return (*this);
				this->_ptr = rhs._ptr;
				return (*this);
			};

			// COPY ASSIGNATION (=) const_iterator
			const_random_access_iterator operator = (const ft::random_access_iterator<T> & rhs)
			{
				this->_ptr = rhs._ptr;
				return (*this);
			};

			// DESTRUCTOR
			~const_random_access_iterator(void)
			{
				return ;
			};

			// DEREFERENCE
			reference operator * (void)
			{
				return (*_ptr);
			};

			// DEREFERENCE
			pointer operator -> (void)
			{
				return (_ptr);
			};

			// PREFIX INCREMENTATION
			const_random_access_iterator & operator ++ (void)
			{
				++_ptr;
				return (*this);
			};

			// SUFIX INCREMENTATION
			const_random_access_iterator operator ++ (int)
			{
				const_random_access_iterator	tmp(*this);

				operator++();
				return (tmp);
			};

			// PREFIX DECREMENTATION
			const_random_access_iterator & operator -- (void)
			{
				--_ptr;
				return (*this);
			};

			// SUFIX DECREMENTATION
			const_random_access_iterator operator -- (int)
			{
				const_random_access_iterator	tmp(*this);

				operator--();
				return (tmp);
			};

			// OPERATOR ==
			bool operator == (const const_random_access_iterator & rhs) const
			{
				return (_ptr == rhs._ptr);
			};

			// OPERATOR !=
			bool operator != (const const_random_access_iterator & rhs) const
			{
				return (_ptr != rhs._ptr);
			};
			
			// OPERATOR >
			bool operator > (const const_random_access_iterator & rhs) const
			{
				return (_ptr > rhs._ptr);
			};

			// OPERATOR >=
			bool operator >= (const const_random_access_iterator & rhs) const
			{
				return (_ptr >= rhs._ptr);
			};

			// OPERATOR <
			bool operator < (const const_random_access_iterator & rhs) const
			{
				return (_ptr < rhs._ptr);
			};

			// OPERATOR <=
			bool operator <= (const const_random_access_iterator & rhs) const
			{
				return (_ptr <= rhs._ptr);
			};

			// ARITHMETIC OPERATOR : a + n
			const_random_access_iterator operator + (difference_type n)
			{
				const_random_access_iterator tmp(*this);
				tmp += n;
				return (tmp);
			}
			
			// ARITHMETIC OPERATOR : n + a
			friend const_random_access_iterator operator + (difference_type n, const_random_access_iterator rhs)
			{
				return (rhs + n);
			}

			// ARITHMETIC OPERATOR : a - n
			const_random_access_iterator operator - (difference_type n)
			{
				const_random_access_iterator tmp(*this);
				tmp -= n;
				return (tmp);
			}

			// ARITHMETIC OPERATOR : a - b
			difference_type operator - (const_random_access_iterator rhs) const
			{
				return _ptr - rhs._ptr;
			}

			//OPERATOR +=
			const_random_access_iterator operator += (difference_type n)
			{
				_ptr += n;
				return (*this);
			};

			//OPERATOR -=
			const_random_access_iterator operator -= (difference_type n)
			{
				_ptr -= n;
				return (*this);
			};

			//OPERATOR []
			reference operator [] (difference_type n) const
			{
				return *(_ptr + n);
			};

		public :

			const T*	_ptr;

	};
};

#endif
