#ifndef FILEREPLACER_HPP
#define FILEREPLACER_HPP

#include <string>

class FileReplacer {
public:
    FileReplacer(const std::string& filename, const std::string& s1, const std::string& s2);
    ~FileReplacer();

    bool process();

private:
    std::string _filename;
    std::string _s1;
    std::string _s2;

    std::string replaceString(const std::string& content);
};

#endif
