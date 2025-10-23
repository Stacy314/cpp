#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>

class Bureaucrat {

public:
    // Exceptions
    class GradeTooHighException : public std::exception {
    public:
    const char* what() const throw();
    };
    class GradeTooLowException : public std::exception {
    public:
    const char* what() const throw();
    };

    // Canonical
    Bureaucrat(const std::string& name, int grade);
    Bureaucrat(const Bureaucrat& other);
    Bureaucrat& operator=(const Bureaucrat& other);
    ~Bureaucrat();

    // Getters
    const std::string& getName() const;
    int getGrade() const;

    // Actions
    void incrementGrade(); // 3->2
    void decrementGrade(); // 3->4

private:
    const std::string _name;
    int _grade; // 1 (highest) .. 150 (lowest)

};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif
