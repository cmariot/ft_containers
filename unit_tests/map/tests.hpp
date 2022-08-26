/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 14:17:24 by cmariot           #+#    #+#             */
/*   Updated: 2022/08/26 15:22:57 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_MAP_HPP
# define TESTS_MAP_HPP

# include "libunit.hpp"

# include "map.hpp"
# include <map>

int		map_launcher(void);
int		pair_test(void);
int		RBTree_test(void);
int		map_constructors_tests(void);
int		map_destructor_tests(void);
int		map_clear_tests(void);
int		map_value_key_comp_tests(void);
int		map_swap_tests(void);
int		map_iterator_tests(void);
int		map_empty_test(void);
int		map_relational_ope(void);
int		map_bound_tests(void);

#endif
