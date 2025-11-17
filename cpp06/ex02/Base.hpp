#ifndef BASE_HPP
#define BASE_HPP

class Base {
public:
    virtual ~Base();
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

// functions required by the subject
Base *generate(void);
void  identify(Base *p);
void  identify(Base &p);

#endif