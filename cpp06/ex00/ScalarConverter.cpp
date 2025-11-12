#include "ScalarConverter.hpp"
#include <iostream>
#include <sstream>
#include <limits>
#include <cstdlib>
#include <cctype>
#include <cmath>



bool isCharLiteral(const std::string& s) {
return s.size() == 1 && !std::isdigit(static_cast<unsigned char>(s[0]));
}
bool isIntLiteral(const std::string& s) {
if (s.empty()) return false;
std::size_t i = (s[0] == '+' || s[0] == '-') ? 1 : 0;
if (i == s.size()) return false;
for (; i < s.size(); ++i) if (!std::isdigit(static_cast<unsigned char>(s[i]))) return false;
return true;
}
bool isFloatPseudo(const std::string& s) {
return (s == "nanf" || s == "+inff" || s == "-inff");
}
bool isDoublePseudo(const std::string& s) {
return (s == "nan" || s == "+inf" || s == "-inf");
}
bool isFloatLiteral(const std::string& s) {
if (isFloatPseudo(s)) return true;
if (s.size() < 2 || s[s.size()-1] != 'f') return false;
std::string core = s.substr(0, s.size()-1);
// decimal only, must contain exactly one '.'
std::size_t i = (core[0] == '+' || core[0] == '-') ? 1 : 0;
bool dot = false; bool digit = false;
for (; i < core.size(); ++i) {
char c = core[i];
if (c == '.') { if (dot) return false; dot = true; }
else if (std::isdigit(static_cast<unsigned char>(c))) { digit = true; }
else return false;
}
return dot && digit;
}
bool isDoubleLiteral(const std::string& s) {
if (isDoublePseudo(s)) return true;
std::size_t i = 0;
if (s.empty()) return false;
if (s[0] == '+' || s[0] == '-') i = 1;
bool dot = false; bool digit = false;
for (; i < s.size(); ++i) {
char c = s[i];
if (c == '.') { if (dot) return false; dot = true; }
else if (std::isdigit(static_cast<unsigned char>(c))) { digit = true; }
else return false;
}
return dot && digit;
}

static void printChar(long double v, bool possible) {
if (isPseudoNan) { std::cout << "nanf\n"; return; }
if (pseudoSign != 0) { std::cout << (pseudoSign>0?"+inff":"-inff") << "\n"; return; }
if (!possible) { std::cout << "impossible\n"; return; }
float f = static_cast<float>(v);
if (std::isinf(f)) { std::cout << (f>0?"+inff":"-inff") << "\n"; return; }
std::cout.setf(std::ios::fixed); std::cout.precision(1);
std::cout << f << 'f' << "\n";
std::cout.unsetf(std::ios::fixed);
}
static void printDouble(long double v, bool possible, bool isPseudoNan=false, int pseudoSign=0) {
std::cout << "double: ";
if (isPseudoNan) { std::cout << "nan\n"; return; }
if (pseudoSign != 0) { std::cout << (pseudoSign>0?"+inf":"-inf") << "\n"; return; }
if (!possible) { std::cout << "impossible\n"; return; }
double d = static_cast<double>(v);
if (std::isinf(d)) { std::cout << (d>0?"+inf":"-inf") << "\n"; return; }
std::cout.setf(std::ios::fixed); std::cout.precision(1);
std::cout << d << "\n";
std::cout.unsetf(std::ios::fixed);
}
}


void ScalarConverter::convert(const std::string& s) {
// CHAR
if (isCharLiteral(s)) {
char c = s[0];
long double v = static_cast<long double>(c);
printChar(v, true);
printInt(v, true);
printFloat(v, true);
printDouble(v, true);
return;
}
// INT
if (isIntLiteral(s)) {
long long ll = std::atol(s.c_str());
long double v = static_cast<long double>(ll);
printChar(v, true);
printInt(v, true);
printFloat(v, true);
printDouble(v, true);
return;
}
// FLOAT
if (isFloatPseudo(s)) {
if (s == "nanf") { printChar(0, false); printInt(0, false); printFloat(0, true, true); printDouble(0, true, true); return; }
int sign = (s[0] == '-') ? -1 : +1;
printChar(0, false); printInt(0, false); printFloat(0, true, false, sign); printDouble(0, true, false, sign); return;
}
if (isFloatLiteral(s)) {
std::string core = s.substr(0, s.size()-1);
std::istringstream iss(core);
double tmp; iss >> tmp; // decimal only
long double v = static_cast<long double>(tmp);
printChar(v, true);
printInt(v, true);
printFloat(v, true);
printDouble(v, true);
return;
}
// DOUBLE
if (isDoublePseudo(s)) {
if (s == "nan") { printChar(0, false); printInt(0, false); printFloat(0, true, true); printDouble(0, true, true); return; }
int sign = (s[0] == '-') ? -1 : +1;
printChar(0, false); printInt(0, false); printFloat(0, true, false, sign); printDouble(0, true, false, sign); return;
}
if (isDoubleLiteral(s)) {
std::istringstream iss(s);
double tmp; iss >> tmp;
long double v = static_cast<long double>(tmp);
printChar(v, true);
printInt(v, true);
printFloat(v, true);
printDouble(v, true);
return;
}
// Unknown
std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n";
