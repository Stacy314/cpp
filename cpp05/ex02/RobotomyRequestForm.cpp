#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>


RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
: AForm("RobotomyRequest", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& o)
: AForm(o), _target(o._target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& o) {
    if (this != &o)
        _target = o._target;
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}


void RobotomyRequestForm::execute(Bureaucrat const& executor) const {
    requireExecutable(executor);
	std::srand((unsigned int)(std::time(0)));
    std::cout << "* Drilling noises *\n";
    int r = std::rand() % 2;
    if (r)
        std::cout << _target << " has been robotomized successfully.\n";
    else
        std::cerr << "Robotomy failed on " << _target << ".\n";
}
