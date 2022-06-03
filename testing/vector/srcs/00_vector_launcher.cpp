/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_laucher.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 14:19:08 by cmariot           #+#    #+#             */
/*   Updated: 2022/06/03 14:51:06 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

int	vector_launcher(void)
{
	s_test	*tests = NULL;
	char	*function_name = (char *)"VECTOR";

	load_test(&tests, function_name, (char *)"Constructor", (void *)&constructor_test, NULL);
	return (launch_tests(&tests));
}
