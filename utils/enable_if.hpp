/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 11:25:01 by cmariot           #+#    #+#             */
/*   Updated: 2022/07/05 13:28:17 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENABLE_IF
# define ENABLE_IF

namespace ft
{


	// ENABLE_IF : Utile pour que des fonctions puissent compiler seulement si
	// la condition Cond est vraie.
	// ft::enable_if<ft::is_integral<int>::value
	template <bool Cond, class T = void>
	struct enable_if
	{

	};
	template<class T>
	struct enable_if <true, T>
	{
		typedef T type;
	};


	// IS_INTEGRAL :
	// structure dont la seule valeur est true si le template est de type integral
	// (bool, int, char ...), false dans les autres cas
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

#endif
