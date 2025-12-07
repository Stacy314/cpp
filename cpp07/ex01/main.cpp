#include "iter.hpp"

template <typename T>
void printElement(T const &x) {
    std::cout << x << " ";
}

template <typename T>
void increment(T &x) {
    ++x;
}

void toUpperChar(char &c) {
    if (c >= 'a' && c <= 'z')
        c = static_cast<char>(c - 'a' + 'A');
}

int main() {
    // int array
    int arr[] = {1, 2, 3, 4, 5};
    std::size_t len = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Original int array: ";
    ::iter(arr, len, printElement<int>);
    std::cout << "\n";

    ::iter(arr, len, increment<int>);

    std::cout << "After increment:    ";
    ::iter(arr, len, printElement<int>);
    std::cout << "\n";

    // const int array 
    const int constArr[] = {10, 20, 30};
    std::size_t constLen = sizeof(constArr) / sizeof(constArr[0]);

    std::cout << "Const int array:    ";
    ::iter(constArr, constLen, printElement<int>);
    std::cout << "\n";

    // std::string array
    std::string strs[] = {"hello", "world", "cpp", "templates"};
    std::size_t slen = sizeof(strs) / sizeof(strs[0]);

    std::cout << "String array:       ";
    ::iter(strs, slen, printElement<std::string>);
    std::cout << "\n";

    // char array 
    char chars[] = "iter is cool";
    std::size_t clen = 0;
    while (chars[clen])
        ++clen;

    ::iter(chars, clen, toUpperChar);
    std::cout << "Uppercase chars:    " << chars << "\n";

    return 0;
}
