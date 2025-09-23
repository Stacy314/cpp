#include <typeinfo>
#include <cstring>
#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

void print_vptr(const char* name, const Animal* p) {
    void* vtable = 0;
    std::memcpy(&vtable, (const void*)(p), sizeof(void*));
    std::cout << name << " vtable @ " << vtable << std::endl;
}

template <typename T>
void print_addr(const char* name, const T* p) {
    std::cout << name << " object @ " << p
              << "  | typeid(*p): " << typeid(*p).name() << "\n";
}

void print_sizes() {
    std::cout << "sizeof(Animal)      = " << sizeof(Animal) << "\n"; //virtual pointer
    std::cout << "sizeof(Dog)         = " << sizeof(Dog) << "\n"; //virtual pointer
    std::cout << "sizeof(Cat)         = " << sizeof(Cat) << "\n"; //virtual pointer
    std::cout << "sizeof(WrongAnimal) = " << sizeof(WrongAnimal) << "\n";
    std::cout << "sizeof(WrongCat)    = " << sizeof(WrongCat) << "\n";
}

int main()
{
std::cout << "\n🧪 Initialized base organism 🧪\n";
const Animal* meta = new Animal();
print_vptr("meta(Animal*)", meta);

std::cout << "\n🧬 New biological specimen created 🧬\n";
const Animal* j = new Dog();
print_vptr("j(Animal*)   ", j);

std::cout << "\n🧬 New biological specimen created 🧬\n";
const Animal* i = new Cat();
const Animal* k = new Cat();
print_vptr("i(Animal*)   ", i);
print_vptr("k(Animal*)   ", k);
k->makeSound();

std::cout << "\n🔬 Identified specimen type 🔬\n";
std::cout << j->getType() << " " << std::endl;
std::cout << i->getType() << " " << std::endl;

std::cout << "\n🧬 Animals are making noises 🧬\n";
i->makeSound();
j->makeSound();
meta->makeSound();

std::cout << "\n🧪 Let's start our experiment 🧪\n";
const WrongAnimal* w = new WrongCat();
w->makeSound();

std::cout << "\n🔬 Additional tests 🔬\n";
print_sizes();
print_addr("meta(Animal*)  ", meta);
print_addr("j(Animal*)     ", j);
print_addr("i(Animal*)     ", i);
print_addr("w(WrongAnimal*)", w);


std::cout << "\n😺 Animals are going to bed 🐶\n";
delete meta;
delete j; 
delete i;
delete k;
delete w;

return 0;
}
