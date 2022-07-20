/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 18:52:14 by cmariot           #+#    #+#             */
/*   Updated: 2022/07/19 23:55:06 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
# define PAIR_HPP

namespace ft
{

	template <class T1, class T2>
	struct pair
	{
		// MEMBER TYPES
		typedef  T1				first_type;
		typedef  T2				second_type;

		// MEMBER OBJECTS
		first_type	first;
		second_type	second;

		// MEMBER FUNCTIONS
			// CONSTRUCTOR

				// DEFAULT
				pair(void) :
					first(first_type()),
					second(second_type())
				{
					return ;
				};

				// INIT
				pair(const T1& x, const T2& y) :
					first(x),
					second(y)
				{
					return ;
				};

				// COPY
				template <class U1, class U2>
				pair(const pair<U1, U2>& p) :
					first(p.first),
					second(p.second)
				{
					return ;
				};


			// OPERATOR =
			pair& operator = (const pair& pr)
			{
				this->first = pr.first;
				this->second = pr.second;
				return (*this);
			};

	};

	// MAKE PAIR
	template <class T1, class T2>
	pair<T1,T2> make_pair(T1 x, T2 y)
	{
		return (pair<T1,T2>(x,y));
	};

	// NON MEMBER FUNCTIONS : RELATIONAL OPERATORS
	template <class T1, class T2>
	bool operator == (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return lhs.first==rhs.first && lhs.second==rhs.second;
	};

	template <class T1, class T2>
	bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return !(lhs==rhs);
	};

	template <class T1, class T2>
	bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second<rhs.second);
	};

	template <class T1, class T2>
	bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return !(rhs<lhs);
	};

	template <class T1, class T2>
	bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return rhs<lhs;
	};

	template <class T1, class T2>
	bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return !(lhs<rhs);
	};

};

#endif
