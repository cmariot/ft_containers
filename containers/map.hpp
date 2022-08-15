/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 15:45:28 by cmariot           #+#    #+#             */
/*   Updated: 2022/08/10 16:55:49 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include <cstddef>
# include <memory>
# include <iostream>
# include <limits>
# include <cmath>

# include "../utils/RBTree.hpp"
# include "../utils/enable_if.hpp"
# include "../utils/utils.hpp"
# include "../iterators/bidirectional_iterator.hpp"
# include "../iterators/rite_map.hpp"
# include "../utils/pair.hpp"

// TODO :
// [ ] erase RBT a implementer
// [ ] copy construct (voir -- sur iterator end)
// [ ] rite

namespace ft
{

	template <class Key, class Value,
			 class Compare = std::less<Key>,
			 class Allocator = std::allocator<ft::pair<const Key, Value> > >
				 class map
				 {

					 // PUBLIC MEMBER TYPES
					 public :

						 typedef Key													key_type;
						 typedef Value													mapped_type;
						 typedef ft::pair<const Key, Value>								value_type;
						 typedef std::size_t											size_type;
						 typedef std::ptrdiff_t											difference_type;
						 typedef Compare												key_compare;
						 typedef Allocator												allocator_type;
						 typedef value_type &											reference;
						 typedef const value_type &										const_reference;
						 typedef typename Allocator::pointer							pointer;
						 typedef typename Allocator::const_pointer						const_pointer;
						 typedef typename ft::bidirectional_iterator<value_type>		iterator;
						 typedef typename ft::const_bidirectional_iterator<value_type>	const_iterator;
						 typedef ft::rite_map<iterator>									reverse_iterator;
						 typedef ft::rite_map<const_iterator>							const_reverse_iterator;

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

							 key_compare					comp;

							 // PROTECTED MEMBER FUNCTION
							 protected :

							 value_compare(key_compare c) :
								 comp(c)
							 {
								 return ;
							 };

							 // PUBLIC MEMBER FUNCTION
							 public :

							 result_type operator () (const value_type & lhs, const value_type & rhs) const
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
						 for (InputIterator it = first ; it != last ; ++it)
						 {
							 if (_tree->find(it->first) == NULL)
							 {
								 _tree->add(ft::make_pair<Key, Value>(it->first, it->second));
								 _size++;
							 }
						 }
					 };

						 // [ ] Copy constructor
						 map(const map & x)
						 {
							 _comp = x.key_comp();
							 _size = 0;
							 _alloc = x.get_allocator();
							 _tree = new red_black_tree;
							 *_tree = red_black_tree(_alloc, _comp);
							 insert(x.begin(), x.end());
						 };

						 // [X] Operator =
						 map& operator = (const map& x)
						 {
							 iterator	it;
							 iterator	ite;

							 it = x.begin();
							 ite = x.end();
							 clear();
							 _size = x.size();
							 _alloc = x.get_allocator();
							 _comp = x.key_comp();
							 while (it != ite)
							 {
								 _tree->add(*it);
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

						 // [ ] Begin
						 iterator begin(void)
						 {
							 return (_tree->begin());
						 };
						 const_iterator begin(void) const
						 {
							 return (_tree->cbegin());
						 };

						 // [ ] End
						 iterator end()
						 {
							 return (_tree->end());
						 };
						 const_iterator end() const
						 {
							 return (_tree->cend());
						 };

						 // [ ] RBEGIN : return a reverse iterator at the 'begining' (i.e. the last index) of the array
						 reverse_iterator rbegin(void)
						 {
							 return (reverse_iterator(end()));
						 };
						 const_reverse_iterator rbegin(void) const
						 {
							 return (const_reverse_iterator(end()));
						 };

						 // [ ] REND : return a reverse iterator at the 'end' (i.e. the first index) of the array
						 reverse_iterator rend(void)
						 {
							 return (reverse_iterator(begin()));
						 };
						 const_reverse_iterator rend(void) const
						 {
							 return (const_reverse_iterator(begin()));
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
							 return (std::numeric_limits<size_type>::max()
									 / sizeof(Node<value_type, allocator_type>));
						 };

						 // [X] Operator []
						 mapped_type& operator[] (const key_type& k)
						 {
							 return (insert(ft::make_pair(k, mapped_type())).first->second);
						 };

						 // [X] Insert
						 pair<iterator, bool> insert (const value_type& val)
						 {
							 if (_tree->find(val.first) != NULL)
								 return (ft::make_pair<iterator, bool>(_tree->find(val.first), false));
							 _size++;
							 return (_tree->add(val));
						 };
						 iterator insert (iterator position, const value_type& val)
						 {
							 if (_tree->find(val.first) != NULL)
								 return (iterator(NULL));
							 insert(val);
							 (void)position;
							 return (_tree->find(val.first));
						 };
						 template <class InputIterator>
							 void insert (InputIterator first, InputIterator last)
							 {
								 while (first != last)
									 insert(*first++);
							 };

						 // [ ] Erase 
						 void erase(iterator position)
						 {
							 _tree->del(position->first);
						 };
						 size_type erase(const key_type& k)
						 {
							 return (_tree->del(k));
						 };
						 void erase(iterator first, iterator last)
						 {
							 while (first != last)
							 {
								 _tree->del(first->first);
								 ++first;
							 }
						 };

						 // [X] Swap
						 void swap(map & x)
						 {
							 red_black_tree	*tmp_tree = x._tree;
							 size_type		tmp_size = x._size;
							 allocator_type	tmp_allocator = x.get_allocator();
							 key_compare	tmp_comp = x.key_comp();

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
							 return (value_compare(key_comp()));
						 };

						 // [ ] Find
						 iterator find(const key_type& k)
						 {
							 return (iterator(_tree->find(k)));
						 };
						 const_iterator find(const key_type& k) const
						 {
							 return (const_iterator(_tree->find(k)));
						 };

						 // [ ] Count
						 size_type count(const key_type& k) const
						 {
							 iterator	it;
							 iterator	ite;

							 it = begin();
							 ite = end();
							 while (it != ite)
							 {
								 if (it->first == k)
									 return (1);
								 ++it;
							 }
							 return (0);
						 };

						 // [ ] Lower Bound
						 iterator lower_bound(const key_type& k)
						 {
							 iterator	it;
							 iterator	ite;

							 ite = end();
							 it = begin();
							 while (it != ite)
							 {
								 if (key_comp()(it->first, k) == false)
									 return (it);
								 ++it;
							 }
							 return (ite);
						 };
						 const_iterator lower_bound(const key_type& k) const
						 {
							 const_iterator	it = begin();
							 const_iterator	ite = end();

							 while (it != ite)
							 {
								 if (key_comp()(it->first, k) == false)
									 return (it);
								 ++it;
							 }
							 return (ite);
						 };

						 // [ ] Upper Bound
						 iterator upper_bound(const key_type& k)
						 {
							 iterator	it;
							 iterator	ite;

							 ite = end();
							 it = begin();
							 while (it != ite)
							 {
								 if (key_comp()(k, it->first) == true)
									 return (it);
								 ++it;
							 }
							 return (ite);
						 };
						 const_iterator upper_bound(const key_type& k) const
						 {
							 const_iterator	it = begin();
							 const_iterator	ite = end();

							 while (it != ite)
							 {
								 if (key_comp()(k, it->first) == true)
									 return (it);
								 ++it;
							 }
							 return (ite);
						 };

						 // [ ] Equal Range
						 pair<const_iterator,const_iterator> equal_range(const key_type& k) const
						 {
							 return (ft::make_pair<const_iterator, const_iterator>(lower_bound(k), upper_bound(k)));
						 };
						 pair<iterator,iterator>	equal_range(const key_type& k)
						 {
							 return (ft::make_pair<iterator, iterator>(lower_bound(k), upper_bound(k)));
						 };

						 // [X] Get Allocator
						 allocator_type get_allocator(void) const
						 {
							 return (_alloc);
						 };

				 };	// END OF CLASS MAP

	// [/] NON-MEMBER FUNCTIONS
	template< class Key, class T, class Compare, class Alloc >
		bool operator == (const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs)
		{
			if (!(lhs.size() == rhs.size()))
				return (false);
			return (ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
		};

	template< class Key, class T, class Compare, class Alloc >
		bool operator != (const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs)
		{
			return (!(lhs == rhs));
		};

	template< class Key, class T, class Compare, class Alloc >
		bool operator < (const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs)
		{
			return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
		};

	template< class Key, class T, class Compare, class Alloc >
		bool operator <= (const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs)
		{
			return !(rhs < lhs);
		};

	template< class Key, class T, class Compare, class Alloc >
		bool operator > (const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs)
		{
			return (rhs < lhs);
		};

	template< class Key, class T, class Compare, class Alloc >
		bool operator >= (const ft::map<Key,T,Compare,Alloc>& lhs, const ft::map<Key,T,Compare,Alloc>& rhs)
		{
			return !(lhs < rhs);
		};

	// [X] Swap
	template< class Key, class T, class Compare, class Alloc >
		void swap(ft::map<Key, T, Compare, Alloc> & lhs, ft::map<Key, T, Compare, Alloc> & rhs)
		{
			lhs.swap(rhs);
		};

}; // END OF NAMESPACE FT


#endif
