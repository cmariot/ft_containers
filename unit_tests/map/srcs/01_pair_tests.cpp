/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_pair_tests.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 14:49:23 by cmariot           #+#    #+#             */
/*   Updated: 2022/07/25 23:38:57 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

int	pair_test(void)
{

	// PAIR
	{
		// CONSTRUCTORS
		{
			// Default
			ft::pair<int, int>	default_constructor;
			if (default_constructor.first != 0 || default_constructor.second != 0)
				return (-1);

			// Copy
			ft::pair<int, int>	copy_constructor(default_constructor);
			if (copy_constructor.first != default_constructor.first
				|| copy_constructor.second != default_constructor.second)
				return (-1);

			// Value
			ft::pair<int, int>	value_constructor(42, 21);
			if (value_constructor.first != 42 || value_constructor.second != 21)
				return (-1);

		}

		// OPERATOR =
		{

			ft::pair<int, int>	value_constructor(42, 21);
			ft::pair<int, int>	default_constructor;

			default_constructor = value_constructor;
			if (default_constructor.first != 42
				|| default_constructor.second != 21)
				return (-1);
		
		}

		// RELATIONAL OPERATORS
		{
			ft::pair<int, char> foo(1, 'A');
			ft::pair<int, char> bar(2, 'B');

			if (foo == bar)
				return (-1);
			if (!(foo != bar))
				return (-1);
			if (!(foo < bar))
				return (-1);
			if (foo > bar)
				return (-1);
			if (foo >= bar)
				return (-1);
			if (!(foo <= bar))
				return (-1);

		}
	}

	// MAKE PAIR
	{
	
		// Make pair
		ft::pair<int, int> foo;
		foo = ft::make_pair(10, 20);
		if (foo.first != 10 || foo.second != 20)
			return (-1);

		// Make pair : implicit conversion
		ft::pair<int, int> bar;
		bar = ft::make_pair(10.5, 'Z');
		if (bar.first != static_cast<int>(10.5) || bar.second != static_cast<int>('Z'))
			return (-1);
	
	}

	return (0);
}
