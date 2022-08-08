/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rite_map.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 19:30:01 by cmariot           #+#    #+#             */
/*   Updated: 2022/08/08 12:34:11 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RITE_MAP_HPP
# define RITE_MAP_HPP

# include <iostream>
# include "random_access_iterator.hpp"

namespace	ft
{
	// REVERSE ITERATOR
	template <class Iterator>
	class rite_map
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
			rite_map(void)
			{
				current = iterator_type();
				return ;
			};

			// CONSTRUCTOR FROM ITERATOR
			rite_map(iterator_type it)
			{
				current = it;
				return ;
			};

			// CONSTRUCTOR FROM REVERSE ITERATOR
			template <class Iter>
			rite_map(const rite_map<Iter>& rev_it)
			{
				*this = rev_it;
				return ;
			};

			// OPERATOR =
			template< class U > 
			rite_map& operator = (const rite_map<U> & other)
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
			rite_map operator + (difference_type n) const
			{
				return (base() - n);
			};

			// OPERATOR ++
			rite_map & operator ++ (void)
			{
				--current;
				return (*this);
			};

			// OPERATOR ++
			rite_map operator ++ (int)
			{
				rite_map	tmp = *this;
				++(*this);
				return (tmp);
			};

			//OPERATOR +=
			rite_map & operator += (difference_type n)
			{
				current -= n;
				return (*this);
			};

			// OPERATOR -
			rite_map operator - (difference_type n) const
			{
				return (base() + n);
			};

			// OPERATOR --
			rite_map & operator -- (void)
			{
				++current;
				return (*this);
			};

			// OPERATOR --
			rite_map operator -- (int)
			{
				rite_map	tmp = *this;
				--(*this);
				return (tmp);
			};
			
			//OPERATOR -=
			rite_map & operator -= (difference_type n)
			{
				current += n;
				return (*this);
			};

		public :

			Iterator		current;

	}; // END OF REVERSE_ITERATOR CLASS


	// NON MEMBER
	template <class Iterator1, class Iterator2>
	bool operator == (const rite_map<Iterator1>& lhs, const rite_map<Iterator2>& rhs)
	{
		return (lhs.base() == rhs.base());
	};

	template <class Iterator1, class Iterator2>
	bool operator != (const rite_map<Iterator1>& lhs, const rite_map<Iterator2>& rhs)
	{
		return (lhs.base() != rhs.base());
	};

	template <class Iterator1, class Iterator2>
	bool operator <  (const rite_map<Iterator1>& lhs, const rite_map<Iterator2>& rhs)
	{
		return (lhs.base() > rhs.base());
	};

	template <class Iterator1, class Iterator2>
	bool operator <= (const rite_map<Iterator1>& lhs, const rite_map<Iterator2>& rhs)
	{
		return (lhs.base() >= rhs.base());
	};

	template <class Iterator1, class Iterator2>
	bool operator >  (const rite_map<Iterator1>& lhs, const rite_map<Iterator2>& rhs)
	{
		return (lhs.base() < rhs.base());
	};

	template <class Iterator1, class Iterator2>
	bool operator >= (const rite_map<Iterator1>& lhs, const rite_map<Iterator2>& rhs)
	{
		return (lhs.base() <= rhs.base());
	};

	// OPERATOR +
	template <class Iter> 
	rite_map<Iter> operator + (typename rite_map<Iter>::difference_type n, const rite_map<Iter>& it)
	{
		return (ft::rite_map<Iter>(it.base() - n));
	};

	// OPERATOR -
	template <class Iterator>
	typename rite_map<Iterator>::difference_type operator - (const rite_map<Iterator> & lhs, const rite_map<Iterator> & rhs)
	{
		return (rhs.base() - lhs.base());
	};
	
	// OPERATOR -
	template <class Iterator1, class Iterator2>
	typename rite_map<Iterator1>::difference_type operator - (const rite_map<Iterator1> & lhs, const rite_map<Iterator2> & rhs)
	{
		return (rhs.base() - lhs.base());
	};

};	// END OF FT NAMESPACE

#endif
