/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bidirectional_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 19:38:11 by cmariot           #+#    #+#             */
/*   Updated: 2022/07/27 00:20:15 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIDIRECTIONAL_ITERATOR_HPP
# define BIDIRECTIONAL_ITERATOR_HPP

# include <iostream>

# include "random_access_iterator.hpp"

namespace	ft
{

	template <class T>
	class const_bidirectional_iterator;

	// RANDOM ACCESS ITERATOR
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
			bidirectional_iterator operator = (const bidirectional_iterator & rhs)
			{
				if (this == &rhs)
					return (*this);
				this->_ptr = rhs._ptr;
				return (*this);
			};

			// DESTRUCTOR
			~bidirectional_iterator(void)
			{
				return ;
			};

			// DEREFERENCE
			reference operator * (void)
			{
				return (*(_ptr->_pair));
			};

			// DEREFERENCE
			pointer operator -> (void)
			{
				return (_ptr->_pair);
			};

			// PREFIX INCREMENTATION
			bidirectional_iterator & operator ++ (void)
			{
				++_ptr;
				return (*this);
			};

			// SUFIX INCREMENTATION
			bidirectional_iterator operator ++ (int)
			{
				bidirectional_iterator	tmp(*this);

				operator++();
				return (tmp);
			};

			// PREFIX DECREMENTATION
			bidirectional_iterator & operator -- (void)
			{
				--_ptr;
				return (*this);
			};

			// SUFIX DECREMENTATION
			bidirectional_iterator operator -- (int)
			{
				bidirectional_iterator	tmp(*this);

				operator--();
				return (tmp);
			};

			// OPERATOR ==
			bool operator == (const bidirectional_iterator & rhs) const
			{
				return (_ptr == rhs._ptr);
			};

			// OPERATOR !=
			bool operator != (const bidirectional_iterator & rhs) const
			{
				return (_ptr != rhs._ptr);
			};
			
			// OPERATOR ==
			bool operator == (const const_bidirectional_iterator<T> & rhs) const
			{
				return (_ptr == rhs._ptr);
			};

			// OPERATOR !=
			bool operator != (const const_bidirectional_iterator<T> & rhs) const
			{
				return (_ptr != rhs._ptr);
			};

		public :

			pointer		_ptr;

	};

	template <class T>
	class const_bidirectional_iterator
	{

		public :

			typedef ft::iterator_traits<iterator<std::bidirectional_iterator_tag, const T> >	traits;

			typedef typename traits::iterator_category		iterator_category;
			typedef typename traits::value_type				value_type;
			typedef typename traits::difference_type		difference_type;
			typedef typename traits::pointer				pointer;
			typedef typename traits::reference				reference;

			// DEFAULT CONSTRUCTOR
			const_bidirectional_iterator(void) :
				_ptr(NULL)
			{
				return ;
			};

			// COPY CONSTRUCTOR
			const_bidirectional_iterator(pointer ptr) :
				_ptr(ptr)
			{
				return ;
			};

			const_bidirectional_iterator(const const_bidirectional_iterator & rhs)
			{
				_ptr = rhs._ptr;
				return ;
			};

			const_bidirectional_iterator(const ft::bidirectional_iterator<T> & rhs)
			{
				_ptr = rhs._ptr;
				return ;
			};

			// COPY ASSIGNATION (=) const_iterator
			const_bidirectional_iterator operator = (const const_bidirectional_iterator & rhs)
			{
				if (this == &rhs)
					return (*this);
				this->_ptr = rhs._ptr;
				return (*this);
			};

			// COPY ASSIGNATION (=) const_iterator
			const_bidirectional_iterator operator = (const ft::bidirectional_iterator<T> & rhs)
			{
				this->_ptr = rhs._ptr;
				return (*this);
			};

			// DESTRUCTOR
			~const_bidirectional_iterator(void)
			{
				return ;
			};

			// DEREFERENCE
			reference operator * (void)
			{
				return (*_ptr);
			};

			// DEREFERENCE
			pointer operator -> (void) const
			{
				return (_ptr);
			};

			// PREFIX INCREMENTATION
			const_bidirectional_iterator & operator ++ (void)
			{
				++_ptr;
				return (*this);
			};

			// SUFIX INCREMENTATION
			const_bidirectional_iterator operator ++ (int)
			{
				const_bidirectional_iterator	tmp(*this);

				operator++();
				return (tmp);
			};

			// PREFIX DECREMENTATION
			const_bidirectional_iterator & operator -- (void)
			{
				--_ptr;
				return (*this);
			};

			// SUFIX DECREMENTATION
			const_bidirectional_iterator operator -- (int)
			{
				const_bidirectional_iterator	tmp(*this);

				operator--();
				return (tmp);
			};

			// OPERATOR ==
			bool operator == (const const_bidirectional_iterator & rhs) const
			{
				return (_ptr == rhs._ptr);
			};

			// OPERATOR !=
			bool operator != (const const_bidirectional_iterator & rhs) const
			{
				return (_ptr != rhs._ptr);
			};

			// OPERATOR ==
			bool operator == (const bidirectional_iterator<T> & rhs) const
			{
				return (_ptr == rhs._ptr);
			};

			// OPERATOR !=
			bool operator != (const bidirectional_iterator<T> & rhs) const
			{
				return (_ptr != rhs._ptr);
			};

		public :

			const T*	_ptr;

	};
};

#endif
