#include "LogParser.h"

#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <map>
#include <utility>

LogParser::LogParser() : website(), top10()
{

}

bool LogParser::LoadFile(std::string filename, bool excludeImages, int selectHour, bool graph)
{
    return false;
}

bool GenerateDotFile(std::string filename)
{
    std::ofstream os(filename);
    if(os)
    {
       os << "digraph {\n";
       std::unordered_map<std::string, Document>::iterator itTargets = website.begin();
       while (itTargets != website.end())
       {
           std::unordered_map<std::string, uint64_t>::iterator itReferers = itTargets->second.referers.begin();
           while(itReferers != itTargets->second.referers.end())
           {
                os << "    ";
                os << itReferers->first << " -> ";
                os << itTargets->first << " [label=\"";
                os << itReferers->second << "\"];\n";
                itReferers++;
           }
           itTargets++;
       }
       os << "}\n";
    }
    else
    {
        std::cerr << "Erreur lors de la création du fichier .dot" << std::endl;
        return false;
    }
    os.close();
    return true;
}

bool nbViewsCompare (uint64_t a, uint64_t b)
    {
        return a > b;
    }

void LogParser::computeTop(uint64_t lastPosition)
{

    std::unordered_map<std::string, Document>::iterator itTargets = website.begin();
   while (itTargets != website.end())
   {
       uint64_t nbViews = 0;
       std::unordered_map<std::string, uint64_t>::iterator itReferers = itTargets->second.referers.begin();
       while(itReferers != itTargets->second.referers.end())
       {
          nbViews += itReferers->second;
       }
       if(top10.size() < lastPosition)
       {
           top10.insert(std::make_pair(itTargets->first, nbViews));
       }
       else if(nbViews > std::prev(top10.end())->second)
       {
           top10.erase(std::prev(top10.end()));
           top10.insert(std::make_pair(itTargets->first, nbViews));
       }
       itTargets++;
   }

}
