/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_iterators.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 09:14:27 by cmariot           #+#    #+#             */
/*   Updated: 2022/07/10 13:49:40 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

#include <typeinfo>
#include <vector>

int	iterators_test(void)
{
	// Create vectors
	ft::vector<int>			ft_vector(10);
	std::vector<int>		std_vector(10);
	for (int i = 0 ; i < 10 ; i++)
	{
		ft_vector[i] = i;
		std_vector[i] = i;
	}

	// Caracteristics for all categories
	{
		// Copy assignable
		ft::random_access_iterator<int> ft_a = ft_vector.begin();
		std::vector<int>::iterator		std_a = std_vector.begin();
		if (*ft_a != *std_a)
			return (-1);

		// Copy constructible
		ft::random_access_iterator<int> ft_b(ft_a);
		std::vector<int>::iterator		std_b(std_a);

		// Postfix incrementation
		ft_b++;
		std_b++;

		// Prefix incrementation
		++ft_b;
		++std_b;

		if (*ft_b != *std_b)
			return (-1);

		//Destructible
	}

	// Input iterator caracteristics
	{
		ft::random_access_iterator<int> ft_a = ft_vector.begin() + 2;
		std::vector<int>::iterator		std_a = std_vector.begin() + 2;

		ft::random_access_iterator<int> ft_b(ft_a);
		std::vector<int>::iterator		std_b(std_a);

		// Supports equality/inequality comparisons	
		if (ft_a != ft_b || std_a != std_b)
			return (-1);
		else if (!(ft_a == ft_b) || !(std_a == std_b))
			return (-1);

		// Can be dereferenced as an rvalue
		if (*ft_a != 2 || *std_b != 2)
			return (-1);

		ft::random_access_iterator<int>		*ft_c = new ft::random_access_iterator<int>;
		std::vector<int>::iterator	*std_c = new std::vector<int>::iterator;
		*ft_c = ft_b;
		*std_c = std_b;
		//if (typeid(ft_c->_ptr) != typeid(int))
		//	return (-1);
		
		delete ft_c;
		delete std_c;
	}

	// Output iterator caracteristics
	{
		ft::random_access_iterator<int> ft_a = ft_vector.begin() + 2;
		std::vector<int>::iterator		std_a = std_vector.begin() + 2;

		*ft_a = 42;
		*std_a = 42;

		if (*ft_a != *std_a)
			return (-1);

		*ft_a++ = 42;
		*std_a++ = 42;

		if (*ft_a != *std_a)
			return (-1);

	}

	// Forward iterator caracteristics
	{
		// Default constructible
		ft::random_access_iterator<int> ft_a;
		std::vector<int>::iterator		std_a;

		ft_a = ft::random_access_iterator<int>();
		std_a = std::vector<int>::iterator();

		ft_a = ft_vector.begin();
		std_a = std_vector.begin();

		// Multi pass
		ft::random_access_iterator<int> ft_b;
		std::vector<int>::iterator		std_b;

		ft_b = ft_a;
		std_b = std_a;

		*ft_a++;
		*std_a++;
		
		if (*ft_a != *std_a)
			return (-1);
		if (*ft_b != *std_b)
			return (-1);

	}

	// Bidirectional iterator caracteristics
	{
		ft::random_access_iterator<int> ft_a = ft_vector.begin();
		std::vector<int>::iterator		std_a = std_vector.begin();

		++ft_a;
		++std_a;
		if (*ft_a != *std_a)
			return (-1);

		ft_a++;
		std_a++;
		if (*ft_a != *std_a)
			return (-1);

		*ft_a++;
		*std_a++;
		if (*ft_a != *std_a)
			return (-1);

		// Can be decremented
		--ft_a;
		--std_a;
		if (*ft_a != *std_a)
			return (-1);

		ft_a--;
		std_a--;
		if (*ft_a != *std_a)
			return (-1);

		*ft_a--;
		*std_a--;
		if (*ft_a != *std_a)
			return (-1);

	}

	// Random access iterator caracteristics
	{

		ft::random_access_iterator<int> ft_a = ft_vector.begin();
		std::vector<int>::iterator		std_a = std_vector.begin();
		
		//Supports arithmetic operators + and -
			// a + n
			if (*(ft_a + 2) != *(std_a + 2))
				return (-1);
			// n + a
			if (*(2 + ft_a) != *(2 + std_a))
				return (-1);
			// a - n
			ft_a += 4;
			std_a += 4;
			if (*(ft_a - 2) != *(std_a - 2))
				return (-1);
			// a - b
			ft::random_access_iterator<int> ft_b = ft_vector.end();
			std::vector<int>::iterator		std_b = std_vector.end();
			if ((ft_b - ft_a) != (std_b - std_a))
				return (-1);

		//Supports inequality comparisons (<, >, <= and >=) between iterators
		if ((ft_a < ft_b) != (std_a < std_b))
			return (-1);
		if ((ft_a <= ft_b) != (std_a <= std_b))
			return (-1);
		if ((ft_a > ft_b) != (std_a > std_b))
			return (-1);
		if ((ft_a >= ft_b) != (std_a >= std_b))
			return (-1);
		//Supports compound assignment operations += and -=
			ft_a += 4;
			std_a += 4;	

			ft_a -= 5;
			std_a -= 5;
		//Supports offset dereference operator ([])

	}

	//REVERSE ITERATORS
	{
		//Constructors 
		{

			ft::vector<int> vct;
			ft::vector<int>::iterator it = vct.begin();
			ft::vector<int>::const_iterator cit = vct.begin();

			ft::vector<int>::reverse_iterator rit(it);

			ft::vector<int>::const_reverse_iterator crit(rit);
			ft::vector<int>::const_reverse_iterator crit_(it);
			ft::vector<int>::const_reverse_iterator crit_2(cit);

			//Error
			//ft::vector<int>::reverse_iterator rit_(crit);
			//ft::vector<int>::reverse_iterator rit2(cit);
			//ft::vector<int>::iterator it2(rit);
			//ft::vector<int>::const_iterator cit2(crit);

		}
		{
			const int size = 5;
			ft::vector<int> vct(size);
			ft::vector<int>::reverse_iterator it = vct.rbegin();
			//std::vector<int>::const_reverse_iterator ite = vct.rbegin();

			for (int i = 0; i < size; ++i)
				it[i] = (size - i) * 5;

			//it = it + 5;
			//it = 1 + it;
			//it = it - 4;
			//std::cout << *(it += 2) << std::endl;
			//std::cout << *(it -= 1) << std::endl;

			//*(it -= 2) = 42;
			//*(it += 2) = 21;

			//std::cout << "const_ite +=/-=: " << *(ite += 2) << " | " << *(ite -= 2) << std::endl;

			//std::cout << "(it == const_it): " << (ite == it) << std::endl;
			//std::cout << "(const_ite - it): " << (ite - it) << std::endl;
			//std::cout << "(ite + 3 == it): " << (ite + 3 == it) << std::endl;

		}
	}

	return (0);
}
