#include "tests.hpp"

int	map_empty_test(void)
{
	// EMPTY MAP CONSTUCTOR
	ft::map<int, char>	ft_empty;
	if (ft_empty.empty() == false)
		return (1);
	
	// ADD AN ELEMENT IN THE MAP
	ft::map<int, char>	ft_not_empty;
	ft_not_empty.insert(ft::make_pair<int, char>(1, 'A'));
	if (ft_not_empty.empty() == true)
		return (1);

	// COPY ASSIGNATION
	ft_empty = ft_not_empty;
	if (ft_empty.empty() == true)
		return (1);

	// RAMGE CONSTUCTOR
	ft::map<int, char>	ft_range(ft_not_empty.begin(), ft_not_empty.end());
	if (ft_range.empty() == true)
		return (1);

	// EMPTY AFTER A CLEAR
	ft_not_empty.clear();
	if (ft_not_empty.empty() == false)
		return (1);

	return (0);
}
