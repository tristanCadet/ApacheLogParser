#include "Command.h"

#include <sstream>
#include <iostream>

Command::Command(const char * const params[], size_t paramCount) : sourceFile(), dotFile(), excludeImages(false), selectHour(-1), errors()
{
    for (size_t i = 1; i < paramCount; i++)
    {
        if (params[i][0] == '-')
        {
            for (int j = 1; params[i][j] != '\0'; j++)
            {
                if (params[i][j] == 'g')
                {
                    if (params[i][j+1] == '\0' && i+1 < paramCount)
                    {
                        i++;
                        if (dotFile.empty())
                            dotFile = params[i];
                        else
                            errors.push_back("Un seul fichier dot doit être spécifié.");
                        break;
                    }
                    else
                        errors.push_back("Un nom de fichier dot doit suivre l'option -g.");
                }
                else if (params[i][j] == 'e')
                {
                    excludeImages = true;
                }
                else if (params[i][j] == 't')
                {
                    if (params[i][j+1] == '\0' && i+1 < paramCount)
                    {
                        i++;
                        std::stringstream ss(params[i]);
                        int hour;
                        if (ss >> hour && hour >= 0 && hour < 24)
                        {
                            if (selectHour == -1)
                                selectHour = hour;
                            else
                                errors.push_back("L'heure ne doit être spécifié qu'une seule fois");
                        }
                        else
                        {
                            errors.push_back("L'heure doit être un nombre entier positif compris entre 0 et 23.");
                        }

                        break;
                    }
                    else
                        errors.push_back("Une heure doit suivre l'option -t.");
                }
                else
                {
                    errors.push_back(std::string("Paramètre -") + params[i][j] + " inconnu !");
                }
            }
        }
        else
        {
            if (sourceFile.empty())
                sourceFile = params[i];
            else
                errors.push_back("Un seul fichier log doit être spécifié.");
        }
    }

    if (sourceFile.empty())
    {
        errors.push_back("Un fichier log doit être spécifié.");
    }
}

void Command::Execute()
{
#ifdef DEBUG
    std::cerr << "[sourceFile = " << sourceFile
              << ", dotFile = " << dotFile
              << ", excludeImages = " << excludeImages
              << ", selectHour = " << selectHour
              << "]" << std::endl;
#endif

    if (!errors.empty())
    {
        for (const std::string &err : errors)
            std::cerr << err << std::endl;

        return;
    }
}

