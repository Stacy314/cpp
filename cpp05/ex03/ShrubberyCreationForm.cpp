#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
: AForm("ShrubberyCreation", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& o)
: AForm(o), _target(o._target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& o) {
    if (this != &o) 
        _target = o._target;
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}


void ShrubberyCreationForm::execute(Bureaucrat const& executor) const {
    requireExecutable(executor);
    std::ofstream ofs((_target + "_shrubbery").c_str());
    if (!ofs)
        throw std::runtime_error("Failed to create shrubbery file");
    ofs << "       ccee88oo\n";
    ofs << "    C8O8O8Q8PoOb o8oo\n";
    ofs << "  dOB69QO8PdUOpugoO9bD\n";
    ofs << " CgggbU8OU qOp qOdoUOdcb\n";
    ofs << "    6OuU  /p u gcoUodpP\n";
    ofs << "      \\\\//  /douUP\n";
    ofs << "        \\\\////\n";
    ofs << "         |||/\\\n";
    ofs << "         |||\\/\n";
    ofs << "         |||||\n";
    ofs << "   .....//||||\\\\....\n";
    ofs.close();
}
