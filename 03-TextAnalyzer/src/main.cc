#include <iostream>
#include <string>
#include "analyzer.hh"

int main(int argc, char** argv){
  if (argc != 2){
    std::cout << "Use: ./main <file>" << std::endl;
    return 1;
  }

  std::string path = argv[1];
  Analyzer analyzer;
  analyzer.test(path);
  return 0;
}
