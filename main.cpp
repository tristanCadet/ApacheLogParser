#include "Command.h"
#include "HTTPRequest.h"

#include <iostream>
#include <fstream>


#ifdef DEBUG
static void testHTTPRequest()
{
    HTTPRequest r;
    std::ifstream ifs("./anonyme.log");
    if (ifs)
    {
        ifs >> r;
    }
    else
    {
        std::cerr << "Le fichier n'a pas pu être ouvert." << std::endl;
    }
}
#endif // DEBUG

int main(int argc, char *argv[])
{
    Command command(argv, argc);
    command.Execute();

    return 0;
}
