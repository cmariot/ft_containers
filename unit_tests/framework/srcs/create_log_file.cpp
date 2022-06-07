/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_log_file.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 18:32:16 by cmariot           #+#    #+#             */
/*   Updated: 2022/06/07 20:47:59 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.hpp"

std::ofstream	create_log_file(t_test *test)
{
	std::ofstream	log_file(test->function + ".log");

	if (log_file.is_open() == false)
		std::cerr << "Error, can't create log file" << std::endl;
	else
		log_file << BOLDWHITE << test->function << " TESTS:" << std::endl << std::endl;
	return (log_file);
}
