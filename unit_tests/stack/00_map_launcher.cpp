/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_map_launcher.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 14:19:08 by cmariot           #+#    #+#             */
/*   Updated: 2022/08/26 15:21:23 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

int	stack_launcher(void)
{
	s_test	*tests = NULL;
	std::string function_name = "STACK";

	load_test(&tests, function_name, "Constructor", (void *)&stack_constructors_tests, "");
	return (launch_tests(&tests));
}
