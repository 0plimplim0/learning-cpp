#include "analysis.hh"
#include <string>

class Analyzer {
public:
  analysis analyze(const std::string& path) const;
  void test(const std::string& path) const;
};
