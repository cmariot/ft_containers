/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   result_file.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 00:54:56 by cmariot           #+#    #+#             */
/*   Updated: 2022/06/04 13:33:55 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.hpp"

std::ofstream	create_log_file(t_test *test)
{
	std::ofstream	log_file((test->function + ".log").c_str());

	if (!log_file.is_open())
		std::cerr << "Error, open failed." << std::endl;
	else
		log_file << test->function << " TESTS:" << std::endl << std::endl;
	return (log_file);
}
