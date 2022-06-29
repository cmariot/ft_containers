/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 19:30:01 by cmariot           #+#    #+#             */
/*   Updated: 2022/06/29 15:15:25 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

# include <iostream>
# include "iterator.hpp"

namespace	ft
{
	template <class Iter>
	class reverse_iterator
	{

		Iter	current;

		public :

			
			typedef ft::iterator_traits<iterator<ft::bidirectional_iterator_tag, Iter> >	traits;

			//MEMBER TYPES
				typedef  Iter								iterator_type;
				typedef typename traits::iterator_category	iterator_category;
				typedef typename traits::value_type			value_type;
				typedef typename traits::difference_type	difference_type;
				typedef typename traits::pointer			pointer;
				typedef typename traits::reference			reference;

			//MEMBER FUNCTIONS

				// COPY CONSTRUCTOR
				reverse_iterator(iterator_type itr) :
					current(itr)
				{
					return ;
				};

				// COPY ASSIGNATION
				reverse_iterator operator = (reverse_iterator & rhs)
				{
					current = rhs->current;
					return (*this);
				};

				//BASE
				iterator_type base(void) const
				{
					return (&*(this + 1));
				};

				// DEREFERENCE WITH OPERATOR *
				reverse_iterator & operator * (void)
				{
					return (*current);
				};

				// DEREFERENCE WITH OPERATOR ->
				reverse_iterator & operator -> (void)
				{
					return (&(this->operator*()));
				};

				//OPERATOR []
				reference operator [] (difference_type n)
				{
					return *(current + n);
				};

				// PREFIX INCREMENTATION
				reverse_iterator& operator ++ (void)
				{
					--current;
					return *this;
				};

				// SUFIX INCREMENTATION
				reverse_iterator& operator ++ (int)
				{
					reverse_iterator tmp(*this);

					--(*this);
					return (tmp);
				};

				//OPERATOR +=
				reverse_iterator operator += (difference_type const &x)
				{
					current -= x;
					return (*this);
				};

				//OPERATOR +
				reverse_iterator operator + (difference_type n) const
				{
					reverse_iterator tmp = *this;
					return (tmp += n);
				};

				// PREFIX DECREMENTATION
				reverse_iterator& operator -- (void)
				{
					++current;
					return (*this);
				};

				// SUFIX DECREMENTATION
				reverse_iterator& operator -- (int)
				{
					reverse_iterator tmp(*this);

					++(*this);
					return (tmp);
				};

				//OPERATOR -=
				reverse_iterator operator -= (difference_type const &x)
				{
					current += x;
					return (*this);
				};

				//OPERATOR -
				reverse_iterator operator - (difference_type n) const
				{
					reverse_iterator tmp = *this;
					return (tmp -= n);
				};

			//NON MEMBER FUNCTIONS

				//OPERATOR ==
				friend bool operator == (reverse_iterator<Iter> a, reverse_iterator<Iter> b)
				{
					return a.current == b.current;
				};

				//OPERATOR !=
				friend bool operator != (reverse_iterator<Iter> a, reverse_iterator<Iter> b)
				{
					return a.current != b.current;
				};

				//OPERATOR <
				bool operator < (const reverse_iterator & rhs)
				{
					return (**this < *rhs);
				};

				//OPERATOR <=
				bool operator <= (const reverse_iterator & rhs)
				{
					if (*this < rhs || *this == rhs)
						return (true);
					return (false);
				};

				//OPERATOR >
				bool operator > (const reverse_iterator & rhs)
				{
					return (*rhs < **this);
				};

				//OPERATOR >=
				bool operator >= (const reverse_iterator & rhs)
				{
					if (*this < rhs || !(*this == rhs))
						return (false);
					return (true);
				};

				//OPERATOR +
				difference_type operator + (reverse_iterator rhs) const
				{
					difference_type	ret = rhs._ptr - current;

					return (ret);
				};

				//OPERATOR -
				difference_type operator - (reverse_iterator rhs) const
				{
					difference_type	ret = rhs._ptr + current;

					return (ret);
				};

	};

};

#endif
