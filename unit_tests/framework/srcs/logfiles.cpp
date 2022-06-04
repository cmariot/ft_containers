/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logfiles.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 21:47:45 by cmariot           #+#    #+#             */
/*   Updated: 2022/06/04 14:14:31 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.hpp"

std::string	filename_to_str(std::string file)
{
	std::ifstream	ifs(file);
	
	if (ifs.is_open() == false)
		return ("");
	std::string		content(
				(std::istreambuf_iterator<char>(ifs)),
				(std::istreambuf_iterator<char>())
			);
	ifs.close();
	return (content);
}

void	exit_child(t_test **test, int *fd, int *stdout_backup, int status)
{
	ft_cleartest_lst(test, 0);
	close(*fd);
	dup2(*stdout_backup, 1);
	close(*stdout_backup);
	exit(status);
}

void	output_redirection(int *fd, int *stdout_backup, t_test *test)
{
	*fd = open((*test).filename.c_str(), O_RDWR | O_CREAT | O_TRUNC, 0640);
	if (*fd == -1)
	{
		std::cerr << "Error, file opening failed." << std::endl;
		return ;
	}
	*stdout_backup = dup(1);
	dup2(*fd, 1);
}
