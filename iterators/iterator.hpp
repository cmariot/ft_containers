/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 16:26:01 by cmariot           #+#    #+#             */
/*   Updated: 2022/06/21 10:28:14 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

namespace	ft
{

	// ITERATOR CATEGORIES :
	// Empty classes to identify the category of an iterator

		// InputIterator
		struct input_iterator_tag
		{
		};

		// ForwardIterator
		struct forward_iterator_tag
		{
		};

		// BidirectionalIterator
		struct bidirectional_iterator_tag
		{
		};

		// RandomAccessIterator
		struct random_access_iterator_tag
		{
		};

		// OutputIterator
		struct output_iterator_tag
		{
		};



		iterator {
			iterator(const iterator&);
			~iterator();
			iterator& operator = (const iterator&);
			iterator& operator ++ (); //prefix increment
			reference operator*() const;
			friend void swap(iterator& lhs, iterator& rhs); //C++11 I think
		};


		input_iterator : public virtual iterator {
			iterator operator++(int); //postfix increment
			value_type operator*() const;
			pointer operator->() const;
			friend bool operator==(const iterator&, const iterator&);
			friend bool operator!=(const iterator&, const iterator&); 
		};
		

		//once an input iterator has been dereferenced, it is 
		//undefined to dereference one before that.
		output_iterator : public virtual iterator {
			reference operator*() const;
			iterator operator++(int); //postfix increment
		};
		

		//dereferences may only be on the left side of an assignment
		//once an output iterator has been dereferenced, it is 
		//undefined to dereference one before that.
		forward_iterator : input_iterator, output_iterator {
			forward_iterator();
		};

		//multiple passes allowed
		bidirectional_iterator : forward_iterator {
			iterator& operator--(); //prefix decrement
			iterator operator--(int); //postfix decrement
		};


		random_access_iterator : bidirectional_iterator {
			friend bool operator<(const iterator&, const iterator&);
			friend bool operator>(const iterator&, const iterator&);
			friend bool operator<=(const iterator&, const iterator&);
			friend bool operator>=(const iterator&, const iterator&);
			
			iterator& operator+=(size_type);
			friend iterator operator+(const iterator&, size_type);
			friend iterator operator+(size_type, const iterator&);
			iterator& operator-=(size_type);  
			friend iterator operator-(const iterator&, size_type);
			friend difference_type operator-(iterator, iterator);
			
			reference operator[](size_type) const;
		};

	// ITERATOR BASE CLASS
	template <class Category, class T, class Distance = ptrdiff_t, class Pointer = T *, class Reference =  T&>
	class iterator
	{

		public :

			typedef Category  iterator_category;
			typedef T         value_type;
			typedef Distance  difference_type;
			typedef Pointer   pointer;
			typedef Reference reference;

	};


	// RANDOM ACCESS ITERATOR
	class random_access_iterator
	{

		public :

		private :

	};


//	template <class T>
//	class random_access_iterator : ft::iterator<std::random_access_iterator_tag, T>
//	{
//
//		public :
//
//			//ITERATORS
//				typedef std::forward_iterator_tag	iterator_category;
//				typedef std::ptrdiff_t				difference_type;
//				typedef T							value_type;
//				typedef T *							pointer;
//				typedef T &							reference;
//				typedef const T &					const_reference;
//
//				// CONSTRUCTOR
//				iterator(pointer ptr) :
//					m_ptr(ptr)
//				{
//					return ;
//				};
//
//				// DEREFERENCE
//				reference operator * (void) const
//				{
//					return (*m_ptr);
//				}
//
//				// DEREFERENCE
//				pointer operator -> (void)
//				{
//					return (m_ptr);
//				}
//
//				// PREFIX INCREMENTATION
//				iterator & operator ++ (void)
//				{
//					m_ptr++;
//					return (*this);
//				}
//
//				// SUFIX INCREMENTATION
//				iterator operator ++ (int)
//				{
//					iterator tmp(*this);
//					++(*this);
//					return (tmp);
//				}
//
//				// COMPARAISON ==
//				friend bool operator == (const iterator & a, const iterator & b)
//				{
//					return (a.m_ptr == b.m_ptr);
//				};
//
//				// COMPARAISON !=
//				friend bool operator != (const iterator & a, const iterator & b)
//				{
//					return (a.m_ptr != b.m_ptr);
//				};
//
//
//				private :
//
//					pointer		m_ptr;
//
//			};
//	};

};
