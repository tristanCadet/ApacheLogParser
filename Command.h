#ifndef COMMAND_H_INCLUDED
#define COMMAND_H_INCLUDED

#include <string>
#include <vector>

class Command
{
public:
    Command(size_t paramCount, const char * const params[]);
    Command(const Command &command) = default;
    Command& operator=(const Command &command) = default;

    virtual ~Command() = default;

    void Execute();

protected:
    std::string sourceFile;
    std::string dotFile;
    bool exclude;
    int selectHour;

    std::vector<std::string> errors;
};

#endif // COMMAND_H_INCLUDED
