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

int main()
{
    cout << "Hello world!" << endl;
    testRequest();
    return 0;
}
