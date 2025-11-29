#include "Serializer.hpp"
#include <iostream>

int main() {
    Data data;
    data.number = 42;
    data.text = "Hello serialization";

    std::cout << "Original Data pointer: " << &data << "\n";
    std::cout << "Data.number: " << data.number << "\n";
    std::cout << "Data.text: " << data.text << "\n";

    uintptr_t raw = Serializer::serialize(&data);

    std::cout << "Serialized uintptr_t: " << raw << "\n";

    Data *restored = Serializer::deserialize(raw);

    std::cout << "Restored Data pointer: " << restored << "\n";
    std::cout << "Restored Data.number: " << restored->number << "\n";
    std::cout << "Restored Data.text: " << restored->text << "\n";

    if (restored == &data)
        std::cout << "✅ Pointers are equal. ✅\n";
    else
        std::cout << "❌ Pointers are different. ❌\n";

    return 0;
}
