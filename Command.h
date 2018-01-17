#ifndef COMMAND_H_INCLUDED
#define COMMAND_H_INCLUDED

#include <string>

class Command
{
public:
    Command(const char *params[]);

    void Execute();

protected:
    std::string sourceFile;
    std::string dotFile;
    bool excludeImages;
    int selectHour;
};

#endif // COMMAND_H_INCLUDED
