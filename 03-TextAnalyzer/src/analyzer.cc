#include "analyzer.hh"
#include <iostream>
#include <string>
#include <fstream>

analysis Analyzer::analyze(const std::string& path) const{
  std::cout << "Analysis complete\n";
  analysis A = {10, 20};
  return A;
}

void Analyzer::test(const std::string& path) const{
  std::cout << "File path is: " << path << "\n";
}
