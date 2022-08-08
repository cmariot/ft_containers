/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 15:45:30 by cmariot           #+#    #+#             */
/*   Updated: 2022/08/08 12:20:31 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

# include "vector.hpp"

namespace ft 
{

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

			Container c;


		// MEMBER FUNCTIONS
		public :

			// DEFAULT CONSTRUCTOR
			explicit stack(const Container& cont = Container()) :
				c(cont)
			{
				return ;
			};
			
			// COPY CONSTRUCTOR
			stack(const stack& other) :
				c(other.c)
			{
				return ;
			};

			// DESTRUCTOR
			~stack()
			{
				return ;
			};

			// OPERATOR = 
			stack& operator = (const stack & other)
			{
				c = other.c;
				return (*this);
			};

			// TOP
			reference top(void)
			{
				return (c.back());
			};
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
			friend bool ft::operator == (const ft::stack<T, Container> &lhs, const ft::stack<T, Container> &rhs);
			friend bool ft::operator != (const ft::stack<T, Container> &lhs, const ft::stack<T, Container> &rhs);
			friend bool ft::operator >  (const ft::stack<T, Container> &lhs, const ft::stack<T, Container> &rhs);
			friend bool ft::operator <  (const ft::stack<T, Container> &lhs, const ft::stack<T, Container> &rhs);
			friend bool ft::operator >= (const ft::stack<T, Container> &lhs, const ft::stack<T, Container> &rhs);
			friend bool ft::operator <= (const ft::stack<T, Container> &lhs, const ft::stack<T, Container> &rhs);
	};

	template <class T, class Container>
	bool operator == (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs.c == rhs.c);
	};

	template <class T, class Container>
	bool operator != (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs.c != rhs.c);
	};
	
	template <class T, class Container>
	bool operator < (const stack<T,Container>& lhs, const stack<T,Container>& rhs) 
	{
		return (lhs.c < rhs.c);
	};
	
	template <class T, class Container>
	bool operator <= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs.c <= rhs.c);
	};
	
	template <class T, class Container>
	bool operator > (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs.c > rhs.c);
	};
	
	template <class T, class Container>
	bool operator >= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs.c >= rhs.c);
	};

};
#endif
