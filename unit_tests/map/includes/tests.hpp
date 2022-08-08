/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 14:17:24 by cmariot           #+#    #+#             */
/*   Updated: 2022/08/08 16:45:40 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_HPP
# define TESTS_HPP

# include "libunit.hpp"

# include "map.hpp"
# include <map>

int		map_launcher(void);
int		pair_test(void);
int		RBTree_test(void);
int		constructors_tests(void);
int		destructor_tests(void);
int		clear_tests(void);
int		value_key_comp_tests(void);
int		swap_tests(void);
int		iterator_tests(void);
int		empty_test(void);
int		relational_ope(void);
int		bound_tests(void);

#endif
