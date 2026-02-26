#include <iostream>
#include <string>
#include "analyzer.hh"
#include "analysis.hh"

int main(int argc, char** argv){
  if (argc != 2){
    std::cout << "Use: ./main <file>" << std::endl;
    return 1;
  }

  std::string path = argv[1];
  Analyzer analyzer;
  analysis A = analyzer.analyze(path);
  std::cout << "Total chars: " << A.totalChars << "\nVisible chars: " << A.visibleChars << "\nWords: " << A.words << "\nLines: " << A.lines << std::endl;
  return 0;
}
