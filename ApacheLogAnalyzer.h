#ifndef APACHELOGANALYZER_H_INCLUDED
#define APACHELOGANALYZER_H_INCLUDED

#include <string>
#include <unordered_map>
#include <map>

struct Document
{
    std::unordered_map<std::string, uint32_t> referers = std::unordered_map<std::string, uint32_t>();
    uint32_t viewCount = 0;
};

class ApacheLogAnalyzer
{
public:
    ApacheLogAnalyzer();
    ApacheLogAnalyzer(const ApacheLogAnalyzer &analyzer) = default;
    ApacheLogAnalyzer& operator=(const ApacheLogAnalyzer &analyzer) = default;

    virtual ~ApacheLogAnalyzer() = default;

    bool LoadFile(std::string filename, bool exclude, int selectHour, bool graph);

    bool GenerateDotFile(std::string filename);

    const std::multimap<uint32_t, std::string, std::greater<uint32_t>>& Top(uint32_t lastPosition = 10);

protected:

    void computeTop(uint32_t lastPosition);

    std::unordered_map<std::string, Document> website;
    std::multimap<uint32_t, std::string, std::greater<uint32_t>> top;
};

#endif // APACHELOGANALYZER_H_INCLUDED
