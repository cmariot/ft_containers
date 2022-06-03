/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timeout.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 13:35:32 by cmariot           #+#    #+#             */
/*   Updated: 2022/06/03 14:34:02 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.hpp"

// Get the time in seconds and microseconds since midnight, January 1, 1970.
size_t	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

int	check_timeout(size_t init_time)
{
	size_t	timeout_delay;

	timeout_delay = (TIMEOUT_DELAY * 1000);
	if (get_time() >= init_time + timeout_delay)
		return (1);
	else
		return (0);
}
