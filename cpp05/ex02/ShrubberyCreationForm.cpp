#include "ShrubberyCreationForm.hpp"
#include <fstream>


ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
: AForm("ShrubberyCreation", 145, 137), _target(target) {}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& o)
: AForm(o), _target(o._target) {}
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& o) { if (this != &o) _target = o._target; return *this; }
ShrubberyCreationForm::~ShrubberyCreationForm() {}


void ShrubberyCreationForm::execute(Bureaucrat const& executor) const {
requireExecutable(executor);
std::ofstream ofs((_target + "_shrubbery").c_str());
if (!ofs) throw std::runtime_error("Failed to create shrubbery file");
ofs << 
"   /\\\\\\\\\\\n"
" /\\\\\\\\\\\\\\n"
" /\\\\\\/ \\\\\\\n"
"    \\ \\ // /\n"
"     \\ \\ // /\n"
"      \\ V /\n"
"       \\ /\n"
"        \\ /\n"
"         V\n";
ofs.close();
}