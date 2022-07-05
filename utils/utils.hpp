/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 13:15:13 by cmariot           #+#    #+#             */
/*   Updated: 2022/07/05 13:16:04 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

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
		} while (nb > 0);
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
	};

};

#endif
