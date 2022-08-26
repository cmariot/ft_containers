/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:42:37 by cmariot           #+#    #+#             */
/*   Updated: 2022/08/26 17:42:08 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"
#include <iostream>

int	main(void)
{
	std::cout << std::endl;

	// LAUNCH VECTOR TESTS
	vector_launcher();
	std::cout << std::endl;

	// LAUNCH STACK TESTS
	stack_launcher();
	std::cout << std::endl;

	// LAUNCH MAP TESTS
	map_launcher();
	std::cout << std::endl;

	return (0);
}
