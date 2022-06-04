/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 22:49:51 by cmariot           #+#    #+#             */
/*   Updated: 2022/06/04 12:10:56 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>

namespace	ft
{

	/*
	 * Vectors are used to store elements in a strict linear sequence.
	 * Elements can be directly accessed by their position.
	 * The size of the container can change dynamically when new elements are added.
	 */

	/*
	 * - T		Type of the element
	 * - Alloc	Type of the allocator used to define the storage allocation model
	 */
	
	template	< class T, class Alloc = std::allocator <T> >
	class	vector
	{

		//ALIAS

			typedef T			value_type;
			typedef Alloc		allocator_type;
			typedef T&			reference;
			typedef const T&	const_reference;
			typedef T*			pointer;
			typedef const T*	const_pointer;
			//typedef 		iterator;
			//typedef 		const_iterator;
			//typedef 		reverse_iterator;
			//typedef 		const_reverse_iterator;
			typedef ptrdiff_t	difference_type;
			typedef size_t		size_type;



		//MEMBER TYPES :
			public :
			private :


		//MEMBER FUNCTIONS :
			public :
				//CONSTRUCTORS
					vector() {};
				//DESTRUCTOR
					~vector() {};
				//OPERATOR=
				//ITERATORS
					//BEGIN
					//END
					//RBEGIN
					//REND
				//CAPACITY
					//SIZE
					//MAX_SIZE
					//RESIZE
					//CAPACITY
					//EMPTY
					//RESERVE
				//ELEMENT ACCESS
					//OPERATOR[]
					//AT
					//FRONT
					//BACK
				//MODIFIERS
					//ASSIGN
					//PUSH_BACK
					//POP_BACK
					//INSERT
					//ERASE
					//SWAP
					//CLEAR
				//ALLOCATOR
					//GET_ALLOCATOR
			private :

		//NON-MEMBER FUNCTION OVERLOADS
			public :
				//RELATIONNAL OPERATORS
				//SWAP
			private :

	} ;

} ;

#endif
