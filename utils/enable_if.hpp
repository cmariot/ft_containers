/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 20:19:21 by cmariot           #+#    #+#             */
/*   Updated: 2022/08/17 01:11:15 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENABLE_IF
# define ENABLE_IF

namespace ft
{

	// ENABLE_IF : Utile pour que des fonctions puissent compiler seulement si
	// la condition Cond est vraie.

	template <bool Cond, class T = void>
		struct enable_if
		{};

	template<class T>
		struct enable_if <true, T>
		{
			typedef T type;
		};

}; // END OF NAMESPACE FT

#endif
