/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_test_output.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 18:55:57 by cmariot           #+#    #+#             */
/*   Updated: 2022/06/11 13:05:37 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.hpp"

/*
 * Get all the file content and store it in a std::string
 */

static std::string	get_file_content(std::string file)
{
	std::ifstream	ifs(file);
	
	if (ifs.is_open() == false)
		return ("");
	std::string		content(
				(std::istreambuf_iterator<char>(ifs)),
				(std::istreambuf_iterator<char>())
			);
	ifs.close();
	unlink(file.c_str());
	return (content);
}

/*
 * Get the content of the file that stores the function output,
 * Compare the output with the expected output
 * or display the output depending the function call parameters.
 */

static void	check_stdout_output(t_test *test, std::ofstream &fd)
{
	std::string	output;

	output = get_file_content(test->filename);
	if (test->expected_output.empty() == false)
	{
		if (output == test->expected_output)
			fd << GREEN "[OUTPUT : OK]" RESET << std::endl;
		else
		{
			fd << RED "[OUTPUT : KO]" << std::endl;
			fd << "\t[OUTPUT]:\t[" << output << "]" << std::endl;
			fd << "\t[EXPECTED]:\t[" << test->expected_output <<  "]" << RESET << std::endl;
			test->status = KO;
		}
	}
	else
	{
		fd << std::endl;
		if (output.empty() == false)
			fd << "[OUTPUT] :" << std::endl << output << std::endl;
	}
}

/*
 * Print the test result on the ofstream fd (i.e. on the logfile)
 * (and call recursively the same function to print on std::cout)
 */

void	print_test_output(t_test *test, int test_number, std::ofstream &fd, bool cout)
{
	if (cout == false)
		print_test_output(test, test_number, static_cast<std::ofstream &>(std::cout), true);
	fd << test->function << "_";
	fd << std::setw(2) << std::setfill('0') << test_number;
	fd << ": " << test->test_name << " \t\t";
	if (test->status == OK)
		fd << GREEN "[OK]" RESET;
	else if (test->status == KO)
		fd << RED "[KO]" RESET;
	else if (test->status == TIMEOUT)
		fd << RED "[TIMEOUT]" RESET;
	else if (test->status == SIGSEGV)
		fd << RED "[SIGSEGV]" RESET;
	else if (test->status == SIGBUS)
		fd << RED "[SIGBUS]" RESET;
	else if (test->status == SIGABRT)
		fd << RED "[SIGABRT]" RESET;
	else if (test->status == SIGFPE)
		fd << RED "[SIGFPE]" RESET;
	else if (test->status == SIGPIPE)
		fd << RED "[SIGPIPE]" RESET;
	else if (test->status == SIGILL)
		fd << RED "[SIGILL]" RESET;
	else if (test->status == 66)
		fd << RED "[LEAKS]" RESET;
	else
		fd << RED "[EXIT : " << test->status << "]" RESET;
	check_stdout_output(test, fd);
}
