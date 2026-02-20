#include "easyfind.hpp"

template <typename T>
void testContainer(T &container, int okValue, int failValue, const std::string &name) {
    try
    {
        typename T::iterator it = easyfind(container, okValue);
        std::cout << "Found in " << name << ": " << *it << "\n";
        it = easyfind(container, failValue);
        std::cout << "Found in " << name << ": " << *it << "\n";
    } catch (std::exception const &e) {
        std::cout << name << ": " << e.what() << "\n";
    }
}

template <typename T>
static void testConstContainer(T const &container, int okValue, int failValue, const std::string &name) {
    try {
        typename T::const_iterator it = easyfind(container, okValue);
        std::cout << "Found in const " << name << ": " << *it << "\n";
        it = easyfind(container, failValue);
        std::cout << "Found in const " << name << ": " << *it << "\n";
    } catch (std::exception const &e) {
        std::cout << "Const " << name << ": " << e.what() << "\n";
    }
}

int main() {
    std::deque<int> dq;
    dq.push_back(1);
    dq.push_back(2);
    dq.push_back(3);

    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    std::list<int> lst;
    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);

    testContainer(dq, 1, 100, "Deque");
    testContainer(v, 3, 42, "Vector");
    testContainer(lst, 2, -1, "List");
    std::cout << "\n";
    
    std::deque<int> const cdq(dq);
    std::vector<int> const cv(v);
    std::list<int> const clst(lst);

    testConstContainer(cdq, 1, 100, "Deque");
    testConstContainer(cv, 2, 42, "Vector");
    testConstContainer(clst, 3, -1, "List");
    
    return 0;
}
