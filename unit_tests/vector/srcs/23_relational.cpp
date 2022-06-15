/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   23_relational.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 09:17:19 by cmariot           #+#    #+#             */
/*   Updated: 2022/06/15 13:50:05 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"

int	relational_test(void)
{
	size_t	min_nb = 10;
	size_t	nb = 42;
	size_t	sup_nb = 100;

	//FT::VECTOR

		// Vecteur de comparaison
		ft::vector<int>		ft_test(nb, 4);
		
		// Vecteurs de test
		ft::vector<int>		ft_equal(nb, 4);				// == test
		ft::vector<int>		ft_different(nb, 10);			// != test
		ft::vector<int>		ft_strict_min(nb, 2);			// <  test
		ft::vector<int>		ft_min_equal(nb, 2);			// <= test
		ft::vector<int>		ft_strict_sup(nb, 6);			// > test
		ft::vector<int>		ft_sup_equal(nb, 6);			// >= test
		ft::vector<int>		ft_size(sup_nb, 4);				// != size (sup)
		ft::vector<int>		ft_size_min(min_nb, 4);			// != size (min)
		
		ft_min_equal.push_back(4);
		ft_sup_equal.push_back(4);

	//STD::VECTOR

		// Vecteur de comparaison
		std::vector<int>	std_test(nb, 4);
		
		// Vecteurs de test
		std::vector<int>	std_equal(nb, 4);				// == test
		std::vector<int>	std_different(nb, 10);			// != test
		std::vector<int>	std_strict_min(nb, 2);			// <  test
		std::vector<int>	std_min_equal(nb, 2);			// <= test
		std::vector<int>	std_strict_sup(nb, 6);			// > test
		std::vector<int>	std_sup_equal(nb, 6);			// >= test
		std::vector<int>	std_size(sup_nb, 4);			// != size
		std::vector<int>	std_size_min(min_nb, 4);		// != size (min)
	
		
		std_min_equal.push_back(4);
		std_sup_equal.push_back(4);


	if ((ft_test == ft_equal) != (std_test == std_equal))
		return (101);
	if ((ft_test != ft_different) != (std_test != std_different))
		return (102);
	if ((ft_test < ft_strict_min) != (std_test < std_strict_min))
		return (103);
	if ((ft_test <= ft_min_equal) != (std_test <= std_min_equal))
		return (104);
	if ((ft_test > ft_strict_sup) != (std_test > std_strict_sup))
		return (105);
	if ((ft_test >= ft_sup_equal) != (std_test >= std_sup_equal))
		return (106);


	if ((ft_test == ft_size) != (std_test == std_size))
		return (107);
	if ((ft_test != ft_size) != (std_test != std_size))
		return (108);
	if ((ft_test < ft_size) != (std_test < std_size))
		return (109);
	if ((ft_test <= ft_size) != (std_test <= std_size))
		return (110);
	if ((ft_test > ft_size) != (std_test > std_size))
		return (111);
	if ((ft_test >= ft_size) != (std_test >= std_size))
		return (112);



	if ((ft_test == ft_size_min) != (std_test == std_size_min))
		return (113);
	if ((ft_test != ft_size_min) != (std_test != std_size_min))
		return (114);
	if ((ft_test < ft_size_min) != (std_test < std_size_min))
	{
		std::cout << "MINE : " << (ft_test < ft_size_min) << " vs. STD : " << (std_test < std_size_min) << std::endl;
		std::cout << "LEN ft_test = " << ft_test.size() << " vs. ft_size_min = " << ft_size_min.size() << std::endl;
		std::cout << "VALUE ft_test = " << ft_test[0] << " vs. ft_size_min = " << ft_size_min[0] << std::endl;
		std::cout << "LEN std_test = " << std_test.size() << " vs. std_size_min = " << std_size_min.size() << std::endl;
		std::cout << "VALUE std_test = " << std_test[0] << " vs. std_size_min = " << std_size_min[0] << std::endl;
		return (115);
	}
	if ((ft_test <= ft_size_min) != (std_test <= std_size_min))
		return (116);
	if ((ft_test > ft_size_min) != (std_test > std_size_min))
		return (117);
	if ((ft_test >= ft_size_min) != (std_test >= std_size_min))
		return (118);


	return (0);
}
