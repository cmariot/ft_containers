/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   20_allocator.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 10:32:32 by cmariot           #+#    #+#             */
/*   Updated: 2022/08/29 12:17:39 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

int	map_allocator_test(void)
{
	ft::map<int, char>				ft_map;
	ft::pair<const int, char>		*ptr;

	if (ft_map.get_allocator() != std::allocator<ft::pair<const int, char> >())
		return (1);

	ptr = ft_map.get_allocator().allocate(1);
	ft_map.get_allocator().construct(ptr, ft::make_pair<const int, char>(0, 'A'));
	ft_map.get_allocator().destroy(ptr);
	ft_map.get_allocator().deallocate(ptr, 1);

	return (0);
}
