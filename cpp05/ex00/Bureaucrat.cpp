#include "Bureaucrat.hpp"

// ==== Exceptions ====
const char* Bureaucrat::GradeTooHighException::what() const throw() {
return "Bureaucrat grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
return "Bureaucrat grade too low";
}


// ==== Canonical ====
Bureaucrat::Bureaucrat(const std::string& name, int grade)
: _name(name), _grade(grade) {
if (grade < 1) throw GradeTooHighException();
if (grade > 150) throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
: _name(other._name), _grade(other._grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
if (this != &other) {
_grade = other._grade;
}
return *this;
}

Bureaucrat::~Bureaucrat() {}


// ==== Getters ====
const std::string& Bureaucrat::getName() const {
    return _name;
}

int Bureaucrat::getGrade() const { 
    return _grade;
}


// ==== Actions ====
void Bureaucrat::incrementGrade() {
if (_grade <= 1) throw GradeTooHighException();
--_grade;
}

void Bureaucrat::decrementGrade() {
if (_grade >= 150) throw GradeTooLowException();
++_grade;
}


// ==== Stream ====
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
return os;
}
