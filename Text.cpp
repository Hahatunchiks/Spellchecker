#include "Text.h"

void Text::readText(std::string &filename) {
  words.clear();
  std::string s;
  char symbol;
  std::string word = ".";
  std::ifstream input(filename);
  while (input.get(symbol)) {
    if (!isspace(symbol)) {
      if (isalpha(symbol)) {
        word += tolower(symbol);
      }
    } else if (word != ".") {
      word += ".";
      words.push_back(word);
      word = ".";
    }
  }
  if (word != ".") {
    word += ".";
    words.push_back(word);
  }
}

std::vector<std::string> Text::getText() {
  return this->words;
}