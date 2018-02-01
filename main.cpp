/*************************************************************************
                           main - Point d'entrée de l'application
                             -------------------
    copyright            : (C) 2018 par CADET DU
*************************************************************************/
//------------- Implémentation du main (fichier main.cpp) ---------------

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
    Command command(argc, argv);
    command.Execute();

    return 0;
}
