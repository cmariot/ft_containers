/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 14:01:33 by cmariot           #+#    #+#             */
/*   Updated: 2022/08/29 16:23:51 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef FT

	# include "vector.hpp"
	# include "stack.hpp"
	# include "map.hpp"
	# define NS ft

#else

	# include <vector>
	# include <stack>
	# include <map>
	# define FT 0
	# define NS std

#endif

#include <iostream>

template <class T>
void	print_vector(NS::vector<T> & vector)
{
	size_t	i = 0;

	std::cout << "PRINT VECTOR :" << std::endl;

	for (typename NS::vector<T>::iterator it = vector.begin() ; it != vector.end() ; ++it)
	{
		std::cout << "\tVECTOR[" << i << "] = " << vector[i] << std::endl;
		++i;
	}
	std::cout << "\tSIZE     = " << vector.size() << std::endl;
	std::cout << "\tCAP      = " << vector.capacity() << std::endl;
	std::cout << "\tMAX_SIZE = " << vector.max_size() << std::endl;
	std::cout << "\tEMPTY    = " << vector.empty() << std::endl;
	if (vector.size())
	{
		std::cout << "\tFRONT    = " << vector.front() << std::endl;
		std::cout << "\tBACK     = " << vector.back() << std::endl;
	}
	std::cout << std::endl;
}

void	test_vector(void)
{
	NS::vector<int>		empty;
	NS::vector<int>		value(5, 2);
	NS::vector<int>		range(value.begin(), value.end());
	NS::vector<int>		copy(range);

	print_vector<int>(empty);
	print_vector<int>(value);
	print_vector<int>(range);
	print_vector<int>(copy);

	copy.resize(3, 0);
	print_vector<int>(copy);
	copy.resize(10, 6);
	print_vector<int>(copy);

	empty.reserve(10);

	for (size_t i = 0 ; i < empty.size() ; ++i)
		std::cout << "AT(" << i << ") = " << empty.at(i) << std::endl;
	
	empty.clear();
	empty.assign(value.begin(), value.end() - 2);
	print_vector<int>(empty);

	empty.assign(3, 42);
	print_vector<int>(empty);

	empty.push_back(0);
	print_vector<int>(empty);

	empty.pop_back();
	print_vector<int>(empty);

	empty.insert(empty.begin() + 2, 6);
	print_vector<int>(empty);

	empty.insert(empty.begin(), 6, 7);
	print_vector<int>(empty);

	empty.insert(empty.begin() + 2, copy.begin(), copy.end());
	print_vector<int>(empty);

	empty.erase(empty.begin() + 3);
	empty.erase(empty.begin(), empty.end() - 5);
	print_vector<int>(empty);

	empty.swap(copy);
	print_vector<int>(empty);
	print_vector<int>(copy);
}

template <class T, class C>
void	print_stack(NS::stack<T, C> &stack)
{
	std::cout << "PRINT STACK :" << std::endl;

	if (stack.empty() == false)
		std::cout << "\tTOP      = " << stack.top() << std::endl;
	std::cout << "\tEMPTY    = " << stack.empty() << std::endl;
	std::cout << "\tSIZE     = " << stack.size() << std::endl;
	std::cout << std::endl;
}

void	test_stack(void)
{
	NS::stack<int, NS::vector<int> >		empty;
	NS::stack<int, NS::vector<int> >		other;

	print_stack<int>(empty);
	for (int i = 0 ; i < 10 ; ++i)
		empty.push(i);
	print_stack<int>(empty);
	for (int i = 0 ; i < 5 ; ++i)
		empty.pop();
	print_stack<int>(empty);
	other = empty;

	print_stack<int>(empty);
	print_stack<int>(other);
}

template <class Key, class Val>
void	print_map(NS::map<Key, Val> &map)
{
	std::cout << "PRINT MAP :" << std::endl;

	std::cout << "\tSIZE     = " << map.size() << std::endl;
	std::cout << "\tMAX_SIZE = " << map.max_size() << std::endl;
	std::cout << "\tEMPTY    = " << map.empty() << std::endl;
	for (typename NS::map<Key, Val>::iterator it = map.begin() ; it != map.end() ; ++it)
	{
		std::cout << "\t" << it->first << " : " << it->second << std::endl;
	}
}

void	test_map(void)
{
	NS::map<int, char>	map;

	map.insert(NS::pair<int, char>(1, 'a'));
	map.insert(NS::pair<int, char>(2, 'b'));
	map.insert(NS::pair<int, char>(3, 'c'));

	NS::map<int, char>	range(map.begin(), map.end()); 
	NS::map<int, char>	copy(map);
	copy = map;

	print_map<int, char>(map);
	print_map<int, char>(range);
	print_map<int, char>(copy);

	range.clear();
	print_map<int, char>(range);

	std::cout << map.key_comp()(1, 2) << std::endl;

	NS::pair<int, char> pair1 = NS::make_pair<int, char>(0, 'a');
	NS::pair<int, char> pair2 = NS::make_pair<int, char>(1, 'b');
	std::cout << map.value_comp()(pair1, pair2) << std::endl;

	map.swap(range);
	print_map<int, char>(map);
	print_map<int, char>(range);

	NS::map<int, char>::iterator itlow, itup;
	
	itlow = range.lower_bound('a');
	itup  = range.upper_bound('b');

	range.erase(itlow, itup);
	print_map<int, char>(range);

	map[99] = 'Z';
	map[98] = '*';
	map[96] = 'F';
	map[94] = 'c';
	map[90] = 'J';

	print_map<int, char>(map);

	map.insert(range.begin(), range.end());
	map.insert(NS::make_pair<int, char>(42, 'f'));
	map.insert(map.end(), NS::make_pair<int, char>(999, 'f'));

	print_map<int, char>(map);
}

int	main(void)
{
	test_vector();
	test_stack();
	test_map();
	return (0);
}
