/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_destructors.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 19:18:19 by cmariot           #+#    #+#             */
/*   Updated: 2022/08/26 20:11:48 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

int	stack_destructors_tests(void)
{

	// DEFAULT CONSTRUCTOR
	ft::stack<std::string>									default_constructor;
	std::stack<std::string, ft::vector<std::string> >		std_default_constructor;


	// EMPTY + PUSH
	ft::stack<std::string>									push;
	std::stack<std::string, ft::vector<std::string> >		std_push;

	for (int i = 0 ; i < 10 ; ++i)
	{
		push.push("Foo");
		std_push.push("Bar");
	}


	// CONTAINER CONSTRUCTOR
	ft::vector<std::string>									vector(5, "Toto");

	ft::stack<std::string>									container_constructor(vector);
	std::stack<std::string, ft::vector<std::string> >		std_container_constructor(vector);


	// NEW / DELETE 
	ft::stack<std::string>	*X = new ft::stack<std::string>;
	X->push("Leak ?");
	delete X;			// Nope


	return (0);
}

