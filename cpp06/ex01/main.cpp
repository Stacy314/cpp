#include "Serializer.hpp"
#include <iostream>

int main()
{
    Data data;
    data.number = 42;
    data.text = "Hello serialization";

    std::cout << "Original Data pointer: " << &data << std::endl;
    std::cout << "Data.number: " << data.number << std::endl;
    std::cout << "Data.text: " << data.text << std::endl;

    uintptr_t raw = Serializer::serialize(&data);
    std::cout << "Serialized uintptr_t: " << raw << std::endl;

    Data *restored = Serializer::deserialize(raw);

    std::cout << "Restored Data pointer: " << restored << std::endl;
    std::cout << "Restored Data.number: " << restored->number << std::endl;
    std::cout << "Restored Data.text: " << restored->text << std::endl;

    if (restored == &data)
        std::cout << "Pointers are equal: serialization works." << std::endl;
    else
        std::cout << "Pointers differ: something is wrong." << std::endl;

    return 0;
}