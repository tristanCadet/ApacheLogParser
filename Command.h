#ifndef COMMAND_H_INCLUDED
#define COMMAND_H_INCLUDED

#include <string>
#include <vector>

class Command
{
public:
    Command(const char *params[], size_t paramCount);

    void Execute();

protected:
    std::string sourceFile;
    std::string dotFile;
    bool excludeImages;
    int selectHour;

    std::vector<std::string> errors;
};

#endif // COMMAND_H_INCLUDED
