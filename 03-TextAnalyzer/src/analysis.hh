#pragma once
#include <string>
#include <vector>

struct analysis {
  int totalChars = 0;
  int visibleChars = 0;
  int words = 0;
  int lines = 0;
  std::string mostWord;
  std::vector<std::string> most5Words;
};

struct wordInfo {
  int wordCount;
  std::string mostWord;
  std::vector<std::string> most5Words;
};
