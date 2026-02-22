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
    return 0;
}
