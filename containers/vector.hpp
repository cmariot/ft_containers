/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 22:49:51 by cmariot           #+#    #+#             */
/*   Updated: 2022/07/07 15:38:13 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// CHECKLIST : 

	// [X] - ENABLE_IF / SFINAE
	// [X] - IS_INTEGRAL
	// [X] - BIDIRECTIONAL ITERATORS
	// [X] - ITERATORS / CONST
	// [ ] - REVERSE ITERATORS

	// [X] - CONSTRUCTORS
	// [X] - DESTRUCTOR
	// [X] - OPERATOR=
	// [X] - ITERATORS
		// [X] - BEGIN / CONST
		// [X] - END / CONST
		// [X] - RBEGIN / CONST
		// [X] - REND / CONST
	// [X] - CAPACITY
		// [X] - SIZE
		// [X] - MAX_SIZE
		// [X] - RESIZE
		// [X] - CAPACITY
		// [X] - EMPTY
		// [X] - RESERVE
	// [X] - ELEMENT ACCESS
		// [X] - OPERATOR[]
		// [X] - AT
		// [X] - FRONT
		// [X] - BACK
	// [X] - MODIFIERS
		// [X] - ASSIGN
		// [X] - PUSH_BACK
		// [X] - POP_BACK
		// [X] - INSERT
		// [X] - ERASE
		// [X] - SWAP / ITERATOR VALIDITY
		// [X] - CLEAR
	// [X] - ALLOCATOR
		// [X] - GET_ALLOCATOR
	// [X} - NON-MEMBER RELATIONAL OPERATORS OVERLOADS
		// [X] - EQUAL AND LEXICOGRAPHICAL_COMPARE
		// [X] - OPERATOR ==
		// [X] - OPERATOR !=
		// [X] - OPERATOR <
		// [X] - OPERATOR <=
		// [X] - OPERATOR >
		// [X] - OPERATOR >=
	// [X] - NON-MEMBER FUNCTION OVERLOADS
		// [X] - SWAP

#ifndef VECTOR_HPP
# define VECTOR_HPP


# include <cstddef>
# include <memory>
# include <iostream>

# include "../utils/enable_if.hpp"
# include "../utils/utils.hpp"
# include "../iterators/iterator.hpp"
# include "../iterators/reverse_iterator.hpp"

# include <vector>


// A namespace is an optionally-named declarative region.
// The name of a namespace can be used to access entities declared in that namespace;
// That are the members of the namespace.
namespace ft
{

	// Vectors are used to store elements in a strict linear sequence.
	// Elements can be directly accessed by their position.
	// The size of the container can change dynamically when new elements are added.
	//
	// - T		Type of the element
	// - Alloc	Type of the allocator used to define the storage allocation model
	//			Default is std::allocator<T>
	template	< class T, class Allocator = std::allocator<T> >
	class	vector
	{

		// TYPEDEFS :
		// Declarations containing the decl-specifier typedef declare identifiers that can
		// be used later for naming fundamental or compound types.
		public :

			typedef T												value_type;
			typedef Allocator										allocator_type;
			typedef size_t											size_type;
			typedef ptrdiff_t										difference_type;
			typedef T &												reference;
			typedef const T &										const_reference;
			typedef T *												pointer;
			typedef const T *										const_pointer;
			typedef typename ft::random_access_iterator<T>			iterator;
			typedef typename ft::const_random_access_iterator<T>	const_iterator;
			typedef typename ft::reverse_iterator<T>				reverse_iterator;
			typedef typename ft::const_reverse_iterator<T>			const_reverse_iterator;


		// MEMBER TYPES :
		protected :

			size_type			_size;
			size_type			_capacity;
			allocator_type		_allocator;
			pointer				_elements;


		// MEMBER FUNCTIONS :
		public :

			// CONSTRUCTORS :

				// Empty container constructor (default constructor)
				vector(const allocator_type & alloc = allocator_type()) :
					_size(0),
					_capacity(0),
					_allocator(alloc),
					_elements(NULL)
				{
					return ;
				};

				// Fill constructor by size and value
				explicit vector(size_type n, const_reference value = value_type(),
						const allocator_type & alloc = allocator_type()) :
					_size(n),
					_capacity(n),
					_allocator(alloc)
				{
					_elements = _allocator.allocate(_capacity);
					for (size_type i = 0 ; i < n ; i++)
						_allocator.construct(&_elements[i], value);
					return ;
				};

				// Range constructor
				template <class InputIterator>
				vector(InputIterator first,
						typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type last,
						const allocator_type & alloc = allocator_type()) :
					_allocator(alloc)
				{
					_size = 0;
					for (InputIterator tmp = first ; tmp != last ; tmp++)
						_size++;
					_capacity = _size;
					_elements = _allocator.allocate(_capacity);
					for (size_type i = 0 ; i < _size ; i++)
						_allocator.construct(&_elements[i], *(first++));
					return ;
				};

				// Copy constructor
				vector(const vector & x)
				{
					_size = x.size();
					_capacity = _size;
					_allocator = x.get_allocator();
					_elements = _allocator.allocate(_capacity);
					for (size_type i = 0 ; i < _size ; i++)
						_allocator.construct(&_elements[i], x[i]);
					return ;
				};


			// DESTRUCTOR
			~vector(void)
			{
				clear();
				get_allocator().deallocate(_elements, _size);
				return ;
			};


			// OPERATOR =
			vector const &	operator = (const vector<T, Allocator> & rhs)
			{
				clear();
				get_allocator().deallocate(_elements, _size);
				assign(rhs.begin(), rhs.end());
				return (*this);
			};


			// ITERATORS
				// BEGIN : return an iterator at the begining of the array
				iterator begin(void)
				{
					return (iterator(&_elements[0]));
				};
				const_iterator begin(void) const
				{
					return (const_iterator(&_elements[0]));
				};
				// END : return an iterator at the end of the array
				iterator end(void)
				{
					return (iterator(&_elements[size()]));
				};
				const_iterator end(void) const
				{
					return (const_iterator(&_elements[size()]));
				};
				// RBEGIN : return a reverse iterator at the 'begining' (i.e. the last index) of the array
				iterator rbegin(void)
				{
					return (reverse_iterator(end()));
				};
				const_iterator rbegin(void) const
				{
					return (const_reverse_iterator(end()));
				};
				// REND : return a reverse iterator at the 'end' (i.e. the first index) of the array
				iterator rend(void)
				{
					return (reverse_iterator(begin()));
				};
				const_iterator rend(void) const
				{
					return (const_reverse_iterator(begin()));
				};


			// CAPACITY

				// SIZE : return the number of elements in the vector
				size_type	size(void) const
				{
					return (_size);
				};

				// MAX_SIZE : return the number of elements that might be
				// allocated as maximum by a call to member allocate.
				size_type	max_size(void) const
				{
					return (get_allocator().max_size());
				};

				// RESIZE : resize the array at the new size n
				void resize(size_type n, value_type val = value_type())
				{
					if (n < _size)
					{
						while (size() > n)
							pop_back();
					}
					else if (n > _size)
					{
						while (size() < n)
							push_back(val);
					}
				};

				// CAPACITY : return the storage space currently allocated
				size_type	capacity(void) const
				{
					return (_capacity);
				};

				// EMPTY : return true if the size is 0
				bool	empty(void) const
				{
					return (_size == 0);
				};

				// RESERVE : allocate memory for the new capacity n
				void reserve(size_type n)
				{
					if (n > max_size())
						throw (std::length_error("vector::reserve"));
					else if (n > capacity())
					{
						pointer		tmp;
						size_type	size_backup = _size;

						tmp = get_allocator().allocate(n);
						for (size_type i = 0 ; i < _size ; i++)
							get_allocator().construct(&tmp[i], _elements[i]);
						clear();
						get_allocator().deallocate(_elements, _size);
						_capacity = n;
						_size = size_backup;
						_elements = tmp;
					}
				};

			// ELEMENT ACCESS
				// OPERATOR[] : access the value at the index i
				reference	operator [] (size_type i)
				{
					return (_elements[i]);
				};
				const_reference operator [] (size_type i) const
				{
					return (_elements[i]);
				};

				// AT : access the value at the index i
				reference	at(size_type i)
				{
					if (i >= size())
						throw (std::out_of_range(
									std::string("vector::_M_range_check: __n (which is ")
									+ ft::itoa<size_t>(i)
									+ ") >= this->size() (which is "
									+ ft::itoa<size_t>(_size)
									+ ")")
								);
					return (_elements[i]);
				};
				const_reference	at(size_type i) const
				{
					if (i >= size())
						throw (std::out_of_range(
									std::string("vector::_M_range_check: __n (which is ")
									+ ft::itoa<size_t>(i)
									+ ") >= this->size() (which is "
									+ ft::itoa<size_t>(_size)
									+ ")")
								);
					return (_elements[i]);
				};

				// FRONT : access the value of the first element
				reference	front(void)
				{
					return (_elements[0]);
				};
				const_reference	front(void) const
				{
					return (_elements[0]);
				};

				//BACK : access the value of the last element
				reference	back(void)
				{
					return (_elements[_size - 1]);
				};
				const_reference	back(void) const
				{
					return (_elements[_size - 1]);
				};

			// MODIFIERS
				// ASSIGN : change the array elements
				template <class InputIterator>
				void assign
					(
						InputIterator first,
						typename ft::enable_if<!ft::is_integral<InputIterator>::value,
						InputIterator>::type last
					)
				{
					if (_size)
					{
						clear();
						get_allocator().deallocate(_elements, _size);
					}
					InputIterator tmp = first;
					while (tmp != last)
					{
						_size++;
						tmp++;
					}
					_capacity = _size;
					if (_size and _size <= max_size())
					{
						_elements = get_allocator().allocate(_capacity);
						for (size_type i = 0 ; i < _size ; i++)
						{
							get_allocator().construct(&_elements[i], *first);
							++first;
						}
					}
					else
						_elements = NULL;
				};
				void	assign(size_type n, const value_type& val)
				{
					if (_size)
					{
						clear();
						get_allocator().deallocate(_elements, _size);
					}
					if (n)
					{
						_size = n;
						_elements = get_allocator().allocate(_size);
						for (size_type i = 0 ; i < n ; i++)
							get_allocator().construct(&_elements[i], val);
					}
					_capacity = _size;
				};

				// PUSH_BACK : add an element at the end of the array
				void	push_back(const value_type & val)
				{
					pointer		tmp;

					if (_size + 1 > capacity())
					{
						if (_capacity == 0)
							_capacity = 1;
						else
							_capacity *= 2;
						tmp = get_allocator().allocate(_capacity);
						for (size_type i = 0 ; i < _size ; i++)
						{
							get_allocator().construct(&tmp[i], _elements[i]);
							get_allocator().destroy(&_elements[i]);
						}
						get_allocator().deallocate(_elements, _size);
						get_allocator().construct(&tmp[_size], val);
						_elements = tmp;
					}
					else if (capacity() == 0)
					{
						_capacity = 1;
						_elements = get_allocator().allocate(_capacity);
						get_allocator().construct(&_elements[_size], val);
					}
					else
						get_allocator().construct(&_elements[_size], val);
					_size = _size + 1;
				};

				// POP_BACK : remove the last element of the array
				void	pop_back(void)
				{
					get_allocator().destroy(&_elements[--_size]);
				};

				// INSERT : add elements to the array
				iterator	insert(iterator position, const value_type & val)
				{
					iterator	it = begin();
					size_type	i = 0;
					size_type	j = 1;

					if (_size + 1 > _capacity)
						reserve(_size + 1);
					while (it != position)
					{
						it++;
						i++;
					}
					size_type backup = i;
					size_type new_pos = i;
					while (i < _size)
					{
						get_allocator().construct(&_elements[_size + 1 - j], _elements[_size - j]);
						j++;
						i++;
					}
					get_allocator().construct(&_elements[backup], val);
					_size += 1;
					return (begin() + new_pos);
				};

				void	insert(iterator position, size_type n, const value_type& val)
				{
					iterator	it = begin();
					size_type	i = 0;
					size_type	j = 1;
					size_type	k = 0;

					if (_size + n > _capacity)
						reserve(_size + n);
					while (it != position)
					{
						it++;
						i++;
					}
					size_type backup = i;
					while (i < _size)
					{
						get_allocator().construct(&_elements[_size + n - j], _elements[_size - j]);
						j++;
						i++;
					}
					while (k < n)
					{
						get_allocator().construct(&_elements[backup], val);
						backup++;
						k++;
					}
					_size += n;
				};

				template <class InputIterator>
				void	insert
						(
							iterator position,
							InputIterator first,
							typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type last
						)
				{
					iterator	it = begin();
					size_type	distance = std::distance(first, last);
					size_type	i = 0;
					size_type	j = 1;
					size_type	k = 0;

					if (_size + distance > _capacity)
						reserve(_size + distance);
					while (it != position)
					{
						it++;
						i++;
					}
					size_type backup = i;
					while (i < _size)
					{
						get_allocator().construct(&_elements[_size + distance - j], _elements[_size - j]);
						j++;
						i++;
					}
					while (k < distance)
					{
						get_allocator().construct(&_elements[backup], *first);
						first++;
						k++;
						backup++;
					}
					_size += distance;
				};

				// ERASE : remove elements in the array
				iterator	erase(iterator position)
				{
					iterator it = begin();

					for (size_t i = 0 ; i < size() ; i++)
					{
						if (it == position)
						{
							get_allocator().destroy(&_elements[i]);
							for (size_t j = i ; j < size() - 1 ; j++)
							{
								get_allocator().construct(&_elements[j], _elements[j + 1]);
								get_allocator().destroy(&_elements[j + 1]);
							}
							_size--;
							return (iterator(&_elements[i]));
						}
						it++;
					}
					return (position);
				};

				iterator	erase(iterator first, iterator last)
				{
					iterator it = begin();
					size_type	distance = 0;

					for (size_t i = 0 ; i < size() ; i++)
					{
						if (it == first)
						{
							distance = 0;
							while (it + 1 != last)
							{
								get_allocator().destroy(&_elements[i + distance]);
								it++;
								distance++;
							}
							for (size_t j = i ; j < size() - 1 ; j++)
							{
								get_allocator().construct(&_elements[j], _elements[j + distance + 1]);
								get_allocator().destroy(&_elements[j + distance + 1]);
							}
								_size -= distance + 1;
							return (iterator(&_elements[i]));
						}
						it++;
					}
					return (last);
				};

				// SWAP : swap 2 vectors
				void	swap(vector & x)
				{
					pointer			tmp_elements = x._elements;
					size_type		tmp_size = x._size;
					size_type		tmp_capacity = x._capacity;
					allocator_type	tmp_allocator = x._allocator;

					x._elements = _elements;
					x._size = _size;
					x._capacity = _capacity;
					x._allocator = _allocator;

					_elements = tmp_elements;
					_size = tmp_size;
					_capacity = tmp_capacity;
					_allocator = tmp_allocator;
				};

				// CLEAR : destroy the array elements
				void	clear(void)
				{
					for (size_type i = 0 ; i < _size ; i++)
						get_allocator().destroy(&_elements[i]);
					_size = 0;
				};

			// ALLOCATOR
				// GET_ALLOCATOR : return the allocator
				allocator_type	get_allocator(void) const
				{
					return (_allocator);
				};


	};	// end of class ft::vector


	// NON-MEMBER RELATIONAL OPERATORS OVERLOADS

		// OPERATOR == : check the size and if all elements are equal
		template <class T, class Alloc>
		bool operator == (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
		{
			if (!(lhs.size() == rhs.size()))
				return (false);
			return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
		};

		// OPERATOR !=
		template <class T, class Alloc>
		bool operator != (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
		{
			return (!(lhs == rhs));
		};

		//OPERATOR < : check all the elements of the first array, if one is sup to the second, return false
		template <class T, class Alloc>
		bool operator < (const vector<T, Alloc> & lhs, const vector<T, Alloc> & rhs)
		{
			return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
		};

		//OPERATOR <=
		template <class T, class Alloc>
		bool operator <= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
		{
			return !(rhs < lhs);
		};

		//OPERATOR >
		template <class T, class Alloc>
		bool operator > (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
		{
			return (rhs < lhs);
		};

		//OPERATOR >=
		template <class T, class Alloc>
		bool operator >= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
		{
			return !(lhs < rhs);
		};

	//NON-MEMBER FUNCTION OVERLOADS

		// SWAP
		template <class U, class Alloc>
		void swap(vector<U, Alloc> & x, vector<U, Alloc> & y)
		{
			x.swap(y);
		};


};	// end of namespace ft

#endif	// VECTOR_HPP
