/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 22:49:51 by cmariot           #+#    #+#             */
/*   Updated: 2022/06/08 12:13:22 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <cstddef>
# include <limits>
# include <memory>

/*
 * A namespace is an optionally-named declarative region.
 * The name of a namespace can be used to access entities declared in that namespace;
 * that is, the members of the namespace.
 */

namespace ft
{

	/*
	 * Vectors are used to store elements in a strict linear sequence.
	 * Elements can be directly accessed by their position.
	 * The size of the container can change dynamically when new elements are added.

	 * - T		Type of the element
	 * - Alloc	Type of the allocator used to define the storage allocation model
	 */

	template	< class T, class Allocator = std::allocator<T> >
	class	vector
	{

		/* 
		 * TYPEDEFS :
		 * Declarations containing the decl-specifier typedef declare identifiers that can
		 * be used later for naming fundamental or compound types.
		 */

		public :
			typedef T			value_type;
			typedef Allocator	allocator_type;
			typedef size_t		size_type;
			typedef ptrdiff_t	difference_type;
			typedef T &			reference;
			typedef const T &	const_reference;
			typedef T *			pointer;
			typedef const T *	const_pointer;
			//typedef 		iterator;
			//typedef 		const_iterator;
			//typedef 		reverse_iterator;
			//typedef 		const_reverse_iterator;



		//MEMBER TYPES :
			public :
			private :
				//iterator __begin_;
				//iterator __end_;
				pointer		_elements;
				size_type	_size;
				size_type	_capacity;
				Allocator	_allocator;


		//MEMBER FUNCTIONS :
			public :
				
				//CONSTRUCTORS
					
					// Empty container constructor (default constructor)
					vector(const Allocator & = Allocator()) :
						_elements(NULL), _size(0), _capacity(0)
					{
						return ;
					};
					
					// Assignment constructor by size and value
					explicit vector(size_type n, const T& value = T(), const Allocator& = Allocator()) :
						_elements(value), _size(n), _capacity(n)
					{
						return ;
					};
					
					// Assignment constructor by size and value
					template <class InputIterator>
					vector(InputIterator first, InputIterator last, const Allocator& = Allocator())
					{
						(void)first;
						(void)last;
						return ;
					};
					
					// Copy constructor
					vector(const vector<T, Allocator>& x)
					{
						(void)x;
						return ;
					};


				//DESTRUCTOR
					~vector()
					{
						return ;
					};
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
						return (std::min((size_type)std::numeric_limits<difference_type>::max(),
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
