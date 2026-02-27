#include "analyzer.hh"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <unordered_map>

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

std::string Analyzer::getMostW(std::vector<std::string>& words){
  std::unordered_map<std::string, int> count;
  for (std::string word : words){
   count[word]++; 
  }
  int maxF = 0;
  std::string maxW;
  for (const auto& [word, freq] : count){
    if(freq > maxF){
      maxF = freq;
      maxW = word;
    }
  }
  return maxW;
}

std::vector<std::string> Analyzer::getMostWs(std::vector<std::string>& words, int limit){
  std::vector<std::string> mostWs;
  std::unordered_map<std::string, int> count;
  for (std::string word : words){
    count[word]++;
  }
  for(int i = limit;i != 0; i--){
    int maxF = 0;
    std::string maxW;
    for (const auto& [word, freq] : count){
      if (freq > maxF){
        maxF = freq;
        maxW = word;
      }
    }
    count.erase(maxW);
    mostWs.push_back(maxW);
  }
  return mostWs;
}

wordInfo Analyzer::getWordInfo(std::ifstream& file){
  std::vector<std::string> words;
  std::string line;
  std::string s;
  wordInfo wInfo;

  while(std::getline(file, line)){
    std::stringstream ss(line);
    while(std::getline(ss, s, ' ')){
      words.push_back(s);
    }
  }
  wInfo.mostWord = getMostW(words);
  wInfo.wordCount = words.size();
  wInfo.most5Words = getMostWs(words, 5);
  return wInfo;
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
    
    wordInfo wordI = getWordInfo(file);

    //Values assignment
    Analysis.totalChars = totalChars.size();
    Analysis.visibleChars = visibleChars.size();
    Analysis.words = wordI.wordCount;
    Analysis.lines = lines.size();
    Analysis.mostWord = wordI.mostWord;
    Analysis.most5Words = wordI.most5Words;
  }
  return Analysis;
}

void Analyzer::testPath(const std::string& path) const{
  std::cout << "File path is: " << path << "\n";
}
