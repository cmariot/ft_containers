/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 15:45:28 by cmariot           #+#    #+#             */
/*   Updated: 2022/07/13 20:57:04 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include <cstddef>
# include <memory>
# include <iostream>

# include "../utils/RBTree.hpp"
# include "../utils/enable_if.hpp"
# include "../utils/utils.hpp"
# include "../iterators/iterator.hpp"
# include "../iterators/reverse_iterator.hpp"
# include "../utils/pair.hpp"

namespace ft
{

	template <class Key,
			 class T,
			 class Compare = std::less<Key>,
			 class Allocator = std::allocator<ft::pair<const Key, T> > >
	class map
	{

		// MEMBER TYPES
		public :

			typedef Key												key_type;
			typedef T												mapped_type;
			typedef ft::pair<const Key, T>							value_type;
			typedef size_t											size_type;
			typedef ptrdiff_t										difference_type;
			typedef Compare											key_compare;
			typedef Allocator										allocator_type;
			typedef value_type &									reference;
			typedef const value_type &								const_reference;
			typedef typename Allocator::pointer						pointer;
			typedef typename Allocator::const_pointer				const_pointer;
			//typedef typename		T*								iterator;			// a implementer
			//typedef typename		T*								const_iterator;		// a implementer
			//typedef typename ft::reverse_iterator<iterator>			reverse_iterator;
			//typedef typename ft::reverse_iterator<const_iterator>	const_reverse_iterator;

		// PRIVATE MEMBER OBJECTS
		private :
			key_compare							_comp;
			allocator_type						_alloc;
			size_type							_size;
			RedBlackTree<key_type, mapped_type>	*_tree;

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
			explicit map(const key_compare & comp = key_compare(), const allocator_type & alloc = allocator_type()) :
				_comp(comp), _alloc(alloc)
			{
				return ;
			};

	};

};

#endif
