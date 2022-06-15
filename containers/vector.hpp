/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 22:49:51 by cmariot           #+#    #+#             */
/*   Updated: 2022/06/15 11:40:20 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <cstddef>
# include <memory>
# include <iostream>

/*
 * A namespace is an optionally-named declarative region.
 * The name of a namespace can be used to access entities declared in that namespace;
 * That are the members of the namespace.
 */

namespace ft
{

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

		public :

			//ITERATORS
			struct iterator
			{
				typedef std::forward_iterator_tag	iterator_category;
				typedef std::ptrdiff_t				difference_type;
				typedef T							value_type;
				typedef T *							pointer;
				typedef T &							reference;
				typedef const T &					const_reference;

				// CONSTRUCTOR
				iterator(pointer ptr) :
					m_ptr(ptr)
				{
					return ;
				};

				// DEREFERENCE
				reference operator * (void) const
				{
					return (*m_ptr);
				}

				// DEREFERENCE
				pointer operator -> (void)
				{
					return (m_ptr);
				}

				// PREFIX INCREMENTATION
				iterator & operator ++ (void)
				{
					m_ptr++;
					return (*this);
				}

				// SUFIX INCREMENTATION
				iterator operator ++ (int)
				{
					iterator tmp(*this);
					++(*this);
					return (tmp);
				}

				// COMPARAISON ==
				friend bool operator == (const iterator & a, const iterator & b)
				{
					return (a.m_ptr == b.m_ptr);
				};

				// COMPARAISON !=
				friend bool operator != (const iterator & a, const iterator & b)
				{
					return (a.m_ptr != b.m_ptr);
				};


				private :

					pointer		m_ptr;

			};


		/* 
		 * TYPEDEFS :
		 * Declarations containing the decl-specifier typedef declare identifiers that can
		 * be used later for naming fundamental or compound types.
		 */

		public :
			typedef T						value_type;
			typedef Allocator				allocator_type;
			typedef size_t					size_type;
			typedef ptrdiff_t				difference_type;
			typedef T &						reference;
			typedef const T &				const_reference;
			typedef T *						pointer;
			typedef const T *				const_pointer;
			typedef vector::iterator		iterator;
			typedef const vector::iterator	const_iterator;
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
					if (_size and _size <= max_size())
					{
						_elements = get_allocator().allocate(_size);
						for (size_type i = 0 ; i < _size ; i++)
							get_allocator().construct(&_elements[i], value);
					}
					else
						_elements = NULL;
					return ;
				};

				// Range constructor
				template <class Inputiterator>
				vector(Inputiterator first, Inputiterator last,
						const allocator_type & alloc = allocator_type())
				{
					_allocator = alloc;
					assign(first, last);
					return ;
				};

				// Copy constructor
				vector(const vector & x)
				{
					_size = x.size();
					_capacity = x.size();
					_allocator = x.get_allocator();
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
				clear();
				return ;
			};


			//OPERATOR=
			vector const &	operator = (const vector<T, Allocator> & rhs)
			{
				clear();
				_size = rhs.size();
				_capacity = rhs.capacity();
				_elements = get_allocator().allocate(size());
				for (size_type i = 0 ; i < size() ; i++)
					get_allocator().construct(&_elements[i], rhs[i]);
				return (*this);
			};

			//ITERATORS
				//BEGIN
				iterator begin(void) const
				{
					return (iterator(& _elements[0]));
				}
				//END
				iterator end(void) const
				{
					return (iterator(& _elements[size()]));
				}
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
					while (size() > n)
						pop_back();
					while (size() < n)
						push_back(val);
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
					//exception n > max_size()
					if (n > capacity())
					{
						pointer		tmp;
						size_type	size_backup = _size;

						tmp = get_allocator().allocate(n);
						for (size_type i = 0 ; i < _size ; i++)
							get_allocator().construct(&tmp[i], _elements[i]);
						clear();
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
						throw (std::out_of_range("Out of range"));
				   return (_elements[i]);
				};
				const_reference	at(size_type i) const
				{
					if (i >= size())
						throw (std::out_of_range("Out of range"));
					return (_elements[i]);
				};

				//FRONT
				reference	front(void)
				{
					return (begin());
				};
				const_reference	front(void) const
				{
					return (begin());
				};

				//BACK
				reference	back(void)
				{
					return (end());
				};
				const_reference	back(void) const
				{
					return (end());
				};

			//MODIFIERS
				//ASSIGN
				template <class Inputiterator>
				void assign (Inputiterator first, Inputiterator last)
				{
					_size = std::distance(first, last);
					_capacity = _size;
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
				};
				void	assign(size_type n, const value_type& val)
				{
					size_type	i = 0;

					clear();
					_size = n;
					_elements = get_allocator().allocate(_size);
					_capacity = _size;
					while (i < n)
					{
						get_allocator().construct(&_elements[i], val);
						i++;
					}
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
					if (!empty())
					{
						get_allocator().destroy(&_elements[_size]);
						_size--;
					}
				};

				//INSERT
				iterator	insert(iterator position, const value_type& val);
				
				void	insert(iterator position, size_type n, const value_type& val);
			
				template <class Inputiterator>
				void	insert(iterator position, Inputiterator first, Inputiterator last);

				//ERASE
				iterator	erase(iterator position)
				{
					pointer	tmp;

					if (position == end())
						pop_back();
					else
					{
						int			i = 0;
						iterator	it = begin();

						tmp = get_allocator().allocate(_size - 1);
						while (it != position)
						{
							get_allocator().construct(&tmp[i++], *it);
							it++;
						}
						it++;
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
					}
					return (begin());
				};

				iterator	erase(iterator first, iterator last)
				{
					pointer	tmp;

					if (last == end())
					{
						while (first++ != end())
							pop_back();
					}
					else
					{
						int			i = 0;
						iterator	it = begin();

						tmp = get_allocator().allocate(_size - std::distance(first, last));
						while (it != first)
						{
							get_allocator().construct(&tmp[i++], *it);
							it++;
						}
						it += std::distance(first, last);
						i += std::distance(first, last) - 1;
						while (it != end())
						{
							get_allocator().construct(&tmp[i++], *it);
							it++;
						}
						for (size_type i = 0 ; i < _size ; i++)
							get_allocator().destroy(&_elements[i]);
						get_allocator().deallocate(_elements, _size);
						_elements = tmp;
						_size -= std::distance(first, last);
					}
					return (begin());
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
					if (_elements)
					{
						for (size_type i = 0 ; i < _size ; i++)
							get_allocator().destroy(&_elements[i]);
						get_allocator().deallocate(_elements, _size);
						_elements = NULL;
						_size = 0;
					}
				};

			//ALLOCATOR
				//GET_ALLOCATOR
				allocator_type	get_allocator(void) const
				{
					return (_allocator);
				};


	};	// end of class ft::vector


	//NON-MEMBER RELATIONNAL OPERATORS OVERLOADS

		//OPERATOR ==
		template <class T, class Alloc>
		bool operator == (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
		{
			if (!(lhs.size() == rhs.size()))
				return (false);
			for (size_t i = 0 ; i < lhs.size() ; i++)
				if (!(lhs[i] == rhs[i]))
					return (false);
			return (true);
		};

		//OPERATOR !=
		template <class T, class Alloc>
		bool operator != (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
		{
			if (!(lhs.size() == rhs.size()))
				return (true);
			for (size_t i = 0 ; i < lhs.size() ; i++)
				if (!(lhs[i] == rhs[i]))
					return (true);
			return (false);
		};

		//OPERATOR <
		template <class T, class Alloc>
		bool operator < (const vector<T, Alloc> & lhs, const vector<T, Alloc> & rhs)
		{
			for (size_t i = 0 ; i < lhs.size() and i < rhs.size() ; i++)
				if ((rhs[i] < lhs[i]) and !(lhs[i] < rhs[i]))
					return (false);
			return (true);
		};

		//OPERATOR <=
		template <class T, class Alloc>
		bool operator <= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
		{
			for (size_t i = 0 ; i < lhs.size() and i < rhs.size() ; i++)
				if (!(rhs[i] < lhs[i]))
					return (true);
			return (false);
		};

		//OPERATOR >
		template <class T, class Alloc>
		bool operator > (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
		{
			for (size_t i = 0 ; i < lhs.size() and i < rhs.size() ; i++)
				if ((rhs[i] < lhs[i]) and !(lhs[i] < rhs[i]))
					return (true);
			return (false);
		};

		//OPERATOR >=
		template <class T, class Alloc>
		bool operator >= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
		{
			for (size_t i = 0 ; i < lhs.size() and i < rhs.size() ; i++)
				if (!(rhs[i] < lhs[i]))
					return (false);
			return (true);
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

#endif
