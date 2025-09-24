#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main() {

    const Animal* dog = new Dog();
    const Animal* cat = new Cat();
    delete dog;
    delete cat;

    std::cout << "\n🧪 Building the zoo 🧪\n";

    const int n = 6;
    Animal* zoo[n];

    for (int i = 0; i < n; ++i) {
        zoo[i] = (i < n/2) ? (Animal*)(new Dog())
                           : (Animal*)(new Cat());
    }


    std::cout << "\n🧬 Animals make sounds 🧬\n";
    for (int i = 0; i < n; ++i) {
        zoo[i]->makeSound();
    }

    std::cout << "\n🔬 Deep-copy test 🔬\n";   
    Dog d1;
    d1.makeSound();
    Dog d2 = d1;
    d2.makeSound();
    Dog d3(d1);
    d3.makeSound();
    Cat c1;
    c1.makeSound();
    Cat c2;
    c2.makeSound();
    c2 = c1;
    c2.makeSound();

    std::cout << "\n🧠 The thinking process is detected 🧠\n";
    Cat schrodinger;
    schrodinger.setIdea(0, "Catch the red dot");
    Cat copy = schrodinger;
    schrodinger.setIdea(0, "Sleep on keyboard");
    std::cout << "Schrodinger : " << schrodinger.getIdea(0) << "\n";
    std::cout << "Doppelganger: " << copy.getIdea(0) << "\n";



    std::cout << "\n😺 Bed time: deleting via Animal* 🐶\n";
    for (int i = 0; i < n; ++i) {
        delete zoo[i];
    }
    return 0;
}
