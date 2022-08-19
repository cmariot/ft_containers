/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 20:31:46 by cmariot           #+#    #+#             */
/*   Updated: 2022/08/17 01:18:02 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
# define PAIR_HPP

namespace ft
{

	template <class Key, class Value>
		struct pair
		{

			// MEMBER TYPES
			typedef  Key				first_type;
			typedef  Value				second_type;

			// MEMBER OBJECTS
			first_type				first;
			second_type				second;

			// MEMBER FUNCTION DEFAULT CONSTRUCTOR
			pair(void) :
				first(first_type()),
				second(second_type())
			{
				return ;
			};

			// MEMBER FUNCTION INIT CONSTRUCTOR
			pair(const Key & x, const Value & y) :
				first(x),
				second(y)
			{
				return ;
			};

			// MEMBER FUNCTION COPY CONSTRUCTOR
			pair(const ft::pair<Key, Value> & other) :
				first(other.first),
				second(other.second)
			{
				return ;
			};

			// MEMBER FUNCTION TEMPLATE COPY CONSTRUCTOR
			template <class T1, class T2>
				pair(const ft::pair<T1, T2> & other) :
					first(other.first),
					second(other.second)
			{
				return ;
			};

			// MEMBER FUNCTION OPERATOR =
			pair& operator = (const pair & other)
			{
				if (this == &other)
					return (*this);
				first = other.first;
				second = other.second;
				return (*this);
			};

		}; // END OF PAIR CLASS

	// NON-MEMBER FUNCTIONS : RELATIONAL OPERATORS
	// ==
	template <class Key, class Value>
		bool operator == (const ft::pair<Key,Value> & lhs, const ft::pair<Key,Value> & rhs)
		{
			return lhs.first == rhs.first && lhs.second == rhs.second;
		};

	// !=
	template <class Key, class Value>
		bool operator != (const ft::pair<Key,Value> & lhs, const ft::pair<Key,Value> & rhs)
		{
			return !(lhs==rhs);
		};

	// <
	template <class Key, class Value>
		bool operator <  (const ft::pair<Key,Value> & lhs, const ft::pair<Key,Value> & rhs)
		{
			return lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second);
		};

	// <=
	template <class Key, class Value>
		bool operator <= (const ft::pair<Key,Value> & lhs, const ft::pair<Key,Value> & rhs)
		{
			return !(rhs < lhs);
		};

	// >
	template <class Key, class Value>
		bool operator >  (const ft::pair<Key,Value> & lhs, const ft::pair<Key,Value> & rhs)
		{
			return rhs < lhs;
		};

	// >=
	template <class Key, class Value>
		bool operator >= (const ft::pair<Key,Value> & lhs, const ft::pair<Key,Value> & rhs)
		{
			return !(lhs < rhs);
		};

}; // END OF NAMESPACE FT

#endif
