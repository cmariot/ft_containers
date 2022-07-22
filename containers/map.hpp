/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 15:45:28 by cmariot           #+#    #+#             */
/*   Updated: 2022/07/21 20:57:13 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include <cstddef>
# include <memory>
# include <iostream>
# include <limits>

# include "../utils/RBTree.hpp"
# include "../utils/enable_if.hpp"
# include "../utils/utils.hpp"
# include "../iterators/bidirectional_iterator.hpp"
# include "../iterators/reverse_iterator.hpp"
# include "../utils/pair.hpp"

namespace ft
{

	/* TO DO :
	 * - [X] MEMBER TYPES
	 * - [X] RED-BLACK TREE :
	      - [X] UTILISER ALLOCATOR DE MAP
	      - [X] UTILISER COMP DE MAP
	 * - [X] CONSTRUCTORS
	 * - [X] DESTRUCTOR
	 * - [X] OPERATOR =
	 * - [ ] ITERATORS
		 - [ ] BEGIN
		 - [ ] END
		 - [ ] RBEGIN
		 - [ ] REND
	 * - [X] CAPACITY
		 - [X] SIZE
		 - [X] EMPTY
		 - [X] MAX SIZE
	 * - [X] ELEMENT ACCESS :
		 * - [X] OPERATOR []
	 * - [ ] MODIFIERS :
		 - [/] INSERT
		 - [ ] ERASE
		 - [X] SWAP
		 - [X] CLEAR
	 * - [X] OBSERVERS :
	 *   - [X] KEY COMP
	 *   - [X] VALUE COMP
	 * - [ ] OPERATIONS :
		 - [ ] FIND
		 - [ ] COUNT
		 - [ ] LOWER_BOUND
		 - [ ] UPPER_BOUND
		 - [ ] EQUAL_RANGE
	 * - [X] ALLOCATOR
		 - [X] GET_ALLOCATOR
	 * - [ ] NON MEMBER FUNCTIONS OVERLOAD
	 *		- [ ] COMPARAISON OPERATORS
	 *		- [X] SWAP
	 */

	template <class Key,
			 class Value,
			 class Compare = std::less<Key>,
			 class Allocator = std::allocator<ft::pair<const Key, Value> > >
	class map
	{

		// MEMBER TYPES
		public :

			typedef Key														key_type;
			typedef Value													mapped_type;
			typedef ft::pair<const Key, Value>								value_type;
			typedef size_t													size_type;
			typedef ptrdiff_t												difference_type;
			typedef Compare													key_compare;
			typedef Allocator												allocator_type;
			typedef value_type &											reference;
			typedef const value_type &										const_reference;
			typedef typename Allocator::pointer								pointer;
			typedef typename Allocator::const_pointer						const_pointer;
			typedef typename ft::bidirectional_iterator<value_type>			iterator;
			typedef typename ft::const_bidirectional_iterator<value_type>	const_iterator;
			typedef ft::reverse_iterator<iterator>							reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>					const_reverse_iterator;

		// PRIVATE MEMBER OBJECTS
		public :

			typedef ft::RedBlackTree <	key_type,
										mapped_type,
										std::allocator<ft::pair<const Key, Value> >,
										key_compare
									  >	red_black_tree;

			key_compare							_comp;
			allocator_type						_alloc;
			size_type							_size;
			red_black_tree						_tree;

		public :
		// MEMBER CLASS
			class value_compare
			{
				// MEMBER TYPES
				public :

					typedef bool								result_type;
					typedef value_type							first_argument_type;
					typedef value_type							second_argument_type;

				// PROTECTED MEMBER OBJECTS
				protected :

					Compare										comp;

				// MEMBER FUNCTIONS
				protected :

					// CONSTRUCTOR
					value_compare(Compare c) :
						comp(c)
					{
						return ;
					};

					// OPERATOR ()
					bool operator () (const value_type & lhs, const value_type & rhs) const
					{
						return (comp(lhs.first, rhs.first));
					};

			};

		// MEMBER FUNCTIONS

			// CONSTRUCTORS
				// DEFAULT CONSTRUCTOR
				explicit map(const key_compare & comp = key_compare(),
							 const allocator_type & alloc = allocator_type()) :
								_comp(comp),
								_alloc(alloc),
								_size(0)
				{
					_tree = red_black_tree(_alloc, _comp);
					return ;
				};

				// RANGE CONSTRUCTOR
				template <class InputIterator>
				map(InputIterator first,
					InputIterator last,
					const key_compare& comp = key_compare(),
					const allocator_type& alloc = allocator_type()) :
							_comp(comp),
							_alloc(alloc),
							_size(0)
				{
					_tree = red_black_tree(_alloc, _comp);
					while (first != last)
					{
						_tree.add(first->first, first->second);
						++first;
						_size++;
					}
					return ;
				};

				// COPY CONSTRUCTOR
				map(const map & x)
				{
					this = map(x.begin(), x.end(), x.key_comp(), x.get_allocator());
					return ;
				};

			// DESTRUCTOR
			~map(void)
			{
				_tree.~red_black_tree();
				_size.~size_type();
				_alloc.~allocator_type();
				_comp.~key_compare();
				return ;
			};

			// OPERATOR =
			map& operator = (const map& other)
			{
				~this();
				this = map(other);
				return (*this);
			};

			// ITERATORS

				// BEGIN
				iterator begin(void)
				{
					return (iterator(_tree.pair));
				};
				const_iterator begin(void) const
				{
					return (const_iterator());
				};

				// END
				iterator end(void)
				{
					return (iterator());
				};
				const_iterator end(void) const
				{
					return (const_iterator());
				};

				// RBEGIN
				reverse_iterator rbegin(void)
				{
					return (reverse_iterator());
				};
				const_reverse_iterator rbegin(void) const
				{
					return (const_reverse_iterator());
				};

				// REND
				reverse_iterator rend(void)
				{
					return (reverse_iterator());
				};
				const_reverse_iterator rend(void) const
				{
					return (const_reverse_iterator());
				};

			// CAPACITY

				// EMPTY
				bool empty(void) const
				{
					return (_size == 0);
				};

				// SIZE
				size_type size(void) const
				{
					return (_size);
				};

				// MAX SIZE
				size_type max_size(void) const
				{
					return (get_allocator().max_size());
				};

			// ELEMENT ACCESS

				// OPERATOR []
				mapped_type& operator[] (const key_type& k)
				{
					return ((*((this->insert(ft::make_pair(k, mapped_type()))).first)).second);
				};

			// MODIFIERS

				//INSERT
				pair<iterator,bool> insert(const value_type& val)
				{
					_tree.add(val.first, val.second);
					_size++;
					return (ft::pair<iterator, bool>(iterator(), true));
				};
				iterator insert (iterator position, const value_type& val);
				template <class InputIterator>
				void insert (InputIterator first, InputIterator last);

				// ERASE
				void erase (iterator position);
				size_type erase (const key_type& k);
				void erase (iterator first, iterator last);

				// SWAP
				void swap (map& x)
				{
					red_black_tree	tmp_tree = x._tree;
					size_type		tmp_size = x._size;
					allocator_type	tmp_allocator = x.get_allocator();
					key_compare		tmp_comp = x.key_comp();

					x._tree = _tree;
					x._size = _size;
					x._alloc = _alloc;
					x._comp = _comp;

					_tree = tmp_tree;
					_size = tmp_size;
					_alloc = tmp_allocator;
					_comp = tmp_comp;
				};

				// CLEAR
				void clear(void)
				{
					_tree.~red_black_tree();
					_tree = red_black_tree();
					_size = 0;
				};

			// OBSERVERS

				// KEY COMP
				key_compare key_comp(void) const
				{
					return (_comp);
				};

				// VALUE COMP
				value_compare value_comp(void) const
				{
					return (value_compare(_comp));
				};

			// OPERATIONS

				// FIND
				iterator find (const key_type& k);
				const_iterator find (const key_type& k) const;

				// COUNT
				size_type count (const key_type& k) const;

				// LOWER BOUNDS
				iterator lower_bound (const key_type& k);
				const_iterator lower_bound (const key_type& k) const;

				// UPPER BOUNDS
				iterator upper_bound (const key_type& k);
				const_iterator upper_bound (const key_type& k) const;

				// EQUAL RANGE
				pair<const_iterator,const_iterator> equal_range (const key_type& k) const;
				pair<iterator,iterator>             equal_range (const key_type& k);

			// ALLOCATOR

				// GET ALLOCATOR
				allocator_type get_allocator(void) const
				{
					return (_alloc);
				};

	}; // END OF CLASS MAP

	// NON MEMBER FUNCTIONS
	
	template< class Key, class T, class Compare, class Alloc >
	bool operator == (const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs);
	
	template< class Key, class T, class Compare, class Alloc >
	bool operator != (const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs);
	
	template< class Key, class T, class Compare, class Alloc >
	bool operator < (const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs);
	
	template< class Key, class T, class Compare, class Alloc >
	bool operator <= (const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs);
	
	template< class Key, class T, class Compare, class Alloc >
	bool operator > (const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs);
	
	template< class Key, class T, class Compare, class Alloc >
	bool operator >= (const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs);

	template<class Key, class T, class Compare, class Alloc>
	void swap(ft::map<Key,T,Compare,Alloc>& lhs, ft::map<Key,T,Compare,Alloc>& rhs)
	{
		lhs.swap(rhs);
	};

}; // END OF NAMESPACE FT

#endif
