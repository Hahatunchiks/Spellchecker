#ifndef SPELLCHECKER__CLIENT_H_
#define SPELLCHECKER__CLIENT_H_
#include <iostream>
#include <algorithm>
#include "SpellChecker.h"
class Client {
 public:
  bool execute(const std::string &line,SpellChecker &checker);
 private:
  int m_wordCount = 10'000;
  double m_N = 4;
  static void printCommandDescription(){
    std::cerr << "'check' - check mistakes in the text\n";
    std::cerr << "'help' - print commands description\n";
    std::cerr << "'exit' - stop the program\n";
    std::cerr << "'set N' - write N index\n";
    std::cerr << "'set word count' - write word count\n";
    std::cerr << "'print diagrams' - shows words and their diagrams\n";
    std::cerr << "'print trigrams' - shows words and their trigrams\n";
  };
};

#endif
