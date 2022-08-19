/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 20:19:55 by cmariot           #+#    #+#             */
/*   Updated: 2022/08/17 01:11:02 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IS_INTEGRAL_HPP
# define IS_INTEGRAL_HPP

namespace ft
{

	// IS_INTEGRAL
	// structure dont la seule valeur est true si le template est de type integral
	// (bool, int, char ...), false dans les autres cas (T)

	template <class T>
		struct is_integral
		{
			static const bool value = false;
		};

	template <>
		struct is_integral <bool>
		{
			static const bool value = true;
		};

	template <>
		struct is_integral <char>
		{
			static const bool value = true;
		};

	template <>
		struct is_integral <wchar_t>
		{
			static const bool value = true;
		};

	template <>
		struct is_integral <signed char>
		{
			static const bool value = true;
		};

	template <>
		struct is_integral <short int>
		{
			static const bool value = true;
		};

	template <>
		struct is_integral <int>
		{
			static const bool value = true;
		};

	template <>
		struct is_integral <long int>
		{
			static const bool value = true;
		};

	template <>
		struct is_integral <long long int>
		{
			static const bool value = true;
		};

	template <>
		struct is_integral <unsigned char>
		{
			static const bool value = true;
		};

	template <>
		struct is_integral <unsigned short int>
		{
			static const bool value = true;
		};

	template <>
		struct is_integral <unsigned int>
		{
			static const bool value = true;
		};

	template <>
		struct is_integral <unsigned long int>
		{
			static const bool value = true;
		};

	template <>
		struct is_integral <unsigned long long int>
		{
			static const bool value = true;
		};

}; // END OF NAMESPACE FT

#endif
