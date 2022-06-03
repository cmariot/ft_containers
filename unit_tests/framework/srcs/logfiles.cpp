/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logfiles.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 21:47:45 by cmariot           #+#    #+#             */
/*   Updated: 2022/06/03 16:31:29 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.hpp"

std::string	filename_to_str(std::string file)
{
	int		file_descriptor;
	int		read_return;
	std::string buf;
	std::string str;

	file_descriptor = open(file.c_str(), O_RDONLY);
	if (file_descriptor == -1)
		std::cerr << "Error, open failed." << std::endl;
	str = "";
	read_return = 1;
	while (read_return)
	{
		read_return = read(file_descriptor, (char *)buf.c_str(), 255);
		if (read_return == -1)
			return (NULL);
		buf[read_return] = '\0';
		if (str.empty() == true)
			str = buf;
		else
			str += buf;
	}
	close(file_descriptor);
	return (str);
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
