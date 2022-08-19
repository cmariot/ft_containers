/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 21:45:35 by cmariot           #+#    #+#             */
/*   Updated: 2022/08/17 01:11:36 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OTHER_HPP
# define OTHER_HPP

namespace ft
{

	// USED IN VECTOR CLASS TO THROW EXCEPTION
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

}; // END OF NAMESPACE FT

#endif
