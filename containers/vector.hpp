/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 22:49:51 by cmariot           #+#    #+#             */
/*   Updated: 2022/06/22 17:34:49 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// CHECKLIST : 

	// [ ] - ITERATORS
	// [ ] - REVERSE ITERATORS
	// [X] - CONSTRUCTORS
	// [X] - DESTRUCTOR
	// [X] - OPERATOR=
	// [ ] - ITERATORS
		// [X] - BEGIN / CONST
		// [X] - END / CONST
		// [ ] - RBEGIN / CONST
		// [ ] - REND / CONST
	// [X] - CAPACITY
		// [X] - SIZE
		// [X] - MAX_SIZE : OK UBUNTU
		// [X] - RESIZE
		// [X] - CAPACITY
		// [X] - EMPTY
		// [X] - RESERVE
	// [X] - ELEMENT ACCESS
		// [X] - OPERATOR[]
		// [X] - AT
		// [X] - FRONT
		// [X] - BACK
	// [ ] - MODIFIERS
		// [ ] - ASSIGN
		// [ ] - PUSH_BACK
		// [X] - POP_BACK
		// [ ] - INSERT
		// [ ] - ERASE / RETURN VALUE ?
		// [ ] - SWAP / ALLOCATOR SWAP ?
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
# include "iterator.hpp"


/*
 * A namespace is an optionally-named declarative region.
 * The name of a namespace can be used to access entities declared in that namespace;
 * That are the members of the namespace.
 */

namespace ft
{

	template <class T>
	void swap(T elem1, T elem2)
	{
		T	tmp = elem1;

		elem1 = elem2;
		elem2 = tmp;
	};

	template <class U>
	std::string	itoa(U nb)
	{
		std::string		str_nb;

		do
		{
			str_nb += '0' + (nb % 10);
			nb /= 10;
		}
		while (nb > 0);
		return (std::string(str_nb.rbegin(), str_nb.rend()));
	};

	template <class InputIterator1, class InputIterator2>
	bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2)
	{
		while (first1 != last1)
		{
			if (first2 == last2 || *first2 < *first1)
				return (false);
			else if (*first1 < *first2)
				return (true);
			++first1;
			++first2;
		}
		return (first2 != last2);
	};

	template <class InputIterator1, class InputIterator2>
	bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
	{
		while (first1 != last1)
		{
			if (!(*first1 == *first2))
				return (false);
			++first1;
			++first2;
		}
		return (true);
	}

	/*
	* Vectors are used to store elements in a strict linear sequence.
	* Elements can be directly accessed by their position.
	* The size of the container can change dynamically when new elements are added.
	*
	* - T		Type of the element
	*
	* - Alloc	Type of the allocator used to define the storage allocation model
	*			Default to std::allocator<T>
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
			typedef T									value_type;
			typedef Allocator							allocator_type;
			typedef size_t								size_type;
			typedef ptrdiff_t							difference_type;
			typedef T &									reference;
			typedef const T &							const_reference;
			typedef T *									pointer;
			typedef const T *							const_pointer;
			typedef ft::bidirectional_iterator<T>		iterator;
			typedef const ft::bidirectional_iterator<T>	const_iterator;
			//typedef ft::random_access_iterator<T>		reverse_iterator;
			//typedef const ft::random_access_iterator<T>	reverse_const_iterator;


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
				vector(const allocator_type & alloc = allocator_type())
				{
					_size = 0;
					_capacity = 0;
					_allocator = alloc;
					_elements = NULL;
					return ;
				};

				// Fill constructor by size and value
				explicit vector(size_type n, const_reference value = value_type(),
						const allocator_type & alloc = allocator_type())
				{
					_size = n;
					_capacity = n;
					_allocator = alloc;
					_elements = _allocator.allocate(_capacity);
					for (size_type i = 0 ; i < n ; i++)
						_allocator.construct(&_elements[i], value);
					return ;
				};

				// Range constructor
				template <class Inputiterator>
				vector(Inputiterator first, Inputiterator last,
						const allocator_type & alloc = allocator_type())
				{
					_size = std::distance(first, last);
					_capacity = _size;
					_allocator = alloc;
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


			//DESTRUCTOR
			~vector(void)
			{
				clear();
				get_allocator().deallocate(_elements, _size);
				return ;
			};


			//OPERATOR=
			vector const &	operator = (const vector<T, Allocator> & rhs)
			{
				clear();
				get_allocator().deallocate(_elements, _size);
				assign(rhs.begin(), rhs.end());
				return (*this);
			};


			//ITERATORS
				//BEGIN
				iterator begin(void)
				{
					return (iterator(&_elements[0]));
				};
				const_iterator begin(void) const
				{
					return (iterator(&_elements[0]));
				};
				//END
				iterator end(void)
				{
					return (iterator(&_elements[size()]));
				};
				const_iterator end(void) const
				{
					return (iterator(&_elements[size()]));
				};
				//RBEGIN
				//REND


			//CAPACITY

				//SIZE : return the number of elements in the vector
				size_type	size(void) const
				{
					return (_size);
				};

				//MAX_SIZE : return the number of elements that might be
				//allocated as maximum by a call to member allocate.
				size_type	max_size(void) const
				{
					return (get_allocator().max_size());
				};

				//RESIZE
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

				//CAPACITY : return the storage space currently allocated
				size_type	capacity(void) const
				{
					return (_capacity);
				};

				//EMPTY : return true if the size is 0
				bool	empty(void) const
				{
					return (_size == 0);
				};

				//RESERVE
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
						throw (std::out_of_range(
									std::string("vector::_M_range_check: __n (which is ")
									+ itoa<size_t>(i)
									+ ") >= this->size() (which is "
									+ itoa<size_t>(_size)
									+ ")")
								);
					return (_elements[i]);
				};
				const_reference	at(size_type i) const
				{
					if (i >= size())
						throw (std::out_of_range(
									std::string("vector::_M_range_check: __n (which is ")
									+ itoa<size_t>(i)
									+ ") >= this->size() (which is "
									+ itoa<size_t>(_size)
									+ ")")
								);
					return (_elements[i]);
				};

				//FRONT
				reference	front(void)
				{
					return (_elements[0]);
				};
				const_reference	front(void) const
				{
					return (_elements[0]);
				};

				//BACK
				reference	back(void)
				{
					return (_elements[_size - 1]);
				};
				const_reference	back(void) const
				{
					return (_elements[_size - 1]);
				};

			//MODIFIERS
				//ASSIGN
				template <class Inputiterator>
				void assign(Inputiterator first, Inputiterator last)
				{
					if (_size)
					{
						clear();
						get_allocator().deallocate(_elements, _size);
					}
					_size = std::distance(first, last);
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

				//PUSH_BACK
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
					else
						get_allocator().construct(&_elements[_size], val);
					_size = _size + 1;
				};

				//POP_BACK
				void	pop_back(void)
				{
					get_allocator().destroy(&_elements[--_size]);
				};

				//INSERT
				iterator	insert(iterator position, const value_type& val)
				{
					pointer		tmp;
					size_t		i = 0;
					iterator	it = begin();

					tmp = get_allocator().allocate(_size + 1);
					while (it != position)
					{
						get_allocator().construct(&tmp[i++], *it);
						it++;
					}
					get_allocator().construct(&tmp[i++], val);
					while (it != end())
					{
						get_allocator().construct(&tmp[i++], *it);
						it++;
					}
					for (size_type i = 0 ; i < _size ; i++)
						get_allocator().destroy(&_elements[i]);
					get_allocator().deallocate(_elements, _size);
					_elements = tmp;
					_size += 1;
					return (begin());
				};

				void	insert(iterator position, size_type n, const value_type& val)
				{
					pointer		tmp;
					size_t		i = 0;
					size_t		j = 0;
					iterator	it = begin();

					tmp = get_allocator().allocate(_size + n);
					while (it != position)
					{
						get_allocator().construct(&tmp[i++], *it);
						it++;
					}
					while (j < n)
					{
						get_allocator().construct(&tmp[i++], val);
						j++;
					}
					while (it != end())
					{
						get_allocator().construct(&tmp[i++], *it);
						it++;
					}
					for (size_type i = 0 ; i < _size ; i++)
						get_allocator().destroy(&_elements[i]);
					get_allocator().deallocate(_elements, _size);
					_elements = tmp;
					_size = i;
				};

				template <class Inputiterator>
				void	insert(iterator position, Inputiterator first, Inputiterator last)
				{
					pointer		tmp;
					size_t		i = 0;
					iterator	it = begin();

					tmp = get_allocator().allocate(_size + std::distance(first, last));
					while (it != position)
					{
						get_allocator().construct(&tmp[i++], *it);
						it++;
					}
					while (first != last)
					{
						get_allocator().construct(&tmp[i++], *first);
						first++;
					}
					while (it != end())
					{
						get_allocator().construct(&tmp[i++], *it);
						it++;
					}
					for (size_type i = 0 ; i < _size ; i++)
						get_allocator().destroy(&_elements[i]);
					get_allocator().deallocate(_elements, _size);
					_elements = tmp;
					_size = i;
				};

				//ERASE
				iterator	erase(iterator position)
				{
					if (position == end())
					{
						pop_back();
						return (end());
					}
					else
					{
						pointer		tmp;
						int			i = 0;
						iterator	it = begin();

						tmp = get_allocator().allocate(_size - 1);
						while (it != position)
						{
							get_allocator().construct(&tmp[i++], *it);
							it++;
						}
						it++;
						iterator ret = it;
						while (it != end())
						{
							get_allocator().construct(&tmp[i++], *it);
							it++;
						}
						for (size_type i = 0 ; i < _size ; i++)
							get_allocator().destroy(&_elements[i]);
						get_allocator().deallocate(_elements, _size);
						_elements = tmp;
						_size--;
						return (ret);
					}
				};

				iterator	erase(iterator first, iterator last)
				{
					if (last == end())
					{
						while (first++ != end())
							pop_back();
						return (end());
					}
					else
					{
						pointer		tmp;
						int			i = 0;
						iterator	it = begin();
						size_type	distance;

						distance = std::distance(first, last);
						tmp = get_allocator().allocate(_size - distance);
						while (it != first)
						{
							get_allocator().construct(&tmp[i++], *it);
							it++;
						}
						it += distance;
						iterator ret = it;
						while (it != end())
						{
							get_allocator().construct(&tmp[i++], *it);
							it++;
						}
						for (size_type i = 0 ; i < _size ; i++)
							get_allocator().destroy(&_elements[i]);
						get_allocator().deallocate(_elements, _size);
						_elements = tmp;
						_size -= distance;
						return (ret);
					}
				};

				//SWAP
				void	swap(vector & x)
				{
					vector	tmp(*this);

					*this = x;
					x = tmp;
				};

				//CLEAR
				void	clear(void)
				{
					for (size_type i = 0 ; i < _size ; i++)
						get_allocator().destroy(&_elements[i]);
					_size = 0;
				};

			//ALLOCATOR
				//GET_ALLOCATOR
				allocator_type	get_allocator(void) const
				{
					return (_allocator);
				};


	};	// end of class ft::vector


	//NON-MEMBER RELATIONAL OPERATORS OVERLOADS

		//OPERATOR ==
		template <class T, class Alloc>
		bool operator == (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
		{
			if (!(lhs.size() == rhs.size()))
				return (false);
			return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
		};

		//OPERATOR !=
		template <class T, class Alloc>
		bool operator != (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
		{
			return (!(lhs == rhs));
		};

		//OPERATOR <
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

		//SWAP
		template <class U, class Alloc>
		void swap(vector<U, Alloc> & x, vector<U, Alloc> & y)
		{
			vector<U, Alloc>	tmp(x);

			x = y;
			y = tmp;
		};


};	// end of namespace ft

#endif	// VECTOR_HPP
