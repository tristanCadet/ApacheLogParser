#include "Command.h"
#include "HTTPRequest.h"

#include <iostream>
#include <fstream>

using namespace std;

static void testHTTPRequest()
{
    HTTPRequest r;
    ifstream ifs("./anonyme.log");
    if (ifs)
    {
        ifs >> r;
    }
    else
    {
        cerr << "Le fichier n'a pas pu être ouvert." << endl;
    }
}

int main(int argc, char *argv[])
{
    cout << "Hello world!" << endl;

    testHTTPRequest();

    Command command(argv, argc);
    command.Execute();

    return 0;
}
