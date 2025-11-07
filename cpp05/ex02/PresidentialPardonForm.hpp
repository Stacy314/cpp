#ifndef PRESIDENTIAL_PARDON_FORM_HPP
#define PRESIDENTIAL_PARDON_FORM_HPP


#include "AForm.hpp"


class PresidentialPardonForm : public AForm {
private:
std::string _target;
public:
PresidentialPardonForm(const std::string& target);
PresidentialPardonForm(const PresidentialPardonForm&);
PresidentialPardonForm& operator=(const PresidentialPardonForm&);
~PresidentialPardonForm();


void execute(Bureaucrat const& executor) const;
};


#endif