/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_tests.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 22:01:37 by cmariot           #+#    #+#             */
/*   Updated: 2022/06/08 11:54:40 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.hpp"

static int	clean_exit(t_test **test, std::ofstream &log_file)
{
	log_file.close();
	clear_test_list(test);
	return (1);
}

/*
 * Launch the tester :
 *  - Create a logfile to store the output
 *  - Exectute each test store in the list t_test
 *  - Print test results
 */

int	launch_tests(t_test **test)
{
	std::ofstream	log_file;
	t_test			*element;
	int				succeeded = 0;
	int				total = 0;

	std::cout << BOLDWHITE << (*test)->function
		<< " TESTS :" << RESET << std::endl << std::endl;
	log_file = create_log_file(*test);
	if (log_file.is_open() == false)
		return (1);
	while (*test)
	{
		if (execute_test(test, log_file))
			return (clean_exit(test, log_file));
		print_test_output(*test, total, log_file, false);
		if ((*test)->status == OK)
			succeeded++;
		total++;
		element = *test;
		*test = (*test)->next;
		delete element;
	}
	return (results(succeeded, total, log_file, true));
}
