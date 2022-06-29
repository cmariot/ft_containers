/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 16:26:01 by cmariot           #+#    #+#             */
/*   Updated: 2022/06/29 19:02:28 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP

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


	// INPUT ITERATOR
	template <class T>
	class input_iterator
	{

		public :

			typedef ft::iterator_traits<iterator<std::input_iterator_tag, T> >	traits;

			typedef typename traits::iterator_category	iterator_category;
			typedef typename traits::value_type			value_type;
			typedef typename traits::difference_type	difference_type;
			typedef typename traits::pointer			pointer;
			typedef typename traits::reference			reference;

			// COPY CONSTRUCTOR
			input_iterator(pointer ptr) :
				_ptr(ptr)
			{
				return ;
			};

			// COPY ASSIGNATION (=)
			reference operator = (input_iterator x)
			{
				this->_ptr = x->_ptr;
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
				return (a._ptr == b._ptr);
			};

			// OPERATOR !=
			friend bool operator != (const input_iterator & a, const input_iterator & b)
			{
				return (a._ptr != b._ptr);
			};
			
			// DEREFERENCE
			reference operator * (void) const
			{
				return (*_ptr);
			};

			// DEREFERENCE
			pointer operator -> (void)
			{
				return (_ptr);
			};

			// PREFIX INCREMENTATION
			input_iterator & operator ++ (void)
			{
				_ptr++;
				return (*this);
			};

			// SUFIX INCREMENTATION
			input_iterator operator ++ (int)
			{
				input_iterator tmp(*this);
				++(*this);
				return (tmp);
			};

		private :

			pointer		_ptr;

	};

	// OUTPUT ITERATOR
	template <class T>
	class output_iterator
	{

		public :

			typedef ft::iterator_traits<iterator<std::output_iterator_tag, T> >	traits;

			typedef typename traits::iterator_category		iterator_category;
			typedef typename traits::value_type				value_type;
			typedef typename traits::difference_type		difference_type;
			typedef typename traits::pointer				pointer;
			typedef typename traits::reference				reference;

			// COPY CONSTRUCTOR
			output_iterator(pointer ptr) :
				_ptr(ptr)
			{
				return ;
			};

			// COPY ASSIGNATION (=)
			reference operator = (output_iterator x)
			{
				this->_ptr = x->_ptr;
				return (*this);
			};

			// DESTRUCTOR
			~output_iterator(void)
			{
				return ;
			};

			// DEREFERENCE
			reference operator * (void) const
			{
				return (*_ptr);
			};

			// PREFIX INCREMENTATION
			output_iterator & operator ++ (void)
			{
				_ptr++;
				return (*this);
			};

			// SUFIX INCREMENTATION
			output_iterator operator ++ (int)
			{
				output_iterator tmp(*this);
				++(*this);
				return (tmp);
			};

		private :

			pointer		_ptr;

	};

	// FORWARD ITERATOR
	template <class T>
	class forward_iterator
	{

		public :

			typedef ft::iterator_traits<iterator<std::forward_iterator_tag, T> >	traits;

			typedef typename traits::iterator_category		iterator_category;
			typedef typename traits::value_type				value_type;
			typedef typename traits::difference_type		difference_type;
			typedef typename traits::pointer				pointer;
			typedef typename traits::reference				reference;

			// DEFAULT CONSTRUCTOR
			forward_iterator(void) :
				_ptr(NULL)
			{
				return ;
			};

			// COPY CONSTRUCTOR
			forward_iterator(pointer ptr) :
				_ptr(ptr)
			{
				return ;
			};

			// COPY ASSIGNATION (=)
			reference operator = (forward_iterator x)
			{
				this->_ptr = x->_ptr;
				return (*this);
			};

			// DESTRUCTOR
			~forward_iterator(void)
			{
				return ;
			};

			// DEREFERENCE
			reference operator * (void) const
			{
				return (*_ptr);
			};

			// DEREFERENCE
			pointer operator -> (void)
			{
				return (_ptr);
			};

			// PREFIX INCREMENTATION
			forward_iterator & operator ++ (void)
			{
				_ptr++;
				return (*this);
			};

			// SUFIX INCREMENTATION
			forward_iterator operator ++ (int)
			{
				forward_iterator tmp(*this);
				++(*this);
				return (tmp);
			};

			// OPERATOR ==
			friend bool operator == (const forward_iterator & a, const forward_iterator & b)
			{
				return (a._ptr == b._ptr);
			};

			// OPERATOR !=
			friend bool operator != (const forward_iterator & a, const forward_iterator & b)
			{
				return (a._ptr != b._ptr);
			};

		private :

			pointer		_ptr;

	};

	// BIDIRECTIONAL ITERATOR
	template <class T>
	class bidirectional_iterator
	{

		public :

			typedef ft::iterator_traits<iterator<std::bidirectional_iterator_tag, T> >	traits;

			typedef typename traits::iterator_category		iterator_category;
			typedef typename traits::value_type				value_type;
			typedef typename traits::difference_type		difference_type;
			typedef typename traits::pointer				pointer;
			typedef typename traits::reference				reference;

			// DEFAULT CONSTRUCTOR
			bidirectional_iterator(void) :
				_ptr(NULL)
			{
				return ;
			};

			// COPY CONSTRUCTOR
			bidirectional_iterator(pointer ptr) :
				_ptr(ptr)
			{
				return ;
			};

			// COPY ASSIGNATION (=)
			reference operator = (bidirectional_iterator x)
			{
				this->_ptr = x._ptr;
				return (*this);
			};

			// DESTRUCTOR
			~bidirectional_iterator(void)
			{
				return ;
			};

			// DEREFERENCE
			reference operator * (void) const
			{
				return (*_ptr);
			};

			// DEREFERENCE
			pointer operator -> (void)
			{
				return (_ptr);
			};

			// PREFIX INCREMENTATION
			bidirectional_iterator & operator ++ (void)
			{
				_ptr++;
				return (*this);
			};

			// SUFIX INCREMENTATION
			bidirectional_iterator operator ++ (int)
			{
				bidirectional_iterator tmp(*this);
				++(*this);
				return (tmp);
			};

			// PREFIX DECREMENTATION
			bidirectional_iterator & operator -- (void)
			{
				_ptr--;
				return (*this);
			};

			// SUFIX DECREMENTATION
			bidirectional_iterator operator -- (int)
			{
				bidirectional_iterator tmp(*this);
				--(*this);
				return (tmp);
			};

			// OPERATOR ==
			friend bool operator == (const bidirectional_iterator & a, const bidirectional_iterator & b)
			{
				return (a._ptr == b._ptr);
			};

			// OPERATOR !=
			friend bool operator != (const bidirectional_iterator & a, const bidirectional_iterator & b)
			{
				return (a._ptr != b._ptr);
			};

		private :

			pointer		_ptr;

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
			random_access_iterator operator = (random_access_iterator x)
			{
				this->_ptr = x._ptr;
				return (*this);
			};

			// DESTRUCTOR
			~random_access_iterator(void)
			{
				return ;
			};

			// DEREFERENCE
			reference operator * (void) const
			{
				return (*_ptr);
			};

			// DEREFERENCE
			pointer operator -> (void)
			{
				return (&(this->operator*()));
			};

			// PREFIX INCREMENTATION
			random_access_iterator & operator ++ (void)
			{
				_ptr++;
				return (*this);
			};

			// SUFIX INCREMENTATION
			random_access_iterator operator ++ (int)
			{
				random_access_iterator	tmp(*this);

				++(*this);
				return (tmp);
			};

			// PREFIX DECREMENTATION
			random_access_iterator & operator -- (void)
			{
				_ptr--;
				return (*this);
			};

			// SUFIX DECREMENTATION
			random_access_iterator operator -- (int)
			{
				random_access_iterator	tmp(*this);

				--(*this);
				return (tmp);
			};

			// OPERATOR ==
			friend bool operator == (const random_access_iterator & a, const random_access_iterator & b)
			{
				return (a._ptr == b._ptr);
			};

			// OPERATOR !=
			friend bool operator != (const random_access_iterator & a, const random_access_iterator & b)
			{
				return (a._ptr != b._ptr);
			};

			//ARITHMETIC OPERATOR - (this - n)
			random_access_iterator operator - (difference_type n) const
			{
				random_access_iterator tmp = *this;
				return (tmp -= n);
			};

			//ARITHMETIC OPERATOR + (this + n)
			random_access_iterator operator + (difference_type n)
			{
				random_access_iterator tmp = *this;
				return (tmp += n);
			};

			//ARITHMETIC OPERATOR - (n - this)
			difference_type operator - (random_access_iterator rhs) const
			{
				difference_type	ret = rhs._ptr - _ptr;

				return (ret);
			};

			//ARITHMETIC OPERATOR + (n + this)
			difference_type operator + (random_access_iterator rhs) const
			{
				difference_type	ret = rhs._ptr + _ptr;

				return (ret);
			};

			//OPERATOR +=
			random_access_iterator operator += (difference_type const &x)
			{
				_ptr += x;
				return (*this);
			};

			//OPERATOR -=
			random_access_iterator operator -= (difference_type const &x)
			{
				_ptr -= x;
				return (*this);
			};

			//OPERATOR []
			reference operator [] (difference_type n)
			{
				return *(_ptr + n);
			};

			// OPERATOR <
			bool operator < (const random_access_iterator & rhs)
			{
				return (**this < *rhs);
			};

			// OPERATOR >
			bool operator > (const random_access_iterator & rhs)
			{
				return (*rhs < **this);
			};

			// OPERATOR <=
			bool operator <= (const random_access_iterator & rhs)
			{
				if (*this < rhs || *this == rhs)
					return (true);
				return (false);
			};

			// OPERATOR >=
			bool operator >= (const random_access_iterator & rhs)
			{
				if (*this < rhs || !(*this == rhs))
					return (false);
				return (true);
			};

		private :

			pointer		_ptr;

	};
};

#endif
