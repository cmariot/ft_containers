#include "tests.hpp"

int	relational_ope(void)
{
    //std::map<int, char> alice{{1, 'a'}, {2, 'b'}, {3, 'c'}};
    //std::map<int, char> bob{{7, 'Z'}, {8, 'Y'}, {9, 'X'}, {10, 'W'}};
    //std::map<int, char> eve{{0, 'a'}, {2, 'b'}, {3, 'c'}};
 
    ft::map<int, char> alice;
	alice.insert(ft::make_pair<int, char>(1, 'a'));
	alice.insert(ft::make_pair<int, char>(2, 'b'));
	alice.insert(ft::make_pair<int, char>(3, 'c'));

    ft::map<int, char> bob;
	bob.insert(ft::make_pair<int, char>(7, 'Z'));
	bob.insert(ft::make_pair<int, char>(8, 'Y'));
	bob.insert(ft::make_pair<int, char>(9, 'X'));

    ft::map<int, char> eve;
	eve.insert(ft::make_pair<int, char>(0, 'a'));
	eve.insert(ft::make_pair<int, char>(2, 'b'));
	eve.insert(ft::make_pair<int, char>(3, 'c'));

    // Compare non equal containers
    if ((alice == bob) == true)
		return (101);
    if ((alice != bob) == false) 
		return (102);
    if ((alice < bob)  == false)
		return (103);
    if ((alice <= bob) == false) 
		return (104);
    if ((alice > bob)  == true)
		return (105);
    if ((alice >= bob) == true) 
		return (106);
 
    std::cout << '\n';
 
    // Compare equal containers
    if ((alice == eve) == false)
		return (107);
    if ((alice != eve) == true)
		return (108);
    if ((alice < eve) == true)
		return (109);
    if ((alice <= eve) == false)
		return (110);
    if ((alice > eve) == true) 
		return (111);
    if ((alice >= eve) == false)
		return (112);

	return (0);
}
