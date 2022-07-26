/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 14:17:24 by cmariot           #+#    #+#             */
/*   Updated: 2022/07/26 08:05:02 by cmariot          ###   ########.fr       */
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

#endif
