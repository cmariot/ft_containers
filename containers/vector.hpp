/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 22:49:51 by cmariot           #+#    #+#             */
/*   Updated: 2022/06/05 14:51:49 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <cstddef>
# include <limits>

namespace	ft
{
	
	template	<class T>
	T const &	min(T const & a, T const & b) {
		return (a < b ? a : b);
	}

	/*
	 * Vectors are used to store elements in a strict linear sequence.
	 * Elements can be directly accessed by their position.
	 * The size of the container can change dynamically when new elements are added.
	 */

	/*
	 * - T		Type of the element
	 * - Alloc	Type of the allocator used to define the storage allocation model
	 */

	template	< class T, class Alloc = std::allocator<T> >
	class	vector
	{

		//TYPE ALIAS
			typedef T			value_type;
			typedef Alloc		allocator_type;
			typedef T &			reference;
			typedef const T &	const_reference;
			typedef T *			pointer;
			typedef const T *	const_pointer;
			//typedef 		iterator;
			//typedef 		const_iterator;
			//typedef 		reverse_iterator;
			//typedef 		const_reverse_iterator;
			typedef ptrdiff_t	difference_type;
			typedef size_t		size_type;



		//MEMBER TYPES :
			public :
				pointer					_elements;
				size_type				_size;				//nb elements in the vector
				size_type				_capacity;			//storage space currently allocated

			private :


		//MEMBER FUNCTIONS :
			public :
				//CONSTRUCTORS
					//Default constructor
					vector() : _elements(NULL), _size(0), _capacity(0)
					{
						return ;
					};
				//DESTRUCTOR
					~vector() {};
				//OPERATOR=
				//ITERATORS
					//BEGIN
					//END
					//RBEGIN
					//REND
				//CAPACITY
					//SIZE : return the number of elements in the vector
					size_type size() const
					{
						return (this->_size);
					};
					//MAX_SIZE
					size_type max_size() const
					{
						return (ft::min((size_type)std::numeric_limits<difference_type>::max(),
							std::numeric_limits<size_type>::max() / sizeof(value_type)));
					};
					//RESIZE
					//CAPACITY : return the storage space currently allocated
					size_type capacity() const
					{
						return (this->_capacity);
					};
					//EMPTY : return true if the size is 0
					bool empty() const
					{
						return (this->_size == 0);
					};
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
