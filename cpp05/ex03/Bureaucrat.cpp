#include "Bureaucrat.hpp"
#include "AForm.hpp"

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
    if (this != &other) 
        _grade = other._grade;
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

void Bureaucrat::signForm(AForm& f) const {
    try {
        f.beSigned(*this);
        std::cout << _name << " signed " << f.getName() << "\n";
    } catch (std::exception& e) {
        std::cerr << _name << " couldn't sign " << f.getName() << " because " << e.what() << "\n";
    }
}


void Bureaucrat::executeForm(AForm const& f) const {
    try {
        f.execute(*this);
        std::cout << _name << " executed " << f.getName() << "\n";
    } catch (std::exception& e) {
        std::cerr << _name << " couldn't execute " << f.getName() << " because " << e.what() << "\n";
    }
}

// ==== Stream ====
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
    os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return os;
}

