#include "analysis.hh"
#include <string>
#include <fstream>
#include <vector>

class Analyzer {
  private:
    std::ifstream openFile(const std::string& path) const;
    void restartPtr( std::ifstream& file);
    std::string getMostW(std::vector<std::string>& words);
    std::vector<std::string> getMostWs(std::vector<std::string>& words, int limit);
    wordInfo getWordInfo(std::ifstream& file);

  public:
    analysis analyze(const std::string& path);
    void testPath(const std::string& path) const;
};
