/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   results.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 21:42:14 by cmariot           #+#    #+#             */
/*   Updated: 2022/08/26 15:28:14 by cmariot          ###   ########.fr       */
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
		fd << RED_COLOR "[KO]" RESET << std::endl;
	//if (recursive == false)
		//fd.close();
	return (0);
}
