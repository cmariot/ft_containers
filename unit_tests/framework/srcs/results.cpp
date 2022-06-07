/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_results.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 21:42:14 by cmariot           #+#    #+#             */
/*   Updated: 2022/06/07 21:36:38 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.hpp"

int	results(int succeeded, int total, std::ofstream &fd, bool recursive)
{
	if (recursive == true)
		results(succeeded, total, static_cast<std::ofstream &>(std::cout), false);
	fd << std::endl << BOLDWHITE << succeeded << " / " << total << " = ";
	if (succeeded == total)
		fd << GREEN "[OK]" RESET << std::endl;
	else
		fd << RED "[KO]" RESET << std::endl;
	if (recursive == false)
		fd.close();
	return (0);
}
