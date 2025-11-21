#include "AForm.hpp"
#include "Bureaucrat.hpp"

// ==== Exceptions ====
const char* AForm::GradeTooHighException::what() const throw() {
    return "Form grade too high";
}
const char* AForm::GradeTooLowException::what() const throw() {
    return "Form grade too low";
}

const char* AForm::NotSignedException::what() const throw() {
    return "Form not signed";
}


// ==== Canonical ====
AForm::AForm(const std::string& name, int gS, int gE)
: _name(name), _signed(false), _gradeToSign(gS), _gradeToExecute(gE) {
    if (gS < 1 || gE < 1) throw GradeTooHighException();
    if (gS > 150 || gE > 150) throw GradeTooLowException();
}

AForm::AForm(const AForm& o) : _name(o._name), _signed(o._signed), _gradeToSign(o._gradeToSign), _gradeToExecute(o._gradeToExecute) {}

AForm& AForm::operator=(const AForm& o) {
    if (this != &o)
        _signed = o._signed;
    return *this;
}

AForm::~AForm() {}


// ==== Getters ====
const std::string& AForm::getName() const {
    return _name;
}

int AForm::getGradeToSign() const {
    return _gradeToSign;
}

int AForm::getGradeToExecute() const {
    return _gradeToExecute;
}

bool AForm::isSigned() const {
    return _signed;
}


void AForm::beSigned(Bureaucrat const& b) {
    if (b.getGrade() > _gradeToSign)
        throw GradeTooLowException();
    _signed = true;
}

void AForm::requireExecutable(Bureaucrat const& executor) const {
    if (!_signed) 
        throw NotSignedException();
    if (executor.getGrade() > _gradeToExecute)
        throw GradeTooLowException();
}


// ==== Stream ====
std::ostream& operator<<(std::ostream& os, const AForm& f) {
    os << "Form '" << f.getName() << "' [signed=" << (f.isSigned()?"yes":"no")
    << ", sign:" << f.getGradeToSign() << ", exec:" << f.getGradeToExecute() << "]";
    return os;
}
