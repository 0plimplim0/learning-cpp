#include "analysis.hh"
#include <string>
#include <fstream>

class Analyzer {
  private:
    std::ifstream openFile(const std::string& path) const;
    void restartPtr( std::ifstream& file);

  public:
    analysis analyze(const std::string& path);
    void test(const std::string& path) const;
};
