/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 19:30:01 by cmariot           #+#    #+#             */
/*   Updated: 2022/06/28 08:26:25 by cmariot          ###   ########.fr       */
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

			
			typedef ft::iterator_traits<iterator<ft::input_iterator_tag, Iter> >	traits;

			//MEMBER TYPES
				typedef  Iter								iterator_type;
				typedef typename traits::iterator_category	iterator_category;
				typedef typename traits::value_type			value_type;
				typedef typename traits::difference_type	difference_type;
				typedef typename traits::pointer			pointer;
				typedef typename traits::reference			reference;

			//MEMBER FUNCTIONS
				//CONSTRUCTOR
				constexpr explicit reverse_iterator(Iter itr): current(itr)
				{
					return ;
				};
				//OPERATOR =
				reverse_iterator operator = (reverse_iterator & rhs)
				{
					reverse_iterator	tmp;

					tmp.current = this->current;
					return (tmp);
				};
				//BASE
				//OPERATOR *
				constexpr auto & operator * (void)
				{
					return *std::prev(current); // <== returns the content of prev
				};
				//OPERATOR ->
				//OPERATOR []
				//OPERATOR ++
				constexpr auto& operator ++ (void)
				{
					--current;
					return *this;
				};
				//OPERATOR ++ (INT)
				constexpr auto& operator ++ (int)
				{
					--current;
					return *this;
				};
				//OPERATOR +=
				//OPERATOR +
				//OPERATOR --
				constexpr auto& operator -- (void)
				{
					--current;
					return *this;
				};
				//OPERATOR -- (INT)
				constexpr auto& operator -- (int)
				{
					--current;
					return *this;
				};
				//OPERATOR -=
				//OPERATOR -

			//NON MEMBER FUNCTIONS
				//OPERATOR ==
				//OPERATOR !=
				constexpr friend bool operator != (reverse_iterator<Iter> a, reverse_iterator<Iter> b)
				{
					return a.current != b.current;
				};
				//OPERATOR <
				//OPERATOR <=
				//OPERATOR >
				//OPERATOR >=
				//OPERATOR +
				//OPERATOR -
	};

};

#endif
