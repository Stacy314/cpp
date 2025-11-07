#include "PresidentialPardonForm.hpp"
#include <iostream>


PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
: AForm("PresidentialPardon", 25, 5), _target(target) {}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& o)
: AForm(o), _target(o._target) {}
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& o) { if (this != &o) _target = o._target; return *this; }
PresidentialPardonForm::~PresidentialPardonForm() {}


void PresidentialPardonForm::execute(Bureaucrat const& executor) const {
requireExecutable(executor);
std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}