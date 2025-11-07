#include "Form.hpp"
#include "Bureaucrat.hpp"


const char* Form::GradeTooHighException::what() const throw() { return "Form grade too high"; }
const char* Form::GradeTooLowException::what() const throw() { return "Form grade too low"; }


Form::Form(const std::string& name, int gS, int gE)
: _name(name), _signed(false), _gradeToSign(gS), _gradeToExecute(gE) {
if (gS < 1 || gE < 1) throw GradeTooHighException();
if (gS > 150 || gE > 150) throw GradeTooLowException();
}
Form::Form(const Form& o)
: _name(o._name), _signed(o._signed), _gradeToSign(o._gradeToSign), _gradeToExecute(o._gradeToExecute) {}
Form& Form::operator=(const Form& o) { if (this != &o) _signed = o._signed; return *this; }
Form::~Form() {}


const std::string& Form::getName() const { return _name; }
bool Form::isSigned() const { return _signed; }
int Form::getGradeToSign() const { return _gradeToSign; }
int Form::getGradeToExecute() const { return _gradeToExecute; }


void Form::beSigned(Bureaucrat const& b) {
if (b.getGrade() > _gradeToSign) throw GradeTooLowException();
_signed = true;
}


std::ostream& operator<<(std::ostream& os, const Form& f) {
os << "Form '" << f.getName() << "' [signed=" << (f.isSigned()?"yes":"no")
<< ", sign:" << f.getGradeToSign() << ", exec:" << f.getGradeToExecute() << "]";
return os;
}