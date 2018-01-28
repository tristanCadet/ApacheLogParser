#ifndef COMMAND_H_INCLUDED
#define COMMAND_H_INCLUDED

#include <string>
#include <vector>

class Command
{
public:
    Command(size_t paramCount, const char * const params[]);

    void Execute();

protected:
    std::string sourceFile;
    std::string dotFile;
    bool exclude;
    int selectHour;

    std::vector<std::string> errors;
};

#endif // COMMAND_H_INCLUDED
