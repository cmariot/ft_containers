/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 11:25:01 by cmariot           #+#    #+#             */
/*   Updated: 2022/06/29 14:46:23 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

namespace ft
{

	//ENABLE_IF
	template <bool Cond, class T = void>
	struct enable_if
	{

	};
	template<class T>
	struct enable_if <true, T>
	{
		typedef T type;
	};

	//IS_INTEGRAL
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

};
