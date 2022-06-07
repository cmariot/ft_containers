/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 21:42:14 by cmariot           #+#    #+#             */
/*   Updated: 2022/06/07 19:02:44 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.hpp"

int	display_results(int count_of_succeeded_tests, int total_number_of_tests)
{
	if (count_of_succeeded_tests == total_number_of_tests)
	{
		std::cout << count_of_succeeded_tests << " / " << total_number_of_tests;
		std::cout << " = " << GREEN"[OK]" RESET << std::endl;
		return (0);
	}
	else
	{
		std::cout << count_of_succeeded_tests << " / " << total_number_of_tests;
		std::cout << " = " << RED"[KO]" RESET << std::endl;
		return (-1);
	}
}
