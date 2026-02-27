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
  std::cout << "Total chars: " << A.totalChars << "\nVisible chars: " << A.visibleChars << "\nWords: " << A.words << "\nLines: " << A.lines << "\n";
  std::cout << "Most Frecuent word: " << A.mostWord << "\n5 Most frecuent words:\n";
  int i = 1;
  for (std::string word : A.most5Words){
    std::cout << i << ". " << word << "\n";
    i++;
  }
  return 0;
}
