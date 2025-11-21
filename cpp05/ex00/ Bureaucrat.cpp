//overload of the insertion («) operator to print output in the following format (without the angle brackets):
//<name>, bureaucrat grade <grade>.

std::ostream& operator<<(std::ostream& os, /*const Fixed& fx*/) {
    //os << fx.toFloat();
    return os;
}