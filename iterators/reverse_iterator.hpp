/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 19:30:01 by cmariot           #+#    #+#             */
/*   Updated: 2022/07/07 16:55:57 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

# include <iostream>
# include "iterator.hpp"

namespace	ft
{
	template <class T>
	class const_reverse_iterator;

	// RANDOM ACCESS ITERATOR
	template <class T>
	class reverse_iterator
	{

		public :

			typedef ft::iterator_traits<iterator<std::random_access_iterator_tag, T> >	traits;

			typedef typename traits::iterator_category		iterator_category;
			typedef typename traits::value_type				value_type;
			typedef typename traits::difference_type		difference_type;
			typedef typename traits::pointer				pointer;
			typedef typename traits::reference				reference;

			// DEFAULT CONSTRUCTOR
			reverse_iterator(void) :
				_ptr(NULL)
			{
				return ;
			};

			// COPY CONSTRUCTOR
			reverse_iterator(pointer ptr) :
				_ptr(ptr)
			{
				return ;
			};

			// COPY ASSIGNATION (=)
			reverse_iterator operator = (const reverse_iterator & rhs)
			{
				if (this == &rhs)
					return (*this);
				this->_ptr = rhs._ptr;
				return (*this);
			};

			// DESTRUCTOR
			~reverse_iterator(void)
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
			reverse_iterator & operator ++ (void)
			{
				++_ptr;
				return (*this);
			};

			// SUFIX INCREMENTATION
			reverse_iterator operator ++ (int)
			{
				reverse_iterator	tmp(*this);

				operator++();
				return (tmp);
			};

			// PREFIX DECREMENTATION
			reverse_iterator & operator -- (void)
			{
				--_ptr;
				return (*this);
			};

			// SUFIX DECREMENTATION
			reverse_iterator operator -- (int)
			{
				reverse_iterator	tmp(*this);

				operator--();
				return (tmp);
			};

			// OPERATOR ==
			bool operator == (const reverse_iterator & rhs) const
			{
				return (_ptr == rhs._ptr);
			};

			// OPERATOR !=
			bool operator != (const reverse_iterator & rhs) const
			{
				return (_ptr != rhs._ptr);
			};
			
			// OPERATOR >
			bool operator > (const reverse_iterator & rhs) const
			{
				return (_ptr > rhs._ptr);
			};

			// OPERATOR >=
			bool operator >= (const reverse_iterator & rhs) const
			{
				return (_ptr >= rhs._ptr);
			};

			// OPERATOR <
			bool operator < (const reverse_iterator & rhs) const
			{
				return (_ptr < rhs._ptr);
			};

			// OPERATOR <=
			bool operator <= (const reverse_iterator & rhs) const
			{
				return (_ptr <= rhs._ptr);
			};

			// OPERATOR ==
			bool operator == (const const_reverse_iterator<T> & rhs) const
			{
				return (_ptr == rhs._ptr);
			};

			// OPERATOR !=
			bool operator != (const const_reverse_iterator<T> & rhs) const
			{
				return (_ptr != rhs._ptr);
			};
			
			// OPERATOR >
			bool operator > (const const_reverse_iterator<T> & rhs) const
			{
				return (_ptr > rhs._ptr);
			};

			// OPERATOR >=
			bool operator >= (const const_reverse_iterator<T> & rhs) const
			{
				return (_ptr >= rhs._ptr);
			};

			// OPERATOR <
			bool operator < (const const_reverse_iterator<T> & rhs) const
			{
				return (_ptr < rhs._ptr);
			};

			// OPERATOR <=
			bool operator <= (const const_reverse_iterator<T> & rhs) const
			{
				return (_ptr <= rhs._ptr);
			};

			// ARITHMETIC OPERATOR : a + n
			reverse_iterator operator + (difference_type n)
			{
				reverse_iterator tmp(*this);
				tmp += n;
				return (tmp);
			}
			
			// ARITHMETIC OPERATOR : n + a
			friend reverse_iterator operator + (difference_type n, reverse_iterator rhs)
			{
				return (rhs + n);
			}

			// ARITHMETIC OPERATOR : a - n
			reverse_iterator operator - (difference_type n)
			{
				reverse_iterator tmp(*this);
				tmp -= n;
				return (tmp);
			}

			// ARITHMETIC OPERATOR : a - b
			difference_type operator - (reverse_iterator rhs)
			{
				return _ptr - rhs._ptr;
			}

			//OPERATOR +=
			reverse_iterator operator += (difference_type n)
			{
				_ptr += n;
				return (*this);
			};

			//OPERATOR -=
			reverse_iterator operator -= (difference_type n)
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
	class const_reverse_iterator
	{

		public :

			typedef ft::iterator_traits<iterator<std::random_access_iterator_tag, const T> >	traits;

			typedef typename traits::iterator_category		iterator_category;
			typedef typename traits::value_type				value_type;
			typedef typename traits::difference_type		difference_type;
			typedef typename traits::pointer				pointer;
			typedef typename traits::reference				reference;

			// DEFAULT CONSTRUCTOR
			const_reverse_iterator(void) :
				_ptr(NULL)
			{
				return ;
			};

			// COPY CONSTRUCTOR
			const_reverse_iterator(pointer ptr) :
				_ptr(ptr)
			{
				return ;
			};

			const_reverse_iterator(const const_reverse_iterator & rhs)
			{
				_ptr = rhs._ptr;
				return ;
			};

			const_reverse_iterator(const ft::reverse_iterator<T> & rhs)
			{
				_ptr = rhs._ptr;
				return ;
			};

			// COPY ASSIGNATION (=) const_iterator
			const_reverse_iterator operator = (const const_reverse_iterator & rhs)
			{
				if (this == &rhs)
					return (*this);
				this->_ptr = rhs._ptr;
				return (*this);
			};

			// COPY ASSIGNATION (=) const_iterator
			const_reverse_iterator operator = (const ft::reverse_iterator<T> & rhs)
			{
				this->_ptr = rhs._ptr;
				return (*this);
			};

			// DESTRUCTOR
			~const_reverse_iterator(void)
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
			const_reverse_iterator & operator ++ (void)
			{
				++_ptr;
				return (*this);
			};

			// SUFIX INCREMENTATION
			const_reverse_iterator operator ++ (int)
			{
				const_reverse_iterator	tmp(*this);

				operator++();
				return (tmp);
			};

			// PREFIX DECREMENTATION
			const_reverse_iterator & operator -- (void)
			{
				--_ptr;
				return (*this);
			};

			// SUFIX DECREMENTATION
			const_reverse_iterator operator -- (int)
			{
				const_reverse_iterator	tmp(*this);

				operator--();
				return (tmp);
			};

			// OPERATOR ==
			bool operator == (const const_reverse_iterator & rhs) const
			{
				return (_ptr == rhs._ptr);
			};

			// OPERATOR !=
			bool operator != (const const_reverse_iterator & rhs) const
			{
				return (_ptr != rhs._ptr);
			};
			
			// OPERATOR >
			bool operator > (const const_reverse_iterator & rhs) const
			{
				return (_ptr > rhs._ptr);
			};

			// OPERATOR >=
			bool operator >= (const const_reverse_iterator & rhs) const
			{
				return (_ptr >= rhs._ptr);
			};

			// OPERATOR <
			bool operator < (const const_reverse_iterator & rhs) const
			{
				return (_ptr < rhs._ptr);
			};

			// OPERATOR <=
			bool operator <= (const const_reverse_iterator & rhs) const
			{
				return (_ptr <= rhs._ptr);
			};

			// ARITHMETIC OPERATOR : a + n
			const_reverse_iterator operator + (difference_type n)
			{
				const_reverse_iterator tmp(*this);
				tmp += n;
				return (tmp);
			}
			
			// ARITHMETIC OPERATOR : n + a
			friend const_reverse_iterator operator + (difference_type n, const_reverse_iterator rhs)
			{
				return (rhs + n);
			}

			// ARITHMETIC OPERATOR : a - n
			const_reverse_iterator operator - (difference_type n)
			{
				const_reverse_iterator tmp(*this);
				tmp -= n;
				return (tmp);
			}

			// ARITHMETIC OPERATOR : a - b
			difference_type operator - (const_reverse_iterator rhs) const
			{
				return _ptr - rhs._ptr;
			}

			//OPERATOR +=
			const_reverse_iterator operator += (difference_type n)
			{
				_ptr += n;
				return (*this);
			};

			//OPERATOR -=
			const_reverse_iterator operator -= (difference_type n)
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
