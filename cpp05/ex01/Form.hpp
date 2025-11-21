#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include <exception>

class Bureaucrat;

class Form {
public:
    class GradeTooHighException : public std::exception {
    public: 
        const char* what() const throw();
    };
    class GradeTooLowException : public std::exception {
    public: 
        const char* what() const throw();
    };

    Form(const std::string& name, int gradeToSign, int gradeToExecute);
    Form(const Form&);
    Form& operator=(const Form&);
    ~Form();

    const std::string& getName() const;
    bool isSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;

    void beSigned(Bureaucrat const& b);

private:
    const std::string _name;
    bool _signed;
    const int _gradeToSign;
    const int _gradeToExecute;
};

std::ostream& operator<<(std::ostream& os, const Form& f);

#endif
