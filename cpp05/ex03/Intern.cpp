#include "Intern.hpp"
#include <iostream>
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {}

Intern::Intern(const Intern&) {}

Intern& Intern::operator=(const Intern&) {
    return *this;
}

Intern::~Intern() {}


static AForm* makeShrub(const std::string& t) {
    return new ShrubberyCreationForm(t);
}

static AForm* makeRobo (const std::string& t) {
    return new RobotomyRequestForm(t);
}

static AForm* makePardon(const std::string& t) {
    return new PresidentialPardonForm(t);
}


AForm* Intern::makeForm(const std::string& name, const std::string& target) const {
    const std::string keys[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    AForm* (*ctors[3])(const std::string&) = { &makeShrub, &makeRobo, &makePardon };
    for (int i = 0; i < 3; ++i) {
        if (name == keys[i]) {
            std::cout << "Intern creates " << name << "\n";
            return ctors[i](target);
        }
    }
    std::cout << "Intern: unknown form name '" << name << "'\n";
    return 0;
}
