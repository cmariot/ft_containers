/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equal.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 20:41:42 by cmariot           #+#    #+#             */
/*   Updated: 2022/08/16 22:39:05 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EQUAL_HPP
# define EQUAL_HPP

namespace ft
{

	// Compares the elements in the range [first1,last1) with those in the
	// range beginning at first2, and returns true if all of the elements in both
	// ranges match.

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
		};

}; // END OF NAMESPACE FT

#endif
