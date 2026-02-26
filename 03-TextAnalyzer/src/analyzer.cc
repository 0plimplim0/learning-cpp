#include "analyzer.hh"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

std::ifstream Analyzer::openFile(const std::string& path) const{
  std::ifstream file(path);
  if (!file.is_open()){
    std::cout << "Error opening file: " << path << std::endl;
  }
  return file;
}

void Analyzer::restartPtr(std::ifstream& file){
  file.clear();
  file.seekg(0, std::ios_base::beg);
}

analysis Analyzer::analyze(const std::string& path){
  analysis Analysis;
  std::ifstream file = openFile(path);
  if (file){
    std::vector<char> totalChars;
    std::vector<char> visibleChars;
    std::vector<char> lines;
    std::vector<std::string> words;
    char c;
    std::string line;
    std::string s;
    
    // Char by char
    while ((c = file.get()) != EOF){
      if (c == '\n'){
        lines.push_back(c);
      }
      if (!(c == '\n')){
        visibleChars.push_back(c);
      }
      totalChars.push_back(c);
    }

    //Pointer cleaning
    restartPtr(file);

    //Line by line
    while(std::getline(file, line)){
      std::stringstream ss(line);
      while (std::getline(ss, s, ' ')){
        words.push_back(s);
      }
    }
    
    //Values assignment
    Analysis.totalChars = totalChars.size();
    Analysis.visibleChars = visibleChars.size();
    Analysis.words = words.size();
    Analysis.lines = lines.size();
  }
  return Analysis;
}

void Analyzer::test(const std::string& path) const{
  std::cout << "File path is: " << path << "\n";
}
