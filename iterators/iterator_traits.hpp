/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 21:42:52 by cmariot           #+#    #+#             */
/*   Updated: 2022/08/16 22:33:16 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_TRAITS_HPP
# define ITERATOR_TRAITS_HPP

namespace ft
{

	// Iterators are a generalization of pointers that allow a C++ program to work with
	// different data structures (containers) in a uniform manner.

	// ITERATOR CATEGORIES :
	// Empty types to identify the category of an iterator

	// InputIterator
	struct input_iterator_tag
	{
	};

	// OutputIterator
	struct output_iterator_tag
	{
	};

	// ForwardIterator
	struct forward_iterator_tag : public input_iterator_tag
	{
	};

	// BidirectionalIterator
	struct bidirectional_iterator_tag : public forward_iterator_tag
	{
	};

	// RandomAccessIterator
	struct random_access_iterator_tag : public bidirectional_iterator_tag
	{
	};

	// ITERATOR BASE CLASS
	// This is a base class template that can be used to derive iterator classes from it.
	// It is not an iterator class and does not provide any of the functionality an iterator is expected to have.
	
	// This base class only provides some member types,
	// which in fact are not required to be present in any iterator type (iterator types have no specific member requirements),
	// but they might be useful, since they define the members needed for the default iterator_traits class template
	// to generate the appropriate instantiation automatically (and such instantiation is required to be valid for all iterator types).

	template <class Category, class T, class Distance = std::ptrdiff_t, class Pointer = T *, class Reference =  T&>
	struct iterator
	{

		typedef Category								iterator_category;
		typedef T										value_type;
		typedef Distance								difference_type;
		typedef Pointer									pointer;
		typedef Reference								reference;

	};

	// ITERATOR TRAITS
	// Traits class defining properties of iterators.
	// For every iterator type, a corresponding specialization of iterator_traits class template shall be defined
	template <class Iterator>
	struct iterator_traits
	{

		typedef typename Iterator::iterator_category	iterator_category;
		typedef typename Iterator::value_type			value_type;
		typedef typename Iterator::difference_type		difference_type;
		typedef typename Iterator::pointer				pointer;
		typedef typename Iterator::reference			reference;

	};

	template <class T>
	struct iterator_traits<T *>
	{

		typedef random_access_iterator_tag				iterator_category;
		typedef T										value_type;
		typedef std::ptrdiff_t							difference_type;
		typedef T *										pointer;
		typedef T &										reference;

	};

	template <class T>
	struct iterator_traits<const T *>
	{

		typedef random_access_iterator_tag				iterator_category;
		typedef T										value_type;
		typedef std::ptrdiff_t							difference_type;
		typedef const T *								pointer;
		typedef const T &								reference;

	};

}; // END OF NAMESPACE FT

#endif
