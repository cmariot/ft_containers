/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 22:49:51 by cmariot           #+#    #+#             */
/*   Updated: 2022/06/13 14:53:26 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <cstddef>
# include <limits>
# include <memory>
# include <stdlib.h>

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
		protected :
			pointer				_elements;
			size_type			_size;
			size_type			_capacity;
			allocator_type		_allocator;


		//MEMBER FUNCTIONS :
		public :

			// CONSTRUCTORS :

				// Empty container constructor (default constructor)
				vector(const allocator_type & alloc = allocator_type()) :
					_elements(NULL), _size(0), _capacity(0), _allocator(alloc)
				{
					return ;
				};

				// Fill constructor by size and value
				explicit vector(size_type n, const_reference value = value_type(),
						const allocator_type & alloc = allocator_type()) :
					_size(n), _capacity(n), _allocator(alloc)
				{
					if (_size <= max_size())
					{
						_elements = get_allocator().allocate(_size);
						for (size_type i = 0 ; i < _size ; i++)
							get_allocator().construct(&_elements[i], value);
						return ;
					}
				};

				// Range constructor
				template <class InputIterator>
				vector(InputIterator first, InputIterator last,
						const allocator_type & alloc = allocator_type())
				{
					_size = std::distance(first, last);
					_capacity = _size;
					_allocator = alloc;
					if (_size and _size <= max_size())
					{
						_elements = get_allocator().allocate(_size);
						for (size_type i = 0 ; i < _size ; i++)
						{
							get_allocator().construct(&_elements[i], *first);
							++first;
						}
					}
					else
						_elements = NULL;
					return ;
				};

				// Copy constructor
				vector(const vector & x)
				{
					this->_size = x.size();
					this->_capacity = x.capacity();
					this->_allocator = x.get_allocator();
					if (_size and _size <= max_size())
					{
						_elements = get_allocator().allocate(_size);
						for (size_type i = 0 ; i < _size ; i++)
							get_allocator().construct(&_elements[i], x[i]);
					}
					else
						_elements = NULL;
					return ;
				};


			//DESTRUCTOR
			~vector(void)
			{
				if (_elements)
				{
					for (size_type i = 0 ; i < _size ; ++i)
						get_allocator().destroy(&_elements[i]);
					get_allocator().deallocate(_elements, _size);
				}
				return ;
			};


			//OPERATOR=
			vector const &	operator = (const vector<T, Allocator> & rhs)
			{
				if (_elements)
				{
					for (size_type i = 0 ; i < _size ; ++i)
						get_allocator().destroy(&_elements[i]);
					get_allocator().deallocate(_elements, _size);
				}
				_size = rhs.size();
				_capacity = rhs.capacity();
				_elements = get_allocator().allocate(size());
				for (size_type i = 0 ; i < size() ; i++)
					get_allocator().construct(&_elements[i], rhs[i]);
				return (*this);
			};

			//ITERATORS
				//BEGIN
				//END
				//RBEGIN
				//REND


			//CAPACITY
				
				//SIZE : return the number of elements in the vector
				size_type size() const
				{
					return (_size);
				};

				//MAX_SIZE : return the number of elements that might be
				//allocated as maximum by a call to member allocate.
				size_type max_size() const
				{
					return (get_allocator().max_size());
				};

				//RESIZE
				void resize(size_type n, value_type val = value_type())
				{
					if (n < size())
					{
						//reduce _elements to only contains the first n elements
					}
					else if (n > size())
					{
						if (n > capacity())
						{
							//allocation
						}
						// add elements at the end
						(void)val;
					}
				};

				//CAPACITY : return the storage space currently allocated
				size_type capacity() const
				{
					return (_capacity);
				};

				//EMPTY : return true if the size is 0
				bool empty() const
				{
					return (_size == 0);
				};

				//RESERVE
				void reserve(size_type n)
				{
					if (n > capacity())
					{
						(void)n;
					}
				};

			//ELEMENT ACCESS
				//OPERATOR[]
				reference	operator [] (size_type i)
				{
				   return (_elements[i]);
				};
				const_reference operator [] (size_type i) const
				{
					return (_elements[i]);
				};

				//AT
				reference	at(size_type i)
				{
					if (i >= size())
					{
						throw (std::out_of_range("Out of range"));
					}
				   return (_elements[i]);
				};
				const_reference at(size_type i) const
				{
					if (i >= size())
						throw (std::out_of_range("Out of range"));
					return (_elements[i]);
				};

				//FRONT
				reference	front()
				{
					return (_elements[0]);
				};
				const_reference	front() const
				{
					return (_elements[0]);
				};

				//BACK
				reference	back()
				{
					return (_elements[size() - 1]);
				};
				const_reference	back() const
				{
					return (_elements[size() - 1]);
				};

			//MODIFIERS
				//ASSIGN
				void assign (size_type n, const value_type& val)
				{
					(void)n;
					(void)val;
				} ;
				//PUSH_BACK
				//POP_BACK
				//INSERT
				//ERASE
				//SWAP
				template <class U, class Alloc>
				void swap (vector <U, Alloc> & x)
				{
					vector<U, Alloc>	tmp(*this);

					*this = x;
					x = tmp;
				};
				//CLEAR
			
			//ALLOCATOR
				//GET_ALLOCATOR
				allocator_type get_allocator() const
				{
					return (_allocator);
				};


		//NON-MEMBER FUNCTION OVERLOADS
		public :
			//RELATIONNAL OPERATORS
			template <class U, class Alloc>
			bool operator == (const vector<U,Alloc>& rhs)
			{
				if (size() != rhs.size())
					return (false);
				else if (capacity() != rhs.capacity())
					return (false);
				else if (get_allocator() != rhs.get_allocator())
					return (false);
				else
					for (size_type i = 0 ; i < size() ; i++)
						if ((*this)[i] != rhs[i])
							return (false);
				return (true);
			} ;
			//SWAP

	} ;

} ;

#endif
