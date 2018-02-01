/**
 * @class Command
 * @brief est une classe qui modélise la commande entrée par l'utilisateur pour lancer l'application. Elle se charge de repérer les erreurs de syntaxe, et permet l'exécution des commandes valides.
 * @date 07/02/2018
 * @author CADET DU
 */
//---------- Interface de la classe <Command> (fichier Command.h) ------------

#ifndef COMMAND_H_INCLUDED
#define COMMAND_H_INCLUDED

#include <string>
#include <vector>

class Command
{
public:

    /** @brief Construit une commande à partir du tableau de paramètres passé en argument tout en repérant les erreurs de syntaxe. Se référer à la spécification pour savoir quels sont les paramètres valides.
     *
     * @param paramCount nombre de paramètres
     * @param params tableau de paramètres à partir duquel la commande est construite
     */
    Command(size_t paramCount, const char * const params[]);
    Command(const Command &command) = default;
    Command& operator=(const Command &command) = default;


    virtual ~Command() = default;


    /** @brief Orchestre l'exécution de la commande conformément à la spécification. Si des erreurs de syntaxe ont été repérées à la construction de l'objet, l'application s'arrête après les avoir affichées.
     *
     */
    void Execute();

protected:
    std::string sourceFile;
    std::string dotFile;
    bool exclude;
    int selectHour;

    std::vector<std::string> errors;
};

#endif // COMMAND_H_INCLUDED
