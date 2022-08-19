/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 21:42:34 by cmariot           #+#    #+#             */
/*   Updated: 2022/08/18 11:45:10 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

# include "vector.hpp"
# include <stack>

namespace ft
{

	// LIFO Container adaptor

	template <class T, class Container = ft::vector<T> >
		class stack
		{

			// MEMBER TYPES
			public :

				typedef Container									container_type;
				typedef typename Container::value_type				value_type;
				typedef typename Container::size_type				size_type;
				typedef typename Container::reference				reference;
				typedef typename Container::const_reference			const_reference;

			// MEMBER OBJECT
			protected :

				container_type										c;

			// MEMBER FUNCTIONS
			public :

				// DEFAULT CONSTRUCTOR
				explicit stack(const container_type & cont = Container()) :
					c(cont)
				{
					return ;
				};

				// COPY CONSTRUCTOR
				stack(const stack & other) :
					c(other.c)
				{
					return ;
				};

				// DESTRUCTOR
				~stack(void)
				{
					return ;
				};

				// OPERATOR =
				stack& operator = (const stack & other)
				{
					if (this == &other)
						return (*this);
					c = other.c;
					return (*this);
				};

				// TOP
				reference top(void)
				{
					return (c.back());
				};

				// TOP CONST
				const_reference top(void) const
				{
					return (c.back());
				};

				// EMPTY
				bool empty(void) const
				{
					return (c.empty());
				};

				// SIZE
				size_type size(void) const
				{
					return (c.size());
				};

				// PUSH
				void push(const value_type & value)
				{
					c.push_back(value);
				};

				// POP
				void pop(void)
				{
					c.pop_back();
				};

				// RELATIONAL OPERATOR DECLARATIONS
				friend bool ft::operator == (const ft::stack<T, Container> & lhs, const ft::stack<T, Container> & rhs);
				friend bool ft::operator != (const ft::stack<T, Container> & lhs, const ft::stack<T, Container> & rhs);
				friend bool ft::operator >  (const ft::stack<T, Container> & lhs, const ft::stack<T, Container> & rhs);
				friend bool ft::operator <  (const ft::stack<T, Container> & lhs, const ft::stack<T, Container> & rhs);
				friend bool ft::operator >= (const ft::stack<T, Container> & lhs, const ft::stack<T, Container> & rhs);
				friend bool ft::operator <= (const ft::stack<T, Container> & lhs, const ft::stack<T, Container> & rhs);

		}; // END OF STACK CLASS

	template <class T, class Container>
		bool operator == (const ft::stack<T, Container> & lhs, const ft::stack<T, Container> & rhs)
		{
			return (lhs.c == rhs.c);
		};

	template <class T, class Container>
		bool operator != (const ft::stack<T, Container> & lhs, const ft::stack<T, Container> & rhs)
		{
			return (lhs.c != rhs.c);
		};

	template <class T, class Container>
		bool operator < (const ft::stack<T, Container> & lhs, const ft::stack<T, Container> & rhs) 
		{
			return (lhs.c < rhs.c);
		};

	template <class T, class Container>
		bool operator <= (const ft::stack<T, Container> & lhs, const ft::stack<T, Container> & rhs)
		{
			return (lhs.c <= rhs.c);
		};

	template <class T, class Container>
		bool operator > (const ft::stack<T, Container> & lhs, const ft::stack<T, Container> & rhs)
		{
			return (lhs.c > rhs.c);
		};

	template <class T, class Container>
		bool operator >= (const ft::stack<T, Container> & lhs, const ft::stack<T, Container> & rhs)
		{
			return (lhs.c >= rhs.c);
		};

}; // END OF NAMESPACE FT

#endif
