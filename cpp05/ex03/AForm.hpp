#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>
#include <exception>

class Bureaucrat;

class AForm {
public:
    class GradeTooHighException : public std::exception { public: const char* what() const throw(); };
    class GradeTooLowException : public std::exception { public: const char* what() const throw(); };
    class NotSignedException : public std::exception { public: const char* what() const throw(); };

    AForm(const std::string& name, int gS, int gE);
    AForm(const AForm&);
    AForm& operator=(const AForm&);
    virtual ~AForm();

    const std::string& getName() const;
    bool isSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;

    void beSigned(Bureaucrat const& b);

    virtual void execute(Bureaucrat const& executor) const = 0;

protected:
    void requireExecutable(Bureaucrat const& executor) const; // common checks

private:
    const std::string _name;
    bool _signed;
    const int _gradeToSign;
    const int _gradeToExecute;
};

std::ostream& operator<<(std::ostream& os, const AForm& f);


#endif
