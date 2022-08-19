/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pair.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 20:38:50 by cmariot           #+#    #+#             */
/*   Updated: 2022/08/16 22:42:25 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAKE_PAIR_HPP
# define MAKE_PAIR_HPP

# include "pair.hpp"

namespace ft
{

	// MAKE PAIR
	template <class T1, class T2>
		ft::pair<T1, T2> make_pair(T1 x, T2 y)
		{
			return (ft::pair<T1, T2>(x, y));
		};

}; // END OF NAMESPACE FT

#endif
