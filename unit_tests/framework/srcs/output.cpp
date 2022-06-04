/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 21:42:14 by cmariot           #+#    #+#             */
/*   Updated: 2022/06/04 14:26:23 by cmariot          ###   ########.fr       */
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

void	check_stdout_output(t_test *test, std::ofstream &fd)
{
	std::string	output;

	output = filename_to_str(test->filename);
	if (test->expected_output.empty() == false)
	{
		if (output == test->expected_output)
			fd << GREEN"[OUTPUT : OK]" RESET << std::endl;
		else
		{
			fd << RED"[OUTPUT : KO]"<< std::endl;
			fd << "\t\t\t[OUTPUT]:\t[" << output << "]" << std::endl;
			fd << "\t\t\t[EXPECTED]:\t[" << test->expected_output <<  "]" << std::endl;
			test->status = KO;
		}
	}
	else
	{
		fd << std::endl;
		fd << "[OUTPUT :" << std::endl << output << "]" << std::endl;
	}
}

void	print_test_output(t_test *test, int test_number, std::ofstream &fd)
{
	if (fd != std::cout)
		print_test_output(test, test_number, (std::ofstream &)std::cout);
	fd << test->function << "_";
	fd << std::setw(2) << std::setfill('0');
	fd << test_number;
	fd << ": " << test->test_name << ":\t";
	if (test->status == OK)
		fd << GREEN"[OK]" RESET;
	else if (test->status == KO)
		fd << RED"[KO]" RESET;
	else if (test->status == TIMEOUT)
		fd << RED"[TIMEOUT]" RESET;
	else if (test->status == SIGSEGV)
		fd << RED"[SIGSEGV]" RESET;
	else if (test->status == SIGBUS)
		fd << RED"[SIGBUS]" RESET;
	else if (test->status == SIGABRT)
		fd << RED"[SIGABRT]" RESET;
	else if (test->status == SIGFPE)
		fd << RED"[SIGFPE]" RESET;
	else if (test->status == SIGPIPE)
		fd << RED"[SIGPIPE]" RESET;
	else if (test->status == SIGILL)
		fd << RED"[SIGILL]" RESET;
	else
		fd << RED"[EXIT : " << test->status << "]" RESET;
	check_stdout_output(test, fd);
}
