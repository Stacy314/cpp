#include "easyfind.hpp"

template <typename T>
void testContainer(T &container, int Value, const std::string &name) {
	std::cout << "Searching in container " << name << "\n";
    try
    {
        typename T::iterator it = easyfind(container, Value);
		std::cout << GREEN << "Value " << *it << " is found in container\n" << RESET;
    } catch (std::exception const &e) {
        std::cout << e.what() << "\n";
    }
}

int main() {
    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    std::list<int> lst;
    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);

    std::deque<int> dq;
    dq.push_back(1);
    dq.push_back(2);
    dq.push_back(3);

    testContainer(dq, 1, "Deque");
    testContainer(v, 3, "Vector");
    testContainer(lst, 2, "List");
	std::cout << "\n";

    testContainer(dq, -1, "Deque");
    testContainer(v, 42, "Vector");
    testContainer(lst, 2000, "List");

    std::cout << "\n";
<<<<<<< HEAD

=======
    
    std::deque<int> const cdq(dq);
    std::vector<int> const cv(v);
    std::list<int> const clst(lst);

    testConstContainer(cdq, 1, 100, "Deque");
    testConstContainer(cv, 2, 42, "Vector");
    testConstContainer(clst, 3, -1, "List");
    
>>>>>>> 938b6550891237ca4279743c68d1573a905e86d2
    return 0;
}
