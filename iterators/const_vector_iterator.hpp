/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   const_vector_iterator.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 22:14:15 by cmariot           #+#    #+#             */
/*   Updated: 2022/08/17 16:19:04 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONST_VECTOR_ITERATOR_HPP
# define CONST_VECTOR_ITERATOR_HPP

namespace ft
{
	template <class T>
	class vector_iterator;

	template <class T>
	class const_vector_iterator
	{

		public :

			typedef ft::iterator_traits<iterator<std::random_access_iterator_tag, const T> >	traits;

			typedef typename traits::iterator_category		iterator_category;
			typedef typename traits::value_type				value_type;
			typedef typename traits::difference_type		difference_type;
			typedef typename traits::pointer				pointer;
			typedef typename traits::reference				reference;

			// DEFAULT CONSTRUCTOR
			const_vector_iterator(void) :
				_ptr(NULL)
			{
				return ;
			};

			// COPY CONSTRUCTOR
			const_vector_iterator(pointer ptr) :
				_ptr(ptr)
			{
				return ;
			};

			const_vector_iterator(const const_vector_iterator & rhs)
			{
				_ptr = rhs._ptr;
				return ;
			};

			const_vector_iterator(const ft::vector_iterator<T> & rhs)
			{
				_ptr = rhs._ptr;
				return ;
			};

			// COPY ASSIGNATION (=) const_iterator
			const_vector_iterator operator = (const const_vector_iterator & rhs)
			{
				if (this == &rhs)
					return (*this);
				this->_ptr = rhs._ptr;
				return (*this);
			};

			// COPY ASSIGNATION (=) const_iterator
			const_vector_iterator operator = (const ft::vector_iterator<T> & rhs)
			{
				this->_ptr = rhs._ptr;
				return (*this);
			};

			// DESTRUCTOR
			~const_vector_iterator(void)
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
			const_vector_iterator & operator ++ (void)
			{
				++_ptr;
				return (*this);
			};

			// SUFIX INCREMENTATION
			const_vector_iterator operator ++ (int)
			{
				const_vector_iterator	tmp(*this);

				operator++();
				return (tmp);
			};

			// PREFIX DECREMENTATION
			const_vector_iterator & operator -- (void)
			{
				--_ptr;
				return (*this);
			};

			// SUFIX DECREMENTATION
			const_vector_iterator operator -- (int)
			{
				const_vector_iterator	tmp(*this);

				operator--();
				return (tmp);
			};

			// OPERATOR ==
			bool operator == (const const_vector_iterator & rhs) const
			{
				return (_ptr == rhs._ptr);
			};

			// OPERATOR !=
			bool operator != (const const_vector_iterator & rhs) const
			{
				return (_ptr != rhs._ptr);
			};
			
			// OPERATOR >
			bool operator > (const const_vector_iterator & rhs) const
			{
				return (_ptr > rhs._ptr);
			};

			// OPERATOR >=
			bool operator >= (const const_vector_iterator & rhs) const
			{
				return (_ptr >= rhs._ptr);
			};

			// OPERATOR <
			bool operator < (const const_vector_iterator & rhs) const
			{
				return (_ptr < rhs._ptr);
			};

			// OPERATOR <=
			bool operator <= (const const_vector_iterator & rhs) const
			{
				return (_ptr <= rhs._ptr);
			};

			// OPERATOR ==
			bool operator == (const vector_iterator<T> & rhs) const
			{
				return (_ptr == rhs._ptr);
			};

			// OPERATOR !=
			bool operator != (const vector_iterator<T> & rhs) const
			{
				return (_ptr != rhs._ptr);
			};
			
			// OPERATOR >
			bool operator > (const vector_iterator<T> & rhs) const
			{
				return (_ptr > rhs._ptr);
			};

			// OPERATOR >=
			bool operator >= (const vector_iterator<T> & rhs) const
			{
				return (_ptr >= rhs._ptr);
			};

			// OPERATOR <
			bool operator < (const vector_iterator<T> & rhs) const
			{
				return (_ptr < rhs._ptr);
			};

			// OPERATOR <=
			bool operator <= (const vector_iterator<T> & rhs) const
			{
				return (_ptr <= rhs._ptr);
			};

			// ARITHMETIC OPERATOR : a + n
			const_vector_iterator operator + (difference_type n)
			{
				const_vector_iterator tmp(*this);
				tmp += n;
				return (tmp);
			}
			
			// ARITHMETIC OPERATOR : n + a
			friend const_vector_iterator operator + (difference_type n, const_vector_iterator rhs)
			{
				return (rhs + n);
			}

			// ARITHMETIC OPERATOR : a - n
			const_vector_iterator operator - (difference_type n)
			{
				const_vector_iterator tmp(*this);
				tmp -= n;
				return (tmp);
			}

			// ARITHMETIC OPERATOR : a - b
			difference_type operator - (const_vector_iterator rhs) const
			{
				return (_ptr - rhs._ptr);
			}

			//OPERATOR +=
			const_vector_iterator operator += (difference_type n)
			{
				_ptr += n;
				return (*this);
			};

			//OPERATOR -=
			const_vector_iterator operator -= (difference_type n)
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
