/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_iterators.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 09:14:27 by cmariot           #+#    #+#             */
/*   Updated: 2022/08/18 09:01:07 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

#include <map>
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
		ft::vector_iterator<int> ft_a = ft_vector.begin();
		std::vector<int>::iterator		std_a = std_vector.begin();
		if (*ft_a != *std_a)
			return (-1);

		// Copy constructible
		ft::vector_iterator<int> ft_b(ft_a);
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
		ft::vector_iterator<int> ft_a = ft_vector.begin() + 2;
		std::vector<int>::iterator		std_a = std_vector.begin() + 2;

		ft::vector_iterator<int> ft_b(ft_a);
		std::vector<int>::iterator		std_b(std_a);

		// Supports equality/inequality comparisons	
		if (ft_a != ft_b || std_a != std_b)
			return (-1);
		else if (!(ft_a == ft_b) || !(std_a == std_b))
			return (-1);

		// Can be dereferenced as an rvalue
		if (*ft_a != 2 || *std_b != 2)
			return (-1);

		ft::vector_iterator<int>		*ft_c = new ft::vector_iterator<int>;
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
		ft::vector_iterator<int> ft_a = ft_vector.begin() + 2;
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
		ft::vector_iterator<int> ft_a;
		std::vector<int>::iterator		std_a;

		ft_a = ft::vector_iterator<int>();
		std_a = std::vector<int>::iterator();

		ft_a = ft_vector.begin();
		std_a = std_vector.begin();

		// Multi pass
		ft::vector_iterator<int> ft_b;
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
		ft::vector_iterator<int> ft_a = ft_vector.begin();
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

		ft::vector_iterator<int> ft_a = ft_vector.begin();
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
			ft::vector_iterator<int> ft_b = ft_vector.end();
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
			// CONSTRUCTORS
			{
				ft::vector<int> myvector;
				for (int i=0; i<10; i++)
					myvector.push_back(i);

				typedef ft::vector<int>::iterator iter_type;

				iter_type from (myvector.begin());
				iter_type until (myvector.end());
				
				ft::reverse_iterator<iter_type> rev_until (from);
				ft::reverse_iterator<iter_type> rev_from (until);
				
				std::reverse_iterator<iter_type> std_rev_until (from);
				std::reverse_iterator<iter_type> std_rev_from (until);
				
				while (rev_from != rev_until)
				{
					if (*rev_from++ != *std_rev_from++)
						return (-1);
				}
			}
			// BASE
			{
				ft::vector<int> myvector;
				for (int i=0; i<10; i++)
					myvector.push_back(i);

				typedef ft::vector<int>::iterator iter_type;

				ft::reverse_iterator<iter_type> rev_end(myvector.begin());
				ft::reverse_iterator<iter_type> rev_begin (myvector.end());

				if (rev_end.base() != myvector.begin())
					return (-1);
				if (rev_begin.base() != myvector.end())
					return (-1);

				int i = 0;
				for (iter_type it = rev_end.base(); it != rev_begin.base(); ++it)
					if (*it != i++)
						return (-1);
			}

			// OPERATOR *
			{
				ft::vector<int> myvector;
				for (int i=0; i<10; i++)
					myvector.push_back(i);

				typedef ft::vector<int>::iterator iter_type;
																		// ? 9 8 7 6 5 4 3 2 1 0 ?
				iter_type from (myvector.begin());						//   ^
																		//         ------>
				iter_type until (myvector.end());						//                       ^
																		//
				ft::reverse_iterator<iter_type> rev_until (from);		// ^
																		//         <------
				ft::reverse_iterator<iter_type> rev_from (until);		//                     ^

				int i = 1;
				while (rev_from != rev_until)
					if (*rev_from++ != *(myvector.end() - i++))
						return (-1);
			}

			// OPERATOR +
			{
				ft::vector<int> myvector;
				for (int i=0; i<10; i++)
					myvector.push_back(i);	// myvector: 0 1 2 3 4 5 6 7 8 9

				typedef ft::vector<int>::iterator iter_type;

				ft::reverse_iterator<iter_type> rev_it;

				rev_it = myvector.rbegin() + 3;

				//std::cout << "The fourth element from the end is: " << *rev_it << '\n';
				if (*rev_it != 6)
					return (-1);

			}

			// OPERATOR ++
			{
				ft::vector<int> myvector;
				for (int i=0; i<10; i++)
					myvector.push_back(i);

				typedef ft::vector<int>::iterator iter_type;
																		// ? 9 8 7 6 5 4 3 2 1 0 ?
				iter_type from (myvector.begin());						//   ^
																		//         ------>
				iter_type until (myvector.end());						//                       ^
																		//
				std::reverse_iterator<iter_type> rev_until (from);		// ^
																		//         <------
				std::reverse_iterator<iter_type> rev_from (until);		//                     ^
				
				int i = 9;
				while (rev_from != rev_until) {
					if (*rev_from != i)
						return (-1);
					++rev_from;
					i--;
				}
			}

			// OPERATOR +=
			{
				ft::vector<int> myvector;
				for (int i=0; i<10; i++)
					myvector.push_back(i);	// myvector: 0 1 2 3 4 5 6 7 8 9

				std::vector<int> myvector2;
				for (int i=0; i<10; i++)
					myvector2.push_back(i);	// myvector: 0 1 2 3 4 5 6 7 8 9

				typedef ft::vector<int>::iterator iter_type;

				ft::reverse_iterator<iter_type> rev_iterator = myvector.rbegin();

				rev_iterator += 2;

				//std::cout << "The third element from the end is: " << *rev_iterator << '\n';
				if (*rev_iterator != 7)
					return -1;
			}

			// OPERATOR -
			{
				ft::vector<int> myvector;
				for (int i=0; i<10; i++) myvector.push_back(i);	// myvector: 0 1 2 3 4 5 6 7 8 9

				typedef ft::vector<int>::iterator iter_type;

				ft::reverse_iterator<iter_type> rev_iterator;

				rev_iterator = myvector.rend() - 3;

				//std::cout << "myvector.rend()-3 points to: " << *rev_iterator << '\n';
				if (*rev_iterator != 2)
				{
					return (-1);
				}
			}

			// OPERATOR -=
			{
				ft::vector<int> myvector;
				for (int i=0; i<10; i++)
					myvector.push_back(i);

				typedef ft::vector<int>::iterator iter_type;

				ft::reverse_iterator<iter_type> rev_begin (myvector.end());
				ft::reverse_iterator<iter_type> rev_end (myvector.begin());

				ft::reverse_iterator<iter_type> rev_iterator = rev_begin;
				
				int i = 9;
				while ( rev_iterator != rev_end )
				{
					if (*rev_iterator++ != i--)
						return (-1);
				}

				i = 0;
				while ( rev_iterator != rev_begin )
				{
					if (*(--rev_iterator) != i++)
						return (-1);
				}
			}

			// OPERATOR ->
			{
				std::map<int,std::string> numbers;
				numbers.insert (std::make_pair(1,"one"));
				numbers.insert (std::make_pair(2,"two"));
				numbers.insert (std::make_pair(3,"three"));

				typedef std::map<int,std::string>::iterator map_iter;

				std::reverse_iterator<map_iter> rev_end (numbers.begin());

				std::reverse_iterator<map_iter> rev_iterator (numbers.end());

				for ( ; rev_iterator != rev_end ; ++rev_iterator )
				{
					if (rev_iterator->first >= 4)
						return (-1);
					else if (rev_iterator->second == "")
						return (-1);
				}
			}

			// OPERATOR []
			{
				ft::vector<int> myvector;
				for (int i=0; i<10; i++)
					myvector.push_back(i);  // myvector: 0 1 2 3 4 5 6 7 8 9

				typedef ft::vector<int>::iterator iter_type;

				ft::reverse_iterator<iter_type> rev_iterator = myvector.rbegin();

				if (rev_iterator[3] != 6)
					return (-1);
			}

			// OPERATOR +
			{
				ft::vector<int> myvector;
				for (int i=0; i<10; i++) myvector.push_back(i);	// myvector: 0 1 2 3 4 5 6 7 8 9

				typedef ft::vector<int>::iterator iter_type;

				ft::reverse_iterator<iter_type> rev_it;

				rev_it = 3 + myvector.rbegin();

				if (*rev_it != 6)
					return (-1);
			}

			// OPERATOR -
			{
				ft::vector<int> myvector;
				
				for (int i=0; i<10; i++)
					myvector.push_back(i);

				ft::reverse_iterator<ft::vector<int>::iterator> from, until;

				from = myvector.rbegin();
				until = myvector.rend();

				// Expected output : myvector has 10 elements.
				if ((until - from) != 10)
					return (-1);
			}


			const int size = 5;
			ft::vector<int> vct(size);
			ft::vector<int>::reverse_iterator it = vct.rbegin();
			ft::vector<int>::const_reverse_iterator ite = vct.rbegin();

			std::vector<int> std_vct(size);
			std::vector<int>::reverse_iterator std_it = std_vct.rbegin();
			//std::vector<int>::const_reverse_iterator std_ite = std_vct.rbegin();

			for (int i = 0; i < size; ++i)
			{
				it[i] = (size - i) * 5;
				std_it[i] = (size - i) * 5;
			}
			
			it = it + 3;
			std_it = std_it + 3;
			if (*it.base() != *std_it.base())
				return (-1);

			it = 1 + it;
			std_it = 1 + std_it;
			if (it[0] != std_it[0])
				return (-1);
		
			for (size_t i = 0 ; i < 2 ; i++)
				if (*(it - i).base() != *(std_it - i).base())
					return (-1);
			it = it - 4;
			std_it = std_it - 4;
			if (*it != *std_it)
				return (102);
			
			if (*(it += 2) != *(std_it += 2))
				return (-1);
			if (*(it -= 1) != *(std_it -= 1))
				return (-1);

			*(it += 2) = 42;
			*(std_it += 2) = 42;
			*(it -= 2) = 21;
			*(std_it -= 2) = 21;

			for (size_t i = 0 ; i < 2 ; i++)
				if (*(it - i) != *(std_it - i))
					return (-1);


			//std::cout << "const_ite +=/-=: " << *(ite += 2) << " | " << *(ite -= 2) << std::endl;

			//std::cout << "(it == const_it): " << (ite == it) << std::endl;
			//std::cout << "(const_ite - it): " << (ite - it) << std::endl;
			//std::cout << "(ite + 3 == it): " << (ite + 3 == it) << std::endl;

		}
	}

	return (0);
}
