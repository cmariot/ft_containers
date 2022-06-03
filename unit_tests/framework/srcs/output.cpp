/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 21:42:14 by cmariot           #+#    #+#             */
/*   Updated: 2022/06/03 17:11:26 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.hpp"

int	ft_putstr_fd(std::string str, int fd)
{
	return (write(fd, (char *)str.c_str(), str.length()));
}

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

void	check_stdout_output(t_test *test, int fd)
{
	std::string	output;

	if (test->expected_output.empty() == false)
	{
		output = filename_to_str(test->filename);
		if (output == test->expected_output)
		{
			ft_putstr_fd(GREEN"[OUTPUT : OK]\n" RESET, fd);
		}
		else
		{
			ft_putstr_fd(RED"[OUTPUT : KO]\n", fd);
			dprintf(fd, "\t\t\t[OUTPUT]:\t[%s]\n", output.c_str());
			dprintf(fd, "\t\t\t[EXPECTED]:\t[%s]\n" RESET, test->expected_output.c_str());
			if (fd != 1)
				test->status = KO;
		}
	}
	else
		ft_putstr_fd("\n", fd);
}

void	print_test_output(t_test *test, int test_number, int fd)
{
	if (fd != 1)
		print_test_output(test, test_number, 1);
	dprintf(fd, "%s_%02d", (char *)test->function.c_str(), test_number);
	dprintf(fd, ": %s:\t", (char *)test->test_name.c_str());
	if (test->status == OK)
		dprintf(fd, GREEN"[OK]" RESET);
	else if (test->status == KO)
		dprintf(fd, RED"[KO]" RESET);
	else if (test->status == TIMEOUT)
		dprintf(fd, RED"[TIMEOUT]" RESET);
	else if (test->status == SIGSEGV)
		dprintf(fd, RED"[SIGSEGV]" RESET);
	else if (test->status == SIGBUS)
		dprintf(fd, RED"[SIGBUS]" RESET);
	else if (test->status == SIGABRT)
		dprintf(fd, RED"[SIGABRT]" RESET);
	else if (test->status == SIGFPE)
		dprintf(fd, RED"[SIGFPE]" RESET);
	else if (test->status == SIGPIPE)
		dprintf(fd, RED"[SIGPIPE]" RESET);
	else if (test->status == SIGILL)
		dprintf(fd, RED"[SIGILL]" RESET);
	else
		dprintf(fd, RED"[EXIT : %d]" RESET, test->status);
	check_stdout_output(test, fd);
}
