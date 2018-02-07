/**
 * @class ApacheLogAnalyzer
 * @brief est une classe offrant divers outils pour analyser un fichier de log Apache qu'elle s'occupe de charger.
 * @date 07/02/2018
 * @author CADET DU
 */
//---------- Interface de la classe <ApacheLogAnalyzer> (fichier ApacheLogAnalyzer.h) ------------

#ifndef APACHELOGANALYZER_H_INCLUDED
#define APACHELOGANALYZER_H_INCLUDED

#include <string>
#include <unordered_map>
#include <set>

/**
 * @struct Document
 * Représente les attributs d'un document, c'est-à-dire
 * l'ensemble de ses documents référents associés
 * ainsi que son nombre total de consultations.
 */
struct Document
{
    std::unordered_map<std::string, uint32_t> referers = {};
    uint32_t viewCount = 0;
};

/**
 * @struct TopComp
 * Structure de comparaison utilisée pour trier le top, d'abord
 * par nombre de consultations décroissant, puis par nom en ordre ASCII.
 */
struct TopComp
{
    bool operator() (const std::pair<uint32_t, std::string> &x,
            const std::pair<uint32_t, std::string> &y) const
    {
        return x.first > y.first || (x.first == y.first && x.second < y.second);
    }
};

class ApacheLogAnalyzer
{
public:
    ApacheLogAnalyzer();
    ApacheLogAnalyzer(const ApacheLogAnalyzer &analyzer) = default;
    ApacheLogAnalyzer &operator=(const ApacheLogAnalyzer &analyzer) = default;

    virtual ~ApacheLogAnalyzer() = default;


    /** @brief Charge un fichier filename de log Apache dans le but de 
               l'analyser, plusieurs options de chargement sont disponibles.
     *
     * @param filename nom du fichier chargé
     * @param exclude si vrai, ne charge pas les documents au format image
     * @param selectHour ne charge que les documents dont l'heure vaut 
              selectHour, -1 désactive l'option
     * @param graph si vrai, stocke les référents de chaque document consulté en
              vue de générer un graphe.
     *
     * @return true si le chargement s'est bien déroulé, false sinon.
     */
    bool LoadFile(std::string filename, bool exclude, int selectHour, bool graph);


    /** @brief Stocke en langage GraphViz, dans le fichier filename, le graphe 
               des documents consultés et leurs référents, pondéré par nombre de
               consultations, orienté du document référent vers le document 
               consulté. Si filename existe déjà, il est écrasé.
     *          
     * @param filename nom du fichier créé, l'extension n'est pas ajoutée 
              automatiquement.
     *
     * @return true si la génération du graphe s'est bien déroulée, false sinon.
     */
    bool GenerateDotFile(std::string filename);


    /** @brief Renvoie le top des documents les plus consultés jusqu'à la 
               position lastPosition. Le top est recalculé uniquement lorsque sa
               taille est différente de lastPosition.
     *
     * @param lastPosition position du dernier document inclus dans le top
     *
     * @return Le top des documents les plus consultés jusqu'à la position 
               lastPosition.
     */
    const std::set<std::pair<uint32_t, std::string>, TopComp> &Top(
                uint32_t lastPosition = 10);

protected:


    /** @brief Calcule et stocke le top jusqu'à la position lastPosition
     *
     */
    void computeTop(uint32_t lastPosition);

    std::unordered_map<std::string, Document> website;
    std::set<std::pair<uint32_t, std::string>, TopComp> top;
};

#endif // APACHELOGANALYZER_H_INCLUDED
