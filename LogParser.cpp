#include "LogParser.h"

LogParser::LogParser() : website(), top10()
{

}

bool LogParser::LoadFile(std::string filename, bool excludeImages, int selectHour, bool graph)
{
    return false;
}

bool GenerateDotFile(std::string filename)
{
    ofstream os(filename);
    if(os)
    {
       os << "digraph {\r\n";
       std::unordered_map<std::string, Document>::iterator itTargets = website.begin();
       while (itTargets != website.end())
       {
           std::unordered_map<std::string, uint64_t>::iterator itReferers = itTargets->second.referers.begin();
           while(itReferers != itTargets->second.referers.end())
           {
                os << "    ";
                os << itReferers->first << " -> ";
                os << itTargets->first << " [label=\"";
                os << itReferers->second << "\"];\r\n";
                itReferers++;
           }
           itTargets++;
       }
       os << "}\r\n";
    }
    else
    {
        cerr << "Erreur lors de la création du fichier .dot" << endl;
    }
    os.close();
    return false;
}
