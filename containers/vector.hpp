/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 22:49:51 by cmariot           #+#    #+#             */
/*   Updated: 2022/06/03 17:47:51 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

namespace	ft
{

	/* Vectors are sequence containers representing arrays that can change in size. */

	template < class T, class Alloc = std::allocator<T> >
	class	vector
	{

		//MEMBER TYPES :
		private :
		public :


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
