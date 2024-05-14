// cmdparser.h
#ifndef CMDPARSER_H
#define CMDPARSER_H

#include <string>
#include <vector>

class CmdParser {
public:
    CmdParser();
    ~CmdParser();

    void parse(const std::string& input);
    std::string getCommand() const;
    std::vector<std::string> getArgs() const;

private:
    std::string command;
    std::vector<std::string> args;
};

#endif // CMDPARSER_H