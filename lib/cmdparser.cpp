// cmdparser.cpp
#include "cmdparser.h"
#include <sstream>

CmdParser::CmdParser() {
    // Constructor
}

CmdParser::~CmdParser() {
    // Destructor
}

void CmdParser::parse(const std::string& input) {
    std::istringstream iss(input);
    iss >> command; // İlk kelimeyi komut olarak al
    std::string arg;
    while (iss >> arg) {
        args.push_back(arg); // Argümanları vektöre ekle
    }
}

std::string CmdParser::getCommand() const {
    return command;
}

std::vector<std::string> CmdParser::getArgs() const {
    return args;
}