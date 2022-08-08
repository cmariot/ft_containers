/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 19:30:01 by cmariot           #+#    #+#             */
/*   Updated: 2022/08/08 03:42:26 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

# include <iostream>
# include "random_access_iterator.hpp"

namespace	ft
{
	// REVERSE ITERATOR
	template <class Iterator>
	class reverse_iterator
	{

		public :

			typedef ft::iterator_traits<Iterator>	traits;

			typedef Iterator								iterator_type;
			typedef typename traits::iterator_category		iterator_category;
			typedef typename traits::value_type				value_type;
			typedef typename traits::difference_type		difference_type;
			typedef typename traits::pointer				pointer;
			typedef typename traits::reference				reference;

			// DEFAULT CONSTRUCTOR
			reverse_iterator(void)
			{
				current = iterator_type();
				return ;
			};

			// CONSTRUCTOR FROM ITERATOR
			reverse_iterator(iterator_type it)
			{
				current = it;
				return ;
			};

			// CONSTRUCTOR FROM REVERSE ITERATOR
			template <class Iter>
			reverse_iterator(const reverse_iterator<Iter>& rev_it)
			{
				*this = rev_it;
				return ;
			};

			// OPERATOR =
			template< class U > 
			reverse_iterator& operator = (const reverse_iterator<U> & other)
			{
				current = other.base();
				return (*this);
			};

			// BASE
			iterator_type base() const
			{
				return (current);
			};

			// DEREFERENCE *
			reference operator * (void) const
			{
				iterator_type tmp = current;
				return (*(--tmp));
			};

			// DEREFERENCE ->
			pointer operator-> (void) const
			{
				return &(operator*());
			};

			//OPERATOR []
			reference operator [] (difference_type n) const
			{
				return (base()[-n - 1]);
			};

			// OPERATOR +
			reverse_iterator operator + (difference_type n) const
			{
				return (base() - n);
			};

			// OPERATOR ++
			reverse_iterator & operator ++ (void)
			{
				--current;
				return (*this);
			};

			// OPERATOR ++
			reverse_iterator operator ++ (int)
			{
				reverse_iterator	tmp = *this;
				++(*this);
				return (tmp);
			};

			//OPERATOR +=
			reverse_iterator & operator += (difference_type n)
			{
				current -= n;
				return (*this);
			};

			// OPERATOR -
			reverse_iterator operator - (difference_type n) const
			{
				return (base() + n);
			};

			// OPERATOR --
			reverse_iterator & operator -- (void)
			{
				++current;
				return (*this);
			};

			// OPERATOR --
			reverse_iterator operator -- (int)
			{
				reverse_iterator	tmp = *this;
				--(*this);
				return (tmp);
			};
			
			//OPERATOR -=
			reverse_iterator & operator -= (difference_type n)
			{
				current += n;
				return (*this);
			};

		public :

			Iterator		current;

	}; // END OF REVERSE_ITERATOR CLASS


	// NON MEMBER
	template <class Iterator1, class Iterator2>
	bool operator == (const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs)
	{
		return (lhs.base() == rhs.base());
	};

	template <class Iterator1, class Iterator2>
	bool operator != (const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs)
	{
		return (lhs.base() != rhs.base());
	};

	template <class Iterator1, class Iterator2>
	bool operator <  (const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs)
	{
		return (lhs.base() > rhs.base());
	};

	template <class Iterator1, class Iterator2>
	bool operator <= (const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs)
	{
		return (lhs.base() >= rhs.base());
	};

	template <class Iterator1, class Iterator2>
	bool operator >  (const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs)
	{
		return (lhs.base() < rhs.base());
	};

	template <class Iterator1, class Iterator2>
	bool operator >= (const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs)
	{
		return (lhs.base() <= rhs.base());
	};

	// OPERATOR +
	template <class Iter> 
	reverse_iterator<Iter> operator + (typename reverse_iterator<Iter>::difference_type n, const reverse_iterator<Iter>& it)
	{
		return (ft::reverse_iterator<Iter>(it.base() - n));
	};

	// OPERATOR -
	template <class Iterator>
	typename reverse_iterator<Iterator>::difference_type operator - (const reverse_iterator<Iterator> & lhs, const reverse_iterator<Iterator> & rhs)
	{
		return (rhs.base() - lhs.base());
	};
	
	// OPERATOR -
	template <class Iterator1, class Iterator2>
	typename reverse_iterator<Iterator1>::difference_type operator - (const reverse_iterator<Iterator1> & lhs, const reverse_iterator<Iterator2> & rhs)
	{
		return (rhs.base() - lhs.base());
	};

};	// END OF FT NAMESPACE

#endif
