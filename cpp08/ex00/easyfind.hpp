#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <vector>
#include <list>
#include <deque>

#define GREEN   "\033[32m"
#define RESET   "\033[0m"

template <typename T>
typename T::iterator easyfind(T &container, int value){
	typename T::iterator itr = std::find(container.begin(), container.end(), value);
	if(itr == container.end())
		throw std::runtime_error("\033[31mValue is not found in container\033[0m");
	return itr;
}

#endif
