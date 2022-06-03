/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   result_file.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 00:54:56 by cmariot           #+#    #+#             */
/*   Updated: 2022/06/03 15:51:26 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.hpp"

int	create_log_file(t_test *test)
{
	std::string filename;
	int		log_file;

	filename = test->function + ".log";
	log_file = open(filename.c_str(), O_RDWR | O_CREAT | O_TRUNC, 0640);
	if (log_file == -1)
	{
		std::cerr << "Error, open failed." << std::endl;
		return (-1);
	}
	ft_putstr_fd((char *)test->function.c_str(), log_file);
	ft_putstr_fd((char *)" TESTS:\n\n", log_file);
	return (log_file);
}
