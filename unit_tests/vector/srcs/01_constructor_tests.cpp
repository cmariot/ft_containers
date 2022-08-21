/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_constructor_tests.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 14:49:23 by cmariot           #+#    #+#             */
/*   Updated: 2022/08/21 11:31:59 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.hpp"
#include <sstream>
using namespace std;

namespace ft
{

	string	to_string(size_t n)
	{
		std::stringstream tmp;

		tmp << n;

		return tmp.str();
	};

}

int	constructor_test(void)
{
//	//Default constructor
//	{
//		ft::ft::vector<char>	ft_default;
//		std::ft::vector<char>	std_default;
//
//		if (ft_default.size() != std_default.size())
//			return (-1);
//		if (ft_default.capacity() != std_default.capacity())
//			return (-1);
//		if (ft_default.empty() != std_default.empty())
//			return (-1);
//	}
//
//	//Fill constructor
//	{
//		size_t	n		= 5;
//		int 	value	= 42;
//
//		ft::ft::ft::vector<int>			ft_fill(n, value);
//		std::ft::ft::vector<int>		std_fill(n, value);
//
//		if (ft_fill.size() != std_fill.size())
//			return (-1);
//		if (ft_fill.capacity() != std_fill.capacity())
//			return (-1);
//		if (ft_fill.empty() != std_fill.empty())
//			return (-1);
//		for (size_t i = 0 ; i < ft_fill.size() ; i++)
//			if (ft_fill[i] != std_fill[i])
//				return (-1);
//
//		// Copy constructor
//		{
//			ft::ft::ft::vector<int>		ft_copy(ft_fill);
//			std::ft::ft::vector<int>	std_copy(std_fill);
//
//			if (ft_copy.size() != std_copy.size())
//				return (-1);
//			if (ft_copy.capacity() != std_copy.capacity())
//				return (-1);
//			if (ft_copy.empty() != std_copy.empty())
//				return (-1);
//			for (size_t i = 0 ; i < ft_copy.size() ; i++)
//				if (ft_copy[i] != std_copy[i])
//					return (-1);
//		}
//
//		// Range constructor
//		{
//			ft::ft::ft::vector<int>		ft_range(ft_fill.begin(), ft_fill.end());
//			std::ft::ft::vector<int>	std_range(std_fill.begin(), std_fill.end());
//
//			if (ft_range.size() != std_range.size())
//				return (101);
//			if (ft_range.capacity() != std_range.capacity())
//				return (102);
//			if (ft_range.empty() != std_range.empty())
//				return (103);
//			for (size_t i = 0 ; i < ft_range.size() ; i++)
//				if (ft_range[i] != std_range[i])
//					return (104);
//		}
//	}
//
//
	ft::vector<string> JOHN;
	ft::vector<string> BOB(5, "Hello");
	cout << "BOB(5, 8) : ";
	for (size_t i = 0; i < BOB.size(); i++)
		cout << BOB[i] << ' ';
	cout << '\n';
	ft::vector<string> MIKE(BOB);

	// CTORs
	cout << "\nCTORS\n";
	cout << "Empty is empty ? " << std::boolalpha << JOHN.empty() << '\n';
	cout << "BOB is empty? " << BOB.empty() << '\n';

	cout << "Size of JOHN " << JOHN.size() << std::endl;
	cout << "Size of BOB " << BOB.size() << std::endl;
	cout << "Size of MIKE " << MIKE.size() << std::endl;


	// RESIZE
	size_t	bob_resize = 2;
	cout << "\nRESIZE\n";
	BOB.resize(bob_resize);
	cout << "Size of JOHN " << JOHN.size() << std::endl;
	if (JOHN.capacity() >= JOHN.size())
		cout << "Capacity of JOHN is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 53\n";
	cout << "Size of BOB " << BOB.size() << std::endl;
	if (BOB.capacity() >= bob_resize)
		cout << "Capacity of BOB is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 58\n";
	cout << "Size of MIKE " << MIKE.size() << std::endl;
	if (MIKE.capacity() >= MIKE.size())
		cout << "Capacity of MIKE is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 63\n";

	size_t	mike_resize = 9;
	bob_resize = 0;
	
	BOB.resize(bob_resize);
	cout << "BOB is empty now ? " << BOB.empty() << '\n';
	MIKE.resize(mike_resize, "juste some random string");
	/*
	cout << "Size of JOHN " << JOHN.size() << std::endl;
	cout << "Capacity of JOHN " << JOHN.capacity() << std::endl;
	cout << "Size of BOB " << BOB.size() << std::endl;
	cout << "Capacity of BOB " << BOB.capacity() << std::endl;
	cout << "Size of MIKE " << MIKE.size() << std::endl;
	cout << "Capacity of MIKE " << MIKE.capacity() << std::endl;
	*/
	cout << "Size of JOHN " << JOHN.size() << std::endl;
	if (JOHN.capacity() >= JOHN.size())
		cout << "Capacity of JOHN is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 86\n";
	cout << "Size of BOB " << BOB.size() << std::endl;
	if (BOB.capacity() >= bob_resize)
		cout << "Capacity of BOB is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 91\n";
	cout << "Size of MIKE " << MIKE.size() << std::endl;
	if (MIKE.capacity() >= mike_resize)
		cout << "Capacity of MIKE is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 96\n";
	for (size_t i = 0; i < MIKE.size(); i++)
		cout << MIKE[i] << ' ';
	cout << std::endl;

	// RESERVE
	cout << "\nRESERVE\n";

	size_t	john_reserve = 5;
	size_t	bob_reserve = 3;
	size_t	mike_reserve = 83;

	JOHN.reserve(john_reserve);
	BOB.reserve(bob_reserve);
	MIKE.reserve(mike_reserve);
	/*
	cout << "Size of JOHN " << JOHN.size() << std::endl;
	cout << "Capacity of JOHN " << JOHN.capacity() << std::endl;
	cout << "Size of BOB " << BOB.size() << std::endl;
	cout << "Capacity of BOB " << BOB.capacity() << std::endl;
	cout << "Size of MIKE " << MIKE.size() << std::endl;
	cout << "Capacity of MIKE " << MIKE.capacity() << std::endl;
	*/
	cout << "Size of JOHN " << JOHN.size() << std::endl;
	if (JOHN.capacity() >= john_reserve)
		cout << "Capacity of JOHN is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 120\n";
	cout << "Size of BOB " << BOB.size() << std::endl;
	if (BOB.capacity() >= bob_reserve)
		cout << "Capacity of BOB is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 125\n";
	cout << "Size of MIKE " << MIKE.size() << std::endl;
	if (MIKE.capacity() >= mike_reserve)
		cout << "Capacity of MIKE is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 130\n";
	for (size_t i = 0; i < MIKE.size(); i++)
		cout << MIKE[i] << ' ';
	cout << std::endl;

	//AT
	cout << "\nAT\n";
	try
	{
		cout << MIKE.at(2) << '\n';
		cout << MIKE.at(87) << '\n';
	}
	catch (std::out_of_range& oor)
	{
		(void)oor;
		cout << "OOR error caught\n";
	}

	// FRONT / BACK
	cout << "\nFRONT / BACK\n";
	cout << "front() of MIKE : " << MIKE.front() << '\n';
	cout << "back() of MIKE : " << MIKE.back() << '\n';

	//ASSIGN
	cout << "\nASSIGN\n";
	BOB.assign(42, "James BOND");

	//ASSIGN RANGE
	cout << "\nASSIGN RANGE\n";
	ft::vector<string>	assign_range;
	assign_range.assign(8, "Covfefe");
	assign_range.assign(BOB.begin() + 1, BOB.end() - 2);

	//EMPTY
	cout << "\nEMPTY\n";
	cout << "BOB is empty ? " << BOB.empty() << '\n';
	cout << "BOB at(41) : " << BOB.at(41) << '\n';

	//PUSH/POP_BACK
	cout << "\nPUSH/POP_BACK\n";
	BOB.push_back("My name is Bond");
	cout << "last elem of BOB : " << BOB.back() << '\n';
	BOB.pop_back();
	cout << "last elem of BOB : " << BOB.back() << '\n';

	//INSERT
	cout << "\nINSERT\n";
	ft::vector<string>	insert_in_me;
	for (size_t i = 0; i < 15; i++)
		insert_in_me.push_back(ft::to_string(i) + " I love hbaudet\n");
	cout << "after push_back, before at\n";
	for (size_t i = 0; i < insert_in_me.size(); i++)
		cout << insert_in_me.at(i) << ' ';
	cout << '\n';

	ft::vector<string>::iterator	tmp;
	tmp = insert_in_me.begin() + 4;
	cout << "SIZE = " << insert_in_me.size() << " CAP = " << insert_in_me.capacity() << endl;
	insert_in_me.insert(tmp, 8, "Norminet");
	cout << endl;
	cout << endl;
	cout << "SIZE = " << insert_in_me.size() << " CAP = " << insert_in_me.capacity() << endl;
	for (size_t i = 0; i < insert_in_me.size(); i++)
		cout << "[" << i << "] = " << insert_in_me.at(i) << ' ';
	cout << '\n';

//	ft::vector<string>::const_iterator const_it(insert_in_me.begin());
//	cout << "Const it : " << std::endl;
//	cout << *const_it << '\n';
//	*const_it = 89; // Does not compile because it's a const_iterator


//	//INSERT
//	cout << "\nINSERT\n";
//	ft::vector<string>	std_insert_in_me;
//	for (size_t i = 0; i < 15; i++)
//		std_insert_in_me.push_back(ft::to_string(i) + " 42 ");
//	for (size_t i = 0; i < std_insert_in_me.size(); i++)
//		cout << std_insert_in_me.at(i) << ' ';
//	cout << '\n';
//
//	ft::vector<string>::iterator	std_tmp;
//	std_tmp = std_insert_in_me.begin() + 4;
//	std_insert_in_me.insert(std_tmp, 8, "Why are you reading this!?");
//	for (size_t i = 0; i < std_insert_in_me.size(); i++)
//		cout << std_insert_in_me.at(i) << ' ';
//	cout << '\n';
//
//
//	//INSERT RANGE
//	cout << "\nINSERT RANGE\n";
//	ft::vector<string>	insert_bis;
//	for (size_t i = 0; i < 7; i++)
//		insert_bis.push_back(ft::to_string(3 * i));
//	for (size_t i = 0; i < insert_bis.size(); i++)
//		cout << insert_bis[i] << ' ';
//	cout << '\n';
//
//	insert_bis.insert(insert_bis.begin() + 5, insert_in_me.begin(), insert_in_me.end());
//	for (size_t i = 0; i < insert_bis.size(); i++)
//		cout << insert_bis[i] << ' ';
//	cout << '\n';


//	//ERASE
//	cout << "\nERASE\n";
//	ft::vector<string>	erase_in_me;
//	for (size_t i = 0; i < 15; i++)
//		erase_in_me.push_back(ft::to_string(2 * i));
//	for (size_t i = 0; i < erase_in_me.size(); i++)
//	{
////		if (erase_in_me[i] < 10)
////			cout << ' ';
//		cout << erase_in_me.at(i) << ' ';
//	}
//	cout << '\n';
//
//	erase_in_me.erase(erase_in_me.begin() + 7);
//	for (size_t i = 0; i < erase_in_me.size(); i++)
//	{
////		if (erase_in_me[i] < 10)
////			cout << ' ';
//		cout << erase_in_me.at(i) << ' ';
//	}
//	cout << '\n';
//
//	erase_in_me.erase(erase_in_me.begin() + 2, erase_in_me.begin() + 6);
//	for (size_t i = 0; i < erase_in_me.size(); i++)
//	{
////		if (erase_in_me[i] < 10)
////			cout << ' ';
//		cout << erase_in_me.at(i) << ' ';
//	}
//	cout << '\n';
//
//	//SWAP
//	cout << "\nSWAP\n";
//	BOB.swap(MIKE);
//	/*
//	cout << "Size of BOB " << BOB.size() << std::endl;
//	cout << "Capacity of BOB " << BOB.capacity() << std::endl;
//	cout << "Size of MIKE " << MIKE.size() << std::endl;
//	cout << "Capacity of MIKE " << MIKE.capacity() << std::endl;
//	*/
//	cout << "Size of JOHN " << JOHN.size() << std::endl;
//	if (JOHN.capacity() >= JOHN.size())
//		cout << "Capacity of JOHN is sufficient\n";
//	else
//		std::cerr << "THERE IS A PROBLEM ON LINE 272\n";
//	cout << "Size of BOB " << BOB.size() << std::endl;
//	if (BOB.capacity() >= BOB.size())
//		cout << "Capacity of BOB is sufficient\n";
//	else
//		std::cerr << "THERE IS A PROBLEM ON LINE 277\n";
//	cout << "Size of MIKE " << MIKE.size() << std::endl;
//	if (MIKE.capacity() >= MIKE.size())
//		cout << "Capacity of MIKE is sufficient\n";
//	else
//		std::cerr << "THERE IS A PROBLEM ON LINE 282\n";
//	for (size_t i = 0; i < MIKE.size(); i++)
//		cout << MIKE[i] << ' ';
//	cout << std::endl;
//
//	MIKE.swap(JOHN);
//	/*
//	cout << "Size of JOHN " << JOHN.size() << std::endl;
//	cout << "Capacity of JOHN " << JOHN.capacity() << std::endl;
//	cout << "Size of MIKE " << MIKE.size() << std::endl;
//	cout << "Capacity of MIKE " << MIKE.capacity() << std::endl;
//	*/
//	cout << "Size of JOHN " << JOHN.size() << std::endl;
//	if (JOHN.capacity() >= JOHN.size())
//		cout << "Capacity of JOHN is sufficient\n";
//	else
//		std::cerr << "THERE IS A PROBLEM ON LINE 298\n";
//	cout << "Size of BOB " << BOB.size() << std::endl;
//	if (BOB.capacity() >= BOB.size())
//		cout << "Capacity of BOB is sufficient\n";
//	else
//		std::cerr << "THERE IS A PROBLEM ON LINE 303\n";
//	cout << "Size of MIKE " << MIKE.size() << std::endl;
//	if (MIKE.capacity() >= MIKE.size())
//		cout << "Capacity of MIKE is sufficient\n";
//	else
//		std::cerr << "THERE IS A PROBLEM ON LINE 308\n";
//	for (size_t i = 0; i < MIKE.size(); i++)
//		cout << MIKE[i] << ' ';
//	cout << std::endl;
//
//	//CLEAR
//	cout << "\nCLEAR\n";
//	JOHN.clear();
//	MIKE.clear();
//	/*
//	cout << "Size of JOHN " << JOHN.size() << std::endl;
//	cout << "Capacity of JOHN " << JOHN.capacity() << std::endl;
//	cout << "Size of MIKE " << MIKE.size() << std::endl;
//	cout << "Capacity of MIKE " << MIKE.capacity() << std::endl;
//	*/
//	cout << "Size of JOHN " << JOHN.size() << std::endl;
//	if (JOHN.capacity() >= JOHN.size())
//		cout << "Capacity of JOHN is sufficient\n";
//	else
//		std::cerr << "THERE IS A PROBLEM ON LINE 327\n";
//	cout << "Size of BOB " << BOB.size() << std::endl;
//	if (BOB.capacity() >= BOB.size())
//		cout << "Capacity of BOB is sufficient\n";
//	else
//		std::cerr << "THERE IS A PROBLEM ON LINE 332\n";
//	cout << "Size of MIKE " << MIKE.size() << std::endl;
//	if (MIKE.capacity() >= MIKE.size())
//		cout << "Capacity of MIKE is sufficient\n";
//	else
//		std::cerr << "THERE IS A PROBLEM ON LINE 337\n";
//	for (size_t i = 0; i < MIKE.size(); i++)
//		cout << MIKE[i] << ' ';
//	cout << std::endl;
//
//	//NON MEMBER Functions
//	cout << "\nNON MEMBER functions\n";
//	swap(BOB, MIKE);
//	/*
//	cout << "Size of BOB " << BOB.size() << std::endl;
//	cout << "Capacity of BOB " << BOB.capacity() << std::endl;
//	cout << "Size of MIKE " << MIKE.size() << std::endl;
//	cout << "Capacity of MIKE " << MIKE.capacity() << std::endl;
//	*/
//	cout << "Size of JOHN " << JOHN.size() << std::endl;
//	if (JOHN.capacity() >= JOHN.size())
//		cout << "Capacity of JOHN is sufficient\n";
//	else
//		std::cerr << "THERE IS A PROBLEM ON LINE 355\n";
//	cout << "Size of BOB " << BOB.size() << std::endl;
//	if (BOB.capacity() >= BOB.size())
//		cout << "Capacity of BOB is sufficient\n";
//	else
//		std::cerr << "THERE IS A PROBLEM ON LINE 360\n";
//	cout << "Size of MIKE " << MIKE.size() << std::endl;
//	if (MIKE.capacity() >= MIKE.size())
//		cout << "Capacity of MIKE is sufficient\n";
//	else
//		std::cerr << "THERE IS A PROBLEM ON LINE 365\n";
//	for (size_t i = 0; i < MIKE.size(); i++)
//		cout << MIKE[i] << ' ';
//	cout << std::endl;
//	
//	//RELATIONAL OPERATORS
//	cout << "\nRELATIONAL OPERATORS\n";
//	ft::vector<string> MIKE_2(MIKE);
//	cout << "MIKE and BOB are equal ? " << (MIKE == BOB) << '\n';
//	cout << "MIKE and MIKE_2 are equal ? " << (MIKE == MIKE_2) << '\n';
//
//	ft::vector<string> real;
//	real.assign(5, "foo");
//	for (ft::vector<string>::iterator it = real.begin(); it != real.end(); it++)
//		cout << *it << " ";
//	cout << '\n';
//
//	cout << std::endl;
	return (0);
}
