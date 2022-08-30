/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 21:44:00 by cmariot           #+#    #+#             */
/*   Updated: 2022/08/30 12:48:46 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_ITERATOR_HPP
# define VECTOR_ITERATOR_HPP

# include "iterator_traits.hpp"
# include "const_vector_iterator.hpp"

namespace ft
{

	// VECTOR ITERATOR
	template <class T>
	class vector_iterator
	{

		public :

			typedef ft::iterator_traits<iterator<std::random_access_iterator_tag, T> >	traits;

			typedef typename traits::iterator_category		iterator_category;
			typedef typename traits::value_type				value_type;
			typedef typename traits::difference_type		difference_type;
			typedef typename traits::pointer				pointer;
			typedef typename traits::reference				reference;

			// DEFAULT CONSTRUCTOR
			vector_iterator(void) :
				_ptr(NULL)
			{
				return ;
			};

			// COPY CONSTRUCTOR
			vector_iterator(pointer ptr) :
				_ptr(ptr)
			{
				return ;
			};

			// COPY ASSIGNATION (=)
			vector_iterator operator = (const vector_iterator & rhs)
			{
				if (this == &rhs)
					return (*this);
				this->_ptr = rhs._ptr;
				return (*this);
			};

			// DESTRUCTOR
			~vector_iterator(void)
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
			vector_iterator & operator ++ (void)
			{
				++_ptr;
				return (*this);
			};

			// SUFIX INCREMENTATION
			vector_iterator operator ++ (int)
			{
				vector_iterator	tmp(*this);

				operator++();
				return (tmp);
			};

			// PREFIX DECREMENTATION
			vector_iterator & operator -- (void)
			{
				--_ptr;
				return (*this);
			};

			// SUFIX DECREMENTATION
			vector_iterator operator -- (int)
			{
				vector_iterator	tmp(*this);

				operator--();
				return (tmp);
			};

			// OPERATOR ==
			bool operator == (const vector_iterator & rhs) const
			{
				return (_ptr == rhs._ptr);
			};

			// OPERATOR !=
			bool operator != (const vector_iterator & rhs) const
			{
				return (_ptr != rhs._ptr);
			};

			// OPERATOR >
			bool operator > (const vector_iterator & rhs) const
			{
				return (_ptr > rhs._ptr);
			};

			// OPERATOR >=
			bool operator >= (const vector_iterator & rhs) const
			{
				return (_ptr >= rhs._ptr);
			};

			// OPERATOR <
			bool operator < (const vector_iterator & rhs) const
			{
				return (_ptr < rhs._ptr);
			};

			// OPERATOR <=
			bool operator <= (const vector_iterator & rhs) const
			{
				return (_ptr <= rhs._ptr);
			};

			// OPERATOR ==
			bool operator == (const const_vector_iterator<T> & rhs) const
			{
				return (_ptr == rhs._ptr);
			};

			// OPERATOR !=
			bool operator != (const const_vector_iterator<T> & rhs) const
			{
				return (_ptr != rhs._ptr);
			};
			
			// OPERATOR >
			bool operator > (const const_vector_iterator<T> & rhs) const
			{
				return (_ptr > rhs._ptr);
			};

			// OPERATOR >=
			bool operator >= (const const_vector_iterator<T> & rhs) const
			{
				return (_ptr >= rhs._ptr);
			};

			// OPERATOR <
			bool operator < (const const_vector_iterator<T> & rhs) const
			{
				return (_ptr < rhs._ptr);
			};

			// OPERATOR <=
			bool operator <= (const const_vector_iterator<T> & rhs) const
			{
				return (_ptr <= rhs._ptr);
			};
			
			// ARITHMETIC OPERATOR : a + n
			vector_iterator operator + (difference_type n)
			{
				vector_iterator tmp(*this);
				tmp += n;
				return (tmp);
			}
			
			// ARITHMETIC OPERATOR : n + a
			friend vector_iterator operator + (difference_type n, vector_iterator rhs)
			{
				return (rhs + n);
			}

			// ARITHMETIC OPERATOR : a - n
			vector_iterator operator - (difference_type n)
			{
				vector_iterator tmp(*this);
				tmp -= n;
				return (tmp);
			}

			// ARITHMETIC OPERATOR : a - b
			difference_type operator - (vector_iterator rhs)
			{
				return _ptr - rhs._ptr;
			}
			difference_type operator - (const_vector_iterator<T> rhs)
			{
				return _ptr - rhs._ptr;
			}

			//OPERATOR +=
			vector_iterator operator += (difference_type n)
			{
				_ptr += n;
				return (*this);
			};

			//OPERATOR -=
			vector_iterator operator -= (difference_type n)
			{
				_ptr -= n;
				return (*this);
			};

			//OPERATOR []
			reference operator [] (difference_type n) const
			{
				return *(_ptr + n);
			};

			// BASE
			pointer base(void) const
			{
				return (_ptr);
			};

		public :

			pointer		_ptr;

	};

};

#endif
