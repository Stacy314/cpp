#include "fileReplacer.hpp"
#include <fstream>
#include <iostream>

FileReplacer::FileReplacer(const std::string& filename, const std::string& s1, const std::string& s2)
    : _filename(filename), _s1(s1), _s2(s2) {}

FileReplacer::~FileReplacer() {}

std::string FileReplacer::_replaceString(const std::string& content) {
    std::string result;
    std::size_t start = 0;
    std::size_t pos;

    while ((pos = content.find(_s1, start)) != std::string::npos) {
        result.append(content.substr(start, pos - start));
        result.append(_s2);
        start = pos + _s1.length();
    }
    result.append(content.substr(start));

    return result;
}

bool FileReplacer::process() {
    std::ifstream inputFile(_filename.c_str());
    if (!inputFile.is_open()) {
        std::cerr << "Error: cannot open file " << _filename << '\n';
        return false;
    }
    std::string content((std::istreambuf_iterator<char>(inputFile)),
                         std::istreambuf_iterator<char>());
    inputFile.close();
    std::string replaced = _replaceString(content);
    std::ofstream outputFile((_filename + ".replace").c_str());
    if (!outputFile.is_open()) {
        std::cerr << "Error: cannot create output file." << '\n';
        return false;
    }
    outputFile << replaced;
    outputFile.close();
    return true;
}
