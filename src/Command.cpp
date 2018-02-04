/*************************************************************************
                                   Command
                             -------------------
    copyright            : (C) 2018 par CADET DU
*************************************************************************/
//---------- Implémentation de la classe <Command> (fichier Command.cpp) ------------

#include "Command.h"

#include "ApacheLogAnalyzer.h"

#include <sstream>
#include <iostream>
#include <unistd.h>

Command::Command(size_t paramCount, const char * const params[]) : sourceFile(),
    dotFile(), exclude(false), selectHour(-1), programName("(null)"), errors()
{
    if (paramCount > 0 && params[0][0] != '\0')
    {
        programName = params[0];
    }
    
    for (size_t i = 1; i < paramCount; i++)
    {
        if (params[i][0] == '-')
        {
            for (int j = 1; params[i][j] != '\0'; j++)
            {
                if (params[i][j] == 'g')
                {
                    if (params[i][j + 1] == '\0' && i + 1 < paramCount)
                    {
                        i++;
                        if (dotFile.empty())
                        {
                            dotFile = params[i];
                        }
                        else
                        {
                            errors.push_back("Un seul fichier dot doit être spécifié.");
                        }
                        break;
                    }
                    else
                    {
                        errors.push_back("Un nom de fichier dot doit suivre l'option -g.");
                    }
                }
                else if (params[i][j] == 'e')
                {
                    exclude = true;
                }
                else if (params[i][j] == 't')
                {
                    if (params[i][j + 1] == '\0' && i + 1 < paramCount)
                    {
                        i++;
                        std::istringstream ss(params[i]);
                        int hour;
                        if (ss >> hour && ss.eof() && hour >= 0 && hour < 24)
                        {
                            if (selectHour == -1)
                            {
                                selectHour = hour;
                            }
                            else
                            {
                                errors.push_back("L'heure ne doit être spécifiée qu'une seule fois.");
                            }
                        }
                        else
                        {
                            errors.push_back("L'heure doit être un nombre entier positif compris entre 0 et 23.");
                        }

                        break;
                    }
                    else
                    {
                        errors.push_back("Une heure doit suivre l'option -t.");
                    }
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
            {
                sourceFile = params[i];
            }
            else
            {
                errors.push_back("Un seul fichier log doit être spécifié.");
            }
        }
    }

    if (sourceFile.empty())
    {
        errors.push_back("Un fichier log doit être spécifié.");
    }
}

bool Command::Execute()
{
#ifdef DEBUG
    std::cerr << "[sourceFile = " << sourceFile
              << ", dotFile = " << dotFile
              << ", exclude = " << exclude
              << ", selectHour = " << selectHour
              << "]" << std::endl;
#endif // DEBUG

    if (!errors.empty())
    {
        std::cerr << "Utilisation : " << programName << " [-e] [-t <heure>] [-g <fichier.dot>] fichier.log" << std::endl;
        for (const std::string &err : errors)
        {
            std::cerr << err << std::endl;
        }

        return false;
    }

    ApacheLogAnalyzer analyzer;

    std::cout << "Lecture du fichier " << sourceFile << "..." << std::endl;
    if (exclude)
    {
        std::cout << "  - Ignore les documents images, css et javascript" << std::endl;
    }

    if (selectHour >= 0)
    {
        std::cout << "  - Ne traite que les requêtes envoyées à " << selectHour << "h." << std::endl;
    }

    if (analyzer.LoadFile(sourceFile, exclude, selectHour, !dotFile.empty()))
    {
        std::cout << "Terminé !" << std::endl << std::endl;

        if (!dotFile.empty())
        {
            if (access(dotFile.c_str(), F_OK) == 0)
            {
                std::cout << "Attention, le fichier " << dotFile << " existe déjà, il sera écrasé." << std::endl;
            }

            std::cout << "Génération du fichier " << dotFile << "..." << std::endl;
            if (analyzer.GenerateDotFile(dotFile))
            {
                std::cout << "Terminé !" << std::endl << std::endl;
            }
            else
            {
                return false;
            }
        }

        std::cout << "Top 10 des documents les plus visités : " << std::endl;
        for (const auto &element : analyzer.Top())
        {
            std::cout << "  - " << element.second << " (" << element.first << " hits)" <<
                      std::endl;
        }
    }
    else
    {
        return false;
    }

    return true;
}

