#include "Dog.hpp"
#include "Cat.hpp"
// #include "Animal.hpp" // cannot instantiate Animal now

int main(){

    // Animal a; // forbidden: abstract
    Animal* d = new Dog();
    Animal* c = new Cat();
    d->makeSound();
    c->makeSound();

    delete d;
    delete c;

    return 0;
}