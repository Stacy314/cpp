int main() {
    const int N = 6;
    const Animal* zoo[N];
    for (int i=0;i<N;++i) zoo[i] = (i < N/2) ? static_cast<const Animal*>(new Dog()) : static_cast<const Animal*>(new Cat());
    for (int i=0;i<N;++i) delete zoo[i];

    Dog d1; d1.makeSound();
    Dog d2 = d1; // deep copy
    d2.makeSound();
    Cat c1; Cat c2; c2 = c1; // deep copy
    return 0;
}