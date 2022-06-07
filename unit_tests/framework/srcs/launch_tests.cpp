/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_tests.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 22:01:37 by cmariot           #+#    #+#             */
/*   Updated: 2022/06/07 19:23:00 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.hpp"

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
	int				total;
	int				succeeded;
	int				routine_exit = 0;

	log_file = create_log_file(*test);
	if (!log_file.is_open())
		return (1);
	total = 0;
	succeeded = 0;
	std::cout << (*test)->function << " TESTS:" << std::endl << std::endl;
	while (*test)
	{
		execute_test(test, log_file);
		print_test_output(*test, total, log_file, false);
		if ((*test)->status == OK)
			succeeded++;
		total++;
		element = *test;
		*test = (*test)->next;
		delete element;
	}
	routine_exit
		= display_results(succeeded, total);
	log_file.close();
	return (routine_exit);
}
