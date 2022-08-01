/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 15:45:28 by cmariot           #+#    #+#             */
/*   Updated: 2022/07/29 20:26:58 by cmariot          ###   ########.fr       */
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

	template <class Key, class Value,
			 class Compare = std::less<Key>,
			 class Allocator = std::allocator<ft::pair<const Key, Value> > >
	class map
	{

		// PUBLIC MEMBER TYPES
		public :

			typedef Key														key_type;
			typedef Value													mapped_type;
			typedef ft::pair<const Key, Value>								value_type;
			typedef std::size_t												size_type;
			typedef std::ptrdiff_t											difference_type;
			typedef Compare													key_compare;
			typedef Allocator												allocator_type;
			typedef value_type &											reference;
			typedef const value_type &										const_reference;
			typedef typename Allocator::pointer								pointer;
			typedef typename Allocator::const_pointer						const_pointer;
			typedef typename ft::bidirectional_iterator<value_type>			iterator;
			typedef typename ft::bidirectional_iterator<value_type>			const_iterator;
			typedef ft::reverse_iterator<iterator>							reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>					const_reverse_iterator;

		// PUBLIC MEMBER CLASS
		public :

			class value_compare
			{
				friend class map;

				// PUBLIC MEMBER TYPES
				public :

					typedef bool				result_type;
					typedef value_type			first_argument_type;
					typedef value_type			second_argument_type;

				// PROTECTED MEMBER OBJECT
				protected :

					Compare						comp;

				// PROTECTED MEMBER FUNCTION
				protected :

					value_compare(Compare c) :
						comp(c)
					{
						return ;
					};

				// PUBLIC MEMBER FUNCTION
				public :

					bool operator () (const value_type & lhs, const value_type & rhs) const
					{
						return (comp(lhs.first, rhs.first));
					};

			};	// END OF CLASS VALUE_COMPARE

		// PRIVATE MEMBER OBJECTS
		private :

			typedef ft::RedBlackTree<key_type, value_type, allocator_type, key_compare>	red_black_tree;

			red_black_tree	*_tree;
			key_compare		_comp;
			size_type		_size;
			allocator_type	_alloc;

		// PUBLIC MEMBER FUNCTIONS
		public :

			// [X] Empty map constructors (default)
			explicit map(const key_compare& comp = key_compare(),
						const allocator_type& alloc = allocator_type()) :
				_comp(comp),
				_size(0),
				_alloc(alloc)
			{
				_tree = new red_black_tree;
				*_tree = red_black_tree(_alloc, _comp);
				return ;
			};

			// [X] Range constructor
			template <class InputIterator>
			map(InputIterator first, InputIterator last,
						const key_compare& comp = key_compare(),
						const allocator_type& alloc = allocator_type()) :
				_comp(comp),
				_size(0),
				_alloc(alloc)
			{
				_tree = new red_black_tree;
				*_tree = red_black_tree(_alloc, _comp);
				while (first != last)
				{
					_tree->add(make_pair<Key, Value>(first->first, first->second));
					_size++;
					first++;
				}
			};

			// [X] Copy constructor
			// A tester apres implementation des iterateurs
			map(const map& x)
			{
				*this = map(x.begin(), x.end(), x.key_comp(), x.get_allocator());
			};

			// [/] Operator =
			map& operator = (const map& x)
			{
				iterator	it = x.begin();

				clear();
				_size = x.size();
				_alloc = x.get_allocator();
				_comp = x.key_comp();
				while (it != x.end())
				{
					_tree->add(make_pair<Key, Value>(it->first, it->second));
					it++;
				}
				return (*this);
			};

			// [X] Destructor
			~map(void)
			{
				delete _tree;
				return ;
			};

			// [/] Begin
			iterator begin(void)
			{
				return (iterator(_tree->begin()));
			};
			const_iterator begin(void) const
			{
				return (const_iterator(_tree->begin()));
			};

			// [/] End
			iterator end()
			{
				return (iterator(_tree->end()));
			};
			const_iterator end() const
			{
				return (const_iterator(_tree->end()));
			};

			// [/] Rbegin
			reverse_iterator rbegin()
			{
				return (reverse_iterator(_tree->end()));
			};
			const_reverse_iterator rbegin() const
			{
				return (const_reverse_iterator(_tree->end()));
			};

			// [/] Rend
			reverse_iterator rend()
			{
				return (reverse_iterator(_tree->begin()));
			};
			const_reverse_iterator rend() const
			{
				return (const_reverse_iterator(_tree->begin()));
			};

			// [X] Empty
			bool empty(void) const
			{
				return (_size == 0);
			};

			// [X] Size
			size_type size() const
			{
				return (_size);
			};

			// [X] Max_size
			size_type max_size() const
			{
				return (std::numeric_limits<difference_type>::max());
			};

			// [/] Operator []
			mapped_type& operator[] (const key_type& k)
			{
				return ((*((this->insert(make_pair(k,mapped_type()))).first)).second);
			};

			// [ ] At
			mapped_type& at (const key_type& k);
			const mapped_type& at (const key_type& k) const;
			
			// [ ] Insert
			pair<iterator,bool> insert (const value_type& val)
			{
				_tree->add(val);
				_size++;
				return (ft::make_pair<iterator, bool>(iterator(), true));
			};
			iterator insert (iterator position, const value_type& val)
			{
				iterator	it = begin();

				while (it != position)
				{
					it++;
				}
				it->second = val;
				return (it);
			};
			template <class InputIterator>
			void insert (InputIterator first, InputIterator last)
			{
				while (first != last)
				{
					insert(ft::make_pair<Key, Value>(first->first, first->second));
					first++;
				}
			};

			// [ ] Erase 
			void erase (iterator position);
			size_type erase (const key_type& k);
			void erase (iterator first, iterator last);

			// [X] Swap
			void swap(map & x)
			{
				red_black_tree	*tmp_tree = x._tree;
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

			// [X] Clear
			void clear(void)
			{
				_tree->~RedBlackTree();
				*_tree = red_black_tree(_alloc, _comp);
				_size = 0;
			};

			// [X] Key Comp
			key_compare key_comp() const
			{
				return (_comp);
			};

			// [X] Value Comp
			value_compare value_comp() const
			{
				return (value_compare(_comp));
			};

			// [ ] Find
			iterator find(const key_type& k);
			const_iterator find(const key_type& k) const;

			// [ ] Count
			size_type count(const key_type& k) const;

			// [ ] Lower Bound
			iterator lower_bound(const key_type& k);
			const_iterator lower_bound(const key_type& k) const;

			// [ ] Upper Bound
			iterator upper_bound(const key_type& k);
			const_iterator upper_bound(const key_type& k) const;

			// [ ] Equal Range
			pair<const_iterator,const_iterator> equal_range(const key_type& k) const;
			pair<iterator,iterator>             equal_range(const key_type& k);

			// [X] Get Allocator
			allocator_type get_allocator(void) const
			{
				return (_alloc);
			};

	};	// END OF CLASS MAP

	// NON-MEMBER FUNCTIONS
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

	// [X] Swap
	template< class Key, class T, class Compare, class Alloc >
	void swap(ft::map<Key, T, Compare, Alloc> & lhs, ft::map<Key, T, Compare, Alloc> & rhs)
	{
		lhs.swap(rhs);
	};

}; // END OF NAMESPACE FT

#endif
