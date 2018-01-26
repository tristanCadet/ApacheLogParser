#include "Command.h"
#include "Request.h"

#include <iostream>
#include <fstream>

using namespace std;

static void testRequest()
{
    Request r;
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
    
    testRequest();
    
    Command command(argv, argc);
    command.Execute();
    
    return 0;
}
