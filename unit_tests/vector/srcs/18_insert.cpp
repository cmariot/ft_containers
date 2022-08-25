/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   18_insert.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 09:16:36 by cmariot           #+#    #+#             */
/*   Updated: 2022/08/25 15:24:24 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

void print_vector(ft::vector<int> &vector)
{
	std::cout << "FT  : ";
	std::cout << "SIZE = " << vector.size();
	std::cout << " CAP = " << vector.capacity() << std::endl;
}

void print_std_vector(std::vector<int> &vector)
{
	std::cout << "STD : ";
	std::cout << "SIZE = " << vector.size();
	std::cout << " CAP = " << vector.capacity() << std::endl;
}

int	insert_test(void)
{
	{
		ft::vector<int>		ft_test(10, 42);
		std::vector<int>	std_test(10, 42);

		// INSERT (1) : vector.insert(position, value)
		ft_test.insert(ft_test.begin() + 2, 0);
		std_test.insert(std_test.begin() + 2, 0);
		
		if (ft_test.size() != std_test.size())
			return (-1);
		for (size_t i = 0 ; i < ft_test.size() ; i++)
			if (ft_test[i] != std_test[i])
				return (-1);
		if (ft_test.capacity() < ft_test.size())
			return (-1);



		// INSERT (2) : vector.insert(position, n, value)
		ft_test.insert(ft_test.end() - 3, 2, 1);
		std_test.insert(std_test.end() - 3, 2, 1);
		
		if (ft_test.size() != std_test.size())
			return (-1);
		for (size_t i = 0 ; i < ft_test.size() ; i++)
		{
			//std::cout << "ft_test[" << i << "] = " << ft_test[i] << std::endl;
			if (ft_test[i] != std_test[i])
				return (-1);
		}
		if (ft_test.capacity() < ft_test.size())
			return (-1);



		// INSERT (3) : vector.insert(position, first, last)
		ft::vector<int>		ft_input(3, 2);
		std::vector<int>	std_input(3, 2);

		ft_test.insert(ft_test.end() - 6, ft_input.begin(), ft_input.end());
		std_test.insert(std_test.end() - 6, std_input.begin(), std_input.end());
		
		if (ft_test.size() != std_test.size())
			return (-1);
		for (size_t i = 0 ; i < ft_test.size() ; i++)
			if (ft_test[i] != std_test[i])
				return (-1);
		if (ft_test.capacity() < ft_test.size())
			return (-1);



		//MORE TESTS

		ft::vector<int> ft_vct(10);
		std::vector<int> std_vct(10);
		ft::vector<int> ft_vct2;
		std::vector<int> std_vct2;

		for (unsigned long int i = 0; i < ft_vct.size(); ++i)
		{
			ft_vct[i] = (ft_vct.size() - i) * 3;
			std_vct[i] = (std_vct.size() - i) * 3;
		}


		ft_vct2.insert(ft_vct2.end(), 42);
		std_vct2.insert(std_vct2.end(), 42);
		if (ft_vct2.size() != std_vct2.size())
			return (-1);
		for (size_t i = 0 ; i < ft_vct2.size() ; i++)
			if (ft_vct2[i] != std_vct2[i])
				return (-1);
		if (ft_vct2.capacity() < ft_vct2.size())
			return (-1);


		ft_vct2.insert(ft_vct2.begin(), 3, 21);
		std_vct2.insert(std_vct2.begin(), 3, 21);
		if (ft_vct2.size() != std_vct2.size())
			return (-1);
		for (size_t i = 0 ; i < ft_vct2.size() ; i++)
			if (ft_vct2[i] != std_vct2[i])
				return (-1);
		if (ft_vct2.capacity() < ft_vct2.size())
			return (-1);


		ft_vct2.insert(ft_vct2.end() - 2, 42);
		std_vct2.insert(std_vct2.end() - 2, 42);
		if (ft_vct2.size() != std_vct2.size())
			return (-1);
		for (size_t i = 0 ; i < ft_vct2.size() ; i++)
			if (ft_vct2[i] != std_vct2[i])
				return (101);
		if (ft_vct2.capacity() < ft_vct2.size())
			return (-1);


		ft_vct2.insert(ft_vct2.end(), 2, 84);
		std_vct2.insert(std_vct2.end(), 2, 84);
		if (ft_vct2.size() != std_vct2.size())
			return (-1);
		for (size_t i = 0 ; i < ft_vct2.size() ; i++)
			if (ft_vct2[i] != std_vct2[i])
				return (-1);
		if (ft_vct2.capacity() < ft_vct2.size())
			return (-1);

		ft_vct2.resize(4);
		std_vct2.resize(4);


		ft_vct2.insert(ft_vct2.begin() + 2, ft_vct.begin(), ft_vct.end());
		std_vct2.insert(std_vct2.begin() + 2, std_vct.begin(), std_vct.end());
		if (ft_vct2.size() != std_vct2.size())
			return (-1);
		for (size_t i = 0 ; i < ft_vct2.size() ; i++)
			if (ft_vct2[i] != std_vct2[i])
				return (-1);
		if (ft_vct2.capacity() < ft_vct2.size())
			return (-1);
		
		ft_vct.clear();
		std_vct.clear();
	}

	//RETURN VALUE
	{
		ft::vector<int> vct(5);
		ft::vector<int> vct2;

		const int cut = 3;

		for (unsigned long int i = 0; i < vct.size(); ++i)
			vct[i] = (vct.size() - i) * 7;
		
		vct2.insert(vct2.begin(), vct.begin(), vct.begin() + cut);
		vct2.insert(vct2.begin(), vct.begin() + cut, vct.end());
		vct2.insert(vct2.end(), vct.begin(), vct.begin() + cut);


		if (*vct2.insert(vct2.end(), 42) != 42)
			return (-1);
		if (*vct2.insert(vct2.begin() + 5, 84) != 84)
			return (-1);

	}
	
	// MAZOISE
	{
		std::cout << std::endl << "INSERT TESTS" << std::endl;
		
		ft::vector<int> test(1, 1);
		std::vector<int> std_test(1, 1);

		ft::vector<int> test2(5, 5);

		test.insert(test.begin(), 200, 12);
		std_test.insert(std_test.begin(), 200, 12);

		print_vector(test);
		print_std_vector(std_test);
		
		test.insert(test.begin() + 12, 200, 30);
		std_test.insert(std_test.begin() + 12, 200, 30);

		print_vector(test);
		print_std_vector(std_test);

		test.insert(test.end(), 12, 50);
		std_test.insert(std_test.end(), 12, 50);

		print_vector(test);
		print_std_vector(std_test);

		test.insert(test.end() - 1, 0, 60);
		print_vector(test);
		test.insert(test.end() - 1, 1, 70);
		print_vector(test);
		test.insert(test.begin() + 412, test2.begin(), test2.end());
		print_vector(test);
		test.insert(test.begin() + 6, test2.begin(), test2.end());
		print_vector(test);
		test.insert(test.end(), test2.begin(), test2.end());
		print_vector(test);
	}


	return (0);
}
