#ifndef LOGPARSER_H_INCLUDED
#define LOGPARSER_H_INCLUDED

#include <string>
#include <unordered_map>
#include <vector>
#include <utility>

struct Document
{
    std::unordered_map<std::string, uint64_t> referers;
};

class LogParser
{
public:
    LogParser();

    bool LoadFile(std::string filename, bool excludeImages, int selectHour, bool graph);

    inline const std::vector<std::pair<std::string, uint64_t>>& Top10() { return top10; }

    bool GenerateDotFile(std::string filename);

protected:
    std::unordered_map<std::string, Document> website;
    std::vector<std::pair<std::string, uint64_t>> top10;
};

#endif // LOGPARSER_H_INCLUDED
